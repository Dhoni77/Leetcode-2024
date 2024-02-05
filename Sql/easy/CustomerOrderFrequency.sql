# Write your MySQL query statement below
SELECT customer_id, name
FROM
    Orders
    JOIN Product USING (product_id)
    JOIN Customers USING (customer_id)
WHERE YEAR(order_date) = 2020
GROUP BY 1
HAVING
    SUM(IF(MONTH(order_date) = 6, quantity * price, 0)) >= 100
    AND SUM(IF(MONTH(order_date) = 7, quantity * price, 0)) >= 100;

/*
 MySql

    Approach 1:

      SELECT
      Customers.customer_id,
      Customers.name
    FROM Customers
    INNER JOIN Orders
      USING (customer_id)
    INNER JOIN Product
      USING (product_id)
    GROUP BY 1
    HAVING
      SUM(
        IF(
          DATE_FORMAT(Orders.order_date, '%Y-%m') = '2020-06',
          Orders.quantity * price,
          0
        )
      ) >= 100
      AND SUM(
        IF(
          DATE_FORMAT(Orders.order_date, '%Y-%m') = '2020-07',
          Orders.quantity * price,
          0
        )
      ) >= 100;

    Approach 2:

        -- create a temp table- join all tables
        -- create 2 additional columns- expenditure in June and in July- CASE, AGGREGATE
        -- in the main query, pull customer ids where expenditure in both columns are >= 100

        with CTE as(select c.customer_id, c.name,
            sum(case when left(o.order_date, 7) = '2020-06' then p.price*o.quantity else 0 end) june_spent,
            sum(case when left(o.order_date, 7) = '2020-07' then p.price*o.quantity else 0 end) july_spent
        from Customers c
        join Orders o
        on c.customer_id = o.customer_id
        join Product p
        on p.product_id = o.product_id
        group by 1)

        select customer_id, name
        from CTE
        where june_spent >= 100 and july_spent >= 100

        Approach 3:

            -- we need customer ids from 2 separate tables using 'and' condition
            -- 1st table- get sum of expenditures of all customers in June 2020, filter by customers whose sum >= 100
            -- 2nd table- get sum of expenditures of all customers in July 2020, filter by customers whose sum >= 100
            -- pull all customers who are in table1 AND table 2

            select c.customer_id, c.name
            from Customers
            where customer_id in
                (select customer_id
                from Orders o
                join Product p
                on o.product_id = p.product_id
                where left(order_date, 7) = '2020-06'
                group by customer_id
                having sum(quantity*price) >= 100)
             and customer_id in
                (select customer_id, sum(quantity*price)
                from Orders o
                join Product p
                on o.product_id = p.product_id
                where left(order_date, 7) = '2020-07'
                group by customer_id
                having sum(quantity*price) >= 100)
 */