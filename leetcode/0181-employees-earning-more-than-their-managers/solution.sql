# Write your MySQL query statement below
SELECT name as Employee
FROM (
    SELECT e1.name, e1.salary, e2.salary as manager_salary
    FROM Employee as e1
    JOIN Employee as e2
    ON e1.managerId = e2.id) t
WHERE salary > manager_salary
