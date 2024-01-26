
/*
 MYSql

    Approach 1:

            WITH
      AccumulatedQueue AS (
        SELECT
          person_name,
          SUM(weight) OVER(ORDER BY turn) AS accumulated_weight
        FROM Queue
      )
    SELECT person_name
    FROM AccumulatedQueue
    WHERE accumulated_weight <= 1000
    ORDER BY accumulated_weight DESC
    LIMIT 1;

    Approach 2:

        # Write your MySQL query statement below
        select person_name
        from(
          select person_name, sum(Weight) over (order by turn) as Total_Weight
          from Queue
        ) as p
        where Total_Weight<=1000
        order by Total_Weight desc limit 1;

    Approach 3:
        Approach
        We join the Queue table with itself, creating combinations of rows where each row is paired with all rows that have a higher or equal turn value.
        We group the rows by turn and calculate the sum of weights for each group.
        Using the HAVING clause, we filter out groups whose sum of weights exceeds the weight limit of 1000.
        We order the results by the sum of weights in descending order, ensuring the last person who can fit is at the top.
        Finally, we limit the result to 1 row since we only need the information of the last person.
        # Write your MySQL query statement below
        SELECT
            q1.person_name
        FROM Queue q1 JOIN Queue q2 ON q1.turn >= q2.turn
        GROUP BY q1.turn
        HAVING SUM(q2.weight) <= 1000
        ORDER BY SUM(q2.weight) DESC
        LIMIT 1
 */