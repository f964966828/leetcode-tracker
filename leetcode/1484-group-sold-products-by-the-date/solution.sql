# Write your MySQL query statement below
SELECT
    sell_date,
    COUNT(distinct product) as num_sold,
    group_concat(distinct product separator ",") as products
FROM Activities
GROUP BY sell_date
ORDER BY sell_date
