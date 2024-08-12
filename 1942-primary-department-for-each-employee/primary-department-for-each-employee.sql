SELECT employee_id, department_id
FROM Employee e
WHERE primary_flag = 'Y' OR (
    SELECT COUNT(*)
    FROM Employee a
    WHERE e.employee_id = a.employee_id
) = 1