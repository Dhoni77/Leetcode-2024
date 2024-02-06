-- CTE1- find highest rank and lowest rank in 2 separate columns using dense_rank()
-- CTE2- get the list of students in CTE1
-- CTE3- get the list of students who took exams but are not in CTE2
-- final query- output id and name of students in CTE3

with CTE1 as
    (select exam_id, student_id, score,
        dense_rank() over(partition by exam_id order by score desc) rank_highest,
        dense_rank() over(partition by exam_id order by score asc) rank_lowest
    from Exam),
    CTE2 as
    (select student_id
    from CTE1
    where rank_highest = 1 or rank_lowest = 1),
    CTE3 as
    (select distinct student_id
    from Exam
    where student_id not in (select * from CTE2))

select student_id, student_name
from Student
where student_id in (select * from CTE3)
order by 1

/*
 MySql

    Approach 1:

        # Write your MySQL query statement below
        WITH
            T AS (
                SELECT
                    student_id,
                    RANK() OVER (
                        PARTITION BY exam_id
                        ORDER BY score
                    ) AS rk1,
                    RANK() OVER (
                        PARTITION BY exam_id
                        ORDER BY score DESC
                    ) AS rk2
                FROM Exam
            )
        SELECT student_id, student_name
        FROM
            T
            JOIN Student USING (student_id)
        GROUP BY 1
        HAVING SUM(rk1 = 1) = 0 AND SUM(rk2 = 1) = 0
        ORDER BY 1;

    Approach 2:

        WITH
          RankedStudents AS (
            SELECT
              student_id,
              RANK() OVER(PARTITION BY exam_id ORDER BY score ASC) rank_asc,
              RANK() OVER(PARTITION BY exam_id ORDER BY score DESC) rank_desc
            FROM Exam
          )
        SELECT * FROM Student
        WHERE student_id IN (
          SELECT student_id FROM RankedStudents
          GROUP BY 1
          HAVING MIN(rank_asc) > 1 AND MIN(rank_desc) > 1
        )
        ORDER BY student_id;
 */