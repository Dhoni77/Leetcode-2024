# Write your MySQL query statement below
SELECT DISTINCT title
FROM
    TVProgram
    JOIN Content USING (content_id)
WHERE
    DATE_FORMAT(program_date, '%Y-%m') = '2020-06'
    AND kids_content = 'Y'
    AND content_type = 'Movies';