import Data.Char

main = readLn >>= print . digitToInt . (!!) (concatMap (show) [0..]) 

