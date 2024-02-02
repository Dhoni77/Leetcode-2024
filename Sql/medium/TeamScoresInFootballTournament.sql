# Write your MySQL query statement below
SELECT
    team_id,
    team_name,
    SUM(
        CASE
            WHEN team_id = host_team
            AND host_goals > guest_goals THEN 3
            WHEN team_id = guest_team
            AND guest_goals > host_goals THEN 3
            WHEN host_goals = guest_goals THEN 1
            ELSE 0
        END
    ) AS num_points
FROM
    Teams
    LEFT JOIN Matches ON team_id = host_team OR team_id = guest_team
GROUP BY 1
ORDER BY 3 DESC, 1;

/*
 MySql

    Approach 1:

    -- union all- one for host(when that team was host)- count host score, 2nd for guest(when that team was guest)- count guest score
    -- calculate sum of points
    -- group by team_id

select t.team_id, t.team_name, coalesce(sum(u.points), 0) as num_points
from Teams t
left join
    (select match_id, host_team as team_id, (case when host_goals > guest_goals then 3
                when host_goals = guest_goals then 1
                else 0 end) as points
    from Matches
    union all
    select match_id, guest_team as team_id,
                (case when host_goals < guest_goals then 3
                when host_goals = guest_goals then 1
                else 0 end) as points
    from Matches) u
on u.team_id = t.team_id
group by team_id
order by 3 desc, 1 asc

    Approach 2:

        -- without using 'UNION ALL'- only used JOIN

        select t.team_id, t.team_name, coalesce(
            sum(case when t.team_id = m.host_team and m.host_goals > m.guest_goals then 3
                     when t.team_id = m.guest_team and m.guest_goals > m.host_goals then 3
                     when host_goals = guest_goals then 1 end), 0) as num_points
        from Teams t
        left join Matches m
        on m.host_team = t.team_id or m.guest_team = t.team_id
        group by team_id
        order by 3 desc, 1 asc

    Approach 3:

            WITH
      TwoWayMatches AS (
        SELECT
          host_team AS team_id,
          host_goals AS goals,
          guest_goals AS opponent_goals
        FROM Matches
        UNION ALL
        SELECT
          guest_team,
          guest_goals,
          host_goals
        FROM Matches
      )
    SELECT
      Teams.team_id,
      Teams.team_name,
      SUM(
        CASE
          WHEN goals > opponent_goals THEN 3
          WHEN goals = opponent_goals THEN 1
          ELSE 0
        END
     ) AS num_points
    FROM Teams
    LEFT JOIN TwoWayMatches
      USING (team_id)
    GROUP BY 1
    ORDER BY num_points DESC, team_id;
 */