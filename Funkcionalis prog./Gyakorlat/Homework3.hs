module Homework3 where

invertX :: (Int, Int) -> (Int, Int)
invertX (x, y) = (x, -y)

isOnNeg2X :: (Int, Int) -> Bool
isOnNeg2X (x, y) =  y == (-2 * x)

xDistance :: (Int, Int) -> (Int, Int) -> Int
xDistance (x1, _) (x2, _) = abs(x2 - x1)

divide :: (Int, Int) -> (Int, Int) -> (Int, Int)
divide (x1, y1) (x2, y2) = (x1 * y2, x2 * y1)