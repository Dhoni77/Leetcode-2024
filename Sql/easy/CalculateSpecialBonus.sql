-- Write your PostgreSQL query statement below
SELECT employee_id,
CASE WHEN employee_id%2 <> 0 AND name not like 'M%' THEN salary
ELSE 0
END as bonus
FROM Employees
ORDER BY employee_id;

/*
MySql

    Approach 1:

      SELECT
      employee_id,
      IF(employee_id % 2 = 1 AND LEFT(name, 1) != 'M', salary, 0) AS bonus
      FROM Employees
      ORDER BY 1;
 */