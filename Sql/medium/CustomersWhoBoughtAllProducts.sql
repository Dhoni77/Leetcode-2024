
/*
 MySql

    Approach 1:

        Select the customer_id from the Customer table.
        Group the results by customer_id.
        Apply a HAVING clause to filter out customers who have not bought all the products.
        In the HAVING clause, use COUNT(DISTINCT product_key) to count the number of distinct product keys for each customer.
        Compare this count with the total count of product keys in the Product table obtained through a subquery.
        If the counts match, it means the customer has bought all the products.

        # Write your MySQL query statement below
        select customer_id from customer
        group by
        customer_id
        having count(distinct product_key ) = (select count(product_key ) from product)
 */