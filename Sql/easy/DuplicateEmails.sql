# Write your MySQL query statement below
SELECT Email FROM Person
GROUP BY Email HAVING COUNT(*) > 1;

/*
 MySql

    Approach 1:

        select Email from
         (
          select Email, count(Email) as num
          from Person
          group by Email
         ) as statistic
         where num > 1;

    Approach 2:

        We can use a self-join to join the Person table with itself, and then filter out the records where the id is different but the email is the same.

        SELECT DISTINCT p1.email
        FROM
            person AS p1,
            person AS p2
        WHERE p1.id != p2.id AND p1.email = p2.email;
 */