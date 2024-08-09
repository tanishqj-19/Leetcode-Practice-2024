SELECT s.student_id, s.student_name, sub.subject_name, COUNT(exam.student_id) AS attended_exams
FROM students s
CROSS JOIN Subjects sub
LEFT JOIN Examinations exam
ON exam.student_id = s.student_id AND sub.subject_name = exam.subject_name

GROUP BY s.student_id, s.student_name, sub.subject_name
ORDER BY s.student_id, sub.subject_name;