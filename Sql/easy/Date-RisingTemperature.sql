-- Write your PostgreSQL query statement below
select W.id from Weather as W left join Weather as W2 on W.recordDate - 1 = W2.recordDate where W.temperature > W2.temperature;

/*
 -- Write your PostgreSQL query statement below
SELECT today.id
FROM weather today
JOIN weather yesterday
    ON today.recordDate = yesterday.recordDate + INTERVAL '1 day'
WHERE today.temperature > yesterday.temperature;
 */

 /*
  MySql

  Approach 1:

      SELECT
        w1.id
    FROM
        Weather w1
    JOIN
        Weather w2
    ON
        DATEDIFF(w1.recordDate, w2.recordDate) = 1
    WHERE
        w1.temperature > w2.temperature;

  Approach 2:

      SELECT
        w1.id
    FROM
        Weather w1
    WHERE
        w1.temperature > (
            SELECT
                w2.temperature
            FROM
                Weather w2
            WHERE
                w2.recordDate = DATE_SUB(w1.recordDate, INTERVAL 1 DAY)
        );

  Approach 3:

      SELECT
        w2.id
    FROM
        Weather w1, Weather w2
    WHERE
        DATEDIFF(w2.recordDate, w1.recordDate) = 1
    AND
        w2.temperature > w1.temperature;
  */