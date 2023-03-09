# Write your MySQL query statement below
WITH info AS (
    SELECT
        account,
        SUM(amount) as balance
    FROM transactions
    GROUP BY account
)

SELECT
    users.name,
    info.balance
FROM info
JOIN users
ON info.account = users.account
WHERE balance > 10000
