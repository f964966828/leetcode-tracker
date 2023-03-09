# Write your MySQL query statement below
WITH order_info AS (
    SELECT
        buyer_id,
        COUNT(*) as orders_in_2019
    FROM orders
    WHERE order_date BETWEEN '2019-01-01' AND '2020-01-01'
    GROUP BY buyer_id
)

SELECT
    user_id as buyer_id,
    join_date,
    IFNULL(orders_in_2019, 0) as orders_in_2019
FROM users
LEFT JOIN order_info
ON user_id = buyer_id

