


import Data.Maybe (fromJust)
import Data.List (find)
import Control.Monad (ap)


threeDigitPairs :: [(Int, Int)]
threeDigitPairs = takeWhile bothThreeDigit $ iterate increment (1,1)
  where
    bothThreeDigit :: (Int, Int) -> Bool
    bothThreeDigit (x, y) = x<1000 && y<1000
    increment :: (Int, Int) -> (Int, Int)
    increment (x, y)
      | x <= y = (x+1, 1)
      | otherwise = (x, y+1)

products :: [(Int, Int)] -> [Int]
products = map $ uncurry (*)

palindromes :: [Int] -> [Int]
palindromes = filter (isPalindrome . toDigitList)
  where
    isPalindrome :: [Int] -> Bool
    isPalindrome = ap (==) reverse
    toDigitList :: Int -> [Int]
    toDigitList n
      | n < 10 = [n]
      | otherwise = mod n 10 : toDigitList (div n 10)

answer :: Int
answer = maximum $ palindromes $ products $ threeDigitPairs

main = print $ answer



