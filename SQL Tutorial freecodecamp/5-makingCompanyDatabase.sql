----------------- CREATING THE DATABASE SCHEMA ----------------------------

CREATE TABLE employee (
    emp_id INT PRIMARY KEY,
    first_name VARCHAR(40),
    last_name VARCHAR(40),
    birth_day DATE,
    sex VARCHAR(1),
    salary INT,
    super_id INT,
    branch_id INT
);


CREATE TABLE branch (
    branch_id INT PRIMARY KEY,
    branch_name VARCHAR(40),
    mgr_id INT,
    mgr_start_date DATE,
    FOREIGN KEY(mgr_id) REFERENCES employee(emp_id) ON DELETE SET NULL
);


ALTER TABLE employee
ADD FOREIGN KEY(branch_id)
REFERENCES branch(branch_id)
ON DELETE SET NULL;

ALTER TABLE employee
ADD FOREIGN KEY(super_id)
REFERENCES employee(emp_id)
ON DELETE SET NULL;


CREATE TABLE client (
    client_id INT PRIMARY KEY,
    client_name VARCHAR(40),
    branch_id INT,
    FOREIGN KEY(branch_id) REFERENCES branch(branch_id) ON DELETE SET NULL
);


CREATE TABLE works_with(
    emp_id INT,
    client_id INT,
    total_sales INT,
    PRIMARY KEY(emp_id, client_id),
    FOREIGN KEY(emp_id) REFERENCES employee(emp_id) ON DELETE CASCADE,
    FOREIGN KEY(client_id) REFERENCES client(client_id) ON DELETE CASCADE
);

CREATE TABLE branch_supplier (
    branch_id INT,
    supplier_name VARCHAR(40),
    supply_type VARCHAR(40),
    PRIMARY KEY(branch_id, supplier_name),
    FOREIGN KEY(branch_id) REFERENCES branch(branch_id) ON DELETE CASCADE
);



-------------------POPULATING TABLES -------------------------
--  Corporate Branch
INSERT INTO employee VALUES(100, 'David', 'Wallace', '1967-11-17', 'M', 250000, NULL, NULL);

INSERT INTO branch VALUES(1, 'Corporate', 100, '2006-02-09');

UPDATE employee
SET branch_id = 1
WHERE emp_id = 100;

INSERT INTO employee VALUES(101, 'Jan', 'Levinson', '1961-05-11', 'F', 110000, 100, 1);


--  Scranton Branch
INSERT INTO employee VALUES(102, 'Michael', 'Scott', '1964-03-15', 'M', 75000, 100, NULL);

INSERT INTO branch VALUES(2, 'Scranton', 102, '1992-04-06');

UPDATE employee
SET branch_id = 2
WHERE emp_id = 102;

INSERT INTO employee VALUES(103, 'Angela', 'Martin', '1971-06-25', 'F', 63000, 102, 2);
INSERT INTO employee VALUES(104, 'Kelly', 'Kapoor', '1980-02-05', 'F', 55000, 102, 2);
INSERT INTO employee VALUES(105, 'Stanley', 'Hudson', '1958-02-19', 'M', 69000, 102, 2);

--  Stamford branch
INSERT INTO employee VALUES(106, 'Josh', 'Porter', '1969-09-05', 'M', 78000, 100, NULL);

INSERT INTO branch VALUES(3, 'Stamford', 106, '1998-02-13');

UPDATE employee
SET branch_id = 3
WHERE emp_id = 106;

INSERT INTO employee VALUES(107, 'Andy', 'Bernard', '1973-07-22', 'M', 65000, 106, 3);
INSERT INTO employee VALUES(108, 'Jim', 'Halpert', '1978-10-01', 'M', 71000, 106, 3);


--  Branch Supplier
INSERT INTO branch_supplier VALUES(2, 'Hammer Mill', 'Paper');
INSERT INTO branch_supplier VALUES(2, 'Uni-ball', 'Writing Utensils');
INSERT INTO branch_supplier VALUES(3, 'Patriot Paper', 'Paper');
INSERT INTO branch_supplier VALUES(2, 'J.T. Forms & Labels', 'Custom Forms');
INSERT INTO branch_supplier VALUES(3, 'Uni-ball', 'Writing Utensils');
INSERT INTO branch_supplier VALUES(3, 'Hammer Mill', 'Paper');
INSERT INTO branch_supplier VALUES(3, 'Stamford Lables', 'Custom Forms');


--  client
INSERT INTO client VALUES(400, 'Dunmore Highschool', 2);
INSERT INTO client VALUES(401, 'Lackawana Country', 2);
INSERT INTO client VALUES(402, 'FedEx', 3);
INSERT INTO client VALUES(403, 'John Daily Law, LLC', 3);
INSERT INTO client VALUES(404, 'Scranton Whitepages', 2);
INSERT INTO client VALUES(405, 'Times Newspaper', 3);
INSERT INTO client VALUES(406, 'FedEx', 2);


