module Beadando where

showState a = show a
showMage a = show a
eqMage a b =  a == b
showUnit a = show a
showOneVOne a = show a

--type Name = String
--type Health = Integer
--type Spell = (Integer -> Integer)
--type Army = [Unit]
--type EnemyArmy = Army
--type Amount = Integer

data State a = Alive a | Dead

instance (Show a) => Show (State a) where
  show (Alive a) = show a
  show Dead = "Dead"
