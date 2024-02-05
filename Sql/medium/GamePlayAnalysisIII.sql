# Write your MySQL query statement below
SELECT
    t1.player_id,
    t1.event_date,
    SUM(t2.games_played) AS games_played_so_far
FROM
    Activity AS t1
    CROSS JOIN Activity AS t2 ON t1.player_id = t2.player_id AND t1.event_date >= t2.event_date
GROUP BY 1, 2;

/*
 MySql

    Approach 1:

        # Write your MySQL query statement below
        SELECT
            player_id,
            event_date,
            SUM(games_played) OVER (
                PARTITION BY player_id
                ORDER BY event_date
            ) AS games_played_so_far
        FROM Activity;
 */