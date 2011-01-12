import System
import System.IO
import Char

usage :: IO ()
usage = do
    hPutStrLn stderr $ "Usage Error"

main :: IO ()
main = do
    args <- getArgs
    let factor : string : _  = args
    putStrLn $ rotate (read factor :: Int) string


rotate :: Int -> String -> String
rotate factor string = 
    [rotateChar factor c | c <- string]


rotateChar :: Int -> Char -> Char
rotateChar factor c 
    | isAlpha c = chr $ (ord c - offset + factor) `mod` 26 + offset
    | otherwise = c
    where offset | isUpper c = ord 'A'
                 | otherwise = ord 'a'
