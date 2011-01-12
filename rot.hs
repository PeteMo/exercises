import System
import System.IO
import Char

usage :: IO ()
usage = do
    progName <- getProgName
    hPutStrLn stderr $ "Usage: " ++ progName ++ " factor string"


main :: IO ()
main = do
    args <- getArgs
    case length args of
        2 -> putStrLn $ rotate (read factor :: Int) string
             where factor : string : _ = args
        _ -> do 
             usage
             exitWith (ExitFailure 1)


rotate :: Int -> String -> String
rotate factor string = 
    [rotateChar factor c | c <- string]


rotateChar :: Int -> Char -> Char
rotateChar factor c 
    | isAlpha c = chr $ (ord c - offset + factor) `mod` 26 + offset
    | otherwise = c
    where offset | isUpper c = ord 'A'
                 | otherwise = ord 'a'
