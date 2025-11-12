# Write your MySQL query statement below

select t.Department, t.Employee, t.Salary
from(
    select e.name as Employee, d.name as Department, e.salary as Salary,
    dense_rank() over(partition by d.id order by e.salary desc) as rnk
    from (Employee as e left join Department as d on e.departmentId = d.id)
) as t
where rnk <= 3 