-- 코드를 작성해주세요
select a.id, b.FISH_NAME, LENGTH
from FISH_INFO a, FISH_NAME_INFO b
where a.FISH_TYPE = b.FISH_TYPE and a.LENGTH is not null and a.LENGTH = (
      SELECT MAX(length)
      FROM FISH_INFO
      WHERE FISH_TYPE = a.FISH_TYPE
  )
order by a.id