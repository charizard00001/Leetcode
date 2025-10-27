# Write your MySQL query statement below
SELECT 
    t1.class
FROM
    Courses AS t1
GROUP BY 
    t1.class
HAVING 
    COUNT(student) >= 5