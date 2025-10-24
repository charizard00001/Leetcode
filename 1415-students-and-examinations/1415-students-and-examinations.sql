# Write your MySQL query statement below
SELECT
    t1.student_id AS student_id,
    t1.student_name AS student_name,
    t2.subject_name AS subject_name,
    COUNT(t3.student_id) AS attended_exams
FROM Students AS t1
CROSS JOIN Subjects AS t2
LEFT JOIN Examinations AS t3
    ON t1.student_id = t3.student_id 
    AND t2.subject_name = t3.subject_name 
GROUP BY t1.student_id, t1.student_name, t2.subject_name
ORDER BY t1.student_id, t2.subject_name