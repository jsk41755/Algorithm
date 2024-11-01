select a.item_id, a.item_name, a.rarity
from ITEM_INFO a, ITEM_TREE b
where a.item_id = b.item_id and b.PARENT_ITEM_ID IN (SELECT ITEM_ID
                              FROM ITEM_INFO
                              WHERE RARITY='RARE')
order by a.item_id desc