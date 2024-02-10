-- using recursive CTE
-- calculate subtask_count starting from given number, subtracting 1 till it reaches 1
-- so subtasks count shouldn't be less than 2, because 2-1 = 1, and 1-1 will become 0
-- use recursive cte to get all subtaks
-- in the final query, pull all rows from cte, except the rows in Executed table

with recursive cte as
    (select task_id, subtasks_count
    from Tasks

    union all

    select task_id, subtasks_count-1
    from cte
    where subtasks_count > 1)

select task_id, subtasks_count as subtask_id
from cte
where (task_id, subtasks_count) not in (select *
                                        from Executed)

/*
 MySql

    Approach 1:

        # Write your MySQL query statement below
WITH RECURSIVE
    T(task_id, subtask_id) AS (
        SELECT
            task_id,
            subtasks_count
        FROM Tasks
        UNION ALL
        SELECT
            task_id,
            subtask_id - 1
        FROM t
        WHERE subtask_id > 1
    )
SELECT
    T.*
FROM
    T
    LEFT JOIN Executed USING (task_id, subtask_id)
WHERE Executed.subtask_id IS NULL;

    Approach 2:

        WITH
      RECURSIVE TaskToSubtask AS (
        SELECT task_id, subtasks_count AS subtask_id FROM Tasks
        UNION ALL
        SELECT task_id, subtask_id - 1 FROM TaskToSubtask
        WHERE subtask_id > 1
      )
    SELECT * FROM TaskToSubtask
    EXCEPT
    SELECT * FROM Executed;
 */