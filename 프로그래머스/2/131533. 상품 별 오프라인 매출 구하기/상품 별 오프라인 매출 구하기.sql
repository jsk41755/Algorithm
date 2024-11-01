-- 코드를 입력하세요
SELECT a.PRODUCT_CODE, sum(a.PRICE * b.SALES_AMOUNT) as SALES
from PRODUCT a, OFFLINE_SALE b
where a.PRODUCT_ID = b.PRODUCT_ID
group by b.PRODUCT_ID
order by SALES desc, a.PRODUCT_CODE
