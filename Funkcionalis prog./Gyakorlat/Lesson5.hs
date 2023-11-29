module Lesson5 where

import Data.Char

foo1 :: Int -> [Int] -> [(Int, Int)]
foo1 a b = [(x,x^a) | x <-b]

foo2 :: [Int] -> [Int]
foo2 a = [x | x <- a, (x `mod` 3 == 0) && (x `mod` 5 == 0)]

foo3 :: String -> [Char]
foo3 a = [x | x <- a, isUpper x]

foo4 :: [String] -> [String]
foo4 a = [x | x <- a, length x > 5]

foo5 :: [(Int, Int, Int)]
foo5 = [(x, y, z) | x <- [1..], y <- [1..(x^2)], z <- [1..(x^2+y^2)], x^2 + y^2 == z^2 && x < y]

--Rekurzio

last' :: [a] -> a
--(x:[]) = x
last' [x] = x
last' (_:xs) = last' xs

-- sum' [1,2,3,4]
-- 1 + sum' [2,3,4]
-- 1 + (2 + sum' [3,4])
-- 1 + (2 + (3 + sum' [4]))
-- 1 + (2 + (3 + 4))
-- 10
sum' :: [Int] -> Int
sum' [] = 0
sum' [x] = x
sum' (x:xs) = x + sum' xs