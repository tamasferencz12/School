module Homework6 where

geometricSequence :: Num a => a -> a -> [a]
geometricSequence x y = x : geometricSequence(x * y) y

isSorted :: Ord a => [a] -> Bool
isSorted [] = True
isSorted [_] = True
isSorted(x:y:xs)
  | x <= y = isSorted (y:xs)
  |otherwise = False

fromTo :: Int -> Int -> [a] -> [a]
fromTo _ _ [] = []
fromTo start end xs
    | start >= end = []
    | start < 0 = fromTo 0 end xs
    | end < 0 = []
    | otherwise = take (end - start) (drop start xs)


runs :: Int -> [a] -> [[a]]
runs _ [] = []
runs n list
  | n == 0 = take n list : runs n (drop n list)
  | length list < n = [list]
  | otherwise = take n list : runs n (drop n list)