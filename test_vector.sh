# Color code
red=`tput setaf 1`
green=`tput setaf 2`
yellow=`tput setaf 3`
reset=`tput sgr0`

# Change main_tmp.cpp to main_vector.cpp in Makefile
sed 's/main_tmp.cpp/main_vector.cpp/g' pre_makefile > Makefile

# Change ft::vector to std::vector and create a new main
sed 's/ft::vector/std::vector/g' main_vector.cpp > main_vector_tmp.cpp
# Change ft::VectorReverseIterator to std::reverse_iterator and create a new main
sed 's/ft::reverse_iterator/std::reverse_iterator/g' main_vector_tmp.cpp > main_vector_tmp2.cpp
# Change ft::swap to std::swap and create a new main
sed 's/ft::swap/std::swap/g' main_vector_tmp2.cpp > main_vector_real.cpp


# Compile with new main and put result into out1
clang++ -Wall -Wextra -Werror -std=c++98 main_vector_real.cpp
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
rm Makefile
rm a.out
rm real_out
rm my_out
rm main_vector_tmp.cpp
rm main_vector_tmp2.cpp
rm main_vector_real.cpp