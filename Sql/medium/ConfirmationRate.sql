-- Write your PostgreSQL query statement below
select
    su.user_id,
    round(avg(case when c.action = 'confirmed' then 1 else 0 end), 2) as confirmation_rate
from
    Confirmations c right join
    Signups su on
    su.user_id = c.user_id
group by
    su.user_id

/*
 with cte_1 as (
    select s.user_id,
    count(*) as num_signup
    from Signups s
    left join Confirmations c using(user_id)
    group by s.user_id
), cte_2 as (
    select s.user_id,
    count(*) as num_confirmed
    from Signups s
    left join Confirmations c using(user_id)
    where c.action = 'confirmed'
    group by s.user_id
)
select
 c1.user_id,
round((coalesce(c2.num_confirmed, 0)::decimal / c1.num_signup), 2) as confirmation_rate
from cte_1 c1
left join cte_2 c2 using(user_id)
 */

 /*
  MySql

    Approach 1:

        # Write your MySQL query statement below
        select Signups.user_id, round(sum(case when action = 'confirmed' then 1 else 0 end) / count(Signups.user_id),2) as confirmation_rate
        from Signups left join Confirmations
        on Signups.user_id = Confirmations.user_id
        group by user_id

  Approach 2:

        # Write your MySQL query statement below
        select s.user_id, round(avg(
                                if(c.user_id is null or c.action = 'timeout', 0, 1)
                                ), 2) confirmation_rate from signups s
        left join confirmations c
        on s.user_id = c.user_id
        group by s.user_id

    Approach 3:

        SELECT
        Signups.user_id,
        IFNULL(ROUND(AVG(Confirmations.action = 'confirmed'), 2), 0) AS confirmation_rate
        FROM Signups
        LEFT JOIN Confirmations
          USING (user_id)
        GROUP BY 1;
  */