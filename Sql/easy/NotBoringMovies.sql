-- Write your PostgreSQL query statement below
select id, movie, cinema.description, rating
from cinema
where id%2 <> 0 and cinema.description <> 'boring'
order by rating desc

/*
 Mysql

 Approach 1:

 select *
 from cinema
 where mod(id, 2) = 1 and description != 'boring'
 order by rating DESC;
 */