#!/usr/local/bin/python3.8


class Student(object):
    '''Class representing a student's weekly academic schedule.
    '''
    def __init__(self, name, id):
        self.name = name
        self.id = id
        self.schedule = set()
    
    @property
    def name(self):
        return self._name
    
    @name.setter
    def name(self, value):
        self._name = value
    
    @property
    def id(self):
        return self._id
    
    @id.setter
    def id(self, value):
        self._id = value
    
    def _valid_time_interval(self, start_time, end_time):
        '''Checks if a new class' time does not end on the following day.

        Args:
            start_time (int): Start of class time in 24-hour format.
            end_time (int): End of class time in 24-hour format.
        
        Returns:
            (bool): True if and only if time interval is within the same day.
        '''
        if end_time <= start_time:
            return False
        return True
    
    def _class_fits_schedule(self, new_class):
        '''Determines if a new class does not conflict with existing classes.

        Args:
            new_class (tuple):
                A 3-tuple representing a class' days, start time, and end time.
        
        Returns:
            True if and only if class is not a duplicate and does not conflict.
        '''
        if new_class in self.schedule:
            return False
        new_days, new_start_time, new_end_time = new_class
        for enrolled_class in self.schedule:
            enrolled_days, enrolled_start_time, enrolled_end_time = enrolled_class
            for day in new_days:
                if day in enrolled_days:
                    if new_start_time in range(
                        enrolled_start_time, enrolled_end_time + 1
                    ):
                        return False
                    if new_end_time in range(
                        enrolled_start_time, enrolled_end_time + 1
                    ):
                        return False
                    
        return True
    
    def add_class(self, days_of_week, start_time, end_time):
        '''Adds a new class to the student's schedule.

        Args:
            days_of_week (string): Non-empty string consisting of at least one
                of these characters: MTWRF.
            start_time (int): Start of class time in 24-hour format.
            end_time (int): End of class time in 24-hour format.
        
        Returns:
            True if and only if the new class is added to the schedule.
        '''
        new_class = (days_of_week, start_time, end_time)
        if not self._valid_time_interval(start_time, end_time):
            return False
        if self._class_fits_schedule(new_class):
            self.schedule.add(new_class)
            return True
        return False
