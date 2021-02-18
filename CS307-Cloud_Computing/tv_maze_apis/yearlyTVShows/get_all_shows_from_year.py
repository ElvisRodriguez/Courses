#! /usr/bin/python3.5
import operator
import requests
import sys

import constants
import dates


def get_all_shows(year):
    '''Retrieves a list of all tv shows that aired in the US in a given year.

    Args:
        year (int): an integer representing a valid year.
    
    Returns:
        dict: a list of tv show names and the number of days they aired during the year.
    '''
    all_shows = {}
    all_dates = dates.get_all_dates(year)
    for date in all_dates:
        print('Retrieving shows from {}...'.format(date))
        request = requests.get(constants.URL.format(date))
        if request.status_code == constants.OK:
            for tv_show in request.json():
                show_name = tv_show['show']['name']
                if show_name in all_shows:
                    all_shows[show_name] += 1
                else:
                    all_shows[show_name] = 1
    return all_shows


def sort_tv_shows_by_days_aired(tv_shows):
    '''Sorts a list of tv shows from most days aired to least.

    Args:
        tv_shows (dict): A list of tv show names and the number of days ther aired in a year.
    
    Returns:
        list: a sorted list of 2-tuples representing tv shows and days aired.
    '''
    sorted_tv_shows = sorted(tv_shows.items(), key=lambda item: item[1], reverse=True)
    return sorted_tv_shows


def display_tv_show_stats(tv_shows, year):
    '''Prints a list of tv shows in order of most days aired.

    Args:
        tv_shows (list): A sorted list of 2-tuples representing tv shows and days aired.
        year (int): an integer representing a valid year.
    
    Returns:
        None.
    '''
    for tv_show, days_aired in tv_shows:
        print('{tv_show}: Aired for {days_aired} days during {year}'.format(
            tv_show=tv_show, days_aired=days_aired, year=year
        ))


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print('A year is requried')
        sys.exit()
    year = int(sys.argv[1])
    if not dates.is_valid_year(year):
        print('Invalid year entered')
        sys.exit()
    all_shows = get_all_shows(year)
    sorted_tv_shows = sort_tv_shows_by_days_aired(all_shows)
    display_tv_show_stats(sorted_tv_shows, year)