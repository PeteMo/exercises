import System
import System.IO
import IO
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


handleArgs :: [String] -> IO (Int, String)
handleArgs args = do
    case length args of
        0 -> do
             words' <- readWords
             handleArgs words'

        2 -> return (read a :: Int, b)
             where a : b : _ = args

        _ -> do
             usage
             exitWith (ExitFailure 1)

readWords :: IO [String]
readWords = do
    line <- getLine `catch` eofHandler
    return $ words line

eofHandler :: IOError -> IO a
eofHandler e = 
    if isEOFError e
        then exitWith ExitSuccess
        else ioError e


rotate :: Int -> String -> String
rotate factor string = 
    [rotateChar factor c | c <- string]


rotateChar :: Int -> Char -> Char
rotateChar factor c 
    | isAlpha c = chr $ (ord c - offset + factor) `mod` 26 + offset
    | otherwise = c
    where offset | isUpper c = ord 'A'
                 | otherwise = ord 'a'
