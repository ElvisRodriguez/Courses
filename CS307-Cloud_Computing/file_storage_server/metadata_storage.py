#!/usr/local/bin/python3.8
import base64
import hashlib
import os

import dotenv
import sqlite3

class MetadataStorage(object):
    def __init__(self, debug_mode=False):
        dotenv.load_dotenv()
        self._db = os.getenv('DATABASE_NAME')
        self.api_key_size = int(os.getenv('API_KEY_SIZE'))
        if debug_mode:
            debug_db = os.getenv('TEST_DATABASE_NAME')
            debug_db_full_path = os.path.join(os.getcwd(), 'tests', debug_db)
            self._db = debug_db_full_path
        connection = sqlite3.connect(self._db, cached_statements=0)
        cursor = connection.cursor()
        cursor.executescript('''
            DROP TABLE IF EXISTS MetaData;
            CREATE TABLE MetaData(
                api_key,
                filename,
                file_id
            );
            DROP TABLE IF EXISTS ValidAPIKeys;
            CREATE TABLE ValidAPIKeys(
                user_email,
                api_key
            );
        ''')
        connection.commit()
        connection.close()

    def verify_api_key(self, api_key):
        connection = sqlite3.connect(self._db, cached_statements=0)
        cursor = connection.cursor()
        fetch_data = (api_key,)
        cursor.execute('SELECT * FROM ValidAPIKeys where api_key=?', fetch_data)
        return_data = cursor.fetchone()
        connection.close()
        return True if return_data is not None else False

    def verify_file_id(self, file_id):
        connection = sqlite3.connect(self._db)
        cursor = connection.cursor()
        fetch_data = (file_id,)
        cursor.execute('SELECT * FROM MetaData where file_id=?', fetch_data)
        return_data = cursor.fetchone()
        connection.close()
        return True if return_data is None else False

    def add_new_api_key(self, user_email):
        hasher = hashlib.sha1(user_email.encode())
        new_api_key = base64.urlsafe_b64encode(
            hasher.digest()[:self.api_key_size]
        )
        new_api_key = str(new_api_key.decode())
        connection = sqlite3.connect(self._db, cached_statements=0)
        cursor = connection.cursor()
        new_user_data = (user_email, new_api_key)
        cursor.execute('INSERT INTO ValidAPIKeys VALUES (?,?)', new_user_data)
        connection.commit()
        connection.close()
        return new_api_key
    
    def add_new_metadata(self, api_key, filename, file_id):
        if self.verify_api_key(api_key):
            connection = sqlite3.connect(self._db)
            cursor = connection.cursor()
            new_metadata = (api_key, filename, file_id)
            query_string = '''INSERT INTO MetaData VALUES (?,?,?)'''
            cursor.execute(query_string, new_metadata)
            connection.commit()
            connection.close()
            return True
        return False
    
    def get_metadata_by_api_key(self, api_key):
        if self.verify_api_key(api_key):
            connection = sqlite3.connect(self._db)
            cursor = connection.cursor()
            fetch_data = (api_key,)
            cursor.execute(
                'SELECT filename, file_id FROM MetaData where api_key=?',
                fetch_data
            )
            raw_data = cursor.fetchall()
            connection.close()
            file_metadata = []
            for row in raw_data:
                filename, file_id = row
                entry = {
                    'filename': filename,
                    'file_id': file_id
                }
                file_metadata.append(entry)
            return file_metadata
    
    def get_filename_by_file_id(self, file_id):
        connection = sqlite3.connect(self._db)
        cursor = connection.cursor()
        fetch_data = (file_id,)
        cursor.execute(
            'SELECT filename FROM MetaData where file_id=?',
            fetch_data
        )
        raw_filename = cursor.fetchone()
        connection.close()
        if raw_filename is None:
            return None
        filename, = raw_filename
        return filename
    
    def delete_filename_by_file_id(self, file_id):
        connection = sqlite3.connect(self._db)
        cursor = connection.cursor()
        fetch_data = (file_id,)
        cursor.execute(
            'DELETE FROM MetaData WHERE file_id=?',
            fetch_data
        )
        connection.close()