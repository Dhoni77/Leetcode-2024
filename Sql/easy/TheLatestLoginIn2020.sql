-- Write your PostgreSQL query statement below

select
    user_id,
    time_stamp as last_stamp
from (
    select
        a.*,
        rank() over (partition by user_id order by time_stamp desc) as rank
    from (
        select
            *
        from logins
        where date_part('year', time_stamp) = '2020'
    ) as a
)
where rank = 1

/*
 MySql

    Approach 1:

    # Write your MySQL query statement below
    SELECT user_id, MAX(time_stamp) AS last_stamp
    FROM Logins
    WHERE YEAR(time_stamp) = 2020
    GROUP BY 1;

    Approach 2:

    select user_id, time_stamp last_stamp
    from
    (
       select user_id, time_stamp, row_number() over(partition by user_id order by time_stamp desc) as rnk
       from logins where year(time_stamp) = 2020
    ) tbl
    where rnk = 1
    group by user_id

    Approach 3:

    # Write your MySQL query statement below
    SELECT USER_ID,
    MAX(TIME_STAMP) AS LAST_STAMP
    FROM LOGINS
    WHERE TIME_STAMP LIKE '2020%'
    GROUP BY USER_ID
    HAVING COUNT(TIME_STAMP)>0;

    Approach 4:

     Using EXTRACT() to get year from the date column and FIRST_VALUE() to find the latest record
        Algorithm
        Select the columns needed for the final output
        Add condition 1 using EXTRACT() to select all records with a timestamp in the year 2020
        Add condition 2 using FIRST_VALUE() to get the latest record for each user from the previous step; the date column is sorted in descending order to make sure the first record is the latest record in 2020
        Because window function returns non-aggregate results, DISTINCT is needed for this approach to make sure users with multiple records in 2020 will return only one record
    SELECT
        DISTINCT user_id,
        FIRST_VALUE(time_stamp)OVER(PARTITION BY user_id ORDER BY time_stamp DESC) AS last_stamp
    FROM
        Logins
    WHERE EXTRACT(Year FROM time_stamp) = 2020;
 */