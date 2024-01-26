WITH
  InsuranceWithCounts AS (
    SELECT
      tiv_2016,
      COUNT(*) OVER(PARTITION by tiv_2015) AS tiv_2015_count,
      COUNT(*) OVER(PARTITION by lat, lon) AS city_count
    FROM Insurance
  )
select round(sum(tiv_2016), 2) as tiv_2016
from InsuranceWithCounts
where tiv_2015_count > 1
and city_count = 1

/*
 MySql

 Approach: Using GROUP BY and COUNT [Accepted]
Intuition

To decide whether a value in a column is unique or not, we can use GROUP BY and COUNT.

Algorithm

Check whether the value of a record's TIV_2015 is unique, if it is not unique, and at the same time, its location (LAT, LON) pair is unique, then this record meeting the criteria. So it should be counted in the sum.

MySQL

SELECT
  ROUND(SUM(insurance.TIV_2016),2) AS TIV_2016
 FROM
  insurance
 WHERE
  insurance.TIV_2015 IN
  (
  SELECT
  TIV_2015
  FROM
  insurance
  GROUP BY TIV_2015
  HAVING COUNT(*) > 1
  )
  AND CONCAT(LAT, LON) IN
  (
  SELECT
  CONCAT(LAT, LON)
  FROM
  insurance
  GROUP BY LAT , LON
  HAVING COUNT(*) = 1
  )
 ;
Tips: Concat the LAT and LON as a whole to represent the location information.

Note: These two criteria should be met without an order, so if you attempt to filter data using criteria #1 first and then criteria #2, you will get a wrong result.

Taking the sample input as an example, the data set will be as following after taking the first criteria.

PID	TIV_2015	TIV_2016	LAT	LON
1	10	5	10	10
3	10	30	20	20
4	10	40	40	40
Then, the second criteria cannot filter any records on this data set. So the result is 75(5+30+40), which is obviously wrong since the location of record with PID '3' is actually the same with the record having been filtered by the first criteria.

PID	TIV_2015	TIV_2016	LAT	LON
2	20	20	20	20
3	10	30	20	20


 Approach 2:

    select round(sum(tiv_2016),2) as tiv_2016
    from insurance
    where tiv_2015 in (select tiv_2015 from insurance group by  tiv_2015  having count(*)>1) and (lat,lon) in (select lat,lon from insurance group by lat,lon having count(*)=1)
 */