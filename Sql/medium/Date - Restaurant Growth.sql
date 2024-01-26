with Dates as (
    select distinct visited_on from customer
    where visited_on >= (
        select date_add(min(visited_on), INTERVAL 6 DAY) from customer
        )
)
select Dates.visited_on,
       sum(customer.amount) amount,
       round(sum(customer.amount) / 7, 2) average_amount
from Dates
left join customer
on (datediff(Dates.visited_on, customer.visited_on) between 0 and 6)
group by Dates.visited_on

/*
 MySql

    Approach 1:

        # Write your MySQL query statement below
        SELECT visits.visited_on AS visited_on, SUM(c.amount) AS amount,
            ROUND(SUM(c.amount) / 7.0, 2) AS average_amount
        FROM (
            SELECT DISTINCT visited_on
            FROM Customer
            WHERE DATEDIFF(visited_on, (SELECT MIN(visited_on) FROM Customer)) >= 6
        ) visits
        LEFT JOIN Customer c
        ON DATEDIFF(visits.visited_on, c.visited_on) BETWEEN 0 and 6
        GROUP BY visits.visited_on
        ORDER BY visited_on;

    Approach 2:

        # Write your MySQL query statement below
        SELECT visited_on,
        (
                SELECT SUM(amount)
                FROM customer
                WHERE visited_on BETWEEN DATE_SUB(c.visited_on, INTERVAL 6 DAY) AND c.visited_on
            ) AS amount,
            ROUND(
                (
                    SELECT SUM(amount) / 7
                    FROM customer
                    WHERE visited_on BETWEEN DATE_SUB(c.visited_on, INTERVAL 6 DAY) AND c.visited_on
                ),
                2
            ) AS average_amount
        FROM customer c
        WHERE visited_on >= (
                SELECT DATE_ADD(MIN(visited_on), INTERVAL 6 DAY)
                FROM customer
            )
        GROUP BY visited_on;

    Approach 3:

        # Write your MySQL query statement below
        with daily_sum as (
        select visited_on, sum(amount) as daily_sum
        from customer
        group by visited_on
        )

        , window_calc as (
        select visited_on,
                row_number() over(order by visited_on asc) as sequence,
                sum(daily_sum) over (order by visited_on asc rows between 6 PRECEDING and 0 following) as sum_6day,
                avg(daily_sum) over (order by visited_on asc rows between 6 PRECEDING and 0 following) as avg_6day
        from daily_sum)

        select visited_on,
                sum_6day as amount,
                round(avg_6day, 2) as average_amount
        from window_calc
        where sequence >=7
        order by visited_on;
 */