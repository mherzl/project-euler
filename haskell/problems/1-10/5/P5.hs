
import Prelude hiding (lookup)
import Data.Maybe (fromMaybe)
import Data.List (find, genericReplicate)
import Data.Map (Map, empty, unionWith, insert, lookup, toList)

primeFactorization :: Integer -> [Integer]
primeFactorization n
  | lpf == n = [n]
  | otherwise = lpf : primeFactorization (div n lpf)
  where lpf = leastPrimeFactor n

leastPrimeFactor :: Integer -> Integer
leastPrimeFactor i = fromMaybe i $ find (\x -> mod i x == 0) ds
  where ds = takeWhile (\x -> x*x<=i) $ 2:[2*x+1 | x <- [1..]]

listUnion :: [Integer] -> [Integer] -> [Integer]
listUnion x y = fromMap $ unionWith max (toMap x) (toMap y)
insertOne :: Integer -> Map Integer Integer -> Map Integer Integer
insertOne n m = insert n (fromMaybe 1 ((+1) <$> lookup n m)) m
toMap :: [Integer] -> Map Integer Integer
toMap = foldr insertOne empty
fromMap :: Map Integer Integer -> [Integer]
fromMap = concatMap (uncurry $ flip genericReplicate) . toList

leastDivisibleByAll :: [Integer] -> Integer
leastDivisibleByAll = product . (foldl listUnion []) . (primeFactorization <$>)

main = do
  print $ leastDivisibleByAll [1..20]


