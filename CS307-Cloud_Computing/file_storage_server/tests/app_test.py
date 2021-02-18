#/usr/local/bin/python3.8
import base64
import datetime
import hashlib
import os
import time
import unittest

import dotenv
import requests


class testStorageApp(unittest.TestCase):
    def setUp(self):
        dotenv.load_dotenv()
        self.email = os.getenv('TEST_EMAIL')
        self.test_upload_file = os.getenv('TEST_UPLOAD_FILE')
        self.test_download_file = os.getenv('TEST_DOWNLOAD_FILE')
        self.api_endpoint = os.getenv('API_ENDPOINT')
        self.api_key_size = int(os.getenv('API_KEY_SIZE'))
        self.host = os.getenv('HOST')
        self.port = os.getenv('PORT')
        hasher = hashlib.sha1(self.email.encode())
        test_api_key = base64.urlsafe_b64encode(
            hasher.digest()[:self.api_key_size]
        )
        self.api_key = str(test_api_key.decode())
    
    def _build_url(self, *args):
        base_url = 'http://{host}:{port}/{api_endpoint}'.format(
            host=self.host, port=self.port, api_endpoint=self.api_endpoint
        )
        raw_url = [base_url]
        for path_param in args:
            raw_url.append(path_param)
        return '/'.join(raw_url)
    
    def testA_request_new_api_key(self):
        url = self._build_url('request-api-key')
        request = requests.get(
            url=url,
            headers={
                'email': self.email
            }
        )
        self.assertTrue(request.ok)
        print(request.json())
    
    def testB_upload_file(self):
        url = self._build_url('upload', 'test-id')
        with open(self.test_upload_file, 'rb') as file_data:
            request = requests.post(
                url=url,
                data={
                    'file_data': file_data
                },
                headers={
                    'api_key': self.api_key,
                    'filename': self.test_upload_file
                }
            )
            self.assertTrue(request.ok)
    
    def testC_request_file_metadata(self):
        url = self._build_url('files')
        request = requests.get(
            url=url,
            headers={
                'api_key': self.api_key
            }
        )
        self.assertTrue(request.ok)
    
    def skiptestD_download_file(self):
        url = self._build_url('files', 'test-id')
        with open(self.test_download_file, 'w') as file:
            request = requests.get(
                url=url,
                headers={
                    'api_key': self.api_key
                }
            )
            self.assertTrue(request.ok)
            print(request.json())
            file_data = request.json()['file_data']
            self.assertIsNotNone(file_data)
    
    def skiptestE_delete_file(self):
        url = self._build_url('delete', 'test-id')
        request = requests.get(
            url=url,
            headers={
                'api_key': self.api_key
            }
        )
        self.assertTrue(request.ok)


if __name__ == '__main__':
    unittest.main()