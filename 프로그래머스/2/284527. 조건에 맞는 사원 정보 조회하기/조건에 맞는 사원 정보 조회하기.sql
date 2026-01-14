-- 코드를 작성해주세요
WITH cte as(
SELECT SCORE, EMP_NO FROM (
    SELECT EMP_NO, rank() over (order by sum(score) desc) as rnk, sum(score) as SCORE
    FROM HR_GRADE
    GROUP BY EMP_NO
) as tt 
WHERE rnk = 1)

SELECT SCORE, cte.EMP_NO, EMP_NAME, POSITION, EMAIL FROM cte
JOIN HR_EMPLOYEES as HE
ON cte.EMP_NO = HE.EMP_NO
JOIN HR_DEPARTMENT as HD
ON HE.DEPT_ID = HD.DEPT_ID