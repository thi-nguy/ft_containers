#include <vector>
#include <iostream>
#include <string>

#include "./vector/vector.hpp"

int main(void)
{
    ft::vector<int> first;
    ft::vector<std::string> second(4, "hello");
    ft::vector<std::string> third(second.begin(), second.end()); // !todo constructor nay bug

    std::vector<int> real_vector;
    std::vector<int>::iterator it;
    return(0);
}