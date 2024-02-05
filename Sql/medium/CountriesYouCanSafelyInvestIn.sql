# Write your MySQL query statement below
SELECT country
FROM
    (
        SELECT c.name AS country, AVG(duration) AS duration
        FROM
            Person
            JOIN Calls ON id IN(caller_id, callee_id)
            JOIN Country AS c ON LEFT(phone_number, 3) = country_code
        GROUP BY 1
    ) AS t
WHERE duration > (SELECT AVG(duration) FROM Calls);

/*
 MySql

    Approach 1:

        select country.name from person
        join country on left(phone_number, 3) = country_code
        join calls on id = caller_id or id = callee_id
        group by country.name
        having sum(duration) / count(*) > (SELECT AVG(duration) FROM Calls)
        order by country.name

    Approach 2:

        SELECT Country.name AS country
        FROM Person
        INNER JOIN Country
          ON (SUBSTRING(Person.phone_number, 1, 3) = Country.country_code)
        INNER JOIN Calls
          ON (Person.id IN (Calls.caller_id, Calls.callee_id))
        GROUP BY 1
        HAVING AVG(Calls.duration) > (
            SELECT AVG(duration) FROM Calls
          );

    Approach 3:

        -- id_country- get country name for each person by joining on country code
        -- id_duration- duration for each person on each call- each person can have multiple rows
        -- final query- join these 2 to calculate avg for each country- group by country
        -- use having clause to filter avg for country > global avg (calculated using id_duration cte)


        with id_country as
            (select p.id, c.name as country
            from Person p
            join Country c
            on left(p.phone_number, 3) = c.country_code),

            id_duration as
            (select caller_id, duration
            from Calls
            union all
            select callee_id, duration
            from Calls)

        select c.country
        from id_country c
        join id_duration d
        on c.id = d.caller_id
        group by c.country
        having avg(duration) > (select avg(duration)
                                from id_duration)
 */