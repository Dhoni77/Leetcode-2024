CREATE OR REPLACE FUNCTION NthHighestSalary(N INT) RETURNS TABLE (Salary INT) AS $
BEGIN
  RETURN QUERY (
    -- Write your PostgreSQL query statement below.
    select distinct e.salary
    from Employee e
    order by e.salary desc
    limit 1 offset N-1
  );
END;
$ LANGUAGE plpgsql;

/*
  MYSql

  Approach 1:

    # Offset is used to skip the number of results we don't want in the result, if you skip N-1 you will fetch the N'th element.

    CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
    BEGIN
        SET N = N - 1;
      RETURN (
          # Write your MySQL query statement below.
            SELECT DISTINCT salary from employee
            order by salary desc
            limit 1 OFFSET N
      );
    END
 */