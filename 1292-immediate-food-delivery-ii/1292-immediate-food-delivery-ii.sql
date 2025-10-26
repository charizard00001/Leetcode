# Write your MySQL query statement below
SELECT 
    ROUND(
        COUNT(*) / ( SELECT COUNT(DISTINCT customer_id) FROM Delivery ) * 100, 
        2
    ) AS immediate_percentage
FROM 
    (
        SELECT 
            t1.customer_id
        FROM
            Delivery AS t1
        GROUP BY
            t1.customer_id
        HAVING 
            MIN(order_date) = MIN(customer_pref_delivery_date)
    )
AS t2

-- SELECT 
--     t1.customer_id
-- FROM
--     Delivery AS t1
-- GROUP BY
--     t1.customer_id
-- HAVING 
--     MIN(order_date) = MIN(customer_pref_delivery_date)
    