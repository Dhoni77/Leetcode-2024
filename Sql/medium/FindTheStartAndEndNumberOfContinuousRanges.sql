# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            log_id,
            log_id - ROW_NUMBER() OVER (ORDER BY log_id) AS pid
        FROM Logs
    )
SELECT MIN(log_id) AS start_id, MAX(log_id) AS end_id
FROM T
GROUP BY pid;

/*
 MySql

    Approach 1:

        # Write your MySQL query statement below
        WITH
            T AS (
                SELECT
                    log_id,
                    SUM(delta) OVER (ORDER BY log_id) AS pid
                FROM
                    (
                        SELECT
                            log_id,
                            IF((log_id - LAG(log_id) OVER (ORDER BY log_id)) = 1, 0, 1) AS delta
                        FROM Logs
                    ) AS t
            )
        SELECT MIN(log_id) AS start_id, MAX(log_id) AS end_id
        FROM T
        GROUP BY pid;

    Approach 2:

            WITH
      LogToRowNumber AS (
        SELECT
          log_id,
          ROW_NUMBER() OVER(ORDER BY log_id) AS `row_number`
        FROM Logs
      )
    SELECT
      MIN(log_id) AS start_id,
      MAX(log_id) AS end_id
    FROM LogToRowNumber
    GROUP BY log_id - `row_number`;
 */