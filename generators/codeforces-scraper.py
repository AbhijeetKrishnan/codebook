import logging
import os
import time

import requests
from bs4 import BeautifulSoup
from ratelimit import limits, sleep_and_retry
from tqdm import tqdm


def detect_language(lang):
    LANGS = {
        'GNU C': 'c',
        'GNU C++11': 'cpp',
        'GNU C++14': 'cpp',
        'GNU C++17': 'cpp',
        'Kotlin': 'kt', 
        'Python 3': 'py', 
        'PyPy 3': 'py', 
    }
    if lang in LANGS:
        logging.info("Detected language: %s" % LANGS[lang])
        return LANGS[lang]
    else:
        logging.warning("Detected unknown language: %s" % lang)
        return 'unknown'

def get_submissions(user):
    res = []
    url = "https://codeforces.com/api/user.status"
    logging.info("Making request for user.status")
    response = requests.get(url, params = {'handle': user})
    logging.debug("Returned status code %d" % response.status_code)

    if response.status_code == 200:
        json = response.json()
        logging.debug("Returned status %s" % json['status'])

        if json['status'] == "OK":
            for submission in json['result']:
                sub = {}
                sub['id'] = submission['id']
                sub['contestId'] = submission['contestId']
                sub['problemName'] = submission['problem']['name']
                sub['problemIndex'] = submission['problem']['index']
                sub['ext'] = detect_language(submission['programmingLanguage'])
                sub['verdict'] = submission['verdict']
                res.append(sub)

    logging.info("Retrieved all submissions for %s" % user)
    return res

def get_contest_names():
    res = {}
    url = "http://codeforces.com/api/contest.list"
    logging.info("Making request for contest.list")
    response = requests.get(url, params = {'gym': 'false'})
    logging.debug("Returned status code %d" % response.status_code)

    if response.status_code == 200:
        json = response.json()
        logging.debug("Returned status %s" % json['status'])
        if json['status'] == "OK":
            for contest in json['result']:
                res[contest['id']] = contest['name']

    logging.info("Retrieved contest list")
    return res

@sleep_and_retry
@limits(calls = 5, period = 1)
def get_submission_code(submission_id, contest_id):
    res = ""
    url = "https://codeforces.com/contest/%s/submission/%s" % (contest_id, submission_id)
    logging.info("Making request for submission %d" % submission_id)
    response = requests.get(url)
    logging.debug("Returned status code %d" % response.status_code)

    if response.status_code == 200:
        soup = BeautifulSoup(response.text, 'html.parser')
        code_tag = soup.find(id = 'program-source-text')

        if not code_tag:
            logging.error("Source code could not be found for submission ID: %d. Request was most likely redirected by Codeforces." % (submission_id))
        res = code_tag.string

    return res

# traverse submission list in reverse order (from oldest to newest)
# save first submission with git commit of Add submission for [index] - [problem_name]
# save subsequent submissions with git commit of Attempt bugfix
def build_codebook(user, root):
    FORWARD_SLASH_REPLACEMENT = '╱'
    start_time = time.process_time_ns()
    
    logging.info("Building Codeforces codebook for %s in folder %s/Codeforces" % (user, root))
    # create Codeforces folder in pwd
    try:
        logging.debug("Attempting to create %s/Codeforces folder" % root)
        os.chdir(root)
        os.mkdir('Codeforces')
        logging.info("Successfully created Codeforces folder")
    except FileExistsError:
        logging.warning("Failed to create Codeforces folder since it already exists")

    logging.info("Retrieving submissions list for %s" % user)
    submissions_list = get_submissions(user)
    if submissions_list:
        logging.info("Successfully retrieved submissions list")
    else:
        logging.critical("Failed to retrieve submissions list")

    logging.info("Retrieving contest names")
    contest_names = get_contest_names()
    if contest_names:
        logging.info("Successfully retrieved contest names")
    else:
        logging.critical("Failed to retrieve contest names")

    for submission in tqdm(submissions_list):
        # Create contest folder
        try:
            logging.debug("Creating folder for contest %s" % contest_names[submission['contestId']])
            os.mkdir(os.path.join('Codeforces', contest_names[submission['contestId']]))
            logging.info("Successfully created folder for contest %s" % contest_names[submission['contestId']])
        except FileExistsError:
            logging.warning("Skipped %s since folder already exists..." % contest_names[submission['contestId']])
        
        # generate filename
        filename = "%s - %s.%s" % (submission['problemIndex'], submission['problemName'], submission['ext'])
        filename = filename.replace('/', FORWARD_SLASH_REPLACEMENT)
        filepath = os.path.join('Codeforces', contest_names[submission['contestId']], filename)
        if not os.path.isfile(filepath):
            fp = open(filepath, 'w')
            logging.debug("Retrieving code for submission %d" % submission['id'])
            code = get_submission_code(submission['id'], submission['contestId'])
            logging.info("Successfully retrieved code for problem %s - %s from contest %s" % (submission['problemIndex'], submission['problemName'], contest_names[submission['contestId']]))
            fp.write(code)
            fp.close()
        else:
            logging.warning("Skipped problem %s - %s from contest %s since it already exists" % (submission['problemIndex'], submission['problemName'], contest_names[submission['contestId']]))
    stop_time = time.process_time_ns()
    logging.info("Codebook generation completed in %dns" % (stop_time - start_time))

if __name__ == "__main__":
    logging.basicConfig(level = logging.ERROR, 
                        format = "[%(levelname)s] %(funcName)s:%(lineno)s - %(message)s")
    root = "/home/akrish13/Documents/codebook"
    user = "MystikNinja"
    build_codebook(user, root)
