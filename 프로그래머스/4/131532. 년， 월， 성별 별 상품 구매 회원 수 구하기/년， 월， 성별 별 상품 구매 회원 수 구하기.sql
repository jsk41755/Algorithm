-- 코드를 입력하세요
SELECT YEAR(b.SALES_DATE) as YEAR,  MONTH(b.SALES_DATE) as MONTH, a.GENDER, count(distinct a.USER_ID) as USERS
from USER_INFO a, ONLINE_SALE b
where a.USER_ID = b.USER_ID and a.GENDER is not null
group by YEAR, MONTH, GENDER
order by YEAR, MONTH, GENDER