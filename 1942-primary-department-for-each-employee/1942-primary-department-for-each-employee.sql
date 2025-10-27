SELECT 
    t1.employee_id AS employee_id,
    t1.department_id AS department_id
FROM
    Employee AS t1
WHERE 
    t1.primary_flag = 'Y'
    OR t1.employee_id IN (
        SELECT 
            t2.employee_id
        FROM
            Employee AS t2
        GROUP BY
            t2.employee_id
        HAVING 
            COUNT(*) = 1
    )