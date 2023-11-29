module Homework5 where

product' :: [Int] -> Int
product' [] = 0
product' [x] = x
product' (x:xs) = x * product' xs

len :: [Char] -> Int
len [] = 0
len (_:xs) = 1 + len xs

fact :: Integer -> Integer
fact 0 = 1
fact x = x * fact(x - 1)

skipEverySecond :: [a] -> [a]
skipEverySecond [] = []
skipEverySecond [x] = [x]
skipEverySecond (x:_:xs) = x : skipEverySecond xs