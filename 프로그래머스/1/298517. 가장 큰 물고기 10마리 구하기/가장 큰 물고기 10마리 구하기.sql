-- 코드를 작성해주세요
select ID, LENGTH
from fish_info
where length is Not null
order by length DESC, id asc
limit 10