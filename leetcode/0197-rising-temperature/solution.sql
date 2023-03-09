# Write your MySQL query statement below
WITH info AS (
    SELECT
        w1.id,
        w1.recordDate,
        w1.temperature,
        w2.temperature as temperature2
    FROM weather w1
    JOIN weather w2
    ON DATE_SUB(w1.recordDate, INTERVAL 1 DAY) = w2.recordDate
)

SELECT 
    id
FROM info
WHERE temperature > temperature2
