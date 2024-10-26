-- 코드를 작성해주세요
select Count(*) as FISH_COUNT
from FISH_INFO
WHERE DATE_FORMAT(TIME, '%Y') = 2021;
