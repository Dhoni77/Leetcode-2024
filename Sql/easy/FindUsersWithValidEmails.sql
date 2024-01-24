-- Write your PostgreSQL query statement below
SELECT *
FROM Users
WHERE mail ~ '^[A-Za-z][A-Za-z0-9._-]*@leetcode\.com$'

/*
 -- Write your PostgreSQL query statement below
SELECT *
FROM Users
WHERE
    mail ~ '^[[:alpha:]](\d|\w|\.|\_|\-)*@leetcode\.com'
 */

/*
 MySql

    Approach 1:
        https://dev.mysql.com/doc/refman/8.0/en/regexp.html#function_regexp-substr
        # Write your MySQL query statement below
        select
            user_id,
            name,
            mail
        from users
        where
            lower(mail) REGEXP '^[a-z][a-z0-9_.-]*@leetcode[.]com'

    Approach 2:

        select * from Users
        where regexp_like(mail, '^[A-Za-z]+[A-Za-z0-9\_\.\-]*@leetcode.com')
 */