# Write your MySQL query statement below
--   UNION ALL is used to get the duplicate ids.
WITH
    T AS (
        SELECT Wimbledon AS player_id
        FROM Championships
        UNION ALL
        SELECT Fr_open AS player_id
        FROM Championships
        UNION ALL
        SELECT US_open AS player_id
        FROM Championships
        UNION ALL
        SELECT Au_open AS player_id
        FROM Championships
    )
SELECT player_id, player_name, COUNT(1) AS grand_slams_count
FROM
    T
    JOIN Players USING (player_id)
GROUP BY 1;

/*
 MySql

 Approach 1:

        # Write your MySQL query statement below
        SELECT
            player_id,
            player_name,
            SUM(
                (
                    CASE
                        WHEN Wimbledon = player_id THEN 1
                        ELSE 0
                    END
                ) + (
                    CASE
                        WHEN Fr_open = player_id THEN 1
                        ELSE 0
                    END
                ) + (
                    CASE
                        WHEN US_open = player_id THEN 1
                        ELSE 0
                    END
                ) + (
                    CASE
                        WHEN Au_open = player_id THEN 1
                        ELSE 0
                    END
                )
            ) AS grand_slams_count
        FROM
            Championships
            CROSS JOIN Players
        GROUP BY player_id
        HAVING grand_slams_count > 0;

    Approach 2:

        SELECT
          Players.player_id,
          Players.player_name,
          SUM(Players.player_id = Championships.Wimbledon) + SUM(Players.player_id = Championships.Fr_open) + SUM(Players.player_id = Championships.US_open) + SUM(Players.player_id = Championships.Au_open) AS grand_slams_count
        FROM Players
        INNER JOIN Championships
          ON (
            Players.player_id IN (
              Championships.Wimbledon,
              Championships.Fr_open,
              Championships.US_open,
              Championships.Au_open
            )
          )
        GROUP BY 1;

    Approach 3:

        -- beginner level solution
        -- all player ids in a single column, count those, join with Players for name

        with CTE as
            (select Wimbledon as id
            from Championships
            union all
            select Fr_open as id
            from Championships
            union all
            select US_open as id
            from Championships
            union all
            select Au_open as id
            from Championships)

        select c.id as player_id, p.player_name, count(c.id) as grand_slams_count
        from CTE c
        join Players p
        on c.id = p.player_id
        group by 1
 */