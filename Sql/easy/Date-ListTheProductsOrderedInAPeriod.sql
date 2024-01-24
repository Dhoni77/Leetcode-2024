with cte1 as
(select p.product_name product_name, o.order_date order_date, o.unit unit
from products p join orders o on p.product_id = o.product_id)
select product_name, sum(unit) unit
from cte1
where extract(year from order_date) = 2020 and extract(month from order_date) = 02
group by product_name
having sum(unit) >= 100

/*
 -- Write your PostgreSQL query statement below
SELECT p.product_name, SUM(o.unit) AS unit
FROM products p
LEFT JOIN orders o ON p.product_id = o.product_id
WHERE o.order_date BETWEEN '2020-02-01' AND '2020-02-29'
GROUP BY p.product_name
HAVING SUM(o.unit) >= 100;
 */


/*
MySql

    Approach 1:

        # Write your MySQL query statement below
        select p.product_name, sum(o.unit) as unit from products p
        left join orders o
        on p.product_id = o.product_id
        where date_format(o.order_date, '%Y-%m') = '2020-02'
        group by o.product_id
        having unit >= 100

    Approach 2:

        # Write your MySQL query statement below
        SELECT p.product_name AS product_name , SUM(o.unit) As unit
        FROM Products p
        INNER JOIN Orders o
        ON P.product_id = o.product_id
        WHERE order_date BETWEEN '2020-02-01' AND '2020-02-29'
        GROUP BY product_name
        HAVING SUM(o.unit) >= 100

    Approach 3:

        # Write your MySQL query statement below
        with cte as(select product_id, sum(unit) as unit
            from Orders
            where YEAR(order_date)=2020
            and MONTH(order_date)=2
            group by product_id)

        select product_name, unit from Products ,cte
            where Products.product_id=cte.product_id
            and unit>=100;

    Approach 4:

        select p.product_name, sum(o.unit) as unit from products p
        left join orders o
        on p.product_id = o.product_id
        where date_format(o.order_date, '%Y-%m') = '2020-02'
        group by o.product_id
        having unit >= 100
*/