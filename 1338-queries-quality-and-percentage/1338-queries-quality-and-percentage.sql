# Write your MySQL query statement below
SELECT 
    t1.query_name AS query_name,
    ROUND(SUM(t1.rating / t1.position) / COUNT(*), 2) AS quality,
    ROUND((SUM(t1.rating < 3) * 100) / COUNT(*), 2) AS poor_query_percentage 
FROM
    Queries AS t1
GROUP BY 
    t1.query_name
