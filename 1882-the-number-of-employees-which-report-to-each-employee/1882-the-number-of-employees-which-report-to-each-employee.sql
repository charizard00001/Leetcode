# Write your MySQL query statement below
SELECT 
    t1.employee_id AS employee_id,
    t1.name AS name,
    COUNT(*) AS reports_count,
    ROUND(AVG(t2.age), 0) AS average_age
FROM
    Employees AS t1
    LEFT JOIN Employees AS t2
    ON t1.employee_id = t2.reports_to
WHERE 
    t2.reports_to IS NOT NULL
GROUP BY
    t1.employee_id
ORDER BY
    t1.employee_id

