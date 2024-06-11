# Write your MySQL query statement below

SELECT
    e1.name as Employee
FROM
    Employee as e1
WHERE 
    e1.managerId IS NOT NULL AND e1.salary > (SELECT salary FROM Employee as e2 where e2.id = e1.managerId);
