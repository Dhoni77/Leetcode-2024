# Write your MySQL query statement below
SELECT
    left_operand,
    operator,
    right_operand,
    CASE
        WHEN (
            (operator = '=' AND v1.value = v2.value)
            OR (operator = '>' AND v1.value > v2.value)
            OR (operator = '<' AND v1.value < v2.value)
        ) THEN 'true'
        ELSE 'false'
    END AS value
FROM
    Expressions AS e
    JOIN Variables AS v1 ON e.left_operand = v1.name
    JOIN Variables AS v2 ON e.right_operand = v2.name;

/*
 SELECT Expressions.*,
  (
    CASE
      WHEN Expressions.operator = '<'
      AND LeftOperand.value < RightOperand.value THEN 'true'
      WHEN Expressions.operator = '>'
      AND LeftOperand.value > RightOperand.value THEN 'true'
      WHEN Expressions.operator = '='
      AND LeftOperand.value = RightOperand.value THEN 'true'
      ELSE 'false'
    END
  ) AS value
FROM Expressions
INNER JOIN VARIABLES AS LeftOperand
  ON (Expressions.left_operand = LeftOperand.name)
INNER JOIN VARIABLES AS RightOperand
  ON (Expressions.right_operand = RightOperand.name);
 */