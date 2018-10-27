

sumOfSquares :: Integer -> Integer
sumOfSquares n = sum $ (^2) <$> [1..n]

squareOfSum :: Integer -> Integer
squareOfSum n = ((n+1)*n `div` 2)^2

-- this is slower
-- squareOfSumMinusSumOfSquares :: Integer -> Integer
-- squareOfSumMinusSumOfSquares n = sum [ x*y | x <- [1..n], y <- [1..(x-1)]++[(x+1)..n]]

main = do
  let n = 100
  print $ (squareOfSum n) - (sumOfSquares n)



