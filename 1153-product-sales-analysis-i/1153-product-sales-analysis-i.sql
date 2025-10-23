SELECT
    -- columns or expressions you want to output
    t2.product_name AS product_name,
    t1.year AS year,
    t1.price AS price
    
FROM
    Sales AS t1
    -- LEFT JOIN: all from left + matching right
    LEFT JOIN Product AS t2 
    ON t1.product_id = t2.product_id
