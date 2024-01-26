        WITH
  Players AS (
    SELECT player_id, MIN(event_date) AS first_login
    FROM Activity
    GROUP BY 1
  )
SELECT ROUND(
    COUNT(Players.player_id) / (
      SELECT COUNT(DISTINCT Activity.player_id)
      FROM Activity
    ),
    2
  ) AS fraction
FROM Players
INNER JOIN Activity
  ON (
    Players.player_id = Activity.player_id
    AND DATEDIFF(Players.first_login, Activity.event_date) = -1)

/*
 MySql

 Approach 1: Subqueries and multi-value use of the IN comparison operator
Intuition
The preferred solution approach to part
II in this problem
series involved using the IN comparison operator in a rather creative or
nuanced way, namely using more than a single value for comparison:

SELECT
  A1.player_id,
  A1.device_id
FROM
  Activity A1
WHERE
  (A1.player_id, A1.event_date) IN (
    SELECT
      A2.player_id,
      MIN(A2.event_date)
    FROM
      Activity A2
    GROUP BY
      A2.player_id
  );
We can use a similar idea for this problem, where, again, we rely on our
ability to access the tuples (player_id, first_login) in some manner:

(val1, val2) IN (
  SELECT
    A.player_id,
    MIN(A.event_date) AS first_login
  FROM
    Activity A
  GROUP BY
    A.player_id
)
But what should val1 and val2 be? We must have player_id as val1, but the choice for val2 is less apparent. We need, in some form or fashion, to be able to relate val2 to the first login date corresponding to the player_id represented by val1; specifically, val2 needs to be a date that is one day after the first login date being referenced. How can we achieve this?

Algorithm
Find the first login date for each player: (player_id, first_login).

Determine which tuples, if any, exist such that

(player_id, day_after_first_login) = (player_id, first_login)
The existence of such a tuple will confirm that whichever player_id is
being considered logged in the day after their first login date (i.e.,
day_after_first_login).

Divide the total number of player_id values obtained from the process
described above by the total number of distinct player_id values from
the entire Activity table and round the result to two decimal places.

Implementation
MySQL
SELECT
  ROUND(
    COUNT(A1.player_id)
    / (SELECT COUNT(DISTINCT A3.player_id) FROM Activity A3)
  , 2) AS fraction
FROM
  Activity A1
WHERE
  (A1.player_id, DATE_SUB(A1.event_date, INTERVAL 1 DAY)) IN (
    SELECT
      A2.player_id,
      MIN(A2.event_date)
    FROM
      Activity A2
    GROUP BY
      A2.player_id
  );
Note: We only need to use COUNT(A1.player_id) in the ROUND() function above as opposed to COUNT(DISTINCT A1.player_id) since (player_id, event_date) is the primary key of the Activity table (i.e., it is not possible for the same player to have duplicated event_date entries for the date after the player's initial login date).

Approach 2: CTEs and INNER JOIN
Intuition
Common table expressions (CTEs) are powerful not only because of what they
allow us to do but also because of how they allow us to think. We can use CTEs to our advantage here so as to approach the problem-solving process in a more or less "linear" fashion:

Identify the first login date for each player.
Identify the number of players who logged in the day after their first login date.
Divide the number of players identified in step 2 by the number of players identified in step 1 and round the result to two decimal places.
Algorithm
See above.

Implementation
MySQL
WITH first_logins AS (
  SELECT
    A.player_id,
    MIN(A.event_date) AS first_login
  FROM
    Activity A
  GROUP BY
    A.player_id
), consec_logins AS (
  SELECT
    COUNT(A.player_id) AS num_logins
  FROM
    first_logins F
    INNER JOIN Activity A ON F.player_id = A.player_id
    AND F.first_login = DATE_SUB(A.event_date, INTERVAL 1 DAY)
)
SELECT
  ROUND(
    (SELECT C.num_logins FROM consec_logins C)
    / (SELECT COUNT(F.player_id) FROM first_logins F)
  , 2) AS fraction;
Note: As with Approach 1, observe that COUNT(A.player_id) is sufficient in the consec_logins CTE since (player_id, event_date) is the primary key of the Activity table.

Database Conclusion
Approach 1 is beautiful in its own right. It is elegant and builds on work done previously throughout this problem series. But we prefer Approach 2 due to its relative simplicity, performance, and rather principled approach. Specifically, you may be hard-pressed to come up with Approach 1 on the spot in an interview. It should be much more manageable to reproduce a solution akin to Approach 2 in an interview setting.
 */