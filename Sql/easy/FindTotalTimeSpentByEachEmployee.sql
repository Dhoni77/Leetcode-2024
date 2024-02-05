
/*
 MySql

    Approach 1:
        To find the total time spent, we need to add up all the durations where the employee was in the office.
        We are told to calculate each duration using out_time - in_time, and then we can add them up using the SUM aggregate function.

        Aggregate functions in SQL are functions that can be applied over groups of data, so the natural questions is Over which groups
        are we applying this function? For this problem, we want the sum of durations for each employee, for each day, so we will need to group,
        or aggregate, our data by emp_id and event_day. We can do this using the GROUP BY clause after our FROM and WHERE clauses.
        However, we do not need a WHERE clause here because we do not need to filter the data.

        # Write your MySQL query statement below
        select event_day day, emp_id, sum(out_time - in_time) total_time
        from employees
        group by event_day, emp_id
 */