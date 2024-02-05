/*
 -- Write your PostgreSQL query statement below

SELECT
    id,
    CASE
        WHEN p_id IS NULL
        THEN 'Root'
        WHEN EXISTS(SELECT 1 FROM Tree t2 WHERE t2.p_id = t1.id)
        THEN 'Inner'
        ELSE 'Leaf'
        END
    as type
FROM Tree t1
 */

# Write your MySQL query statement below
Select id, (case when p_id is null then 'Root'
                 when id in (Select p_id From Tree) then 'Inner'
                 else 'Leaf' end) as type
From Tree
/*
 MySql

    Approach 1:

        # Write your MySQL query statement below
        WITH parents AS
        (
        SELECT DISTINCT p_id AS id
        FROM Tree
        WHERE p_id IS NOT NULL
        )

        SELECT
            t.id,
            CASE WHEN t.p_id IS NULL THEN 'Root'
            WHEN p.id IS NOT NULL THEN 'Inner'
            ELSE 'Leaf' END AS type
        FROM Tree AS t
        LEFT JOIN parents AS p
            ON t.id = p.id

    Approach 2:

        SELECT DISTINCT Parent.id,
          (
            CASE
              WHEN Parent.p_id IS NULL THEN 'Root'
              WHEN Parent.p_id IS NOT NULL AND Child.p_id IS NOT NULL THEN 'Inner'
              WHEN Parent.p_id IS NOT NULL AND Child.p_id IS NULL THEN 'Leaf'
            END
          ) AS type
        FROM Tree AS Parent
        LEFT JOIN Tree AS Child
          ON (Parent.id = Child.p_id);

 /** (Official Solution) **/
Approach I: Using UNION [Accepted]
Intuition

We can print the node type by judging every record by its definition in this table.

Root: it does not have a parent node at all
Inner: it is the parent node of some nodes, and it has a not NULL parent itself.
Leaf: rest of the cases other than above two
Algorithm

By transiting the node type definition, we can have the following code.

For the root node, it does not have a parent.

SELECT
  id, 'Root' AS Type
 FROM
  tree
 WHERE
  p_id IS NULL
For the leaf nodes, they do not have any children, and it has a parent.

SELECT
  id, 'Leaf' AS Type
 FROM
  tree
 WHERE
  id NOT IN (SELECT DISTINCT
  p_id
  FROM
  tree
  WHERE
  p_id IS NOT NULL)
  AND p_id IS NOT NULL
For the inner nodes, they have have some children and a parent.

SELECT
  id, 'Inner' AS Type
 FROM
  tree
 WHERE
  id IN (SELECT DISTINCT
  p_id
  FROM
  tree
  WHERE
  p_id IS NOT NULL)
  AND p_id IS NOT NULL
So, one solution to the problem is to combine these cases together using UNION.

MySQL

SELECT
  id, 'Root' AS Type
 FROM
  tree
 WHERE
  p_id IS NULL

 UNION

 SELECT
  id, 'Leaf' AS Type
 FROM
  tree
 WHERE
  id NOT IN (SELECT DISTINCT
  p_id
  FROM
  tree
  WHERE
  p_id IS NOT NULL)
  AND p_id IS NOT NULL

 UNION

 SELECT
  id, 'Inner' AS Type
 FROM
  tree
 WHERE
  id IN (SELECT DISTINCT
  p_id
  FROM
  tree
  WHERE
  p_id IS NOT NULL)
  AND p_id IS NOT NULL
 ORDER BY id;
Approach II: Using flow control statement CASE [Accepted]
Algorithm

The idea is similar with the above solution but the code is simpler by utilizing the flow control statements, which is effective to output differently based on different input values. In this case, we can use CASE statement.

MySQL

SELECT
  id AS `Id`,
  CASE
  WHEN tree.id = (SELECT atree.id FROM tree atree WHERE atree.p_id IS NULL)
  THEN 'Root'
  WHEN tree.id IN (SELECT atree.p_id FROM tree atree)
  THEN 'Inner'
  ELSE 'Leaf'
  END AS Type
 FROM
  tree
 ORDER BY `Id`
 ;
MySQL provides different flow control statements besides CASE. You can try to rewrite the slution above using IF flow control statement.

Approach III: Using IF function [Accepted]
Algorithm

Also, we can use a single IF function instead of the complex flow control statements.

MySQL

SELECT
  atree.id,
  IF(ISNULL(atree.p_id),
  'Root',
  IF(atree.id IN (SELECT p_id FROM tree), 'Inner','Leaf')) Type
 FROM
     tree atree
 ORDER BY atree.id
 */