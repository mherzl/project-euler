module P1 where

{-
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
-}

main = print $ sumMultiplesBelow1000 3 + sumMultiplesBelow1000 5 - sumMultiplesBelow1000 (lcm 3 5)

sumMultiplesBelow1000 :: Integer -> Integer
sumMultiplesBelow1000 n = n * sumOneToN (div 999 n)

sumOneToN :: Integer -> Integer
sumOneToN n = n * (n+1) `div` 2

lcm' :: Integer -> Integer -> Integer
lcm' x y = div (x * y) (gcf' x y)

gcf' :: Integer -> Integer -> Integer
gcf' x y
  | x < y = gcf' y x
  | mod x y == 0 = y
  | otherwise = gcf' y (mod x y)




