-- PostgreSql
SELECT sell_date,
       COUNT(*)                 AS num_sold,
       STRING_AGG(product, ',') AS products
FROM (SELECT sell_date, product
      FROM Activities
      GROUP BY sell_date, product
      ORDER BY sell_date, product) AS g
GROUP BY sell_date;

/*
 SELECT sell_date,
       COUNT(DISTINCT (product))                          AS num_sold,
       STRING_AGG(DISTINCT product, ',' ORDER BY product) AS products
FROM Activities
GROUP BY sell_date;
 */

/*
 MySql

 Approach 1:

    select sell_date, count(distinct product) num_sold,
       group_concat(distinct product order by product) products
    from
    activities
    group by sell_date
    order by sell_date
 */