--  works_with
INSERT INTO works_with VALUES(105, 400, 55000);
INSERT INTO works_with VALUES(102, 401, 267000);
INSERT INTO works_with VALUES(108, 402, 22500);
INSERT INTO works_with VALUES(107, 403, 5000);
INSERT INTO works_with VALUES(108, 403, 12000);
INSERT INTO works_with VALUES(105, 404, 33000);
INSERT INTO works_with VALUES(107, 405, 26000);
INSERT INTO works_with VALUES(102, 406, 15000);
INSERT INTO works_with VALUES(105, 406, 130000);


---------------- MORE BASIC QUERIES --------------------    

-- Find all employees
SELECT *
FROM employee;

-- Find all clients
SELECT *
FROM client;

-- Find all employees ordered by salary
SELECT *
FROM employee
ORDER BY salary;

-- Find all employees ordered by salary
SELECT *
FROM employee
ORDER BY salary DESC;

-- Find all employees ordered by sex then name
SELECT *
FROM employee
ORDER BY sex, first_name, last_name;

-- Find the first 5 employees in the table
SELECT *
FROM employee
LIMIT 5;

-- Find the first and last names of all employees
SELECT first_name, last_name
FROM employee;

-- Find the forename and surnames of all employees
SELECT first_name AS forename, last_name AS surname
FROM employee;

-- Find out all the diferent genders
SELECT DISTINCT sex
FROM employee;



---------------- FUNCTIONS --------------------    

-- Find the number of employees  --- Answer 9
SELECT COUNT(emp_id)
FROM employee;

-- Find the number of employees who have supervisors --- Answer 8
SELECT COUNT(super_id)
FROM employee;

-- Find the number of female employees born after 1970
SELECT COUNT(emp_id)
FROM employee
WHERE sex = 'F' AND birth_day > '1971-01-01';

-- Find the average of all employee's salaries
SELECT AVG(salary)
FROM employee;

-- Find the average of all male employee's salaries
SELECT AVG(salary)
FROM employee
WHERE sex = 'M';

-- Find the sum of all employee's salaries
SELECT SUM(salary)
FROM employee;

-- Find out how many males and females there are -- AGGREGATION
SELECT COUNT(sex), sex
FROM employee
GROUP BY sex;

-- Find the total sales of each salesman -- AGGREGATION
SELECT SUM(total_sales), emp_id
FROM works_with
GROUP BY emp_id;


-- Find the spending of each client -- AGGREGATION
SELECT SUM(total_sales), client_id
FROM works_with
GROUP BY client_id;



---------------- WILDCARDS AND LIKE KEYWORD IN SQL --------------------    

-- % = any no of characters, _ = one character

-- Find any clients who are in LLC
SELECT *
FROM client
WHERE client_name LIKE '%LLC';

-- Find any branch suppliers who are in label business
SELECT *
FROM branch_supplier
WHERE supplier_name LIKE '%Label%';


-- Find any employee born in october
SELECT *
FROM employee
WHERE birth_day LIKE '____-10%';


-- Find all clients who are schools
SELECT *
FROM client
WHERE client_name LIKE '%school%';



---------------- UNION --------------------    

-- For UNION, in each select statement the output should have similar number of columns 
-- and should have same data type (may or maynot work)

-- Find a list of employee and branch names in a single column
SELECT first_name
FROM employee
UNION
SELECT branch_name
FROM branch;

-- Find a list of all names stored in company database
SELECT first_name AS Company_Names
FROM employee
UNION
SELECT branch_name
FROM branch
UNION
SELECT client_name 
FROM client;


-- Find a list of all clients' and branch suppliers' names
SELECT client_name , branch_id
FROM client
UNION
SELECT supplier_name, branch_id
FROM branch_supplier;

-- Find a list of all clients' and branch suppliers' names
SELECT client_name , client.branch_id
FROM client
UNION
SELECT supplier_name, branch_supplier.branch_id
FROM branch_supplier;

-- Find a list of all money spent or earned by company
SELECT salary AS Money
FROM employee
UNION
SELECT total_sales
FROM works_with;


---------------- JOINS --------------------    

-- 4 basic types of join

INSERT INTO branch VALUES(4, 'Buffalo', NULL, NULL);

-- INNER / GENERAL JOIN
-- Find all branches and names of their managers
SELECT employee.emp_id, employee.first_name, branch.branch_name
FROM employee
JOIN branch
ON employee.emp_id = branch.mgr_id;   -- INNER JOIN : Join on the shared column ; only the employees which have are in mgr_id are included in table


