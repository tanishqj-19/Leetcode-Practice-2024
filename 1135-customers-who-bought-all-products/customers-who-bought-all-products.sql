SELECT customer_id 
FROM Customer
GROUP BY customer_id
HAVING Count(distinct Product_key) = (SELECT COUNT(*) FROM Product)