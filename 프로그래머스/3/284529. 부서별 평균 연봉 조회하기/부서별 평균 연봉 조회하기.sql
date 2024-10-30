select a.DEPT_ID, a.DEPT_NAME_EN, round(avg(b.SAL),0) as AVG_SAL
from HR_DEPARTMENT a, HR_EMPLOYEES b
where a.DEPT_ID	= b.DEPT_ID
group by a.DEPT_NAME_EN, a.DEPT_ID, a.DEPT_NAME_KR, a.LOCATION
order by AVG_SAL desc
