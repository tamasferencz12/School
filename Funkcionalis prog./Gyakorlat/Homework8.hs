module Homework8 where
import Data.Maybe
import Data.Tuple

takeWhile' :: (a -> Bool) -> [a] -> [a]
takeWhile' _ [] = []
takeWhile' p (x:xs)
  | p x = x : takeWhile' p xs
  | otherwise = []

dropWhile' :: (a -> Bool) -> [a] -> [a]
dropWhile' _ [] = []
dropWhile' p (x:xs)
  | p x = dropWhile' p xs
  | otherwise = (x:xs)

dropWord :: String -> String
dropWord "" = ""
dropWord x = dropWhile' (/= ' ') x

doesUserExist :: String -> [(String, String)] -> Bool
doesUserExist name l = any (\(n, _ )-> n == name ) l
users = [ ("mrbean", "4321"), ("admin", "s3cr3t"), ("finn", "algebraic")]

charList :: [Char]
charList = ['0'..'9'] ++ ['A'..'Z'] ++ ['a'..'z']

mapping :: [(Char, Char)]
mapping = zip charList (drop 3 charList ++ take 3 charList)

find :: (a -> Bool) -> [a] -> a -> a
find _ [] d = d
find f (x:xs) d
  | f x = x
  | otherwise = find f xs d

encodeCaesar :: String -> String
encodeCaesar = map (\c -> snd (find (\(a,b) -> a == c) mapping ('?', '?')))

decodeCaesar :: String -> String
decodeCaesar = map (\c -> fst (find (\(a,b) -> b == c) mapping ('?', '?')))
