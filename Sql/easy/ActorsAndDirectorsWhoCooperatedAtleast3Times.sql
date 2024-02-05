# Write your MySQL query statement below

SELECT actor_id,director_id
FROM ActorDirector
GROUP BY actor_id,director_id
HAVING COUNT(actor_id)>=3 AND COUNT(director_id)>=3

/*
MySql

    Approach 1:

        SELECT actor_id, director_id
        from ActorDirector
        Group by actor_id,director_id
        having count(timestamp)>=3

        Explanation:

            +-------------+-------------+-------------+
            | actor_id    | director_id | timestamp   |
            +-------------+-------------+-------------+
            | 1           | 1           | 0           |
            | 1           | 1           | 1           |
            | 1           | 1           | 2           |
            | 1           | 2           | 3           |
            | 1           | 2           | 4           |
            | 2           | 1           | 5           |
            | 2           | 1           | 6           |
            +-------------+-------------+-------------+

            Group by actor_id, director_id:
            +-------------+-------------+-------------+
            | actor_id    | director_id | timestamp   |
            +-------------+-------------+-------------+
            | 1           | 1           | 0, 1, 2    |
            | 1           | 2           | 3, 4        |
            | 2           | 1           | 5. 6        |
            +-------------+-------------+-------------+

            Group by actor_id, director_id
            Having count(timestamp)>=3

            | actor_id    | director_id | count(timestamp)  |
            +-------------+-------------+-------------+
            | 1           | 1           |                3                         |
            | 1           | 2           |                2                         |
            | 2           | 1           |                2                         |
            +-------------+-------------+-------------+

            select actor_id, director_id from:

            | actor_id    | director_id
            +-------------+---------+
            | 1           | 1                    |
            +-------------+---------+
 */