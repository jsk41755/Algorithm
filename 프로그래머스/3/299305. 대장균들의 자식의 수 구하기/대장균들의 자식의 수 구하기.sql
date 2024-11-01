select id, ifnull((select count(*)
                             from ECOLI_DATA 
                             group by PARENT_ID
                             having PARENT_ID = id), 0) as CHILD_COUNT
from ECOLI_DATA 
order by id;