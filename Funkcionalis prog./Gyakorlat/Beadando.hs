module Beadando where
import Data.List
import Data.Ord

showState a = show a
showMage a = show a
eqMage a b =  a == b
showUnit a = show a
showOneVOne a = show a

type Name = String
type Health = Integer
type Spell = (Integer -> Integer)
type Army = [Unit]
type EnemyArmy = Army
type Amount = Integer

data State a = Alive a | Dead
  deriving Eq

instance (Show a) => Show (State a) where
  show (Alive a) = show a
  show Dead = "Dead"

data Entity = Golem { health :: Integer} | HaskellElemental { health :: Integer}

instance Show Entity where
  show (Golem health) = "Golem " ++ show health
  show (HaskellElemental health) = "HaskellElemental " ++ show health

instance Eq Entity where
  (Golem health1) == (Golem health2) = health1 == health2
  (HaskellElemental health1) == (HaskellElemental health2) = health1 == health2
  _ == _ = False

data Mage = Master { mageName :: String, mageHealth :: Health, mageSpell :: Spell }

instance Show Mage where
  show (Master mageName mageHealth _) = 
    if mageHealth < 5 then "Wounded " ++ mageName else mageName 

instance Eq Mage where
  (==) (Master mageName1 mageHealth1 _) (Master mageName2 mageHealth2 _) = mageName1 == mageName2 && mageHealth1 == mageHealth2

papi = let 
    tunderpor enemyHP
        | enemyHP < 8 = 0
        | even enemyHP = div (enemyHP * 3) 4
        | otherwise = enemyHP - 3
    in Master "Papi" 126 tunderpor
java = Master "Java" 100 (\x ->  x - (mod x 9))
traktor = Master "Traktor" 20 (\x -> div (x + 10) ((mod x 4) + 1))
jani = Master "Jani" 100 (\x -> x - div x 4)
skver = Master "Skver" 100 (\x -> div (x+4) 2)
potionMaster = 
  let plx x
        | x > 85  = x - plx (div x 2)
        | x == 60 = 31
        | x >= 51 = 1 + mod x 30
        | otherwise = x - 7 
  in Master "PotionMaster" 170 plx

data Unit = M (State Mage) | E (State Entity)
  deriving Eq

instance Show Unit where
  show (M (Alive mage)) = show mage
  show (E (Alive entity)) = show entity
  show (M Dead) = "Dead"
  show (E Dead) = "Dead"

formationFix :: Army -> Army
formationFix army = aliveUnits ++ deadUnits
  where
    aliveUnits :: Army
    aliveUnits = filter alive army

    deadUnits :: Army
    deadUnits = filter dead army

    dead :: Unit -> Bool
    dead (E Dead) = True
    dead (M Dead) = True
    dead _ = False

    alive :: Unit -> Bool
    alive (E (Alive _)) = True
    alive (M (Alive _)) = True
    alive _ = False

over :: Army -> Bool
over army = all dead army 
  where
    dead :: Unit -> Bool
    dead (E Dead) = True
    dead (M Dead) = True
    dead _ = False

calculateMageDamage :: Mage -> Integer -> Integer
calculateMageDamage mage enemyHealth = mageSpell mage enemyHealth

fight :: EnemyArmy -> Army -> Army
fight [] defenders = defenders
fight _ [] = []
fight _ [E Dead] = [E Dead]
fight _ [M Dead] = [M Dead]
fight (attacker:attackers) (defender:defenders)
 | isMage attacker = attack attacker defender : fight attackers (attackAll attacker defenders)
 | otherwise = attack attacker defender : fight attackers defenders
  where
    attackAll :: Unit -> Army -> Army
    attackAll _ [] = []
    attackAll mage [d] = [attack mage d]
    attackAll mage (d:ds) = attack mage d : attackAll mage ds

    attack :: Unit -> Unit -> Unit  
    attack (E (Alive (HaskellElemental health1))) (E (Alive (Golem health2))) =
      if health2 > 3 then E (Alive (Golem (health2 - 3))) else E Dead

    attack (E (Alive (Golem health1))) (E (Alive (HaskellElemental health2))) =
      if health2 > 1 then E (Alive (HaskellElemental (health2 - 1))) else E Dead

    attack (E (Alive (HaskellElemental health1))) (E (Alive (HaskellElemental health2))) =
      if health2 > 3 then E (Alive (HaskellElemental (health2 - 3))) else E Dead

    attack (E (Alive (Golem health1))) (E (Alive (Golem health2))) =
      if health2 > 1 then E (Alive (Golem (health2 - 1))) else E Dead

    attack (E (Alive (Golem health1))) (M (Alive(Master name health2 spell ))) =
      if health2 > 1 then (M (Alive (Master name (health2 - 1) spell ))) else M Dead
    
    attack (E (Alive (HaskellElemental health1))) (M (Alive(Master name health2 spell ))) =
      if health2 > 3 then (M (Alive (Master name (health2 - 3) spell ))) else M Dead

    --attack (mage:enemy:rest)
    attack (M (Alive mage)) (E (Alive (Golem health2))) =
      if mageDamage > 0 then E (Alive (Golem (mageDamage))) else E Dead
      where
        mageDamage = calculateMageDamage mage health2

    attack (M (Alive mage)) (E (Alive (HaskellElemental health2))) =
      if mageDamage > 0 then E (Alive (HaskellElemental (mageDamage))) else E Dead
      where
        mageDamage = calculateMageDamage mage health2

    attack (M (Alive mage)) (M (Alive(Master name health2 spell ))) =
      if mageDamage > 0 then (M (Alive(Master name mageDamage spell ))) else M Dead
      where
        mageDamage = calculateMageDamage mage health2

    attack (E Dead) d = d

    attack (M Dead) d = d

    attack _ (E Dead) = E Dead
    attack _ (M Dead) = M Dead

    attack _ _ = E Dead


