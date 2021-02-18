#!/usr/local/bin/python3.8
import io
import os
import sys

import boto3
import dotenv


class Client(object):
    def __init__(self):
        dotenv.load_dotenv()
        self.bucket = os.getenv('S3_BUCKET_NAME')
        self.client = boto3.client(
            service_name='s3',
            aws_access_key_id=os.getenv('AWS_ACCESS_KEY_ID'),
            aws_secret_access_key=os.getenv('AWS_SECRET_KEY')
        )
        self.tempfile = os.getenv('TEMPFILE')
    
    def upload_file(self, file, filename, file_id):
        file_object = io.BytesIO(file)
        object_name = '{file_id}-{filename}'.format(
            filename=filename, file_id=file_id
        )
        try:
            self.client.upload_fileobj(file_object, self.bucket, object_name)
            return True
        except:
            return False
    
    def download_file(self, filename, file_id):
        object_name = '{file_id}-{filename}'.format(
            filename=filename, file_id=file_id
        )
        with open(self.tempfile, 'wb') as data:
            self.client.download_fileobj(self.bucket, object_name, data)
        with open(self.tempfile, 'r') as data:
            return '\n'.join(data.readlines())
        return None
    
    def delete_file(self, filename, file_id):
        object_name = '{file_id}-{filename}'.format(
            filename=filename, file_id=file_id
        )
        aws_response = self.client.delete_object(
            Bucket=self.bucket, Key=object_name
        )
        return aws_response