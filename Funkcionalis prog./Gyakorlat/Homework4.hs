module Homework4 where

import Data.List

powersOfTwo :: [Int]
powersOfTwo = [ 2^x | x <- [0,1..]]

isPrime :: Int -> Bool
isPrime 0 = False
isPrime 1 = False
isPrime x = null [y | y <- [2..x-1], x `mod` y == 0]

primes :: [Int]
primes = [x | x <-[1..], isPrime x]

allPositive :: [Int] -> Bool
allPositive x = null [y | y <- x, y <= 0]

dominoes :: [(Int, Int)]
dominoes = [(x,y) | x <-[0..6], y <-[x..6]]

compress :: String -> [(Int, Char)]
compress xs = [(length group, head group) | group <- group xs]

decompress :: [(Int, Char)] -> String
decompress [] = ""
decompress ((x, y):z) = replicate x y ++ decompress z