/*
 To count the number of characters used in a string, the best function to use is CHAR_LENGTH(str), which returns the length of the string str.

The other common function, LENGTH(str), also works for this question since the column content contains only English characters and no special characters.
Otherwise, LENGTH() might return a different result because this function returns the length of the string str in bytes and certain characters contain more than 1 byte.

Using character '¥' as an example: CHAR_LENGTH() returns 1 as the result, while LENGTH() return 2 because this string contains 2 bytes.

SELECT LENGTH('¥'), CHAR_LENGTH('¥')

 SELECT
  tweet_id
 FROM
  Tweets
 WHERE CHAR_LENGTH(content)> 15
 */

select tweet_id from tweets where length(content) > 15;