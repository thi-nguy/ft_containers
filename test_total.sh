# Color code
red=`tput setaf 1`
green=`tput setaf 2`
yellow=`tput setaf 3`
reset=`tput sgr0`

# Change main_tmp.cpp to main_map.cpp in Makefile
sed 's/main_tmp.cpp/main_total.cpp/g' pre_makefile > Makefile

make re
rm Makefile