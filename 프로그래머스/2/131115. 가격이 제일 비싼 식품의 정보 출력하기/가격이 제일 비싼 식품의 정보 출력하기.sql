-- 코드를 입력하세요
-- 
select * from food_product
where product_id = (SELECT PRODUCT_ID from FOOD_PROduCT ORDER BY PRICE DESC limit 1) 

-- SELECT * from food_product