SELECT sell_date, COUNT(distinct product) AS num_sold,
 GROUP_CONCAT(DISTINCT product ) AS 
 products
FROM Activities a
GROUP BY sell_date;
