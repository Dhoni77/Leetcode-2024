# Write your MySQL query statement below
WITH
    T AS (
        SELECT user1_id AS user_id FROM Friendship WHERE user2_id = 1
        UNION
        SELECT user2_id AS user_id FROM Friendship WHERE user1_id = 1
    )
SELECT DISTINCT page_id AS recommended_page
FROM
    T
    JOIN Likes USING (user_id)
WHERE page_id NOT IN (SELECT page_id FROM Likes WHERE user_id = 1);

/*
 MySql

    Approach 1:

        # Write your MySQL query statement below
        SELECT DISTINCT page_id AS recommended_page
        FROM Likes
        WHERE
            user_id IN (
                SELECT user1_id AS user_id FROM Friendship WHERE user2_id = 1
                UNION ALL
                SELECT user2_id AS user_id FROM Friendship WHERE user1_id = 1
            )
            AND page_id NOT IN (SELECT page_id FROM Likes WHERE user_id = 1);

    Approach 2:

                WITH
          UserToFriends AS (
            SELECT user1_id AS user_id, user2_id AS friend_id FROM Friendship
            UNION ALL
            SELECT user2_id AS user_id, user1_id AS friend_id FROM friendship
          )
        SELECT FriendLikes.page_id AS recommended_page
        FROM UserToFriends
        LEFT JOIN Likes AS FriendLikes
          ON (UserToFriends.friend_id = FriendLikes.user_id)
        LEFT JOIN Likes AS UserLikes
          ON (
            UserToFriends.user_id = UserLikes.user_id
            AND FriendLikes.page_id = UserLikes.page_id)
        WHERE
          UserToFriends.user_id = 1
          AND UserLikes.page_id IS NULL
          AND FriendLikes.page_id IS NOT NULL
        GROUP BY 1;

    Approach 3:

        -- got user1=id = 1 friends in t0 and t1
        -- joined t1 with Likes on 1's friends
        -- where condition- page shouldn't be liked by 1

        with t0 as
            (select user1_id, user2_id
            from Friendship
            union
            select user2_id, user1_id
            from Friendship),
        t1 as
            (select user1_id, user2_id
            from t0
            where user1_id = 1)

        select distinct l.page_id as recommended_page
        from t1 join Likes l
        on t1.user2_id = l.user_id
        where page_id not in
            (select page_id
            from Likes
            where user_id = 1)

    Approach 4:

        with t1 as
        (select user1_id, user2_id
        from Friendship
        union
        select user2_id, user1_id
        from Friendship)

        select distinct l.page_id as recommended_page
        from t1 join Likes l
        on t1.user2_id = l.user_id
        where t1.user1_id = 1
        and page_id not in
            (select page_id
            from Likes
            where user_id = 1)
 */