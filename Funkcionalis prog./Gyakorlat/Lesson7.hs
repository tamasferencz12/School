module Lesson7 where

langAndRegion :: String -> (String, String)
langAndRegion (x:y: '-':xs ) = (x:y:[], xs)

zip' :: [a] -> [b] -> [(a,b)]
zip' [] _ = []
zip' _ [] = []
zip' (x:xs) (y:ys) = (x, y) : zip' xs ys

unzip' :: [(a,b)] -> ([a],[b])
unzip' l = ([x | (x,_) <-  l ], [y | (_,y) <-  l ])

empty :: String -> [Int]
empty s = [x | (x,y) <- zipped, y == ""]
    where
        zipped = zip [1..] (lines s)

--- Magasabb rendu fuggvenyek

map' :: (a -> b) -> [a] -> [b]
map' _ [] = []
map' f (x:xs) = f x : map' f xs
-- map' even (x:xs) = even x : map' even xs

-- map' f l = [f x | x <- l]

filter' :: (a -> Bool) -> [a] -> [a]
filter' _ [] = []
filter' p (x:xs)
    | p x = x : filter' p xs
    | otherwise = filter' p xs
-- filter' p l = [x | x <- l, p x]
