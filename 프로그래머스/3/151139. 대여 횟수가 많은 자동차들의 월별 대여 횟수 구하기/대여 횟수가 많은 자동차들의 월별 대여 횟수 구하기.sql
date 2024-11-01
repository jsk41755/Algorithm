-- 코드를 입력하세요
SELECT month(start_date) as month, CAR_ID, COUNT(HISTORY_ID) as RECORDS
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where DATE_FORMAT(START_DATE, "%Y-%m") >= '2022-08' and DATE_FORMAT(START_DATE, "%Y-%m") <= '2022-10' and
    CAR_ID in (select CAR_ID
               from CAR_RENTAL_COMPANY_RENTAL_HISTORY
               where DATE_FORMAT(START_DATE, "%Y-%m") >= '2022-08' and DATE_FORMAT(START_DATE, "%Y-%m") <= '2022-10'
               group by car_id 
               having count(history_id)>4)
group by month, car_id
having RECORDS > 0
order by month, car_id desc;