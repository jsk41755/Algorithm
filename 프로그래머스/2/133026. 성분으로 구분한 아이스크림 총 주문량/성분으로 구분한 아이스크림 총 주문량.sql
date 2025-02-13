-- 코드를 입력하세요
SELECT b.INGREDIENT_TYPE, SUM(TOTAL_ORDER) as TOTAL_ORDER
from FIRST_HALF a, ICECREAM_INFO b
where a.FLAVOR = b.FLAVOR
GROUP BY b.INGREDIENT_TYPE
order by count(INGREDIENT_TYPE)