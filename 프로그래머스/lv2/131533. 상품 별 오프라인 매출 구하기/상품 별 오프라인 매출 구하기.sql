-- 코드를 입력하세요
SELECT PRODUCT_CODE, sum(PRICE* SALES_AMOUNT)as SALES
from PRODUCT as p, OFFLINE_SALE as off
where p.PRODUCT_ID = off.PRODUCT_ID
group by PRODUCT_CODE
order by SALES desc, PRODUCT_CODE;