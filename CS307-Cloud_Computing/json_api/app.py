#!/usr/local/bin/python3.8
import json
import logging
import os

import flask

from data_handler import load_json_data, write_json_data


JSON_FILE = 'data.json'

app = flask.Flask(__name__)
app.config['DEBUG'] = True


@app.before_first_request
def before_first_request():
    log_level = logging.INFO
    for handler in app.logger.handlers:
        app.logger.removeHandler(handler)
    root = os.path.dirname(os.path.abspath(__file__))
    log_directory = os.path.join(root, 'logs')
    if not os.path.exists(log_directory):
        os.mkdir(log_directory)
    log_file = os.path.join(log_directory, 'app.log')
    handler = logging.FileHandler(log_file)
    handler.setLevel(log_level)
    app.logger.addHandler(handler)
    app.logger.setLevel(log_level)


@app.route('/question/<id>', methods=['GET'])
def find_question(id):
    json_data = load_json_data(JSON_FILE)
    app.logger.info('Loaded JSON data')
    question = {}
    if str(id) in json_data:
        app.logger.info('Found ID #{id} in JSON data: {question}'.format(
            id=id, question=question)
        )
        question = json_data[str(id)]['question']
    else:
        app.logger.info('ID #{id} not found'.format(id=id))
    return flask.jsonify(question)


@app.route('/question/<id>/<answer>', methods=['GET'])
def check_answer(id, answer):
    json_data = load_json_data(JSON_FILE)
    app.logger.info('Loaded JSON data')
    response = {}
    if str(id) in json_data:
        db_answer = json_data[str(id)]['answer']
        app.logger.info('Loaded answer to ID #{id}'.format(id=id))
        if answer == db_answer:
            response = {'correct': 'true'}
            app.logger.info('Correct answer given')
        else:
            response = {'correct': 'false'}
            app.logger.info('Incorrect answer given')
    else:
        app.logger.info('ID #{id} not found'.format(id=id))
    return flask.jsonify(response)


@app.route('/question/save/', methods=['POST'])
def enter_new_question():
    try:
        question = flask.request.values['question']
        answer = flask.request.values['answer']
        app.logger.info('POST data valid')
    except KeyError:
        app.logger.info('POST data invalid or NULL')
        return flask.jsonify(success=False)
    json_data = load_json_data(JSON_FILE)
    app.logger.info('Loaded JSON data')
    new_key = max([int(id) for id in json_data.keys()]) + 1
    app.logger.info('Created ID #{id} for new JSON data'.format(id=id))
    json_data[str(new_key)] = {
        'question': question,
        'answer': answer
    }
    app.logger.info('Created new entry in JSON data')
    write_json_data(JSON_FILE, json_data)
    app.logger.info('Saved edited JSON data')
    return flask.jsonify(success=True)


if __name__ == '__main__':
    app.run()
