SELECT customer_id, Count(v.visit_id)  as count_no_trans
FROM Visits v
LEFT JOIN Transactions t
ON v.visit_id = t.visit_id
where t.transaction_id is NULL
GROUP BY v.customer_id



