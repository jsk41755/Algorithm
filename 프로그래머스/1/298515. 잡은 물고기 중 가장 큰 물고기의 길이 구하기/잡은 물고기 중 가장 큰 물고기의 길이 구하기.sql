select concat(max(Length), 'cm') as MAX_LENGTH
from fish_info
where length is not null