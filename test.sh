# Color code
red=`tput setaf 1`
green=`tput setaf 2`
yellow=`tput setaf 3`
reset=`tput sgr0`

# Change ft::vector to std::vector and create a new main
sed 's/ft::vector/std::vector/g' main.cpp > main_real_containers.cpp

# Compile with new main and put result into out1
clang++ -Wall -Wextra -Werror -std=c++98 -fsanitize=address main_real_containers.cpp
./a.out > out1

# Compile our main and put result into out2
make re
./ft_containers > out2

# Compare out1 out2
result=$(diff -u out1 out2)
if [ "$result" = "" ]; 
then
    echo "${green}It works!${reset}"
else
    echo "${red}It does not work!${reset}"
    echo "${yellow}$result${reset}"
fi

rm a.out
make fclean
rm out1 out2
rm main_real_containers.cpp