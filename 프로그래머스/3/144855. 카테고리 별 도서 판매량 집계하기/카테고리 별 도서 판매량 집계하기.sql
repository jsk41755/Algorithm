-- 코드를 입력하세요
SELECT a.CATEGORY, sum(b.SALES) as TOTAL_SALES
from BOOK a, BOOK_SALES b
where a.BOOK_ID = b.BOOK_ID and Date_Format(b.SALES_DATE, '%Y-%m') = '2022-01'
group by a.CATEGORY
order by a.CATEGORY
