module Homework10 where

data USTime = AM Int Int | PM Int Int
  deriving (Show, Eq)

data Time = T Int Int
 deriving Show

eqTime :: Time -> Time -> Bool
eqTime (T h1 m1) (T h2 m2) = h1 == h2 && m1 == m2
  
showUSTime :: USTime -> String
showUSTime (AM h m) = show h ++ "." ++ show m ++ " am"
showUSTime (PM h m) = show h ++ "." ++ show m ++ " pm"

usTimeToTime :: USTime -> Time
usTimeToTime (AM h m)
  | h == 12 = T 00 m
  | otherwise = T h m

usTimeToTime (PM h m)
  | h == 12 = T 12 m
  |otherwise =  T (h + 12) m

timeToUSTime :: Time -> USTime
timeToUSTime (T h m)
  | h == 00 = AM 12 m
  | h == 12 = PM h m 
  | h > 12 = PM (h - 12) m
  | otherwise = AM h m
