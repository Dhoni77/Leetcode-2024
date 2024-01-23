
/*
 MySql

 Approach 1:

    This code selects the row number and student name from the "seat" table, and orders the results by alternating odd and even row numbers.

Explanation:

1. The "select" statement is used to retrieve data from the "seat" table.
2. "row_number() over()" is a window function that assigns a unique row number to each row in the result set.
3. "id" is an alias for the row number assigned by the window function.
4. "student" is the name of the student in the "seat" table.
5. "order by" is used to sort the results by a specified column or expression.
6. "mod(id, 2)" returns the remainder of dividing the row number by 2.
7. "if(mod(id, 2) = 0, id - 1, id + 1)" is a conditional expression that checks if the row number is even or odd.
8. If the row number is even, the expression returns "id - 1", which assigns an odd row number to the even row.
9. If the row number is odd, the expression returns "id + 1", which assigns an even row number to the odd row.
10. The results are then ordered by the alternating odd and even row numbers.

    select row_number() over () id, student from seat
        order by if(mod(id, 2) = 0, id - 1, id + 1)

    Approach 2:

        # Write your MySQL query statement below
        SELECT
            RANK() OVER (ORDER BY (id - 1) ^ 1) AS id,
            student
        FROM Seat;

    Approach 3:

        SELECT s1.id, COALESCE(s2.student, s1.student) AS student
        FROM
            Seat AS s1
            LEFT JOIN Seat AS s2 ON (s1.id + 1) ^ 1 - 1 = s2.id
        ORDER BY 1;
 */