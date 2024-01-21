-- Write your PostgreSQL query statement below
select a.product_id, coalesce(round(sum(a.price * b.units) / sum(b.units)::numeric, 2), 0) as average_price
from Prices a
         left join UnitsSold b
                   on a.product_id = b.product_id
                       and b.purchase_date between a.start_date and a.end_date
group by a.product_id;

/*
 -- Write your PostgreSQL query statement below
    select p.product_id, coalesce(round(sum(units*price)::decimal/sum(units)::decimal,2), 0) as average_price
    from Prices p
    left join UnitsSold u on p.product_id = u.product_id and u.purchase_date >= p.start_date and u.purchase_date <= p.end_date
    group by p.product_id
 */

    /*
         SELECT
        p.product_id,
        COALESCE(ROUND(SUM(CAST(units AS DECIMAL) * CAST(price AS DECIMAL)) / NULLIF(SUM(units), 0), 2), 0) AS average_price
    FROM
        Prices p
    LEFT JOIN
        UnitsSold u ON p.product_id = u.product_id AND u.purchase_date BETWEEN start_date AND end_date
    GROUP BY
        p.product_id;
     */

/*
 MySql

 Approach 1:

    SELECT p.product_id, IFNULL(ROUND(SUM(units*price)/SUM(units),2),0) AS average_price
    FROM Prices p LEFT JOIN UnitsSold u
    ON p.product_id = u.product_id AND
    u.purchase_date BETWEEN start_date AND end_date
    group by product_id
 */