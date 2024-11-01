select count(*) as FISH_COUNT
from FISH_INFO a, FISH_NAME_INFO b
where a.FISH_TYPE = b.FISH_TYPE and b.FISH_TYPE in (select FISH_TYPE
                   from FISH_NAME_INFO
                   where FISH_NAME in ('BASS', 'SNAPPER'))
            