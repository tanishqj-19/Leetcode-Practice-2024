SELECT e.name, bonus
FROM Employee e
LEFT JOIN Bonus b
ON e.empId = b.empId
WHERE b.bonus is NULL or b.bonus < 1000
