-- 코드를 입력하세요
SELECT HOUR(DATETIME) as HOUR, count(ANIMAL_ID)
from ANIMAL_OUTS
group by hour
having hour >= 9 and hour < 20
order by hour