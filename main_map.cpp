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
#include "./map/red_black_tree.hpp"

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

void        test_tree_Node(std::string test_type)
{
    print_test_name(test_type);

    // Constructor
    ft::treeNode< int > node1;
    ft::treeNode< int > node2 (4);
    ft::treeNode< std::string > node3 ("hello");
    ft::treeNode< ft::pair< int, char > > node4;

    ft::pair < int, std::string > a_pair (42, "my school");
    ft::treeNode< ft::pair< int, std::string > > node5 (a_pair);

    // Copy constructor && operator =
    ft::treeNode <ft::pair< int, std::string > > node6 = node5;
    ft::treeNode <ft::pair < int, char > > node7 (node4);
}

void        test_red_black_tree(std::string test_type)
{
    print_test_name(test_type);

    // ft::pair < int, std::string > pair1 (42, "my school");
    // ft::pair < int, std::string > pair2 (43, "not my school");
    // ft::pair < int, std::string > pair3 (44, "never my school");
    // ft::RedBlackTree < ft::pair< int, std::string > > my_tree;
    // my_tree.insert(pair1);
    // my_tree.insert(pair2);
    // my_tree.insert(pair3);

    // my_tree.print2D(); // lam operator << cho ft::pair

    ft::RedBlackTree <int> my_tree;

    for (int i = 0; i < 10; i++)
        my_tree.insert(i);
    my_tree.print2D(); // lam operator << cho ft::pair



}


void        test_map(std::string test_type)
{
    print_test_name(test_type);
    // test_pair("pair");
    test_tree_Node("Tree Node");
    test_red_black_tree("Red Black Tree");
}

int main(void)
{
    test_map("MAP");
    return (0);
}