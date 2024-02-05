-- Write your PostgreSQL query statement below

select o.customer_number from orders o
group by o.customer_number
order by count(o.order_number) desc
LIMIT 1

/*
 with orders_count as (
    select customer_number, count(customer_number) order_cnt from orders
    group by customer_number
    order by order_cnt desc limit 1
)
select customer_number from orders_count
 */

/*
 MySql

    Approach 1:

        SELECT customer_number
        FROM Orders
        GROUP BY 1
        ORDER BY COUNT(*) DESC
        LIMIT 1;
 */