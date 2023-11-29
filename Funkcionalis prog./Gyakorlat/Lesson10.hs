module Lesson10 where

type String' = [Char]
type Point = (Int, Int)

p :: Point
p = (0,0)

newtype Vector = V Point
  deriving (Show, Eq)

data Days = Mon | Tue | Wen | Thu | Fri | Sat | Sun
  deriving (Eq, Enum)

data Time = T Int Int
 deriving Show

instance Show Days where
  show :: Days -> String
  show Mon = "Hetfo"
  show Tue = "Kedd"
  show Wen = "Szerda"
  show Thu = "Csutortok"
  show Fri = "Pentek"
  show Sat = "Szombat"
  show Sun = "Vasarnap"

eqDays :: Days -> Days -> Bool
eqDays Mon Mon = True
eqDays Tue Tue = True
eqDays _ _ = False

eqTime :: Time -> Time -> Bool
eqTime (T h1 m1) (T h2 m2) = h1 == h2 && m1 == m2

hTOm :: Time -> Int
hTOm (T h m) = (h * 60) + m

isEarlier :: Time -> Time -> Bool
isEarlier (T h1 m1) (T h2 m2) = hTOm(T h1 m1) < hTOm(T h2 m2)

isBetween :: Time -> Time -> Time -> Bool
isBetween (T h1 m1) (T h2 m2) (T h3 m3) = hTOm(T h1 m1) < hTOm(T h2 m2) && hTOm(T h2 m2) < hTOm(T h3 m3)

time :: Int -> Int -> Time
time h m 
  | h > 23 || h < 0 = error("time: invalid hour:" ++ show h)
  | m > 59 || m < 0 = error("time: invalid minute:" ++ show m)
  | otherwise = (T h m)

data USTime = AM Int Int | PM Int Int
  deriving (Show, Eq)

foo (AM h m) = undefined
foo (PM h m) = undefined
