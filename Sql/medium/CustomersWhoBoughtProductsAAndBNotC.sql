# Write your MySQL query statement below
SELECT customer_id, customer_name
FROM
    Customers
    LEFT JOIN Orders USING (customer_id)
GROUP BY 1
HAVING SUM(product_name = 'A') > 0 AND SUM(product_name = 'B') > 0 AND SUM(product_name = 'C') = 0
ORDER BY 1;

/*
 Mysql

 Approach 1:

    select o.customer_id, c.customer_name
    from
        (select order_id, customer_id,
        sum(case when product_name='A' then 1 else 0 end) as A,
        sum(case when product_name='B' then 1 else 0 end) as B,
        sum(case when product_name='C' then 1 else 0 end) as C
        from Orders
        group by customer_id) o
    left join Customers c
    on c.customer_id = o.customer_id
    where A > 0 and B > 0 and C = 0
    order by 1

    Approach 2:

        -- group_concat() approach- unique approach- my first thought
        -- group all products per customer, choose customers with only A and B but not c

        select  customer_id, customer_name
        from
            (
                select o.order_id, o.customer_id, c.customer_name, group_concat(o.product_name order by product_name) as group_products
            from Orders o left join Customers c
            on o.customer_id = c.customer_id
            group by c.customer_id
            ) temp1
        where group_products like '%A%B%' and group_products not like '%A%B%C%'
 */