-- -- DATA TYPES IN MYSQL

-- INT                 -- Whole Number
-- DECIMAL(M,N)        -- Decimal Numbers - Exact Value
-- VARCHAR(1)          -- String of text of lemgth 1
-- BLOB                -- Binary Large Object, Stores large data
-- DATA                -- 'YYYY-MM-DD'
-- TIMESTAMP           -- 'YYYY-MM-DD HH:MM:SS'  - used for recording

-- Convenetion : Write sql reserved words in capitals

-- Database Schema (Table) we use for the tutorial

--       -----------------------------------------------------
--       | student_id |     name       |    major            |
--       -----------------------------------------------------
--       |     1      |     Jack       |   Biology           |
--       |     2      |     Kate       |   Sociology         |
--       |     3      |    Claire      |   Chemistry         |
--       |     4      |     Jack       |   Biology           |
--       |     5      |     Mike       |   Computer Science  |
--       -----------------------------------------------------




---- CREATING A TABLE ----


-- CREATE TABLE student (
--     student_id INT PRIMARY KEY,
--     name VARCHAR(20),
--     major VARCHAR(20)
-- );

-- DESCRIBE student;                                          -- Describe Table

-- DROP TABLE student;                                        -- Deleting the table

-- ALTER TABLE student ADD gpa DECIMAL(3,2);                  -- Add column and alter the table

-- ALTER TABLE student DROP COLUMN gpa;                       -- Remove column and alter the table



---- INSERTING DATA INTO TABLES ----


CREATE TABLE student (
    student_id INT,
    name VARCHAR(20),
    major VARCHAR(20),
    PRIMARY KEY(student_id)                                   -- Primary can be specified separately here as well
);
SELECT * FROM student;

INSERT INTO student VALUES(1, 'Jack', 'Biology');          -- Make entry in the table
INSERT INTO student VALUES(2, 'Kate', 'Sociology');        -- Make another entry in the table 
INSERT INTO student(student_id, name) VALUES(3, 'Claire');    -- Make entry if one or more values unknown
-- INSERT INTO student(student_id, name) VALUES(3, 'Claire');    -- Error: Duplicate entries not allowed for primary key
-- INSERT INTO student(student_id, name) VALUES(4, 'Claire');    -- Can insert duplicate entries if primary key is different
INSERT INTO student VALUES(4, 'Jack', 'Biology');    
INSERT INTO student VALUES(5, 'Mike', 'Computer Science');


---- CONSTRAITS ----


CREATE TABLE student (
    student_id INT,
    name VARCHAR(20) NOT NULL,                                -- NOT NULL : Ensures that Column name cannot be NULL
    major VARCHAR(20) UNIQUE,                                 -- UNIQUE : Ensures that Column entry major must be unique, hence reject duplicate entries 
    -- major VARCHAR(20) DEFAULT 'undecided',                 -- DEFAULT 'undecided' : Sets a default value for the column if value not entered
    PRIMARY KEY(student_id)
);
SELECT * FROM student;

INSERT INTO student VALUES(1, 'Jack', 'Biology');          
INSERT INTO student VALUES(2, 'Kate', 'Sociology');        
INSERT INTO student VALUES(3, NULL, 'Chemistry');             -- Throws Error : name column cannot be NULL
INSERT INTO student VALUES(4, 'Jack', 'Biology');             -- Throws Error : DUplicate entry for column major not allowed
INSERT INTO student VALUES(5, 'Mike', 'Computer Science'); 


-- Example of AUTO_INCREMENT --

CREATE TABLE student (
    student_id INT AUTO_INCREMENT,
    name VARCHAR(20),
    major VARCHAR(20),
    PRIMARY KEY(student_id)
);
SELECT * FROM student;

INSERT INTO student(name, major) VALUES('Jack', 'Biology'); 
INSERT INTO student(name, major) VALUES('Kate', 'Sociology');


---- UPDATE AND DELETE ----

UPDATE student
SET major = 'Bio'
WHERE major = 'Biology';


UPDATE student
SET major = 'Comp Sci'
WHERE student_id = 4;


UPDATE student 
SET name = 'Tom', major = 'undecided'
WHERE student_id = 1;


UPDATE student
SET major = 'undecided';       -- SETs for all rows


DELETE FROM student;           -- DELETEs everything


DELETE FROM student            
WHERE student_id = '5';


DELETE FROM student
WHERE name = 'Tom' AND major = 'undecided';


---- BASIC QUERIES ----

SELECT name
FROM student;


SELECT name, major
FROM student;


SELECT student.name, student.major
FROM student;


SELECT student.name, student.major
FROM student
ORDER BY name;


SELECT student.name, student.major
FROM student
ORDER BY name DESC;


SELECT *
FROM student
ORDER BY student_id ASC;


SELECT *
FROM student
ORDER BY major, student_id;


SELECT *
FROM student
ORDER BY major, student_id DESC;


SELECT *
FROM student
ORDER BY major, student_id DESC
LIMIT 2;


SELECT *
FROM student
LIMIT 2;


SELECT *
FROM student
WHERE major = 'Biology';


SELECT name, major
FROM student
WHERE major = 'Chemistry' OR name = 'Kate';

-- <, >, <=, >=, =, <>, AND, OR

SELECT name, major
FROM student
WHERE major <> 'Chemistry';


SELECT *
FROM student
WHERE student_id <= 3 AND name <> 'Jack';

SELECT *
FROM student
WHERE name IN ('Claire','Kate','Mike');


SELECT *
FROM student
WHERE major IN ('Biology','Chemistry') AND student_id > 2;