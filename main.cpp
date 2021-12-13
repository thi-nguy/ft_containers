#include <vector>
#include <iostream>
#include "vector.hpp"

int main(void)
{
    ft::vector<int> first;
    ft::vector<std::string> second(4, "hello");
    ft::vector<std::string> third(second.getBegin(), second.getEnd());
    ft::vector<std::string>::pointer it = third.getBegin();
    while (it != third.getEnd())
    {
        std::cout << *it << " ";
        ++it;
    }

    return(0);
}