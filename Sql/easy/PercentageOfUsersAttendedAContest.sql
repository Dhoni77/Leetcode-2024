SELECT
contest_id,
ROUND(COUNT(contest_id)::numeric/(SELECT COUNT(*)  FROM Users)*100,2) AS percentage
FROM Register
GROUP BY contest_id
ORDER BY percentage desc, contest_id

/*
 MySql

 Approach 1:
     # Write your MySQL query statement below
    SELECT contest_id, ROUND(COUNT(user_id)/(select COUNT(user_id) FROM Users)*100,2) as percentage
    FROM Register
    GROUP BY contest_id
    ORDER BY percentage DESC, contest_id ASC

 Approach 2:
    # Write your MySQL query statement below
    SELECT
        contest_id,
        ROUND(COUNT(1) * 100 / (SELECT COUNT(1) FROM Users), 2) AS percentage
    FROM Register
    GROUP BY 1
    ORDER BY 2 DESC, 1;
 */