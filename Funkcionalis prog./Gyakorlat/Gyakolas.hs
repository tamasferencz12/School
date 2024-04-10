module Gyakorlas where
import Data.Char
import Data.List

extremes :: (Ord a, Num a) => a -> [(a, a)] -> Bool
extremes _ [] = False
extremes diff ((minTemp, maxTemp):rest)
  | maxTemp - minTemp > diff = True
  | otherwise = extremes diff rest

late3 :: [(Int, Int)] -> Bool
late3 [] = False
late3 [_] = False
late3 [_, _] = False
late3 ((h1, m1):(h2, m2):(h3, m3):rest)
  |((h1 * 60 + m1) > timeTen) && ((h2 * 60 + m2) > timeTen) && ((h3 * 60 + m3) > timeTen) = True
  | otherwise = late3 ((h2, m2):(h3,m3):rest)
  where timeTen = 10 * 60

swapEvenIdxs :: [a] -> [a]
swapEvenIdxs [] = []
swapEvenIdxs [x] = [x]
swapEvenIdxs [x,y] = []
swapEvenIdxs (x:y:z:rest) = z : y : (swapEvenIdxs (x : rest))

atLeast3Elems :: [[a]] -> [[a]]
atLeast3Elems = filter (\lst -> lengthAtLeast3 lst)
  where
    lengthAtLeast3 :: [b] -> Bool
    lengthAtLeast3 (_:_:_:_) = True
    lengthAtLeast3 _         = False

weirdSearch :: (a -> Bool) -> (a -> Bool) -> [a] -> Maybe a
weirdSearch _ _ [] = Nothing
weirdSearch _ _ [_] = Nothing
weirdSearch evenCond oddCond (x:_:rest) 
    | evenCond x = if oddCond x then Just x else weirdSearch evenCond oddCond rest
    | otherwise = weirdSearch evenCond oddCond rest

-- Szak típusszinoníma
type Szak = [(Hal, Int)]

-- Horgaszhely adattípus
data Horgaszhely = Versenyzo String Int Szak

-- Verseny típusszinoníma
type Verseny = [Horgaszhely]

-- Hal adattípus
data Hal = Ponty Int | Karasz Int | Keszeg Int | Harcsa Int

-- Eq és Show típusosztályok példányosítása a Hal típusra
instance Eq Hal where
  (Ponty x) == (Ponty y) = x == y
  (Karasz x) == (Karasz y) = x == y
  (Keszeg x) == (Keszeg y) = x == y
  (Harcsa x) == (Harcsa y) = x == y
  _ == _ = False

instance Show Hal where
  show (Ponty x) = "Ponty " ++ show x
  show (Karasz x) = "Karasz " ++ show x
  show (Keszeg x) = "Keszeg " ++ show x
  show (Harcsa x) = "Harcsa " ++ show x

-- summarize függvény definíciója
summarize :: Verseny -> [(String, Int, Int)]
summarize [] = []
summarize (h:verseny) = (getNev h, getSorszam h, getSumHalak $ getHalak h) : summarize verseny
  where
    getNev (Versenyzo nev _ _) = nev
    getSorszam (Versenyzo _ sorszam _) = sorszam
    getHalak (Versenyzo _ _ halak) = halak
    getSumHalak halak = sum [suly | (hal, suly) <- halak, not $ isHarcsa hal]

-- Segédfüggvény a harcsa kiszűrésére
isHarcsa :: Hal -> Bool
isHarcsa (Harcsa _) = True
isHarcsa _ = False

which :: ([Char], [Char], [Char]) -> Char -> Int
which ([], [], []) _ = 0
which ((x:xs),(y:ys),(z:zs)) char
  | x == char = 1
  | y == char = 2
  | z == char = 3
  | otherwise = which (xs,ys,zs) char

matches :: (Int, Int) -> (Int, Int) -> Bool
matches (x, y) (z, w) = y == z || x == w

toUpperCase :: String -> String
toUpperCase [] = []
toUpperCase (x:xs) 
  | isLetter x = toUpper x : xs
  | otherwise = x : xs

repliCate :: Int -> String -> Int
repliCate x string = x - length string

align :: Int -> String -> String
align x string
  | x > length string = replicate (repliCate x string) ' ' ++ string
  | otherwise = string

swap :: Maybe a -> b -> Maybe b
swap Nothing _ = Nothing
swap (Just a) b = Just b

numeric :: String -> Int
numeric "" = 0
numeric (x:xs)
  | x == 'r' = 4 + numeric xs
  | x == 'w' = 2 + numeric xs
  | x == 'x' = 1 + numeric xs
  | otherwise = numeric xs

pythagoreans :: [(Int, Int, Int)]
pythagoreans = [(x,y,z) | x <- [1..], y <-[x..], z <- [y..], x^2 + y^2 == z^2 ]

hasLongWord :: Int -> String -> Bool
hasLongWord _ "" = False
hasLongWord x string
  | x <= length (takeWhile (\x -> x /= ' ') string) = True
  | x <= length (dropWhile (\y -> y /= ' ') string) - 1 = True
  | otherwise = False

isLonger :: [Int] -> Int -> Bool
isLonger list n
  | (dropWhile (\x -> x <= n) list) > [] = True
  | otherwise = False

evenPairs :: [a] -> [(a,a)]
evenPairs [] = []
evenPairs [x] = []
evenPairs [x,y] = []
evenPairs (x:y:z:rest) = (x,z) : (evenPairs (z : rest))
