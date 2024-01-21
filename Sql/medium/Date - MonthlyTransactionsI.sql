-- Write your PostgreSQL query statement below

select
    to_char(trans_date , 'YYYY-MM') as month,
    country,
    count(id) as trans_count,
    count(id) filter(where state = 'approved') as approved_count,
    sum(amount) as trans_total_amount,
    coalesce(sum(amount) filter(where state = 'approved'),0) as approved_total_amount
from Transactions
group by 1,2

/*
 -- Write your PostgreSQL query statement below
    SELECT TO_CHAR(trans_date, 'YYYY-MM') AS month,
           country,
           count(*) AS trans_count,
           sum(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) AS approved_count,
           sum(amount) AS trans_total_amount,
           sum(CASE WHEN state = 'approved' THEN amount ELSE 0 END) AS approved_total_amount
    FROM transactions
    GROUP BY month, country;
 */

 /*
  MySql

  Approach 1:
    select date_format(trans_date, '%Y-%m') as month, country, count(*) as trans_count,
    sum(if(state = 'approved', 1, 0)) as approved_count, sum(amount) as trans_total_amount,
        sum(if(state = 'approved', amount, 0)) as approved_total_amount
            from Transactions
                group by date_format(trans_date, '%Y-%m'), country;

  Approach 2:
    // The LEFT() function extracts a number of characters from a string (starting from left).

    select
    left(trans_date,7) as month,
    country,
    count(id) as trans_count,
    sum(amount) as trans_total_amount,
    sum(case when state='approved' then 1 else 0 end) as approved_count,
    sum(case when state='approved' then amount else 0 end) as approved_total_amount
    from transactions
    group by month, country

  Approach 3:

  Select CONCAT(Year(trans_date),'-',LPAD(Month(trans_date),2,'0')) AS month, country,
    count(*) as trans_count,
    SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) AS approved_count,
    SUM(amount) AS trans_total_amount,
    SUM(CASE WHEN state = 'approved' THEN Amount else 0 end) as approved_total_amount
    From Transactions
    group by country, Month
  */