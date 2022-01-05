#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <utility> // ft::pair, std::make_pair
#include <string>

#include "./map/map.hpp"

void        print_test_name(std::string name)
{
    std::cout << "\n------- TEST ";
    std::cout << name << " ------------------\n";
}

void        test_pair(std::string test_type)
{
    print_test_name(test_type);
    ft::pair<std::string, double> product1;
    ft::pair<std::string, double> product2 ("tomatoes", 2.30);
    ft::pair<std::string, double> product3 (product2);

    product1 = ft::make_pair(std::string("lightbulbs"),0.99);
    
    std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
    std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
    std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';

    product3.first = "gloves";
    product3.second = 42.90;
    std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
    std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
    std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';

    ft::pair<int,char> foo (10,'z');
    ft::pair<int,char> foo2 (10,'z');
    ft::pair<int,char> bar (90,'a');

    if (foo==foo2) std::cout << "foo and foo2 are equal\n";
    if (foo!=bar) std::cout << "foo and bar are not equal\n";
    if (foo< bar) std::cout << "foo is less than bar\n";
    if (bar > foo) std::cout << "bar is greater than foo\n";
    if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
    if (bar >= foo) std::cout << "bar is greater than or equal to foo\n";
}


void        test_map(std::string test_type)
{
    print_test_name(test_type);
    test_pair("pair");
}

int main(void)
{
    test_map("MAP");
    return (0);
}