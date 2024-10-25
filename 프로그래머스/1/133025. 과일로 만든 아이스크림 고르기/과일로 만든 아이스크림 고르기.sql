-- 코드를 입력하세요
SELECT a.FLAVOR
FROM FIRST_HALF a, ICECREAM_INFO b
WHERE a.FLAVOR = b.FLAVOR AND b.INGREDIENT_TYPE = "fruit_based" AND a.TOTAL_ORDER > 3000
GROUP BY a.FLAVOR
ORDER BY a.TOTAL_ORDER DESC