-- 코드를 작성해주세요
WITH cte as (SELECT EMP_NO, CASE
    WHEN avg(SCORE) >= 96 THEN 'S'
    WHEN avg(SCORE) >= 90 THEN 'A' 
    WHEN avg(SCORE) >= 80 THEN 'B'
    ELSE 'C'
END AS grade
FROM HR_GRADE 
GROUP BY EMP_NO)

SELECT cte.EMP_NO, hr.EMP_NAME, cte.grade as GRADE, CASE
    WHEN cte.grade = 'S' THEN hr.SAL * 0.2 
    WHEN cte.grade = 'A' THEN hr.SAL * 0.15
    WHEN cte.grade = 'B' THEN hr.SAL * 0.1
    ELSE 0
END AS BONUS
FROM cte
JOIN HR_EMPLOYEES  as hr
ON cte.EMP_NO = hr.EMP_NO
ORDER BY cte.EMP_NO asc
