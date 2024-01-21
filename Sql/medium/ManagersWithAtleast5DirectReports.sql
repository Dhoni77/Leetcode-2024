/*
     -- Write your PostgreSQL query statement below
    select name from employee
    where id = any (select distinct managerid from employee
    group by (managerid)
    having count(*) >= 5)
 */


-- Write your PostgreSQL query statement below

with bosses as (
  select managerId from employee
  group by managerId
  having count(managerId) >= 5
)
select name from employee
 join bosses on (bosses.managerId = employee.id)

/*
 MySql

 Approach 1: Using SubQuery

    SELECT name
    FROM Employee
    WHERE id IN (
        SELECT managerId
        FROM Employee
        GROUP BY managerId
        HAVING COUNT(*) >= 5)

 Approach 2: Using Join

    SELECT e2.name
    from Employee e1
    INNER JOIN Employee e2
    ON e1.managerId = e2.id
    GROUP BY e1.managerId
    HAVING COUNT(e1.id) >= 5
 */