-- LEFT JOIN  -- include all rows of left table here employee table
-- Find all branches and names of their managers
SELECT employee.emp_id, employee.first_name, branch.branch_name
FROM employee
LEFT JOIN branch
ON employee.emp_id = branch.mgr_id;    -- All employees got included in the result

-- RIGHT JOIN -- include all rows of right table here branch
-- Find all branches and names of their managers
SELECT employee.emp_id, employee.first_name, branch.branch_name
FROM employee
RIGHT JOIN branch
ON employee.emp_id = branch.mgr_id;

-- FULL OUTER JOIN -- Can't do it in mySQL



---------------- ADVANCED QUERY WRITING --------------------    

---------------- NESTED QUERIES --------------------    

-- Multiple select statements to get specific statement ; results of one select statement inform other select statement

-- Find names of all employee who have sold over 30,000 to a single client
SELECT employee.first_name, employee.last_name
FROM employee
WHERE employee.emp_id IN (
    SELECT works_with.emp_id 
    FROM works_with
    WHERE works_with.total_sales > 30000
);


-- Find all clients who are handled by the branch that
-- Michael Scott manages
-- Assume you know Michael's ID

SELECT client.client_name
FROM client
WHERE client.branch_id = (
    SELECT branch.branch_id
    FROM branch
    WHERE branch.mgr_id = 102
    LIMIT 1
);


---------------- ON DELETE --------------------    

-- Deleting entries in database when they have foreign keys associated to them


-- CREATE TABLE branch (
--     branch_id INT PRIMARY KEY,
--     branch_name VARCHAR(40),
--     mgr_id INT,
--     mgr_start_date DATE,
--     FOREIGN KEY(mgr_id) REFERENCES employee(emp_id) ON DELETE SET NULL  -- If a row is deleted the forign key will be set as NULL
-- );

DELETE FROM employee
WHERE emp_id = 102;  -- In branch table mgr_id will be set to NULL and in emloyee table a lot of super_id is set to NULL



-- CREATE TABLE branch_supplier (
--     branch_id INT,
--     supplier_name VARCHAR(40),
--     supply_type VARCHAR(40),
--     PRIMARY KEY(branch_id, supplier_name),
--     FOREIGN KEY(branch_id) REFERENCES branch(branch_id) ON DELETE CASCADE   -- ON DELETE CASCADE -- deleted the entire row
-- );


DELETE FROM branch
WHERE branch_id = 2;   -- In branch_supplier table the rows with branch_id = 2 gets deleted because branch_id is a part of primary key as well as foreign key



---------------- TRIGGERS --------------------    


CREATE TABLE trigger_test (
    message VARCHAR(100)
);   -- Not important to create a table but doing for tutorial

-- Define triggers on sql command line because we need to change sql delimiter.
DELIMITER $$
CREATE 
    TRIGGER my_trigger BEFORE INSERT
    ON employee
    FOR EACH ROW BEGIN
        INSERT INTO trigger_test VALUES('added new employee');
    END$$
DELIMITER ;

INSERT INTO employee
VALUES (109, 'Oscar', 'Martinez', '1968-02-19', 'M', 69000, 106, 3);   -- This statement triggers our trigger and a statement is added in trigger_test table


DELIMITER $$
CREATE 
    TRIGGER my_trigger1 BEFORE INSERT
    ON employee
    FOR EACH ROW BEGIN
        INSERT INTO trigger_test VALUES(NEW.first_name);
    END$$
DELIMITER ;


INSERT INTO employee
VALUES (110, 'Kevin', 'Malone', '1978-02-19', 'M', 69000, 106, 3);   -- This statement triggers both the above triggers and two rows are inserted in the trigger_test table

DELIMITER $$
CREATE 
    TRIGGER my_trigger2 BEFORE INSERT  -- (AFTER) (DELETE,UPDATE) could be used
    ON employee
    FOR EACH ROW BEGIN
        IF NEW.sex = 'M' THEN
            INSERT INTO trigger_test VALUES('added male employee');
        ELSEIF NEW.sex = 'F' THEN
            INSERT INTO trigger_test VALUES('added female');
        ELSE
            INSERT INTO trigger_test VALUES('added other employee');
        END IF;
    END$$
DELIMITER ;

INSERT INTO employee
VALUES (111, 'Pam', 'Beesly', '1988-02-19', 'F', 69000, 106, 3);   -- This statement triggers all the above 3 triggers and three rows are inserted in the trigger_test table

DROP TRIGGER my_trigger;  -- In terminal write this to delete a trigger


---------------- ER Diagrams Into --------------------    
-- Entity - An object we want to model and store information about
-- Entity Relationship  ; Help in designing Database Schema