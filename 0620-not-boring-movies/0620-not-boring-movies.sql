SELECT *
FROM    
    Cinema as t1
WHERE 
    MOD(t1.id, 2) = 1
    AND t1.description != 'boring'
ORDER BY 
    t1.rating DESC