WITH RECURSIVE cte AS (
    SELECT 0 as hour
    UNION ALL
    SELECT hour + 1 FROM cte WHERE hour < 23
)


SELECT cte.hour, COALESCE(cnt.val, 0) as COUNT FROM cte 
LEFT JOIN 
    (SELECT HOUR(DATETIME) as hour, count(*) as val
    FROM ANIMAL_OUTS
    GROUP BY HOUR(DATETIME)) as cnt
ON cte.hour = cnt.hour