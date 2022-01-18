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
#include "./map/pair.hpp"
#include "./map/treeNode.hpp"

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

    // ! insertValue, pair

    // ft::pair < int, std::string > pair1 (42, "orange");
    // ft::pair < int, std::string > pair2 (43, "apple");
    // ft::pair < int, std::string > pair3 (44, "kiwi");
    // ft::pair < int, std::string > pair4 (45, "banana");
    // ft::pair < int, std::string > pair5 (46, "coconut");
    // ft::pair < int, std::string > pair6 (47, "kiwi");
    // ft::RedBlackTree < ft::pair< int, std::string > > my_tree;
    // my_tree.insertValue(pair1);
    // my_tree.insertValue(pair2);
    // my_tree.insertValue(pair3);
    // my_tree.insertValue(pair4);
    // my_tree.insertValue(pair5);
    // my_tree.insertValue(pair6);

    // // ! In noi dung cua searchValue bang 2 cach
    // ft::treeNode<ft::pair < int, std::string> > *a_node = my_tree.searchValue(my_tree.getRoot(), pair3);
    // std::cout << a_node->value << "\n";

    // std::cout << my_tree.searchValue(my_tree.getRoot(), pair3)->value << "\n";

    // my_tree.print2D();
    // std::cout << " -------------------------------------------------------\n";
    // my_tree.deleteValue(pair2);
    // my_tree.print2D();

    // ! insertValue, int
    ft::RedBlackTree <int, ft::treeNode<int> > my_tree2;
    for (int i = 0; i < 10; i++)
        my_tree2.insertValue(i);
    my_tree2.print2D(); // lam operator << cho ft::pair

    

    // if (my_tree2.getRoot() != NULL)
    //     std::cout << my_tree2.getRoot()->value << "\n";
    // ! Delete a node
    // my_tree2.deleteValue(0);
    // std::cout << " -------------------------------------------------------\n";
    // my_tree2.print2D();

}

void        test_empty(std::string test_type)
{
    print_test_name(test_type);

    ft::map<char, int> map_a;
    std::cout << map_a.empty() << "\n";
}


void        test_constructor(std::string test_type)
{
    print_test_name(test_type);

    // std::cout << "Empty constructor called\n";
    ft::map<char, int> map_a;

    // std::cout << "Range constructor called\n";
    // ft::map<std::string> map_b(4, "hello");
    // std::cout << "First element: " << map_b.front() << std::endl << std::endl;

    // std::cout << "Copy constructor called\n";
    ft::map<char,int> first;

    // first['a']=10;
    // first['b']=30;
    // first['c']=50;
    // first['d']=70;

    ft::map<char,int> second (first);
}

void        test_mapIterator(std::string test_type)
{
    print_test_name(test_type);

    ft::map<char, int> my_map;
    // ft::map<std::string, int>::iterator my_iterator;

    // my_iterator = my_map.begin();

    ft::pair<char,int> pair1('a',100);
    std::cout << pair1.first << " " << pair1.second << "\n";



}

void        test_size(std::string test_type)
{
    print_test_name(test_type);

    ft::map<char, int> my_map;
    std::cout << "mymap.size() is " << my_map.size() << '\n';
}


void        test_map(std::string test_type)
{
    print_test_name(test_type);
    // test_pair("pair");
    // test_tree_Node("Tree Node");
    // test_red_black_tree("Red Black Tree");
    // test_empty("Empty");
    // test_mapIterator("map iterator");
    // test_size("size");
    // test_constructor("constructor");
}

int main(void)
{
    test_map("MAP");
    return (0);
}