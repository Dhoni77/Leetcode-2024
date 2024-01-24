-- Write your PostgreSQL query statement below
-- cannot use initcap because we want `Marry ann` instead of `Marry Ann`
SELECT
user_id,
UPPER(LEFT(name, 1)) || LOWER(RIGHT(name, -1)) AS name
FROM Users
ORDER BY user_id

/*
 MySql

    Approach 1:
        select user_id,
        concat(upper(substring(name, 1, 1)),
                      lower(substring(name, 2))) as name
        from users
        order by user_id
 */