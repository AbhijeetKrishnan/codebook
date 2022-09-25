#!/usr/bin/env python

import os
import re
import sys
from time import sleep

import requests
from bs4 import BeautifulSoup
from ratelimit import RateLimitException, limits, sleep_and_retry


def to_ext(lang_code):
    LANG_MAP = {
        'PYTH 3': 'py',
        'C': 'c',
        'C++14 (GCC 5.4.1)': 'cpp',
    }
    if lang_code not in LANG_MAP.keys():
        print(f"No mapping found for {lang_code}")
        return 'x'
    else:
        return LANG_MAP[lang_code]

class AtCoder:
    def __init__(self, username):
        self.username = username

    @sleep_and_retry
    @limits(calls=1, period=2)
    def get_contests(self):
        "Return list of (contest_id, contest_name) for this user"
        
        url = f'https://atcoder.jp/users/{self.username}/history'
        response = requests.get(url)
        if response.status_code != 200:
            raise RateLimitException(f'Page response: {response.status_code}', 2)
        else:
            soup = BeautifulSoup(response.text, 'html.parser')
            contest_re = r'/contests/([a-zA-Z0-9]+)$'
            contest_tags = soup.find_all('a', href=re.compile(contest_re))
            contests = map(lambda tag: (tag.attrs['href'].split('/')[-1], tag.string), contest_tags)
            return list(contests)


    @sleep_and_retry
    @limits(calls=1, period=2)
    def get_last_ac(self, contest_id):
        "Given contest_id, get (language, status=AC, submission_id) for the contest"
        
        url = f'https://atcoder.jp/contests/{contest_id}/submissions?f.User={self.username}'
        response = requests.get(url)
        if response.status_code != 200:
            raise RateLimitException(f'Page response: {response.status_code}', 2)
        else:
            soup = BeautifulSoup(response.text, 'html.parser')
            submission_re = r'/contests/[a-zA-Z0-9]+/submissions/([a-zA-Z0-9]+)$'
            submission_tags = soup.find_all('a', href=re.compile(submission_re))
            submission_ids = map(lambda tag: tag.attrs['href'].split('/')[-1], submission_tags)
            label_tags = soup.find_all('span', class_='label')
            labels = map(lambda tag: tag.string, label_tags)
            submissions = zip(submission_ids, labels)
            ac_submissions = filter(lambda submission: submission[1] == 'AC', submissions)
            return list(ac_submissions)[0]

    @sleep_and_retry
    @limits(calls=1, period=2)
    def get_submission_details(self, contest_id, submission_id):
        "Give submission_id, get task name, language, source code"

        url = f'https://atcoder.jp/contests/{contest_id}/submissions/{submission_id}'
        response = requests.get(url)
        if response.status_code != 200:
            raise RateLimitException(f'Page response: {response.status_code}', 2)
        else:
            soup = BeautifulSoup(response.text, 'html.parser')
            code = soup.find('pre', id='submission-code').string
            task = soup.find('a', href=re.compile(fr'^/contests/{contest_id}/tasks/[a-zA-Z0-9_]+$')).string
            lang = soup.find('th', string='Language').find_next_sibling('td').string
            return (task, lang, code)

def main():
    username = sys.argv[1]
    root = sys.argv[2]

    user = AtCoder(username)
    contests = user.get_contests()
    for contest_id, contest_name in contests:
        os.makedirs(os.path.join(root, contest_name), exist_ok=True)
        last_ac, _ = user.get_last_ac(contest_id)
        task_name, lang, code = user.get_submission_details(contest_id, last_ac)
        ext = to_ext(lang)
        with open(os.path.join(root, contest_name, f'{task_name}.{ext}'), 'w') as code_file:
            code_file.write(code)

if __name__ == '__main__':
    main()
