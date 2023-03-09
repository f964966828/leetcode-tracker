# Write your MySQL query statement below
SELECT
    name,
    IFNULL(SUM(distance), 0) as travelled_distance
FROM users
LEFT JOIN rides
ON users.id = rides.user_id
GROUP BY users.id, name
ORDER BY travelled_distance DESC, name
