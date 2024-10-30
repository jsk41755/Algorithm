SELECT CATEGORY, PRICE as MAX_PRICE, PRODUCT_NAME
FROM FOOD_PRODUCT 
where (CATEGORY, PRICE) in (select CATEGORY, max(PRICE)
                  from FOOD_PRODUCT
                  GROUP BY CATEGORY
                  HAVING CATEGORY IN ('과자', '국', '김치', '식용유'))
order by MAX_PRICE desc