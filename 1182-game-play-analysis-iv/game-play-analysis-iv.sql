# Write your MySQL query statement below

-- SELECT ROUND( COUNT(distinct player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) as fraction
-- FROM Activity
-- WHERE (player_id, first_login) IN (
--     SELECT player_id, min(event_date) as first_login
--     FROM  Activity
--     GROUP BY player_id
-- )

SELECT ROUND(SUM(IF(Activity.event_date = DATE_ADD(min_date, INTERVAL 1 DAY), 1, 0)) / count(distinct Activity.player_id), 2) as fraction
FROM Activity
JOIN (   SELECT player_id, min(event_date) as min_date
    FROM Activity 
    GROUP BY player_id
) as sub
WHERE Activity.player_id = sub.player_id