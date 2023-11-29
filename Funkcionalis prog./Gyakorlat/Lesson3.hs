module Lesson3 where

--TUPLE

-- tuple, rendezett n-esek
-- (_ , _) -> konstruktor
-- tobb tipust is kepes tarolni


x :: (Int, Bool, String)
x = (42, True, "Haskell")

fst3 :: (Int, Bool, String) -> Int
fst3 (x, _, _) = x

add' :: (Int, Int) -> (Int, Int) -> (Int, Int)
add' (x1,y1) (x2,y2) = ((x1*y1+x2*y1), y1 * y2)

mul :: (Int, Int) -> (Int, Int) -> (Int, Int)
mul (x1,y1) (x2, y2) = (x1*x2, y1*y2)

modd :: Int -> Int -> (Int, Int)
modd x y = (mod x y, div x y)

quadric :: Float -> Float -> Float -> (Float, Float)
quadric a b c =(((-1*b) - sqrt((b^2)-(4*a*c))) / (2 * a), ((-1*b) + sqrt((b^2)-(4*a*c))) / (2 * a))

matches :: (Int, Int) -> (Int, Int) -> Bool
matches (x1, y1) (x2, y2) = (x1 == x2 || x1 == y2 || x2 == x1 || x2 == y1)

distance :: (Int, Int) -> (Int, Int) -> Double
distance (x1, y1) (x2, y2) = sqrt(fromIntegral((x2-x1)^2 + (y2 - y1)^2))

-- []
-- konstruktor (:)
-- homogen
--type String = [Char]
--type (Int, Int) = Point

headInt :: [Int] -> Int
headInt [] = error "Empty list!"
headInt (x:_) = x
