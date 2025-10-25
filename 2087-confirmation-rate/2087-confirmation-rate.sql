SELECT 
    t1.user_id,
    IFNULL( ROUND( SUM(t2.action = 'confirmed') / COUNT(t2.action), 2), 0) AS confirmation_rate
FROM 
    Signups AS t1
LEFT JOIN 
    Confirmations AS t2
ON 
    t1.user_id = t2.user_id
GROUP BY 
    t1.user_id;
