-- Write your PostgreSQL query statement below
SELECT  u.name, coalesce(sum(r.distance), 0) as travelled_distance
FROM    Users u
LEFT    JOIN    rides r on u.id = r.user_id
GROUP BY    u.id, u.name
ORDER BY    travelled_distance desc, u.name

/*
 MySql

 Overview
This is the type of question that you might want to slow down and pay attention to the details before writing:

Since the question is asking for the distance travelled by each user and there may be users who have not travelled any distance, LEFT JOIN is needed so each user from the Users table will be included.

For those users who have not travelled, functions such as IFNULL() or COALESCE() are needed to return 0 instead of null for their total distance. The two functions are a little bit different, but for this question, they can be used interchangeably.

IFNULL(): takes two arguments and returns the first one if it's not NULL or the second if the first one is NULL.

COALESCE(): takes two or more parameters and returns the first non-NULL parameter, or NULL if all parameters are NULL.

Since users might have the same name and id is the primary key for this table (which means the values in this column will be unique). We need to use id for GROUP BY to get the aggregated distance for each user.

Don't forget to check the order required for the final output! This question requires two different types of order.

Approach: LEFT JOIN
Algorithm
Select the columns needed for the final output: name of the user, and the total distance; for users who do not have any rides, use IFNULL() or COALESCE() to return 0 for their distance
JOIN the two tables by user id
GROUP the result by id so each user has only one aggregated total distance. It's important to use id instead of name so the users with the same names will not be merged
ORDER the result by the 2nd column in descending order and the 1st column in ascending order per requested
Implementation
MySQL
SELECT
    u.name,
    IFNULL(SUM(distance),0) AS travelled_distance
FROM
    Users u
LEFT JOIN
    Rides r
ON
    u.id = r.user_id
GROUP BY
    u.id
ORDER BY 2 DESC, 1 ASC
 */