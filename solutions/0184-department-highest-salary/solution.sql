-- /* Write your T-SQL query statement below */
-- WITH RankedSalaries AS (
--     SELECT d.name AS Department,
--            e.name AS Employee,
--            e.salary AS Salary,
--            DENSE_RANK() OVER (
--             PARTITION BY e.departmentId 
--             ORDER BY e.salary DESC)
--            AS [rank]
--       FROM Employee e
--       JOIN Department d ON e.departmentId = d.id
-- )

-- SELECT Department, Employee, Salary
--   FROM RankedSalaries
--  WHERE [rank] = 1

SELECT d.name AS Department,
       e.name AS Employee,
       e.salary AS Salary
  FROM Employee e
  JOIN Department d ON e.departmentId = d.id
  -- This inner join acts like a filter:
  JOIN (
       SELECT departmentId, MAX(salary) AS max_salary
         FROM Employee
       GROUP BY departmentId
  ) max_per_dept ON e.departmentId = max_per_dept.departmentId 
                AND e.salary = max_per_dept.max_salary;
