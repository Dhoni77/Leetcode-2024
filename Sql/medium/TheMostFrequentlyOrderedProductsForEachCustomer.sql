-- first create cte1 with count
-- then cte2 with rank using that count
-- then fetch rows with rnk = 1, join for product name

with cte1 as
    (select customer_id, product_id, count(product_id) as count_product
    from Orders
    group by customer_id, product_id),
    cte2 as
    (select customer_id, product_id,
        dense_rank() over(partition by customer_id  order by count_product desc) as rnk
    from cte1)

select c.customer_id, c.product_id, p.product_name
from cte2 c
join Products p
on p.product_id = c.product_id
where rnk = 1

 /*
  MySql

    Approach 1:

            We group the Orders table by customer_id and product_id, and then use the window function rank(),
            which assigns a rank to each product_id in each customer_id group based on its frequency
            in descending order. Finally, we select the product_id with a rank of 1
            for each customer_id, which is the most frequently ordered product for that customer_id.

            # Write your MySQL query statement below
            WITH
                T AS (
                    SELECT
                        customer_id,
                        product_id,
                        RANK() OVER (
                            PARTITION BY customer_id
                            ORDER BY COUNT(1) DESC
                        ) AS rk
                    FROM Orders
                    GROUP BY 1, 2
                )
            SELECT customer_id, product_id, product_name
            FROM
                T
                JOIN Products USING (product_id)
            WHERE rk = 1;

    Approach 2:

                WITH
          RankedOrders AS (
            SELECT
              Orders.customer_id,
              Orders.product_id,
              Products.product_name,
              RANK() OVER(
                PARTITION BY Orders.customer_id
                ORDER BY COUNT(Orders.product_id) DESC
              ) AS `rank`
            FROM Orders
            INNER JOIN Products
              USING (product_id)
            GROUP BY 1, 2
          )
        SELECT
          customer_id,
          product_id,
          product_name
        FROM RankedOrders
        WHERE `rank` = 1;
  */