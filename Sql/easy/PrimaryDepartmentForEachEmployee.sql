select employee_id , min(department_id) as department_id
from employeee
group by employee_id
having count(department_id) = 1
union
select employee_id , department_id
from employeee
where primary_flag = 'Y'

/*

SELECT
    e.employee_id,
    e.department_id
FROM
    employee e
WHERE
    e.primary_flag = 'Y'
    OR e.employee_id IN (
        SELECT
            employee_id
        FROM
            employee
        GROUP BY
            employee_id
        HAVING
            COUNT(DISTINCT department_id) = 1
    );
 */


/*
 MySql

 Approach 1: UNION
Intuition
The UNION approach combines two distinct sets of logic using the UNION operator. Here's the intuition behind each part:

Step 1 - Retrieving employees with primary_flag set to 'Y':

SELECT
  employee_id,
  department_id
FROM
  Employee
WHERE
  primary_flag = 'Y'
This part selects those employees that have been explicitly marked as having a particular department as their primary.
For employees who belong to multiple departments, one of those departments will have the primary_flag set to 'Y', which denotes it as the primary department.
The SQL code fetches employee_id and department_id where primary_flag is 'Y'.
Step 2 - Retrieving employees that appear exactly once in the Employee table:

SELECT
  employee_id,
  department_id
FROM
  Employee
GROUP BY
  employee_id
HAVING
  COUNT(employee_id) = 1
The objective here is to capture employees who are associated with only one department. In such cases, that single department is automatically their primary department.
The code groups the records in the Employee table by employee_id using GROUP BY. For each employee ID, it then checks the count of associated rows (or departments).
The HAVING clause filters out groups where the count of rows (i.e., departments) for that employee is not equal to 1.
This way, only those employees who are associated with a single department are selected.
Step 3 - Combining both results with UNION:

SELECT
  employee_id,
  department_id
FROM
  Employee
WHERE
  primary_flag = 'Y'
UNION
SELECT
  employee_id,
  department_id
FROM
  Employee
GROUP BY
  employee_id
HAVING
  COUNT(employee_id) = 1;
UNION is an SQL operator that combines the results of two SELECT statements into a single set of rows. It automatically removes duplicates.
Here, it's used to merge the results from the two aforementioned logics: those with primary_flag = 'Y' and those appearing only once in the table.
The final output is a unified list containing the primary department for each employee.
In essence, the SQL code ensures that for every employee, either their explicitly marked primary department is selected, or if they belong to only one department, that department is picked as the primary.

Implementation
Based on the understanding above, the solution can be implemented as:

-- Retrieving employees with primary_flag set to 'Y'
        SELECT
          employee_id,
          department_id
        FROM
          Employee
        WHERE
          primary_flag = 'Y'
        UNION
        -- Retrieving employees that appear exactly once in the Employee table
        SELECT
          employee_id,
          department_id
        FROM
          Employee
        GROUP BY
          employee_id
        HAVING
          COUNT(employee_id) = 1;

Approach 2: Window Function (COUNT)
Intuition
This approach uses an advanced SQL feature called window functions, specifically COUNT() OVER(). Here's the intuition for each step:

Step 1 - Inner Query with Window Function:

SELECT
  *,
  COUNT(employee_id) OVER(PARTITION BY employee_id) AS EmployeeCount
FROM
  Employee
This query fetches all columns from the Employee table and adds a new computed column, EmployeeCount.
COUNT(employee_id) OVER(PARTITION BY employee_id) is a window function. Let's break down what it does:
PARTITION BY employee_id: This breaks down the data into 'windows' or 'partitions' of rows that have the same employee_id. Each window is essentially a subset of the data for a specific employee.
COUNT(employee_id) OVER(...): This counts the number of rows (i.e., the number of departments) for each employee within their respective partition/window. The result is a new column, EmployeeCount, which tells us how many departments each employee is associated with. This count is repeated for every row of the same employee.
Step 2 - Alias & Outer Query:

SELECT
  employee_id,
  department_id
FROM
  EmployeePartition
The inner query result is treated as a temporary table named EmployeePartition.
From this table, we select the desired columns: employee_id and department_id.
Step 3 - Filtering with WHERE Clause:

WHERE
  EmployeeCount = 1
  OR primary_flag = 'Y'
We have two conditions to filter out the primary department for each employee:
EmployeeCount = 1: This captures those employees who belong to only one department. For them, that single department is automatically their primary department.
primary_flag = 'Y': This captures employees who belong to multiple departments but have one department explicitly marked as primary with a flag 'Y'.
The OR operator is used, so any row satisfying either of the above conditions is included in the result.
Summary:
The code first assigns an employee department count to each row using a window function. It then filters out the desired rows based on whether an employee is associated with just one department or has a department explicitly flagged as primary. The end result is a list of primary departments for each employee.

Implementation
Based on the understanding above, the solution can be implemented as:

    SELECT
      employee_id,
      department_id
    FROM
      (
        SELECT
          *,
          COUNT(employee_id) OVER(PARTITION BY employee_id) AS EmployeeCount
        FROM
          Employee
      ) EmployeePartition
    WHERE
      EmployeeCount = 1
      OR primary_flag = 'Y';
 */