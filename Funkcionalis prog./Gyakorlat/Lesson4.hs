module Lesson4 where

import Data.List
import Data.Char

--Prelude

lista :: [Int]
lista = [1,2,3,4]

--[]
--konstruktor (:), (++)
--homogen
--[ x | x <- [1..](,y <- [1..10], ...), mod x 2 == 0] ---lista kifejezes
--head, tail, null, length, elem

head' :: [a] -> a
head' (x:_) = x

tail' :: [b] -> [b]
tail' (_:x) = x

-- [] -> ures lista
-- (x:xs) -> legalabb egy elemu lista
-- (x:[]) (([x])) -> pontosan 1 elemu
--(x:_:(z,y):xs) -> legalabb 3 elemu tuple lista


-- 1.feladat
isSingleton :: [a] -> Bool
isSingleton [_] = True
isSingleton _ = False

-- 2.feladat
toUpperFirst :: String -> String
toUpperFirst s = unwords [ toUpper x : xs | (x:xs) <- words s]
--toUpperFirst s = unwords [ toUpper (head x) : tail x | x <- words s]

-- 3.feladat
mountain :: Int -> [Int]
mountain x = [1..x]++[x-1,x-2..1]

--4.feladat
divisors :: Int -> [Int]
divisors x = [ x | x <- [1..](y <- [1..10], ..), mod x 2 == 0]
