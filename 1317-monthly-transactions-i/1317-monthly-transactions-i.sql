SELECT 
    DATE_FORMAT(t1.trans_date, '%Y-%m') AS month,
    t1.country AS country,
    COUNT(*) AS trans_count,
    SUM(t1.state = 'approved') AS approved_count,
    SUM(t1.amount) AS trans_total_amount,
    SUM(CASE WHEN t1.state = 'approved' THEN t1.amount ELSE 0 END) AS approved_total_amount
FROM 
    Transactions AS t1
GROUP BY
    month, t1.country

-- SQL logically executes GROUP BY before SELECT, the query parser/compiler knows that aliases defined in SELECT can be reused in GROUP BY or ORDER BY for convenience.