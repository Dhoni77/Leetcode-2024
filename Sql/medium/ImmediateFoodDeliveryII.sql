-- Write your PostgreSQL query statement below
SELECT
    ROUND(SUM(CASE WHEN order_date = customer_pref_delivery_date THEN 1 ELSE 0 END) * 100.0 / COUNT(DISTINCT customer_id), 2) AS immediate_percentage
FROM Delivery
WHERE (customer_id, order_date) IN (
    SELECT customer_id, MIN(order_date) AS first_order_date
    FROM Delivery
    GROUP BY customer_id
)

/*
 -- Write your PostgreSQL query statement below
SELECT
    ROUND(COUNT(CASE WHEN order_date = customer_pref_delivery_date THEN 1 END)::numeric(10,2) * 100.0 / COUNT(DISTINCT customer_id), 2) AS immediate_percentage
FROM
    Delivery
WHERE
    (customer_id, order_date) IN (
        SELECT
            customer_id,
            MIN(order_date) AS first_order_date
        FROM
            Delivery
        GROUP BY
            customer_id
    );

 */

/*
 MySql

    Approach 1:

            select round(sum(case
                         when customer_id is null or
                              order_date = customer_pref_delivery_date then 1
                         else 0 end) / count(customer_id) * 100, 2) immediate_percentage
    from delivery
    where (customer_id, order_date) in
          (select customer_id, min(order_date)
           from delivery
           group by customer_id)

    Approach 2:

    # Write your MySQL query statement below
    WITH
        T AS (
            SELECT
                *,
                RANK() OVER (
                    PARTITION BY customer_id
                    ORDER BY order_date
                ) AS rk
            FROM Delivery
        )
    SELECT
        ROUND(AVG(order_date = customer_pref_delivery_date) * 100, 2) AS immediate_percentage
    FROM T
    WHERE rk = 1;

    Approach 3:

            WITH
      CustomerToIsImmediate AS(
        SELECT
          DISTINCT customer_id,
          FIRST_VALUE(order_date = customer_pref_delivery_date) OVER(
            PARTITION BY customer_id
            ORDER BY order_date
          ) is_immediate
        FROM Delivery
      )
    SELECT ROUND(AVG(is_immediate) * 100, 2) immediate_percentage
    FROM CustomerToIsImmediate;

    Approach 4:

        SELECT
        ROUND(AVG(order_date = customer_pref_delivery_date) * 100, 2) AS immediate_percentage
    FROM Delivery
    WHERE
        (customer_id, order_date) IN (
            SELECT customer_id, MIN(order_date)
            FROM Delivery
            GROUP BY 1
        );
 */