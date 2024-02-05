/*
 MySql

    Approach 1:

        Inner Join + Group By + Sum Function
        We can use an inner join to join the Warehouse table and the Products table on the condition of product_id, and then group by
        warehouse name to calculate the inventory of each warehouse using the SUM function.


        MySQL

        # Write your MySQL query statement below
        SELECT
            name AS warehouse_name,
            SUM(width * length * height * units) AS volume
        FROM
            Warehouse
            JOIN Products USING (product_id)
        GROUP BY 1;

    Approach 2:

        with CTE as (
        select product_id, (Width * Length * Height) as size
        from Products)

        select name as warehouse_name, sum(units * size) as volume
        from Warehouse w
        left join CTE c
        on c.product_id = w.product_id
        group by name
 */