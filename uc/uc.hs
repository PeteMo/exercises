import Char
import System

uc :: String -> String
uc s = [toUpper(c) | c <- s]

main :: IO ()
main = do
    args <- getArgs
    case length args of
        0 -> do
             line <- getLine
             putStrLn $ uc line
        _ -> putStrLn $ uc (unwords args)
