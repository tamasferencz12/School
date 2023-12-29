module Lesson11 where
import Data.Char

{-login :: String -> String -> Database -> Cookie
login _ _ [] = LoggedOut
login name password ((n,pw,priv):xs)
  |name == n && password == pw = LoggedIn n priv
  |otherwise = login name password xs

passwd :: String -> Cookie -> Database -> Database
passwd _ LoggedOut db = db
passwd _ _ [] = []
passwd newpw c@(LoggedIn name _) (x@(n, pw, priv):xs)
  | name == n = (n, newpw, priv) : xs
  | otherwise = x : passwd newpw c xs

delete :: String -> Cookie -> Database -> Database
delete _ LoggedOut db = db
delete _ (LoggedIn _ Unpriviliged) db = db
delete name (LoggedIn _ Admin) db = filter (\(n,pw,priv) -> n /= name) db

users :: Database -> [String]
users db = map (\(n,_,_) -> n) db-}

type ABC = [Char]
abc :: ABC
abc = ['A'..'Z']

type Riddle       = String
type RightGuesses = [Char]
type WrongGuesses = [Char]

data State = St Riddle RightGuesses WrongGuesses
  deriving (Show, Eq)

isValidLetter :: Char -> ABC -> Bool
isValidLetter x abc = (toUpper x) `elem` abc

startState :: ABC -> String -> Maybe State
startState abc s = Just (St s [] [])