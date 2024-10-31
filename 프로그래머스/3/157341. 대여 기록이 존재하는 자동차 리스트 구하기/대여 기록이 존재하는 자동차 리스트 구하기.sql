-- 코드를 입력하세요
SELECT a.CAR_ID
from CAR_RENTAL_COMPANY_CAR a, CAR_RENTAL_COMPANY_RENTAL_HISTORY b
where a.CAR_ID = b.CAR_ID and a.CAR_TYPE = '세단' and (b.CAR_ID, b.START_DATE) in (select CAR_ID, START_DATE
                                                      from CAR_RENTAL_COMPANY_RENTAL_HISTORY 
                                                      where MONTH(START_DATE) = '10'
                                                      group by b.CAR_ID)
group by b.CAR_ID
order by b.CAR_ID desc