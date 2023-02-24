-- 코드를 입력하세요
SELECT a.flavor as FLAVOR
from first_half as a join july as b
on a.flavor = b.flavor
group by a.flavor
order by sum(a.total_order)+sum(b.total_order) desc limit 3;
