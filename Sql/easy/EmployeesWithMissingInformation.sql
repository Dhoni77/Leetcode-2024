/*
 We can first find all employee_id that are not in the Salaries table from the Employees table, and
 then find all employee_id that are not in the Employees table from the Salaries table.
 Finally, we can combine the two results using the UNION operator, and sort the result by employee_id
 */

SELECT employee_id from Employees e WHERE employee_id not in (Select employee_id from Salaries)
UNION
SELECT employee_id from Salaries s WHERE employee_id not in (Select employee_id from Employees)
ORDER BY employee_id;

/*
 MySql

    Approach 1:

        # Write your MySQL query statement below
        WITH CTE AS (
        SELECT EMPLOYEE_ID FROM Employees
        UNION ALL
        SELECT EMPLOYEE_ID FROM Salaries
        )
        SELECT EMPLOYEE_ID
        FROM CTE
        GROUP BY EMPLOYEE_ID
        HAVING COUNT(EMPLOYEE_ID) != 2
        ORDER BY EMPLOYEE_ID

    Approach 2:

        SELECT Employees.employee_id
        FROM Employees
        LEFT JOIN Salaries
          USING (employee_id)
        WHERE Salaries.salary IS NULL
        UNION ALL
        SELECT Salaries.employee_id
        FROM Salaries
        LEFT JOIN Employees
          USING (employee_id)
        WHERE Employees.name IS NULL
        ORDER BY 1;
 */