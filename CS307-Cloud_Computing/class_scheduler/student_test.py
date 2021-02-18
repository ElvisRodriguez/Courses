#!/usr/local/bin/python3.8
import unittest

from student import Student

class TestStudent(unittest.TestCase):
    def setUp(self):
        self.name = 'Elvis Rodriguez'
        self.id = 0
        self.valid_class = (
            'MWF', 1300, 1530
        )
        self.invalid_class = (
            'MW', 1400, 1600
        )
        self._student = Student(self.name, self.id)
    
    def test_get_name(self):
        self.assertEqual(self.name, self._student.name)
    
    def test_get_id(self):
        self.assertEqual(self.id, self._student.id)
    
    def test_valid_time_interval(self):
        self.assertTrue(self._student._valid_time_interval(1200, 1400))
        self.assertFalse(self._student._valid_time_interval(1400, 1200))
        self.assertFalse(self._student._valid_time_interval(1200, 1200))
    
    def test_add_valid_class(self):
        self.assertTrue(self._student.add_class(*self.valid_class))
    
    def test_add_invalid_class(self):
        self._student.add_class(*self.valid_class)
        self.assertFalse(self._student.add_class(*self.invalid_class))
    

if __name__ == '__main__':
    unittest.main()