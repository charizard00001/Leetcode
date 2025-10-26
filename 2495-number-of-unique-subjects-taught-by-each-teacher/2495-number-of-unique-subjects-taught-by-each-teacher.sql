SELECT 
    t1.teacher_id AS teacher_id,
    COUNT(DISTINCT t1.subject_id) AS cnt
FROM
    Teacher AS t1
GROUP BY 
    t1.teacher_id
