# Write your MySQL query statement below
SELECT MAX(salary) as SecondHighestSalary
from employee
where Salary < (select max(salary) from employee)