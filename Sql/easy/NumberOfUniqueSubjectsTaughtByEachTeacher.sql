select teacher_id, count(distinct subject_id) cnt from teacher
group by teacher_id

/*
 -- Write your PostgreSQL query statement below
    with cte as (select teacher_id, Count(distinct subject_id) as cnt from teacher
    group by teacher_id)
    select  teacher_id, cnt from cte;
 */

 /*
  MySql

  Approach 1:

    SELECT teacher_id, COUNT(DISTINCT subject_id) AS cnt
    FROM Teacher
    GROUP BY 1;
  */