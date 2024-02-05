
/*
 MySql

    Approach 1:

        We can use the window function LEAD to obtain the date of the next visit for each user
        (if the date of the next visit does not exist, it is considered as 2021-1-1), and
        then use the DATEDIFF function to calculate the number of days between two visits.
        Finally, we can take the maximum value of the number of days between visits for each user.

                WITH
            T AS (
                SELECT
                    user_id,
                     visit_date,
                        LEAD(visit_date, 1, '2021-1-1') OVER (
                            PARTITION BY user_id
                            ORDER BY visit_date
                        ) as date_order,
                    datediff(
                    LEAD(visit_date, 1, '2021-1-1') OVER (
                            PARTITION BY user_id
                            ORDER BY visit_date
                        ),
                    visit_date
                    ) as diff
                FROM UserVisits
            )
        select user_id, max(diff) from T
        group by user_id

        Approach 2:

            -- use lead() to get next date
            -- if there's no date, difference has to be calculated with 2021-1-1, so put this value in lead()

            with CTE as
                (select user_id, visit_date,
                lead(visit_date, 1, '2021-1-1') over(partition by user_id order by visit_date) as next_date
                from UserVisits)

            select user_id, max(datediff(next_date, visit_date)) as biggest_window
            from CTE
            group by user_id
 */