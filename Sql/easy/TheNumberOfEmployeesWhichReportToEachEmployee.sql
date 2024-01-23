-- Write your PostgreSQL query statement below
SELECT
    e1.employee_id,
    e1.name,
    COUNT(e2.employee_id) AS reports_count,
    ROUND(AVG(e2.age)) AS average_age
FROM
    Employees e1
JOIN
    Employees e2 ON e1.employee_id = e2.reports_to
GROUP BY
    e1.employee_id, e1.name
HAVING
    COUNT(e2.reports_to) >= 1
ORDER BY
    e1.employee_id;


/*
 MySql

 Approach 1:

    select e1.employee_id,
        e1.name,
        count(e2.reports_to) reports_count,
        round(avg(e2.age))   average_age
        from employees e1
                 left join employees e2
                           on e1.employee_id = e2.reports_to
        group by e1.employee_id, e1.name
        having reports_count > 0
        order by e1.employee_id

 Approach 2:

    select mgr.employee_id, mgr.name, COUNT(emp.employee_id) as reports_count, ROUND(AVG(emp.age)) as average_age
    from employees emp join employees mgr
    on emp.reports_to = mgr.employee_id
    group by employee_id
    order by employee_id
 */