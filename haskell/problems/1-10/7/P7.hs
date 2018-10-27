

isPrime :: Integer -> Bool
isPrime n = all ((/=0) . mod n) $ takeWhile ((<=n) . (^2)) primes

primes :: [Integer]
primes = 2:(filter isPrime $ iterate (+2) 3)

nthPrime :: Integer -> Integer
nthPrime i = primes !! (fromInteger $ i-1)

main = print $ nthPrime 10001

