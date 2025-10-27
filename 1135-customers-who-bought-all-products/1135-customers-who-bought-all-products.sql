# Write your MySQL query statement below
SELECT 
    t1.customer_id AS customer_id
FROM 
    Customer AS t1
GROUP BY
    t1.customer_id
HAVING 
    COUNT(DISTINCT t1.product_key) = (
        SELECT 
            COUNT(*)
        FROM
            Product
    )