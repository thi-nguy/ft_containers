#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "./map/map.hpp"
#include "./utils/utils.hpp"

void        print_test_name(std::string name)
{
    std::cout << "\n------- TEST ";
    std::cout << name << " ------------------\n";
}

template <class T>
void        print_element(ft::vector<T> my_vector)
{
    int size = my_vector.size();
    if (size <= 0)
        return ;
    std::cout << "Elements in the vector: {";
    int i;
    for (i = 0; i < size - 1; i++)
    {
        std::cout << my_vector[i] << ", ";
    }
    std::cout << my_vector[i] << "}" << std::endl;
}

void        test_constructor(std::string test_type)
{
    print_test_name(test_type);
    std::map<char, int> first;
    first['a'] = 10;
    first['d'] = 40;
    first['b'] = 100;

}




void        test_map(std::string test_type)
{
    print_test_name(test_type);

    // test_constructor("constructor");
    // Iterator
}

int main(void)
{
    test_map("MAP");
    return (0);
}