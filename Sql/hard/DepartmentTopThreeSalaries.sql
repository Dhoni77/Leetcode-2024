-- Write your PostgreSQL query statement below
select department, employee, salary from  (
select d.name as department, e.name as employee, salary,
dense_rank() over(partition by d.id order by salary desc) as rn
from employee e inner join department d
on e.departmentid=d.id) ranking_table
where rn <= 3;

/*
 MySql

 Approach 1:

    Approach 1: Return the First n Rows Using Correlated Subquery
Algorithm

We can build a correlated subquery to identify the top N records from more than one category. Since the correlated subquery is dependent on the main query, the idea behind this approach is to compare the values between the main query and the subquery, so that in the subquery, at most N-1 salaries can be greater than each selected salary from the main query.

To do this, we first build the main query. In the main query, we can also join the table Employee to the table Department on departmentId to get the name of the departments and rename the columns as requested by the final output.

SELECT d.name AS 'Department',
       e1.name AS 'Employee',
       e1.salary AS 'Salary'
FROM Employee e1
JOIN Department d
ON e1.departmentId = d.id
In the correlated subquery, we select the number of salaries from the same table Employee. To compare the salaries between the main query and the subquery, we make sure the department is the same from both queries, but the salary from the subquery is always bigger than the salary from the main query.

(
    SELECT COUNT(DISTINCT e2.salary)
    FROM Employee e2
    WHERE e2.salary > e1.salary AND e1.departmentId = e2.departmentId
)
Since we need to identify the top three high earners in the main query, and the subquery always has larger salaries than the salaries from the main query, the maximum count of the larger salaries in the subquery is two. We add this criteria as a filter to the main query.

Implementation
SELECT d.name AS 'Department',
       e1.name AS 'Employee',
       e1.salary AS 'Salary'
FROM Employee e1
JOIN Department d
ON e1.departmentId = d.id
WHERE
    3 > (SELECT COUNT(DISTINCT e2.salary)
        FROM Employee e2
        WHERE e2.salary > e1.salary AND e1.departmentId = e2.departmentId);

    Approach 2:

        Approach 2: Return the First n Rows Using DENSE_RANK()
Algorithm

Unlike the previous approach that utilized a correlated subquery, in this approach, we sorted the salaries in descending order, ranked employees based on their salaries within the department, and selected only the first 3 employees for the final output.

We first create a subquery or CTE to rank the employees. Since the definition of a high earner is the employee who has a salary in the top three unique salaries for the department, we can use the function DENSE_RANK() to avoid the scenario that employees from the same department make the same amount of salary. In this step, we can also join the table Department on departmentId to get the name of the departments and rename the columns for the final output.

WITH employee_department AS
    (
    SELECT d.id,
        d.name AS Department,
        salary AS Salary,
        e.name AS Employee,
        DENSE_RANK()OVER(PARTITION BY d.id ORDER BY salary DESC) AS rnk
    FROM Department d
    JOIN Employee e
    ON d.id = e.departmentId
    )
Now, each employee has a rank based on the salary in a descending order for each department.

id	Department	Salary	Employee	rnk
1	IT	90000	Max	1
1	IT	85000	Joe	2
1	IT	85000	Randy	2
1	IT	70000	Will	3
1	IT	69000	Janet	4
2	Sales	80000	Henry	1
2	Sales	60000	Sam	2
With the rank, we can select the high earners. We can add the filter to select employees that have a rank smaller than or equal to 3 in the main query.

SELECT Department, Employee, Salary
FROM employee_department
WHERE rnk <= 3
Implementation
WITH employee_department AS
    (
    SELECT d.id,
        d.name AS Department,
        salary AS Salary,
        e.name AS Employee,
        DENSE_RANK()OVER(PARTITION BY d.id ORDER BY salary DESC) AS rnk
    FROM Department d
    JOIN Employee e
    ON d.id = e.departmentId
    )
SELECT Department, Employee, Salary
FROM employee_department
WHERE rnk <= 3
 */