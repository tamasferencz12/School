intExpr1 :: Int
intExpr1 = 1

intExpr2 :: Int
intExpr2 = 2

intExpr3 :: Int
intExpr3 = 3

charExpr1 :: Char
charExpr1 = 'a'

charExpr2 :: Char
charExpr2 = 'b'

charExpr3 :: Char
charExpr3 = 'c'

boolExpr1 :: Bool
boolExpr1 = True

boolExpr2 :: Bool
boolExpr2 = False

boolExpr3 :: Bool
boolExpr3 = True


flowerSeeds :: Int
flowerSeeds = 183

pot :: Int
pot = 13

canPlantAll :: Bool
canPlantAll = flowerSeeds `mod` pot == 0

remainingSeeds :: Int
remainingSeeds = flowerSeeds `mod` pot