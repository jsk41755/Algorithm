-- 코드를 입력하세요
SELECT ANIMAL_TYPE, case when name is null then 'No name' else name END as NAME, SEX_UPON_INTAKE
from ANIMAL_INS
