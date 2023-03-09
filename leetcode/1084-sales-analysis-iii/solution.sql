# Write your MySQL query statement below
WITH inside_product AS(
    SELECT 
        distinct product_id 
    FROM sales
    WHERE sale_date BETWEEN '2019-01-01' AND '2019-03-31'
), outside_product AS (
    SELECT
        distinct product_id
    FROM sales
    WHERE sale_date < '2019-01-01' 
        OR sale_date > '2019-03-31'
)

SELECT 
    product_id,
    product_name
FROM product
WHERE product_id IN (SELECT * FROM inside_product)
    AND product_id NOT IN (SELECT * FROM outside_product)
