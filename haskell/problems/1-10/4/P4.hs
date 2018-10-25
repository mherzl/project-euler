



data DigitList = DigitList [Int]

isPalindrome :: DigitList -> Bool
isPalindrome (DigitList l) = l == reverse l

toDigitList :: Int -> DigitList
toDigitList n
  | n < 10 = DigitList [n]
  | otherwise = (mod n 10) `cons` (toDigitList $ div n 10)
  where cons :: Int -> DigitList -> DigitList
        cons x (DigitList xs) = DigitList (x:xs)

allUnorderedPairs :: [(Int, Int)]
allUnorderedPairs = iterate advance (1,1)
  where advance :: (Int, Int) -> (Int, Int)
        advance (x, y)
          | x>y = (x, y+1)
          | otherwise = (x+1,1)

allProductsOfThreeDigitNumbers :: [Int]
allProductsOfThreeDigitNumbers = (\(x,y) -> x*y) <$> takeWhile (\(x,_) -> x<1000) allUnorderedPairs

palindromes :: [Int]
palindromes = filter (isPalindrome . toDigitList) allProductsOfThreeDigitNumbers

main = print $ maximum palindromes



