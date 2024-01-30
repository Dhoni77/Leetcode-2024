WITH
  RankedEnrollments AS (
    SELECT
      student_id,
      course_id,
      grade,
      RANK() OVER(
        PARTITION BY student_id
        ORDER BY grade DESC, course_id
      ) AS `rank`
    FROM Enrollments
  )
SELECT
  student_id,
  course_id,
  grade
FROM RankedEnrollments
WHERE `rank` = 1;

/*
 MySql

Solution 1: RANK() OVER() Window Function
We can use the RANK() OVER() window function to sort the grades of each student in descending order. If the grades are the same, we sort them in ascending order by course number, and then select the record with a rank of
1
1 for each student.


MySQL

# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY student_id
                ORDER BY grade DESC, course_id
            ) AS rk
        FROM Enrollments
    )
SELECT student_id, course_id, grade
FROM T
WHERE rk = 1
ORDER BY student_id;

Solution 2: Subquery
We can first query the highest grade of each student, and then query the minimum course number corresponding to the highest grade of each student.


MySQL

# Write your MySQL query statement below
SELECT student_id, MIN(course_id) AS course_id, grade
FROM Enrollments
WHERE
    (student_id, grade) IN (
        SELECT student_id, MAX(grade) AS grade
        FROM Enrollments
        GROUP BY 1
    )
GROUP BY 1
ORDER BY 1;
 */