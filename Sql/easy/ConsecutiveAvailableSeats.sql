# Write your MySQL query statement below
SELECT DISTINCT a.seat_id
FROM
    Cinema AS a
    JOIN Cinema AS b ON ABS(a.seat_id - b.seat_id) = 1 AND a.free AND b.free
ORDER BY 1;

/*
 MySql

    Approach 1:

        # Write your MySQL query statement below
    WITH
        T AS (
            SELECT
                seat_id,
                (free + (LAG(free) OVER (ORDER BY seat_id))) AS a,
                (free + (LEAD(free) OVER (ORDER BY seat_id))) AS b
            FROM Cinema
        )
    SELECT seat_id
    FROM T
    WHERE a = 2 OR b = 2;

    Approach 2:

        # Write your MySQL query statement below
        WITH
            T AS (
                SELECT
                    *,
                    SUM(free = 1) OVER (
                        ORDER BY seat_id
                        ROWS BETWEEN 1 PRECEDING AND 1 FOLLOWING
                    ) AS cnt
                FROM Cinema
            )
        SELECT seat_id
        FROM T
        WHERE free = 1 AND cnt > 1
        ORDER BY 1;

        Approach 3:

                WITH CinemaNeighbors AS (
          SELECT
            *,
            LAG(free) OVER(ORDER BY seat_id) AS prev_free,
            LEAD(free) OVER(ORDER BY seat_id) AS next_free
          FROM Cinema
        )
        SELECT seat_id
        FROM CinemaNeighbors
        WHERE free = 1
          AND (prev_free = 1 OR next_free = 1)
        ORDER BY 1;

        Approach 4:

        -- lag and lead will give the rows above and below
        -- if free = 1 and either of lag_free or lead_free is 1, it means we have 2 consecutive free seats.
        -- just pick those rows

        with CTE as(
            select seat_id, free,
                lag(free, 1) over(order by seat_id) as lag_free,
                lead(free, 1) over(order by seat_id) as lead_free
            from Cinema)

        select seat_id
        from CTE
        where (free = 1 and lag_free = 1) or (free = 1 and lead_free = 1)
        order by 1

        Approach 5:

        -- if seat = free AND seat + 1 or seat - 1 have free = 1, then pull that seat

        select seat_id
        from Cinema
        where free = 1 and
             (seat_id - 1 in (select seat_id
                              from Cinema
                              where free = 1)
            or
            seat_id + 1 in (select seat_id
                              from Cinema
                              where free = 1))
 */