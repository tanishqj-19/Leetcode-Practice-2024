SELECT s.user_id,
    ROUND(
        COALESCE(
            (SELECT COUNT(*) FROM Confirmations c WHERE c.action = 'confirmed' AND c.user_id = s.user_id) 
            / NULLIF((SELECT COUNT(*) FROM Confirmations c WHERE c.user_id = s.user_id), 0), 
        0), 2) AS confirmation_rate
FROM Signups s;





