-- 코드를 입력하세요
SELECT BOARD_ID, WRITER_ID, TITLE, PRICE, case when status = 'DONE' then '거래완료' when status = 'SALE' then '판매중' else '예약중' end as STATUS
from USED_GOODS_BOARD
where date_format(CREATED_DATE, '%Y-%m-%d') = '2022-10-05'
order by BOARD_ID desc