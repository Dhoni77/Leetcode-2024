SELECT query_name,
ROUND(SUM(rating::numeric/position::numeric)/COUNT(*), 2) as quality,
ROUND(SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END)::numeric/COUNT(*)::numeric*100, 2) as poor_query_percentage
FROM queries
GROUP BY query_name

/*
 -- Write your PostgreSQL query statement below
    select
    query_name,
    round(avg(cast(rating as decimal) / position), 2) as quality,
    round(1.0*sum(case when rating < 3 then 1 else 0 end) * 100 / count(*), 2) as poor_query_percentage
    from
    queries
    group by
    query_name;
 */

/*
 MySql

Approach 1:
         select query_name,
           round(sum(rating / position) / count(*), 2) as quality,
           round(sum(if(rating < 3, 1, 0)) * 100 / count(*), 2) as poor_query_percentage
    from Queries
    group by query_name;

Approach 2:
        SELECT
        query_name,
        ROUND(AVG(rating / position), 2) AS quality,
        ROUND(AVG(rating < 3) * 100, 2) AS poor_query_percentage
    FROM
        Queries
    GROUP BY
        query_name
 */