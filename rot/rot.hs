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
    (factor, string) <- handleArgs args
    putStrLn $ rotate factor string
    case length args of
        0 -> main
        _ -> exitWith ExitSuccess


handleArgs :: [String] -> IO (Int, String)
handleArgs args
    | length args == 1 = usage >> exitWith (ExitFailure 1)
    | length args >= 2 = return (read a :: Int, unwords b)
    | otherwise        = do
                         line <- getLine `catch` (\_ -> exitWith ExitSuccess)
                         handleArgs $ words line
    where a : b = args


rotate :: Int -> String -> String
rotate factor string = 
    [rotateChar factor c | c <- string]


rotateChar :: Int -> Char -> Char
rotateChar factor c 
    | isAlpha c = chr $ (ord c - offset + factor) `mod` 26 + offset
    | otherwise = c
    where offset | isUpper c = ord 'A'
                 | otherwise = ord 'a'
