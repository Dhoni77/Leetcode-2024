SELECT activity_date AS day,
       count(DISTINCT user_id) AS active_users
FROM activity
WHERE activity_date >= date('2019-06-28')
  AND activity_date <= date('2019-07-27')
GROUP BY activity_date;

/*
 -- Write your PostgreSQL query statement below
    SELECT
        activity_date AS day,
        COUNT(DISTINCT user_id) AS active_users
    FROM Activity
    WHERE
        activity_date <= '2019-07-27'::Date
        AND activity_date > '2019-07-27'::Date - 30
    GROUP BY activity_date;


    -- Write your PostgreSQL query statement below

    SELECT activity_date as day, COUNT(DISTINCT user_id) AS active_users
    FROM Activity
    WHERE activity_date BETWEEN '2019-06-28' AND '2019-07-27'
    GROUP BY activity_date
 */


/*
MySql

    Approach 1:

        select activity_date day, count(distinct user_id) active_users from activity
        where activity_date >= date('2019-06-28') and activity_date <= date('2019-07-27')
        group by activity_date

    Approach 2:

    The two keys for solving this question are:

    select a specific date range
    count only distinct users as there are users having more than one activity per day, and the final results are grouped by day.
    There are several ways to select a specific range of dates:

    manually calculate the date and use this date in the filter to get the range. For this question, the result is looking for a period of 30 days ending 2019-07-27, which is all the days between 2019-06-28 and 2019-07-27:
    activity_date > '2019-06-27' AND activity_date <= '2019-07-27'
    or using BETWEEN:

    activity_day BETWEEN '2019-06-28' AND '2019-07-27'
    The date '2019-06-28' is used here because the BETWEEN operator is inclusive, and the begin and end values are included.

    DATEDIFF(date1, date2): this function returns date1 - date2 expressed as a value in days from one date to the other, so there is no need to calculate the exact date for the filter:
    DATEDIFF('2019-07-27', activity_date)<30
    AND
    DATEDIFF('2019-07-27', activity_date)>=0
    the first condition checks that date2 is within 30 days of date1. The second condition checks that date2 does not occur after date1. Without the second condition, a negative difference is also '<30', and we will get dates after 2019-07-27 in this case

    Another way to use DATEDIFF:

    DATEDIFF('2019-07-27', activity_date) BETWEEN 0 AND 29
    DATE_SUB(date, INTERVAL expr unit): this function performs date arithmetic, if the syntax does not support adding or subtracting days directly using operators such as '+' or '-':
    activity_date BETWEEN date_sub('2019-07-27', INTERVAL 29 DAY)
    AND '2019-07-27'
    Approach:
    Algorithm
    Select the columns needed for the final output: the dates, and the number of distinct users for each date.
    Add the filter for the date range. Make sure you are familiar with at least one method to pull the date range correctly with minimum calculation.
    Group the results by the activity date.
    MySQL
    SELECT
        activity_date AS day,
        COUNT(DISTINCT user_id) AS active_users
    FROM
        Activity
    WHERE
        DATEDIFF('2019-07-27', activity_date) < 30 AND DATEDIFF('2019-07-27', activity_date)>=0
    GROUP BY 1

    Approach 3:

    WHERE activity_date BETWEEN DATE_SUB('2019-07-27', INTERVAL 29 DAY) AND '2019-07-27'
 */