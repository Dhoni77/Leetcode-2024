# Write your MySQL query statement below
WITH
    T AS (
        SELECT team_id, COUNT(1) AS team_size
        FROM Employee
        GROUP BY 1
    )
SELECT employee_id, team_size
FROM
    Employee
    JOIN T USING (team_id);

/*
 MySql

    Approach 1:

        # Write your MySQL query statement below
        SELECT e1.employee_id, COUNT(1) AS team_size
        FROM
            Employee AS e1
            LEFT JOIN Employee AS e2 USING (team_id)
        GROUP BY 1;

    Approach 2:

        -- if we do not use order by in over(), we do not get running total, just normal aggregate for all rows within that partition

        select employee_id, count(*) over(partition by team_id) as team_size
        from Employee
        order by 1
 */