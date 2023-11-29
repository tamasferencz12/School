module Lesson6 where

--foo = if 2 == 0 then True else False

withoutLastElem :: [a] -> [a]
withoutLastElem [] = []
withoutLastElem (x:xs)
  | length xs /= 1 = x : withoutLastElem xs
  | otherwise = [x]

fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib x = fib(x-1) + fib(x-2)

pow :: Int -> Int -> Int
pow 0 0 = 1
pow 0 _ = 0
pow _ 0 = 1
pow x y = x * pow x (y-1)

min' :: Ord a=> [a] -> a
min' [x] = x
min' (x:y:xs) =min'( (min x y) : xs)

range :: Int -> Int -> [Int]
range x y 
  | x < y = x : range (x+1) y
  | x == y = [x]
  | otherwise = x : range (x-1) y

and' :: [Bool] -> Bool
and' [] = True
and' (x:xs) = x && and' xs

or' :: [Bool] -> Bool
or' [] = False
or' (x:xs) = x || or' xs

repeat' :: a -> [a]
repeat' x = x : repeat' x

drop' :: a -> [a] = []
drop' x [1] = []
drop' x y =

