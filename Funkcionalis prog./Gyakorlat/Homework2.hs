isSmallPrime :: Int -> Bool
isSmallPrime 5 = True
isSmallPrime 7 = True
isSmallPrime 11 = True
isSmallPrime 13 = True
isSmallPrime _ = False

equivalent :: Bool -> Bool -> Bool
equivalent True True = True
equivalent True False = False
equivalent False True = False
equivalent False False = True

implies :: Bool -> Bool -> Bool
implies True True = True
implies True False = False
implies False True = True
implies False False = True