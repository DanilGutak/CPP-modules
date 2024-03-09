#!bin/bash
make re;

GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m'

m=10000
n=1000
while [ $n -le $m ]
do
    echo "Running command for $n elements"
    valgrind ./PmergeMe $(shuf -i 1-10000 -n $n | tr "\n" " ")
    ((n+=97))  # Increment n by 1 for the next iteration
done



echo -e "${GREEN}All PmergeMe executions completed.${NC}\n"
echo -e "Running make fclean: "

make fclean;
