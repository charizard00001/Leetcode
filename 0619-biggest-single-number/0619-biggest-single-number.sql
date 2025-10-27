# Write your MySQL query statement below
SELECT 
    MAX(t1.num) AS num
FROM (
    SELECT 
        t2.num
    FROM 
        MyNumbers AS t2
    GROUP BY
        t2.num
    HAVING
        COUNT(*) = 1
)
AS t1

