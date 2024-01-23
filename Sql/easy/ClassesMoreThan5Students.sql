-- Write your PostgreSQL query statement below
select class
from Courses
group by class
having count(*) >= 5

select class
from (select class, count(*) from courses group by class having count(*) >= 5) as c