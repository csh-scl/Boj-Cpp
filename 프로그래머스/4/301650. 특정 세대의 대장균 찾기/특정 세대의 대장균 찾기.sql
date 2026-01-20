-- 코드를 작성해주세요
WITH RECURSIVE cte as(
    SELECT ID, PARENT_ID, 1 as gen
    FROM ECOLI_DATA 
    WHERE PARENT_ID is null
    
    UNION ALL
    
    SELECT e.ID, e.PARENT_ID, cte.gen + 1
    FROM ECOLI_DATA as e
    JOIN cte 
    ON cte.ID = e.PARENT_ID
)

SELECT ID FROM cte
WHERE gen = 3
ORDER BY ID 