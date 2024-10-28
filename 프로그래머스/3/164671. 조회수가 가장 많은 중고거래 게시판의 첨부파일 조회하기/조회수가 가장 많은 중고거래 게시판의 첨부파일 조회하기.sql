-- 코드를 입력하세요
SELECT concat('/home/grep/src/', a.Board_ID, '/', b.FILE_ID, b.FILE_NAME, b.FILE_EXT) as FILE_PATH
FROM USED_GOODS_BOARD a, USED_GOODS_FILE b
where a.BOARD_ID = b.BOARD_ID and a.views =
    (select views
     from USED_GOODS_BOARD
     order by views desc
     limit 1
    )
order by b.FILE_ID desc
