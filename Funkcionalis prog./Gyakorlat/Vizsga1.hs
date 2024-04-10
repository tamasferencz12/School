module Vizsga1 where

f5 :: Integral a => a -> a
f5 a = a `mod` 5
-- 1

matchingArgs :: Eq a => a -> a -> a -> Bool 
matchingArgs a b c = (a == b) || (b == c) || (a == c)
-- 1

elemOnEvenIdx :: Eq a => a -> [a] -> Bool
elemOnEvenIdx _ [] = False
elemOnEvenIdx a (x:xs)
 | length xs `mod` 2 == 0 = x == a
 | otherwise = elemOnEvenIdx a xs
-- 2

simDiff :: Eq a => [a] -> [a] -> [a]
simDiff xs ys = (filter (\x -> not (x `elem` ys)) xs) ++ (filter (\y -> not (y `elem` xs)) ys)
-- 2