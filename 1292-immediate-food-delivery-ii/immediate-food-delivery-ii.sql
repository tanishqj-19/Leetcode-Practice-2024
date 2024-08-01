# Write your MySQL query statement below
SELECT (ROUND(SUM(IF(order_date = customer_pref_delivery_date, 1, 0)) /  count(*) , 4) * 100)  as immediate_percentage 
FROM Delivery 
WHERE (customer_id, order_date) in 
(
    SELECT customer_id, min(order_date) 
    FROM delivery
    GROUP BY customer_id
)

