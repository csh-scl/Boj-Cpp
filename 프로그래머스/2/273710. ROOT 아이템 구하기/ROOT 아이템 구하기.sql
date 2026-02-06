-- 코드를 작성해주세요
SELECT it.ITEM_ID, ITEM_NAME FROM ITEM_INFO as ii
JOIN ITEM_TREE as it
ON ii.ITEM_ID = it.ITEM_ID
where PARENT_ITEM_ID is null
order by it.ITEM_ID asc