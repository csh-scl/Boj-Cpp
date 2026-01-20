-- 코드를 작성해주세요
-- 세대를 포함한 정보 
WITH RECURSIVE cte as(
    SELECT ID, PARENT_ID, 1 as GEN
    FROM ECOLI_DATA 
    WHERE PARENT_ID is null
    
    UNION ALL
    
    SELECT e.ID, e.PARENT_ID, GEN+1
    FROM ECOLI_DATA as e
    JOIN cte
    ON e.PARENT_ID = cte.ID 
)

SELECT count(*) as COUNT, GEN as GENERATION FROM cte
LEFT JOIN ECOLI_DATA as ch
ON cte.ID = ch.PARENT_ID
WHERE ch.PARENT_ID is null
GROUP BY GEN