# Color code
red=`tput setaf 1`
green=`tput setaf 2`
yellow=`tput setaf 3`
reset=`tput sgr0`

# Change main_tmp.cpp to main_map.cpp in Makefile
sed 's/main_tmp.cpp/main_map.cpp/g' pre_makefile > Makefile

# Change ft::map to std::map and create a new main
sed 's/ft::map/std::map/g' main_map.cpp > main_map_tmp2.cpp
# Change ft::pair to std::pair and create a new main
sed 's/ft::pair/std::pair/g' main_map_tmp2.cpp > main_map_tmp3.cpp
# Change ft::make_pair to std::make_pair and create a new main
sed 's/ft::make_pair/std::make_pair/g' main_map_tmp3.cpp > main_map_tmp4.cpp
# Change ft::swap to std::swap and create a new main
sed 's/ft::swap/std::swap/g' main_map_tmp4.cpp > main_map_tmp.cpp

# Change ft::reverse_iterator to std::reverse_iterator and create a new main
sed 's/ft::reverse_iterator/std::reverse_iterator/g' main_map_tmp.cpp > main_map_real.cpp

# Compile with new main and put result into out1
c++ -Wall -Wextra -Werror -std=c++98 main_map_real.cpp
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

make fclean
# rm Makefile
rm a.out
rm real_out
rm my_out
rm main_map_tmp.cpp
rm main_map_tmp2.cpp
rm main_map_tmp3.cpp
rm main_map_tmp4.cpp
rm main_map_real.cpp