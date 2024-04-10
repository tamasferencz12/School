module PeldaZH where
import Data.Char
import Data.List

which :: ([Char], [Char], [Char]) -> Char -> Int
which (x , y, z) k
  | elem k x = 1
  | elem k y= 2
  | elem k z = 3
  | otherwise = 0

matches :: (Int, Int) -> (Int, Int) -> Bool
matches (x1, y1) (x2, y2) = (x1 == y2) || (y1 == x2)

toUpperCase :: String -> String
toUpperCase "" = ""
toUpperCase (x:xs) = toUpper x :xs

numeric :: String -> Int
numeric "" = 0
numeric (x:xs)
  | x == 'r' = 4 + numeric xs
  | x == 'w' = 2 + numeric xs
  | x == 'x' = 1 + numeric xs
  | otherwise = numeric xs

pythagoreans :: [(Int, Int, Int)]
pythagoreans = [(a, b, c) | a <- [1..100], b <-[a..100], c <-[b..100], a^2 + b^2 == c^2]

asLongWord :: Int -> String -> Bool
asLongWord _ "" = False
asLongWord 0 _ = True
asLongWord k (x:xs)
  | k == length (takeWhile (/= ' ') (x:xs)) = True
  | otherwise = False
