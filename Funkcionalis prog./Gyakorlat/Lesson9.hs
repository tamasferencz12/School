module Lesson9 where

-- Folding
--foldr (\x y -> concat ["(", x, "+", y,")"]) "0" ( map show [1..10]) --fold right
--"(1+(2+(3+(4+(5+(6+(7+(8+(9+(10+0))))))))))" --terminal output

--foldl (\x y -> concat ["(", x, "+", y,")"]) "0" ( map show [1..10]) --fold left
--"((((((((((0+1)+2)+3)+4)+5)+6)+7)+8)+9)+10)" --terminal output

fr :: (a -> b -> b) -> b -> [a] -> b
fr _ acc [] = acc
fr f acc (x:xs) = f x (fr f acc xs)
--"(1+(2+(3+(4+(5+(6+(7+(8+(9+(10+0))))))))))" --terminal output

fl :: (b -> a -> b) -> b ->[a] -> b
fl _ acc [] = acc
fl f acc (x:xs) = fl f (f acc x) xs
--"((((((((((0+1)+2)+3)+4)+5)+6)+7)+8)+9)+10)" --terminal output

sum' :: Num a => [a] -> a
sum' l = foldr (+) 0 l

product' :: Num a => [a] -> a
product' l = foldr (*) 1 l

and' :: [Bool] -> Bool
and' x = foldr (&&) True x

or' :: [Bool] -> Bool
or' x = foldl (||) False x

insert :: Ord a => [a] -> a -> [a]
insert xs x = takeWhile ( <= x) xs ++ [x] ++ dropWhile (<= x) xs

isort' :: Ord a => [a] -> [a]
isort' l = foldl insert [] l

concat' :: [[a]] -> [a]
concat' l = foldl (\x y ->x++y) [] l
