module Homework9 where
import Data.List

dropSpaces :: String -> String
dropSpaces = dropWhile (== ' ')

trim :: String -> String
trim = unwords . words

monogram :: String -> String
monogram = unwords . map ((\x -> head x : ".") . take 1) . words

uniq :: Ord a => [a] -> [a]
uniq = map head . group . sort

repeated :: Ord a => [a] -> [a]
repeated = concatMap (\xs -> if length xs > 1 then [head xs] else []) . group . sort

zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith' _ [] _ = []
zipWith' _ _ [] = []
zipWith' f (x:xs) (y:ys) = f x y : zipWith' f xs ys