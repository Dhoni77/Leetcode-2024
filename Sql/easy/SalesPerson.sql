select s.name
from salesPerson as s
where s.sales_id not in
(select o.sales_id from orders as o
left join company as c
on o.com_id=c.com_id
where name='RED')

/*
 MySql

 Approach 1:

    SELECT SalesPerson.name
FROM Orders
INNER JOIN Company
  ON (Orders.com_id = Company.com_id AND Company.name = 'RED')
RIGHT JOIN SalesPerson
  USING (sales_id)
WHERE Orders.sales_id IS NULL;

 Approach 2:
    Solution 1: LEFT JOIN + GROUP BY
We can use a left join to join the SalesPerson table with the Orders table on the condition of sales id, and then join the result with the Company table on the condition of company id. After that, we can group by sales_id and count the number of orders with the company name RED. Finally, we can filter out the salespersons who do not have any orders with the company name RED.


MySQL

# Write your MySQL query statement below
SELECT s.name
FROM
    SalesPerson AS s
    LEFT JOIN Orders USING (sales_id)
    LEFT JOIN Company AS c USING (com_id)
GROUP BY sales_id
HAVING IFNULL(SUM(c.name = 'RED'), 0) = 0;
 */