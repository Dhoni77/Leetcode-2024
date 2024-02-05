SELECT
  LEAST(from_id, to_id) AS person1,
  GREATEST(from_id, to_id) AS person2,
  COUNT(*) AS call_count,
  SUM(duration) AS total_duration
FROM Calls
GROUP BY 1, 2;

/*
 MySql

    Approach 1:

        -- union all- this gets all calls, then we put condition p1 < p2

        select from_id as person1, to_id as person2, count(*) as call_count, sum(duration) as total_duration
        from
            (select from_id, to_id, duration
            from Calls
            union all
            select to_id, from_id, duration
            from Calls) t
        where from_id < to_id
        group by 1, 2

    Approach 2:

        # Write your MySQL query statement below
        SELECT
            IF(from_id < to_id, from_id, to_id) AS person1,
            IF(from_id < to_id, to_id, from_id) AS person2,
            COUNT(1) AS call_count,
            SUM(duration) AS total_duration
        FROM Calls
        GROUP BY 1, 2;
 */