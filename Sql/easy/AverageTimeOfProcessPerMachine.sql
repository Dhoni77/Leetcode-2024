-- Write your PostgreSQL query statement below
SELECT a1.machine_id,
       ROUND(AVG(a1.timestamp-a2.timestamp)::numeric,3) as processing_time
FROM Activity a1 INNER JOIN Activity a2
                            ON a1.machine_id=a2.machine_id
WHERE a1.activity_type='end' AND a2.activity_type='start'
GROUP BY a1.machine_id;

/*
 Sql

 Approach 1: Transform Values with CASE WHEN and then Calculate

     SELECT
        machine_id,
        ROUND(SUM(CASE WHEN activity_type='start' THEN timestamp*-1 ELSE timestamp END)*1.0
        / (SELECT COUNT(DISTINCT process_id)),3) AS processing_time
    FROM
        Activity
    GROUP BY machine_id

 Approach 2: Calling the original Table twice and Calculate as two columns

     SELECT a.machine_id,
           ROUND(AVG(b.timestamp - a.timestamp), 3) AS processing_time
    FROM Activity a,
         Activity b
    WHERE
        a.machine_id = b.machine_id
    AND
        a.process_id = b.process_id
    AND
        a.activity_type = 'start'
    AND
        b.activity_type = 'end'
    GROUP BY machine_id

 Approach 1 improvement:

     # Write your MySQL query statement below
    SELECT
        machine_id,
        ROUND(AVG(IF(activity_type = 'start', -1, 1) * timestamp) * 2, 3) AS processing_time
    FROM Activity
    GROUP BY 1;
 */

