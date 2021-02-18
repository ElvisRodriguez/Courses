#!/usr/local/bin/python3.8
import datetime
import logging
import os

import boto3
import dotenv
import flask
import requests

from aws_client import Client
from metadata_storage import MetadataStorage



app = flask.Flask(__name__)
app.config['DEBUG'] = True
dotenv.load_dotenv()
metadata_store = MetadataStorage(debug_mode=True)
LOG = flask.logging.create_logger(app)


def get_timestamp():
    current_datetime = datetime.datetime.now()
    timestamp = str(current_datetime)
    return timestamp


@app.before_first_request
def before_first_request():
    log_level = logging.INFO
    root = os.path.dirname(os.path.abspath(__file__))
    log_directory = os.path.join(root, 'logs')
    if not os.path.exists(log_directory):
        os.mkdir(log_directory)
    log_file = os.path.join(log_directory, 'app.log')
    handler = logging.FileHandler(log_file)
    handler.setLevel(log_level)
    LOG.addHandler(handler)
    LOG.setLevel(log_level)

@app.route('/storage/request-api-key')
def request_api_key():
    user_email = flask.request.headers['email']
    LOG.info('{timestamp} Received Email: {email}'.format(
        timestamp=get_timestamp(), email=user_email
    ))
    new_api_key = metadata_store.add_new_api_key(user_email)
    LOG.info('{timestamp} New API Key Created: {api_key}'.format(
        timestamp=get_timestamp(), api_key=new_api_key
    ))
    return flask.jsonify({
        'response': 200,
        'new_api_key': new_api_key
    })

@app.route('/storage/upload/<id>', methods=['POST'])
def upload_file(id):
    api_key = flask.request.headers['api_key']
    filename = flask.request.headers['filename']
    file_data = flask.request.get_data()
    LOG.info('{timestamp} Received API Key: {api_key}'.format(
        timestamp=get_timestamp(), api_key=api_key
    ))
    LOG.info('{timestamp} Received File: {filename} with ID: {file_id}'.format(
        timestamp=get_timestamp(), filename=filename, file_id=id
    ))
    if not metadata_store.verify_file_id(id):
        LOG.info('{timestamp} Invalid ID: {file_id} received'.format(
            timestamp=get_timestamp(), file_id=id
        ))
        return flask.jsonify({'response': 400})
    metadata_added = False
    if metadata_store.verify_api_key(api_key):
        metadata_added = metadata_store.add_new_metadata(api_key, filename, id)
    else:
        LOG.info('{timestamp} Invalid API key {api_key} received'.format(
            timestamp=get_timestamp(), api_key=api_key
        ))
        return flask.jsonify({'response': 403})
    if metadata_added:
        s3_client = Client()
        upload_successful = s3_client.upload_file(file_data, filename, id)
        if upload_successful:
            return flask.jsonify({'response': 200})
    LOG.info('{timestamp} Error entering metadata into database.'.format(
        timestamp=get_timestamp()
    ))
    return flask.jsonify({'response': 400})


@app.route('/storage/files')
def list_all_user_files():
    api_key = flask.request.headers['api_key']
    LOG.info('{timestamp} Received API Key: {api_key}'.format(
        timestamp=get_timestamp(), api_key=api_key
    ))
    if metadata_store.verify_api_key(api_key):
        LOG.info('{timestamp} API Key: {api_key} is verified'.format(
            timestamp=get_timestamp(), api_key=api_key
        ))
        file_metadata = metadata_store.get_metadata_by_api_key(api_key)
        return flask.jsonify({
                'response': 200,
                'file_metadata': file_metadata
            })
    LOG.info('{timestamp} Invalid API key {api_key} received'.format(
            timestamp=get_timestamp(), api_key=api_key
    ))
    return flask.jsonify({'response': 403})


@app.route('/storage/files/<id>')
def download_file(id):
    api_key = flask.request.headers['api_key']
    LOG.info('{timestamp} Received API Key: {api_key}'.format(
        timestamp=get_timestamp(), api_key=api_key
    ))
    if metadata_store.verify_api_key(api_key):
        LOG.info('{timestamp} API Key: {api_key} is verified'.format(
            timestamp=get_timestamp(), api_key=api_key
        ))
        filename = metadata_store.get_filename_by_file_id(id)
        if filename is not None:
            LOG.info('{timestamp} {filename} retrieved using {file_id}'.format(
                timestamp=get_timestamp(), filename=filename, file_id=id
            ))
            s3_client = Client()
            print('BREAKPOINT')
            file_data = s3_client.download_file(filename, id)
            if file_data is not None:
                return flask.jsonify({
                    'response': 200,
                    'file_data': str(file_data)
                })
            LOG.info('{timestamp} Object: {file_id}-{filename} is empty'.format(
                timestamp=get_timestamp(), file_id=id, filename=filename
            ))
            return flask.jsonify({'response': 400})
        LOG.info('{timestamp} ID: {file_id} does not point to a file'.format(
            timestamp=get_timestamp(), file_id=id
        ))
        return flask.jsonify({'response': 400})
    LOG.info('{timestamp} Invalid API key {api_key} received'.format(
            timestamp=get_timestamp(), api_key=api_key
    ))
    return flask.jsonify({'response': 403})


@app.route('/storage/delete/<id>')
def delete_file(id):
    api_key = flask.request.headers['api_key']
    LOG.info('{timestamp} Received API Key: {api_key}'.format(
        timestamp=get_timestamp(), api_key=api_key
    ))
    if metadata_store.verify_api_key(api_key):
        LOG.info('{timestamp} API Key: {api_key} is verified'.format(
            timestamp=get_timestamp(), api_key=api_key
        ))
        filename = metadata_store.get_filename_by_file_id(id)
        if filename is not None:
            LOG.info('{timestamp} {filename} retrieved using {file_id}'.format(
                timestamp=get_timestamp(), filename=filename, file_id=id
            ))
            s3_client = Client()
            aws_response = s3_client.delete_file(filename, id)
            if aws_response is not None:
                return flask.jsonify({
                    'response': 200,
                    'aws_response': aws_response
                })
            LOG.info('{timestamp} File {filename} not deleted.'.format(
                timestamp=get_timestamp(), filename=filename
            ))
            return flask.jsonify({'response': 400})
        LOG.info('{timestamp} ID: {file_id} does not point to a file'.format(
            timestamp=get_timestamp(), file_id=id
        ))
        return flask.jsonify({'response': 400})
    LOG.info('{timestamp} Invalid API key {api_key} received'.format(
            timestamp=get_timestamp(), api_key=api_key
    ))
    return flask.jsonify({'response': 403})


if __name__ == '__main__':
    app.run(host=os.getenv('HOST'), port=os.getenv('PORT'))