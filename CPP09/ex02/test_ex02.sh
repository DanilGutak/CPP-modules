#!bin/bash
make re;

GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m'

m=100
n=1
while [ $n -le $m ]
do
    echo "Running command for $n elements"
    ./PmergeMe $(shuf -i 1-1000 -n $n | tr "\n" " ")
    ((n+=1))  # Increment n by 1 for the next iteration
done



echo -e "${GREEN}All PmergeMe executions completed.${NC}\n"
echo -e "Running make fclean: "

make fclean;
