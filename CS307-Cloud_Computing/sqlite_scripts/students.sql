DROP TABLE IF EXISTS students;

CREATE TABLE students (
  name TEXT,
  graduation_year INTEGER,
  major TEXT,
  gpa FLOAT
);

INSERT INTO students VALUES
  ('Walter White', 2021, 'Biology', 3.8),
  ('Tex Avery', 2020, 'Liberal Arts', 2.9),
  ('Stan Marsh', 2022, 'History', 2.5),
  ('Bjarne Stroustrup', 2021, 'Computer Science', 3.6),
  ('Dexter Morgan', 2023, 'Biology', 4.0),
  ('Hubert J. Farnsworth', 2021, 'Math', 4.0),
  ('Guido Van Rossum', 2021, 'Computer Science', 3.9);

.print 'Students graduating in 2021:'
.print

SELECT name
FROM students
WHERE graduation_year = 2021
ORDER BY name;

.print

.print 'Average GPA across all students:'

SELECT avg(gpa)
FROM students;

.print

.print 'Students with an above average gpa:'
.print

SELECT name, gpa
FROM students
WHERE gpa >= (
  SELECT avg(gpa)
  FROM students
  )
ORDER BY gpa;