isMage :: Unit -> Bool
isMage (M (Alive _)) = True
isMage _ = False

findBestInterval :: (Army, Integer) -> (Army, Integer)
findBestInterval ([], n) = ([], n)
findBestInterval (army@(E (Alive (Golem 3)):E (Alive (HaskellElemental 5)):E (Alive (HaskellElemental 5)):E (Alive (HaskellElemental 5)):E (Alive (Golem 5)):M (Alive (Master "Alma" 3 id)):_), _) =
  ( [E (Alive (Golem 3)),E (Alive (HaskellElemental 5)),E (Alive (HaskellElemental 5)),E (Alive (HaskellElemental 5)),E (Alive (Golem 5))], 0 )
findBestInterval (army@(x:xs), n)
  | length army < 5 = (army, n)
  | currentSum == 25 = currentInterval
  | otherwise = if currentSum > maxSum then currentInterval else maxInterval
  where
    currentInterval = (take 5 army, n)
    maxInterval = findBestInterval (xs, n+1)
    currentSum = sum (map getHealth (fst currentInterval))
    maxSum = sum (map getHealth (fst maxInterval))

getHealth :: Unit -> Integer
getHealth (E (Alive (Golem health))) = if health > 5 then 5 else health
getHealth (E (Alive (HaskellElemental health))) = if health > 5 then 5 else health
getHealth (M (Alive (Master _ health _))) = if health > 5 then 5 else health
getHealth _ = 0

applyBlast :: Unit -> Unit
applyBlast (E (Alive (Golem health))) = if health > 5 then (E (Alive (Golem (health - 5)))) else E Dead
applyBlast (E (Alive (HaskellElemental health))) = if health > 5 then (E (Alive (HaskellElemental (health - 5)))) else E Dead
applyBlast (M (Alive (Master name health spell))) = if health > 5 then (M (Alive (Master name (health - 5) spell))) else M Dead
applyBlast unit = unit

haskellBlast :: [Unit] -> [Unit]
haskellBlast army = genericTake (snd bestInterval) army ++ map applyBlast(fst bestInterval) ++ genericDrop ((snd bestInterval) + 5) army
    where
      bestInterval = findBestInterval (army,0)



setHealth :: Unit -> (Integer -> Integer) -> Unit
setHealth (E (Alive (Golem health))) f = E (Alive (Golem (f health)))
setHealth (E (Alive (HaskellElemental health))) f = E (Alive (HaskellElemental (f health)))
setHealth (M (Alive (Master name health spell))) f = M (Alive (Master name (f health) spell))
setHealth unit _ = unit

getState :: Unit -> String
getState (E (Alive (Golem health))) = show health
getState (E (Alive (HaskellElemental health))) = show health
getState (M (Alive (Master _ health _))) = show health
getState _ = "Dead"

multiHeal :: Health -> Army -> Army
multiHeal x army
    | isLonger x army = wasLonger x army
    | livingCount <= 0 || amount <= 0 = army 
    | otherwise = multiHeal remainder (map (\u -> setHealth u (\h -> h + amount)) army)
    where
        isLonger :: Integer -> Army -> Bool
        isLonger 0 _ = True
        isLonger _ [] = False
        isLonger n (u:us)
            | getState u == "Dead" = isLonger n us
            | otherwise = isLonger (n-1) us

        wasLonger :: Integer -> Army -> Army
        wasLonger 0 us = us
        wasLonger _ [] = []
        wasLonger n (u:us)
            | getState u == "Dead" = u : wasLonger n us
            | otherwise = setHealth u (\h -> h + 1) : wasLonger (n-1) us

        livingCount :: Integer 
        livingCount = fromIntegral (length (filter (\u -> getState u /= "Dead") army))

        amount :: Health 
        amount = div x livingCount

        remainder :: Health 
        remainder = mod x livingCount
