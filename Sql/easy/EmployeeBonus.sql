select name, bonus from employee left join bonus using(empId)
where bonus < 1000 or bonus is null;

/*
 Mysql

 Approach 1:

     SELECT
        Employee.name, Bonus.bonus
    FROM
        Employee
            LEFT JOIN
        Bonus ON Employee.empid = Bonus.empid
    WHERE
        bonus < 1000 OR bonus IS NULL
    ;

 Approach 2:

    select e.name, b.bonus
    from Employee e
    left join Bonus b
    on e.empId = b.empId
    where ifnull(b.bonus, 0) < 1000

 Approach 3:

    SELECT name, bonus
    FROM Employee LEFT JOIN Bonus USING(empId)
    WHERE COALESCE(bonus, 0) < 1000;
 */