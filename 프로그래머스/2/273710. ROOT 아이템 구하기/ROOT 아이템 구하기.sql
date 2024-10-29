-- 코드를 작성해주세요
select a.ITEM_ID, a.ITEM_NAME
from ITEM_INFO a, ITEM_TREE b
where a.ITEM_ID = b.ITEM_ID and b.PARENT_ITEM_ID is null
order by a.ITEM_ID