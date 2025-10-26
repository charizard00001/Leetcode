# Write your MySQL query statement below
SELECT
    ROUND(COUNT(DISTINCT t2.player_id) / COUNT(DISTINCT t1.player_id), 2) AS fraction  
FROM
    Activity AS t1
    LEFT JOIN Activity AS t2
    ON t1.player_id = t2.player_id
    AND DATEDIFF(t2.event_date, t1.event_date) = 1
WHERE 
    t1.event_date = (
        SELECT MIN(event_date)
        FROM Activity
        WHERE t1.player_id = player_id
    )