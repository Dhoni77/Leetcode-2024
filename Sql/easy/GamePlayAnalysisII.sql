# Write your MySQL query statement below
SELECT
    player_id,
    device_id
FROM Activity
WHERE
    (player_id, event_date) IN (
        SELECT
            player_id,
            MIN(event_date) AS event_date
        FROM Activity
        GROUP BY 1
    );

/*
 MySql

    Approach 1:

        # Write your MySQL query statement below
        WITH
            T AS (
                SELECT
                    *,
                    RANK() OVER (
                        PARTITION BY player_id
                        ORDER BY event_date
                    ) AS rk
                FROM Activity
            )
        SELECT player_id, device_id
        FROM T
        WHERE rk = 1;

        Approach 2:

            SELECT DISTINCT
              player_id,
              FIRST_VALUE(device_id) OVER(
                PARTITION by player_id
                ORDER BY event_date
              ) AS device_id
            FROM Activity;
 */