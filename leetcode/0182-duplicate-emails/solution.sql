# Write your MySQL query statement below
SELECT email
FROM Person
Group By email
HAVING count(*) >= 2
