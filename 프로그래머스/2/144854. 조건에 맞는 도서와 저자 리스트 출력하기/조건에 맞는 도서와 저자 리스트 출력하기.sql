-- 코드를 입력하세요
SELECT a.BOOK_ID, b.AUTHOR_NAME, DATE_FORMAT(a.PUBLISHED_DATE, "%Y-%m-%d") as PUBLISHED_DATE
from book a, author b
where a.author_id = b.author_id and a.category = '경제'
order by published_date asc;