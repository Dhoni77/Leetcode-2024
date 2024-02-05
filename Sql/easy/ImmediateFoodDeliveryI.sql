# Write your MySQL query statement below
SELECT
    ROUND(SUM(order_date = customer_pref_delivery_date) / COUNT(1) * 100, 2) AS immediate_percentage
FROM Delivery;

/*
 MySql

    Approach 1:

        select round(sum( case when order_date = customer_pref_delivery_date then 1 else 0 end) / count(*) * 100, 2) as immediate_percentage
        from Delivery
 */