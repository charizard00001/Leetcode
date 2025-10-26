# Write your MySQL query statement below
# [2019-06-28, 2019-07-27]
SELECT
    t1.activity_date AS day,
    COUNT(DISTINCT t1.user_id) AS active_users
FROM
    Activity AS t1
WHERE 
    t1.activity_date BETWEEN '2019-06-28' AND '2019-07-27'
GROUP BY 
    t1.activity_date


    