-- 코드를 입력하세요
SELECT product_id,product_name,sum(price*amount) as total_sales
from food_product natural join food_order
where produce_date between '2022-05-01' and '2022-05-31'
group by product_id
order by total_sales desc, product_id;