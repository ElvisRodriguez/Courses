#!/usr/local/bin/python3.8

import sqlite3


class Cache(object):
    def __init__(self):
        self._db = 'cache.db'
        connection = sqlite3.connect(self._db)
        cursor = connection.cursor()
        cursor.executescript('''
            DROP TABLE IF EXISTS cache;
            CREATE TABLE cache(
                key,
                value
            );
        ''')
        connection.commit()
        connection.close()
    
    def get(self, key):
        fetch_data = (key,)
        connection = sqlite3.connect(self._db)
        cursor = connection.cursor()
        cursor.execute('SELECT value FROM cache WHERE key=?', fetch_data)
        raw_data = cursor.fetchone()
        if len(raw_data) > 1:
            return raw_data
        get_data, = raw_data
        connection.close()
        return get_data
    
    def set(self, key, value):
        new_data = (key, value)
        connection = sqlite3.connect(self._db)
        cursor = connection.cursor()
        cursor.execute('INSERT INTO cache VALUES (?,?)', new_data)
        connection.commit()
        connection.close()


if __name__ == '__main__':
    cache = Cache()
    cache.set('test', '123')
    print(cache.get('test'))