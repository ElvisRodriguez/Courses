#!/usr/local/bin/python3.8
import json
import collections


DEFAULT_SIZE = 50


class WebCache(object):
    def __init__(self, size=DEFAULT_SIZE):
        self.data = {}
        self.size = size
        self.lru_list = collections.deque(maxlen=size)
    
    def __contains__(self, url_string):
        '''Checks if url_string is in cache.

        Args:
            url_string (str): string denoting an api endpoint.
        
        Returns:
            bool: True is url_string is in cache, False otherwise.
        '''
        if url_string in self.data:
            return True
        return False
    
    def __getitem__(self, url_string):
        '''Returns cached JSON response. Updates cache to reflect the frequency of api calls.

        Args:
            url_string (str): string denoting the url of an api call.
        
        Returns:
            dict: JSON response data.
        '''
        if url_string in self.data:
            self.lru_list.remove(url_string)
            self.lru_list.append(url_string)
            return self.data[url_string]
        raise KeyError

    def __setitem__(self, url_string, json_response):
        '''Adds new json response data to cache. Removes least popular api call if cache is full.

        Args:
            url_string (str): string denoting the url of an api call.
            json_response (dict): JSON response data to be cached.
        
        Returns:
            None.
        '''
        if len(self.data) > self.size:
            removed_url = self.lru_list.popleft()
            self.data.pop(removed_url)
            self.lru_list.append(url_string)
            self.data[url_string] = json_response
        else:
            self.data[url_string] = json_response
            self.lru_list.append(url_string)
        return None
