#! /usr/bin/python3.5
import datetime

import calendar
import constants

CURRENT_YEAR = datetime.datetime.today().year
CURRENT_MONTH = datetime.datetime.today().month
CURRENT_DAY = datetime.datetime.today().day


def is_valid_year(year):
    '''Checks if a given integer represents a valid year.

    Args:
        year (int): An integer representing a year.
    
    Returns:
        bool: True if year is a valid year, False otherwise.
    '''
    if (year < datetime.MINYEAR):
        return False
    if (year > CURRENT_YEAR):
        return False
    return True


def generate_month_day_pairs(year):
    '''Generates a list of pairs representing months and their number of days.

    Args:
        year (int): a 4 digit integer representing a year.
    
    Returns:
        list: a list of 2-tuples integer pairs of months and their number of days.
    '''
    month_day_pairs = []
    for month in range(constants.JANUARY, constants.DECEMBER + 1):
        if month in constants.MONTHS_WITH_30_DAYS:
            month_day_pairs.append((month, 30))
        elif month in constants.MONTHS_WITH_31_DAYS:
            month_day_pairs.append((month, 31))
        elif month == constants.FEBRUARY:
            if calendar.isleap(year):
                month_day_pairs.append((month, 29))
            else:
                month_day_pairs.append((month, 28))
    return month_day_pairs


def get_all_dates(year):
    '''Returns all ISO-format dates in a year

    Args:
        year (int): a 4 digit integer representing a year
    
    Returns:
        list: a list of strings representing ISO-format dates
    '''
    month_day_pairs = generate_month_day_pairs(year)
    dates = []
    for month, days in month_day_pairs:
        for day in range(1, days + 1):
            date = datetime.date(year, month, day).isoformat()
            dates.append(date)
            if year == CURRENT_YEAR:
                todays_date = datetime.date(
                    CURRENT_YEAR, CURRENT_MONTH, CURRENT_DAY).isoformat()
                if date == todays_date:
                    return dates
    return dates