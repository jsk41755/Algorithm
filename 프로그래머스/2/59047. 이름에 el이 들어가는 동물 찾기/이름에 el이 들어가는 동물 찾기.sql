-- 코드를 입력하세요
SELECT ANIMAL_ID, NAME
from ANIMAL_INS 
where ANIMAL_TYPE = 'Dog' and NAME Like '%el%'
order by NAME