# Write your MySQL query statement below
SELECT
    a.employee_id
FROM (
    SELECT employee_id 
    FROM employees
    WHERE employee_id NOT IN
        (SELECT employee_id FROM salaries)

    UNION

    SELECT employee_id 
    FROM salaries
    WHERE employee_id NOT IN
        (SELECT employee_id FROM employees)    
) a
ORDER BY a.employee_id
