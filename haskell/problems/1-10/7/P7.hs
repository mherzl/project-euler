

isPrime :: Integer -> Bool
isPrime n = not $ any (\d -> mod n d == 0) $ takeWhile (\d -> d*d <= n) primes

primes :: [Integer]
primes = 2:3:5:7:11:13:(filter isPrime $ iterate (+2) 17)

nthPrime :: Integer -> Integer
nthPrime i = primes !! (fromInteger $ i-1)

main = print $ nthPrime 10001

