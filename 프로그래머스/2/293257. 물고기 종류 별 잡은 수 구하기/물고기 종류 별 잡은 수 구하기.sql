select count(a.id) as FISH_COUNT, b.FISH_NAME
from FISH_INFO a, FISH_NAME_INFO b
where a.FISH_TYPE = b.FISH_TYPE
group by b.FISH_TYPE, b.FISH_NAME
order by FISH_COUNT desc