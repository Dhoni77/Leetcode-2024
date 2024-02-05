SELECT
    u.name,
    SUM(t.amount) as balance
FROM
    Users u
    JOIN Transactions t ON u.account = t.account
GROUP BY
    u.name
HAVING
    SUM(t.amount) > 10000

/*
 MySql

    Approach 1: First Calculate Then JOIN

    Algorithm
    Use SUM() to get the total balance for each account
    Use HAVING to filter the aggregated results (total balance for each account) and return only the qualified accounts
    Join the User table to get the user name for these accounts
    MySQL
    Step 1 and 2

    SELECT
        account, SUM(amount) as balance
    FROM
        Transactions
    GROUP BY 1
    HAVING
        balance>10000
    Step 3 - Join the subquery created in the previous steps to the other table

    SELECT
        DISTINCT a.name, b.balance
    FROM
        Users a
    JOIN (
        SELECT
            account, SUM(amount) as balance
        FROM
            Transactions
        GROUP BY 1
        HAVING balance>10000) b
    ON
        a.account = b.account

    Approach 2: Use JOIN and Calculate At Same Time

    Algorithm
    Select the two columns needed for the final output: name of the user, and the balance (SUM of the column amount)
    JOIN the two tables
    GROUP the results by each account, so the query will return only one result for each user
    Use HAVING to filter the aggregated results and return only the qualified accounts
    MySQL
    SELECT
        u.name, SUM(t.amount) AS balance
    FROM
        Users u
    JOIN
        Transactions t
    ON
        u.account = t.account
    GROUP BY u.account
    HAVING
        balance > 10000
 */