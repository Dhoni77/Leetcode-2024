-- Write your PostgreSQL query statement below
 with cte as (
                select num,
                lead(num,1) over() as num1,
                lead(num,2) over() as num2
                from logs
             )
select distinct num as ConsecutiveNums from cte
where num = num1 and num = num2

 /*
  with main_1 as (
      select *, LAG(num) OVER() num_lag_1
      from logs
),
main_2 as (
      select *, LAG(num_lag_1) OVER() num_lag_2
      from main_1
),
main_3 as (
      select num,
      case
      when (num = num_lag_1) and (num_lag_1 = num_lag_2)  then 1 else 0 end as result
      from main_2
)
select distinct(num) as ConsecutiveNums
from main_3
where result = 1
  */

/*
 MySql

 Approach 1:

    # Write your MySQL query statement below
    SELECT DISTINCT
        l1.Num AS ConsecutiveNums
    FROM
        Logs l1,
        Logs l2,
        Logs l3
    WHERE
        l1.Id = l2.Id - 1
        AND l2.Id = l3.Id - 1
        AND l1.Num = l2.Num
        AND l2.Num = l3.Num;

    Approach 2:

    select distinct Num as ConsecutiveNums
    from (
        select lag(Num) over() as preNum,
            Num,
            lead(Num) over() as nextNum
        from Logs
    ) temp
    where preNum = Num and Num = nextNum;

    Approach 3:

        # Write your MySQL query statement below
        select l1.num ConsecutiveNums from logs l1, logs l2, logs l3
        where l1.id = l2.id + 1 and l1.id = l3.id + 2
        and (l1.num = l2.num and l2.num = l3.num)
        group by l1.num
 */