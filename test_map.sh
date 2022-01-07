# Color code
red=`tput setaf 1`
green=`tput setaf 2`
yellow=`tput setaf 3`
reset=`tput sgr0`

# Change ft::map to std::map and create a new main
sed 's/ft::map/std::map/g' main_map.cpp > main_map_tmp.cpp
# Change ft::mapReverseIterator to std::reverse_iterator and create a new main
sed 's/ft::mapReverseIterator/std::reverse_iterator/g' main_map_tmp.cpp > main_map_real.cpp

# Compile with new main and put result into out1
c++ -Wall -Wextra -Werror -std=c++98 -fsanitize=address main_map_real.cpp
./a.out > real_out

# Compile our main and put result into out2
make re
./ft_containers > my_out

# Compare out1 out2
result=$(diff -u real_out my_out)
if [ "$result" = "" ]; 
then
    echo "${green}It works!${reset}"
else
    echo "${red}It does not work!${reset}"
    echo "${yellow}$result${reset}"
fi

rm a.out
make fclean
rm real_out
rm my_out
rm main_map_tmp.cpp
rm main_map_real.cpp