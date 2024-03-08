#!bin/bash
make re;

GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m'

m=30
n=1
while [ $n -le $m ]
do
    echo "Running command for $n elements"
    valgrind ./PmergeMe $(shuf -i 1-10000 -n $n | tr "\n" " ")
    ((n++))  # Increment n by 1 for the next iteration
done

#echo -e "${YELLOW}Running PmergeMe with 100 random numbers between 2 and 5000${NC}"
#./PmergeMe $(jot -r 5000 2 5000 | tr '\n' ' ')

echo -e "${GREEN}All PmergeMe executions completed.${NC}\n"
echo -e "Running make fclean: "

make fclean;
