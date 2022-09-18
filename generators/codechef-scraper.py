#!/usr/bin/env python

import os
import sys
import json

import requests



def to_ext(lang_code):
    LANG_MAP = {
        'PYTH 3': 'py',
        'C': 'c',
        'C++14': 'cpp',
    }
    if lang_code not in LANG_MAP.keys():
        print(f"No mapping found for {lang_code}")
        return 'x'
    else:
        return LANG_MAP[lang_code]

class Chef:
    def __init__(self, access_token, username):
        self.access_token = access_token
        self.username = username

    def request(self, url):
        headers = {
            "Accept": "application/json",
            "Authorization": f"Bearer {self.access_token}"
        }
        r = requests.get(url, headers=headers)
        response = r.json()
        print(url, response)
        return response

    def get_all_self_submissions(self):
        API_URL = "https://api.codechef.com/users/me"
        user_details = self.request(API_URL)
        solved = user_details['result']['data']['content']['problemStats']['solved']
        return solved

    def search_submissions(self, problemCode=None, contestCode=None):
        API_URL = f"https://api.codechef.com/submissions/?result=AC&username={self.username}&problemCode={problemCode}&contestCode={contestCode}&limit=1"
        submission_details = self.request(API_URL)
        submission_id = submission_details['result']['data']['content'][0]['id']
        return submission_id

    def get_submission_code(self, submission_id):
        API_URL = f"https://api.codechef.com/submissions/{submission_id}?fields=code,language"
        result = self.request(API_URL)['result']['data']['content']
        language = to_ext(result['language'])
        code = result['code']
        return language, code

def get_credentials(secrets_file):
    secret = json.load(secrets_file)
    payload = secret
    payload['grant_type'] = 'client_credentials'
    payload['scope'] = 'public'

    url = 'https://api.codechef.com/oauth/token'
    r = requests.post(url, json=payload)
    response = r.json()
    access_token = response['result']['data']['access_token']
    username = secret['username']
    return Chef(access_token, username)

def main():
    with open(sys.argv[1]) as secrets_file:
        chef = get_credentials(secrets_file)
    root = sys.argv[2]

    solved = chef.get_all_self_submissions()
    for contest_code, problem_list in solved.items():
        if contest_code == 'Practice Problems':
            contest_code = 'practice'
        os.makedirs(os.path.join(root, contest_code), exist_ok=True)
        for problem_code in problem_list:
            submission_id = chef.search_submissions(problem_code, contest_code)
            ext, code = chef.get_submission_code(submission_id)
            with open(os.path.join(root, contest_code, f'{problem_code}.{ext}'), 'w') as code_file:
                code_file.write(code)


if __name__ == '__main__':
    main()