-- Write your PostgreSQL query statement below
SELECT
    MAX(NUM) AS NUM
FROM(
    SELECT
        NUM
    FROM MYNUMBERS
    GROUP BY NUM
    HAVING COUNT(NUM)=1
);