-- Write your PostgreSQL query statement below
-- id where viewer_id = author_id
-- order by id (viewer_id) in asc order

-- Faster solution with group by

select viewer_id as id
from Views
where viewer_id = author_id
group by viewer_id
order by id

/*
SELECT DISTINCT author_id AS id
FROM Views
WHERE author_id = viewer_id
ORDER BY id;
 */