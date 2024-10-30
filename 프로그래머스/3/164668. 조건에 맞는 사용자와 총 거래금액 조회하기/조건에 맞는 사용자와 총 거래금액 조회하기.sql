-- 코드를 입력하세요
SELECT b.USER_ID, b.NICKNAME, sum(PRICE) as TOTAL_SALES
from USED_GOODS_BOARD a, USED_GOODS_USER b
where a.WRITER_ID = b.USER_ID and a.STATUS = 'DONE'
group by a.WRITER_ID
having TOTAL_SALES >= 700000
order by TOTAL_SALES