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
    let (low, high) = (1, 10)
    r <- getRandom low high
    putStrLn $ "You have " ++ show numGuesses ++ " tries to guess my number between " ++ show low ++ " and " ++ show high ++ "."
    play r numGuesses


play :: Int -> Int -> IO ()
play r numGuesses = do
    case numGuesses of
        0 -> putStrLn ("You lose, the number was " ++ show r ++ ".") >> exitWith ExitSuccess
        _ -> do
            putStrLn $ "What is your guess?"
            guess <- getLine

            case checkGuess (read guess :: Int) r of
                0  -> putStrLn "You Win!" >> exitWith ExitSuccess
                1  -> putStrLn "Too High."
                -1 -> putStrLn "Too Low."
                _  -> error "Unpossible!"

            play r (numGuesses - 1)


checkGuess :: Int -> Int -> Int
checkGuess guess answer 
    | guess == answer = 0
    | guess >  answer = 1
    | guess <  answer = -1
    | otherwise       = error "Unpossible!"
