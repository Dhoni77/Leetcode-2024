-- Write your PostgreSQL query statement below
SELECT x, y, z, (CASE WHEN x + y > z AND y + z > x AND x + z > y THEN 'Yes' ELSE 'No' END) triangle
FROM Triangle

/*
 MySql

 Approach 1:

 select *, if(x + y > z and y + z > x and x + z > y, 'Yes', 'No') triangle from triangle;
 */