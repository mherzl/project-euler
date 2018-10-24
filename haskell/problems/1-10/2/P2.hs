

fib :: [Integer]
fib = 0:1: zipWith (+) fib (tail fib)

evens :: [Integer] -> [Integer]
evens = filter (\x -> x `mod` 2 == 0)

doNotExceedFourMillion :: [Integer] -> [Integer]
doNotExceedFourMillion = takeWhile (<= 4000000)

main = print ans
  where ans = sum $ doNotExceedFourMillion $ evens fib



