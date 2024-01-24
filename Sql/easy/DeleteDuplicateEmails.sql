select id
from person
where id
          not in (select min_id from (select min(id) as min_id from person group by email) A)

/*
 MySql

    Approach 1:

        By joining this table with itself on the Email column, we can get the following code.

SELECT p1.*
 FROM Person p1,
  Person p2
 WHERE
  p1.Email = p2.Email
 ;
Then we need to find the bigger id having same email address with other records. So we can add a new condition to the WHERE clause like this.

SELECT p1.*
 FROM Person p1,
  Person p2
 WHERE
  p1.Email = p2.Email AND p1.Id > p2.Id
 ;
As we already get the records to be deleted, we can alter this statement to DELETE in the end.

MySQL

DELETE p1 FROM Person p1,
  Person p2
 WHERE
  p1.Email = p2.Email AND p1.Id > p2.Id

    Approach 2:
        
        delete P2  FROM Person AS P1
        INNER JOIN Person AS P2
          ON (P1.email = P2.email)
        where p1.id < p2.id
 */