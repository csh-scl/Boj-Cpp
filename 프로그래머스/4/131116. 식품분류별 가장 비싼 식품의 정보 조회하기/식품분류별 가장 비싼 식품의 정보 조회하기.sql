-- 코드를 입력하세요
select CATEGORY, PRICE, PRODUCT_NAME
from (SELECT *, row_number() over (PARTition by category order by price desc) as RN
from FOOD_PRODUCT) as T
where RN = 1 and CATEGORY IN ('과자', '국', '김치', '식용유')
ORDER BY PRICE DESC