# Write your MySQL query statement below
SELECT
    -- columns or expressions you want to output
    t1.machine_id, 
    ROUND(AVG(t2.timestamp - t1.timestamp), 3) AS processing_time

FROM
    Activity AS t1
    -- INNER JOIN: only matching rows
    JOIN Activity AS t2 
    ON t1.machine_id = t2.machine_id
    AND t1.process_id = t2.process_id

WHERE
    -- filter conditions
    t1.activity_type = 'start'
    AND t2.activity_type = 'end'

GROUP BY
    -- for aggregation functions
    t1.machine_id
