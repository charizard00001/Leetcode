# Write your MySQL query statement below
SELECT 
    -- columns or expressions you want to output
    t1.customer_id AS customer_id,
    COUNT(*) AS count_no_trans
FROM
    Visits AS t1
    -- LEFT JOIN: all from left + matching right
    LEFT JOIN Transactions AS t2 ON t1.visit_id = t2.visit_id

WHERE
    -- filter conditions
    t2.visit_id IS NULL

GROUP BY
    -- for aggregation functions
    t1.customer_id