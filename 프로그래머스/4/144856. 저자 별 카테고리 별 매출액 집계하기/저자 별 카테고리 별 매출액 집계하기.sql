-- 코드를 입력하세요
SELECT a.AUTHOR_ID, b.AUTHOR_NAME, a.CATEGORY, sum(c.SALES * a.PRICE) as TOTAL_SALES
from book a, author b, book_sales c
where a.AUTHOR_ID = b.AUTHOR_ID and a.BOOK_ID = c.BOOK_ID and DATE_FORMAT(SALES_DATE, '%Y-%m') = '2022-01'
GROUP by b.AUTHOR_NAME, a.CATEGORY
order by a.AUTHOR_ID asc, a.CATEGORY desc;
