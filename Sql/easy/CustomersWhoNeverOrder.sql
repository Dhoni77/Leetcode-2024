-- Write your PostgreSQL query statement below
select name as Customers from Customers
full outer join Orders
on Customers.id=Orders.customerId
where customerId is null

/*
 -- Write your PostgreSQL query statement below
select
    name as Customers
from
    Customers as c
    left join OrderS as o on c.id = o.customerId
where
    o.customerId is NULL
;
 */

/*
MySql

Approach 1:

    select name as Customers from customers
    where id not in (select customerId from orders)
 */