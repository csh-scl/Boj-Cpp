-- 코드를 입력하세요
Select month(start_date) as MONTH, CAR_ID, count(*) as RECORDS from CAR_RENTAL_COMPANY_RENTAL_HISTORY 
Where car_id in 
(Select car_id from CAR_RENTAL_COMPANY_RENTAL_HISTORY 
Where year(start_date) = 2022 and month(start_date) in (8,9,10)
Group by car_id
Having count(*) >= 5) 
and month(start_date) in (8,9,10)
group by month(start_date), car_id

order by MONTH asc, CAR_ID desc 
