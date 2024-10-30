select a.EMP_NO, a.EMP_NAME, 
 case when avg(b.score) >= 96 then 'S' when avg(b.score) >= 90 then 'A' when avg(b.score) >= 80 then 'B' else 'C' end as GRADE,
 case when avg(b.score) >= 96 then SAL * 0.2 when avg(b.score)>= 90 then SAL * 0.15 when avg(b.score) >= 80 then SAL * 0.1 else 0 end as BONUS
from HR_EMPLOYEES a, HR_GRADE b
where a.EMP_NO = b.EMP_NO
group by b.EMP_NO
order by a.EMP_NO
