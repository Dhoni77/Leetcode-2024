-- Write your PostgreSQL query statement below
select player_id, min(event_date) first_login
from activity
group by player_id

/*
 MySql

    Approach 1:

            SELECT
      X.player_id,
      X.event_date AS first_login
     FROM
      (
      SELECT
      A.player_id,
      A.event_date,
      RANK() OVER (
      PARTITION BY
      A.player_id
      ORDER BY
      A.event_date
      ) AS rnk
      FROM
      Activity A
      ) X
     WHERE
      X.rnk = 1;

     Approach 2:

         SELECT DISTINCT
          A.player_id,
          FIRST_VALUE(A.event_date) OVER (
          PARTITION BY
          A.player_id
          ORDER BY
          A.event_date
          ) AS first_login
         FROM
          Activity A;

        Approach 3:

            For those who are curious, it is also possible to craft a solution to this
            problem using the LAST_VALUE() window function, but care must be taken in
            effectively defining the window function frame
            specification.
            If we did not provide a frame specification, then, using the example from the
            problem description, we would get the following (incorrect) result set:

            +-----------+-------------+
             | player_id | first_login |
             +-----------+-------------+
             | 1 | 2016-05-02 |
             | 1 | 2016-03-01 |
             | 2 | 2017-06-25 |
             | 3 | 2018-07-03 |
             | 3 | 2016-03-02 |
             +-----------+-------------+
            As noted in the MySQL
            docs,
            using ORDER BY within a window function results in the following default
            frame specification:

            RANGE BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW
            If ORDER BY is not specified, then the default frame specification is as
            follows:

            RANGE BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING
            Hence, an appropriate frame specification when using LAST_VALUE() would look
            something like the following:

            SELECT DISTINCT
              A.player_id,
              LAST_VALUE(A.event_date) OVER (
              PARTITION BY
              A.player_id
              ORDER BY
              A.event_date DESC RANGE BETWEEN UNBOUNDED PRECEDING
              AND UNBOUNDED FOLLOWING
              ) AS first_login
             FROM
              Activity A;
 */