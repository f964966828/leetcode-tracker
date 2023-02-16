# Write your MySQL query statement below
WITH employeeInfo AS(
    SELECT 
        d.name as "department",
        e.name as "employee", 
        salary
    FROM employee as e
    JOIN department as d
    ON e.departmentId = d.id
), departmentInfo AS(
    SELECT
        department,
        max(salary) as maxSalary
    FROM employeeInfo
    GROUP BY department
)

SELECT 
    e.department,
    employee,
    salary
FROM employeeInfo as e
JOIN  departmentInfo as d
ON e.department = d.department
WHERE e.salary = d.maxSalary

