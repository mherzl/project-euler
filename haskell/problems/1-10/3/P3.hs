

import Data.Maybe (fromMaybe)

n :: Integer
n = 600851475143

main = do
  print $ largestPrimeFactor n

largestPrimeFactor :: Integer -> Integer
largestPrimeFactor x
  | x <= 1 = 1
  | leastPrimeDivisor == x = x
  | otherwise = largestPrimeFactor (div x leastPrimeDivisor)
  where candidateDivisors = takeWhile (\d -> d*d <= x) (2:[1+2*d | d <- [1..]])
        leastPrimeDivisor = fromMaybe x (first (\d -> mod x d == 0) candidateDivisors)


first :: (a -> Bool) -> [a] -> Maybe a
first _ [] = Nothing
first p (x:xs)
  | p x = Just x
  | otherwise = first p xs

