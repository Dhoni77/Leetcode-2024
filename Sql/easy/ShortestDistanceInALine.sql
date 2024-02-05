SELECT min(p2.x - p1.x) as shortest
FROM
    Point AS p1
    JOIN Point AS p2 ON p1.x < p2.x;

/*
 MySql

    Approach 1:

        # Write your MySQL query statement below
        SELECT x - LAG(x) OVER (ORDER BY x) AS shortest
        FROM Point
        ORDER BY 1
        LIMIT 1, 1;

    Approach 2:

        -- cross joining all the points from 2 tables, except the ones where they are same
        -- find the min of absolute distance

        select min(abs(a - b)) as shortest
        from
          (select p1.x as a, p2.x as b
          from Point p1 cross join Point p2
          where p1.x != p2.x) temp
 */