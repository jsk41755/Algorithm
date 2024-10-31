-- 코드를 입력하세요
SELECT b.USER_ID, b.NICKNAME, 
concat(b.CITY, ' ', b.STREET_ADDRESS1, ' ', STREET_ADDRESS2) as 전체주소, 
concat(substring(TLNO, 1,3) , '-', substring(TLNO, 4,4), '-', substring(TLNO, 8)) as 전화번호
from USED_GOODS_BOARD a, USED_GOODS_USER b
where a.WRITER_ID = b.USER_ID
group by a.WRITER_ID
having count(a.WRITER_ID) >= 3
order by b.USER_ID desc
