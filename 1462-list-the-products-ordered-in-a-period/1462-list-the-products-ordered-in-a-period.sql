-- name, amt
-- >= 100 units, feb 2020

SELECT 
    p.product_name, SUM(o.unit) AS unit
FROM 
    Products p
LEFT JOIN Orders o
    ON p.product_id = o.product_id
WHERE 
    -- DATE_FORMAT(order_date, '%Y-%m') = '2020-02'
    EXTRACT(YEAR FROM order_date) = '2020'
    AND EXTRACT(MONTH FROM order_date) = '02'
GROUP BY 
    p.product_name
HAVING 
    SUM(o.unit) >= 100