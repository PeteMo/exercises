import System
import System.Random

getRandom :: Int -> Int -> IO Int
getRandom low high = do
    gen <- getStdGen
    let (r,_) = randomR (low, high) gen :: (Int, StdGen)
    return r

main :: IO ()
main = do
    let numGuesses = 3
    r <- getRandom 1 10
    putStrLn $ "Guess my number between 1 and 10"
    play r numGuesses


play :: Int -> Int -> IO ()
play r numGuesses = do
    case numGuesses of
        0 -> putStrLn ("You lose, the number was " ++ show r) >> exitWith ExitSuccess
        1 -> putStrLn ( "You have " ++ show numGuesses ++ " guess remaining. What is your guess?") >> evalGuess r numGuesses
        _ -> putStrLn ( "You have " ++ show numGuesses ++ " guesses remaining. What is your guess?") >> evalGuess r numGuesses


evalGuess :: Int -> Int -> IO ()
evalGuess r n = do
    guess <- getLine
    case checkGuess (read guess :: Int) r of
        0  -> putStrLn "You Win!" >> exitWith ExitSuccess
        1  -> putStrLn "Too High"
        -1 -> putStrLn "Too Low"
        _  -> error "Unpossible!"
    play r (n-1)


checkGuess :: Int -> Int -> Int
checkGuess guess answer 
    | guess == answer = 0
    | guess >  answer = 1
    | guess <  answer = -1
    | otherwise       = error "Unpossible!"
