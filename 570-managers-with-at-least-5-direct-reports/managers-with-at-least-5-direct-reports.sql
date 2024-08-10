SELECT name
FROM Employee e1
WHERE (SELECT count(*) FROM Employee e2 where e2.managerId = e1.id) >= 5
