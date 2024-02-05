# Write your MySQL query statement below
SELECT
    sale_date,
    SUM(IF(fruit = 'apples', sold_num, -sold_num)) AS diff
FROM Sales
GROUP BY 1
ORDER BY 1;

/*
 MySql

    Approach 1:

        -- using join- 1 table for apples, 1 for oranges, join on sales date

        select sa.sale_date, (ifnull(sum(sa.sold_num),0)-ifnull(sum(so.sold_num), 0)) as diff
        from Sales sa
        join Sales so
        on sa.sale_date = so.sale_date and sa.fruit = 'apples' and so.fruit = 'oranges'
        group by 1
        order by 1
 */