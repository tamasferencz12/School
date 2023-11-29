module Homework7 where
import Data.List

rook :: (Int, Int) -> [(Int, Int)]
rook (x, y) =
  [(x, i) | i <- [0..7], i /= y] ++ [(i, y) | i <- [0..7], i /= x]

knight :: (Int, Int) -> [(Int, Int)]
knight (x, y) =
  [(x+i, y+j) | i <- [-2, -1, 1, 2], j <- [-2, -1, 1, 2], abs i + abs j == 3, 0 <= x+i && x+i <= 7, 0 <= y+j && y+j <= 7]

attacks :: ((Int, Int) -> [(Int, Int)]) -> (Int, Int) -> [(Int, Int)] -> Bool
attacks piece (x, y) board =
  any (\pos -> elem pos board) (piece (x, y))
