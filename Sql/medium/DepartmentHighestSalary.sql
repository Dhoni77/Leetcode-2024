# Write your MySQL query statement below
select name1 as Department, name2 as Employee, salary as Salary
from (
select b.name as name1, a.name as name2, a.salary, dense_rank() over (partition by a.departmentId order by a.salary desc) as rnk
from Employee a
join Department b
on a.departmentId = b.id
) as tab
where rnk = 1

/*
 MySql

    Approach 1:

        # Write your MySQL query statement below
        SELECT d.name AS department, e.name AS employee, salary
        FROM
            Employee AS e
            JOIN Department AS d ON e.departmentId = d.id
        WHERE
            (d.id, salary) IN (
                SELECT departmentId, MAX(salary)
                FROM Employee
                GROUP BY 1
            );

    Approach 2:

        # Write your MySQL query statement below
        WITH
            T AS (
                SELECT
                    d.name AS department,
                    e.name AS employee,
                    salary,
                    RANK() OVER (
                        PARTITION BY d.name
                        ORDER BY salary DESC
                    ) AS rk
                FROM
                    Employee AS e
                    JOIN Department AS d ON e.departmentId = d.id
            )
        SELECT department, employee, salary
        FROM T
        WHERE rk = 1;
 */