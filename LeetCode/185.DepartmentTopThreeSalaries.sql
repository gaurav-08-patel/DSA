SELECT Department , Employee , Salary FROM (
    SELECT d.name Department ,
    e.name Employee ,
    e.salary Salary ,
    DENSE_RANK() OVER (PARTITION BY d.name ORDER BY e.salary DESC) AS "rnk" 
    FROM Employee e LEFT JOIN Department d ON e.departmentId = d.id
) AS Ranked
WHERE Ranked.rnk <= 3;