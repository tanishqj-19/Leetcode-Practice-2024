SELECT
    score, 
    (SELECT Count(DISTINCT Score) FROM Scores x WHERE x.Score >= s.Score) 'Rank'
FROM
Scores s
ORDER BY score DESC;
