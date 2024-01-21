

-- Write your PostgreSQL query statement below
SELECT EmployeeUNI.unique_id, Employees.name FROM Employees LEFT JOIN EmployeeUNI ON EmployeeUNI.id = Employees.id;

/*
SELECT eu.unique_id , e.name FROM
Employees e  LEFT JOIN EmployeeUNI eu
USING(id)
 */