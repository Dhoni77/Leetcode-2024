/*
 MySql

 Approach 1:
    # Write your MySQL query statement below
    SELECT seller_name
    FROM
        Seller
        LEFT JOIN Orders USING (seller_id)
    GROUP BY seller_id
    HAVING IFNULL(SUM(YEAR(sale_date) = 2020), 0) = 0
    ORDER BY 1;

 Approach 2:

    SELECT Seller.seller_name
    FROM Seller
    LEFT JOIN Orders
      ON (
        Seller.seller_id = Orders.seller_id
        AND YEAR(Orders.sale_date) = 2020)
    WHERE Orders.order_id IS NULL
    ORDER BY 1;

 Approach 3:

    -- select sellers from Orders table
    -- then select Sellers from Sellers table who are not in temp

    select seller_name
    from Seller s
    where seller_id not in
        (select seller_id
        from Orders
        where sale_date like '2020%')
    order by seller_name
 */