#!/usr/local/bin/python3.8
import random
import unittest

from class_scheduler import ClassScheduler


class TestClassScheduler(unittest.TestCase):
    def setUp(self):
        self.students = (
            'Guido van Rossum', 'Linus Torvalds', 'Tim Berners-Lee',
            'Ray Tomlinson', 'Alan Turing'
        )
        self.classes = {
            'valid class A': ('MWF', 1815, 2030), # 2:15 * 3 = 6:45
            'valid class B': ('TR', 1815, 2030), # 2:15 * 2 = 4:30
            'valid class C': ('MWF', 1530, 1730), # 2 * 3 = 6
            'invalid class': ('MWTRF', 1530, 2030)
        }
        self.scheduler = ClassScheduler()
        # Total (valid) class time: 17 hours and 15 minutes
        self.total_class_hours = 17
    
    def test_add_student(self):
        for correct_id, student_name in enumerate(self.students):
            self.assertEqual(
                self.scheduler.add_student(student_name), correct_id + 1
            )
    
    def test_add_class(self):
        student_name = random.choice(self.students)
        student_id = self.scheduler.add_student(student_name)
        self.assertIsNone(
            self.scheduler.add_class(
                student_id, *self.classes['valid class A']
            )
        )
    
    def test_add_valid_same_day_class(self):
        student_name = random.choice(self.students)
        student_id = self.scheduler.add_student(student_name)
        self.assertIsNone(
            self.scheduler.add_class(
                student_id, *self.classes['valid class A']
            )
        )
        self.assertIsNone(
            self.scheduler.add_class(
                student_id, *self.classes['valid class C']
            )
        )
    
    def test_add_invalid_class(self):
        student_name = random.choice(self.students)
        student_id = self.scheduler.add_student(student_name)
        self.assertIsNone(
            self.scheduler.add_class(
                student_id, *self.classes['valid class A']
            )
        )
        with self.assertRaises(KeyError):
            self.scheduler.add_class(
                student_id, *self.classes['invalid class']
            )
    
    def test_add_duplicate_class(self):
        student_name = random.choice(self.students)
        student_id = self.scheduler.add_student(student_name)
        self.assertIsNone(
            self.scheduler.add_class(
                student_id, *self.classes['valid class A']
            )
        )
        with self.assertRaises(KeyError):
            self.scheduler.add_class(
                student_id, *self.classes['valid class A']
            )
    
    def test_total_class_time_with_no_classes(self):
        student_name = random.choice(self.students)
        student_id = self.scheduler.add_student(student_name)
        self.assertEqual(
            self.scheduler.total_class_time(student_id), 0
        )
    
    def test_total_class_time_with_all_valid_classes(self):
        student_name = random.choice(self.students)
        student_id = self.scheduler.add_student(student_name)
        for valid_class in self.classes:
            if valid_class != 'invalid class':
                self.scheduler.add_class(
                    student_id, *self.classes[valid_class]
                )
        self.assertEqual(
            self.scheduler.total_class_time(student_id),
            self.total_class_hours
        )



if __name__ == '__main__':
    unittest.main()