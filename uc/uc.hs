import Char
import System

uc :: String -> String
uc s = [toUpper(c) | c <- s]

main :: IO ()
main = do
    args <- getArgs
    case length args of
        0 -> do
             line <- getLine `catch` (\_ -> exitWith ExitSuccess)
             putStrLn $ uc line
             main

        _ -> putStrLn $ uc (unwords args)
