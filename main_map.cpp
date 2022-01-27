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

// void        test_red_black_tree(std::string test_type)
// {
//     print_test_name(test_type);

//     // ! insertValue, pair

//     ft::pair < int, std::string > pair1 (42, "orange");
//     ft::pair < int, std::string > pair2 (43, "apple");
//     ft::pair < int, std::string > pair3 (44, "kiwi");
//     ft::pair < int, std::string > pair4 (45, "banana");
//     ft::pair < int, std::string > pair5 (46, "coconut");
//     ft::pair < int, std::string > pair6 (47, "kiwi");
//     ft::RedBlackTree < ft::pair< int, std::string > > my_tree;
//     my_tree.insertValue(pair1);
//     my_tree.insertValue(pair2);
//     my_tree.insertValue(pair3);
//     my_tree.insertValue(pair4);
//     my_tree.insertValue(pair5);
//     my_tree.insertValue(pair6);

//     // // ! In noi dung cua searchValue bang 2 cach
//     my_tree.print2D();
//     // std::cout << "first node is: " << my_tree.getFirstNode()->value << "\n";
//     // std::cout << "Last node is: " << my_tree.getLastNode()->value << "\n";

//     std::cout << " -------------------------------------------------------\n";
//     my_tree.deleteValue(pair6);
//     my_tree.deleteValue(pair1);
//     my_tree.print2D();
//     // std::cout << "first node is: " << my_tree.getFirstNode()->value << "\n";
//     // std::cout << "Last node is: " << my_tree.getLastNode()->value << "\n";

//     // ! insertValue, int
//     // ft::RedBlackTree <int, ft::treeNode<int> > my_tree2;
//     // for (int i = 0; i < 15; i++)
//     //     my_tree2.insertValue(i);
//     // my_tree2.print2D(); // lam operator << cho ft::pair

//     // std::cout << "first node is: " << my_tree2.getFirstNode()->value << "\n";
//     // my_tree2.deleteValue(3);
//     // std::cout << " -------------------------------------------------------\n";
//     // my_tree2.print2D();
//     // std::cout << "first node is: " << my_tree2.getFirstNode()->value << "\n";

// }

// void        test_tree_Node(std::string test_type)
// {
//     print_test_name(test_type);

//     // Constructor
//     ft::treeNode< int > node1;
//     ft::treeNode< int > node2 (4);
//     ft::treeNode< std::string > node3 ("hello");
//     ft::treeNode< ft::pair< int, char > > node4;

//     ft::pair < int, std::string > a_pair (42, "my school");
//     ft::treeNode< ft::pair< int, std::string > > node5 (a_pair);

//     // Copy constructor && operator =
//     ft::treeNode <ft::pair< int, std::string > > node6 = node5;
//     ft::treeNode <ft::pair < int, char > > node7 (node4);
// }
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

void        test_empty(std::string test_type)
{
    print_test_name(test_type);

    ft::map<char, int> map_a;
    std::cout << map_a.empty() << "\n";
}

// bool fncomp (char lhs, char rhs) {return lhs<rhs;}

// struct classcomp {
//   bool operator() (const char& lhs, const char& rhs) const
//   {return lhs<rhs;}
// };

// void        test_constructor(std::string test_type)
// {
//     print_test_name(test_type);

//     ft::map<char,int> first;

//     first['a']=10;
//     first['b']=30;
//     first['c']=50;
//     first['d']=70;

//     ft::map<char,int> second (first.begin(),first.end());

//     ft::map<char,int> third (second);

//     ft::map<char,int, classcomp> fourth;                 // class as Compare

//     bool(*fn_pt)(char,char) = fncomp;
//     ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

// }

void        test_insert(std::string test_type)
{
    print_test_name(test_type);

    ft::map<char,int> mymap;

    // first insert function version (single parameter):
    mymap.insert ( ft::pair<char,int>('a',100) );
    mymap.insert ( ft::pair<char,int>('b',200) );
    mymap.insert ( ft::pair<char,int>('c',100) );
    mymap.insert ( ft::pair<char,int>('d',200) );
    
    // mymap.get_tree().print2D();
    // std::cout << "Root = " << mymap.get_tree().getRoot() << "\n";
    // std::cout << "Root's value = " << mymap.get_tree().getRoot()->value.first << "\n";

    // ft::pair<ft::map<char,int>::iterator,bool> ret;
    // ret = mymap.insert ( ft::pair<char,int>('z',500) ); // ! Tao them mot tree nua la sao?
    // if (ret.second==false) {
    //     std::cout << "element 'z' already existed";
    //     std::cout << " with a value of " << ret.first->second << '\n';
    // }

    // second insert function version (with hint position):
    ft::map<char,int>::iterator it = mymap.begin();
    mymap.insert ( ft::pair<char,int>('h',100) );
    mymap.insert ( ft::pair<char,int>('x',200) );
    mymap.insert ( ft::pair<char,int>('z',200) );
    mymap.insert ( ft::pair<char,int>('f',100) );
    mymap.insert ( ft::pair<char,int>('g',200) );
    mymap.insert (it, ft::pair<char,int>('e',300));  // max efficiency inserting
    mymap.insert (it, ft::pair<char,int>('i',400));  // no max efficiency inserting
    
    // showing contents:
    std::cout << "mymap contains:\n";
    it = mymap.begin();
    ft::map<char, int>::iterator it_end = mymap.end();
    while(it != it_end)
    {
        std::cout << it->first << " => " << it->second << '\n';
        ++it;
    }

    // Print tree of map
    // mymap.get_tree().print2D();
    // std::cout << "Root = " << mymap.get_tree().getRoot() << "\n";
    // std::cout << "Root's value = " << mymap.get_tree().getRoot()->value.first << "\n";

    // third insert function version (range insertion):
    ft::map<char,int> anothermap;
    anothermap.insert(mymap.begin(),mymap.find('c'));

    // showing contents:
    std::cout << "anothermap contains:\n";
    for (it=anothermap.begin(); it!=anothermap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    // Print tree of map
    // anothermap.get_tree().print2D();

}

void        test_size(std::string test_type)
{
    print_test_name(test_type);

    ft::map<char, int> my_map;
    std::cout << "mymap.size() is " << my_map.size() << '\n';
}

void        test_max_size(std::string test_type)
{
    print_test_name(test_type);

      int i;
    ft::map<int,int> mymap;

    if (mymap.max_size()>1000)
    {
        for (i=0; i<1000; i++) mymap[i]=0;
        std::cout << "The map contains 1000 elements.\n";
    }
    else std::cout << "The map could not hold 1000 elements.\n";

}
void        test_operator_access(std::string test_type)
{
    print_test_name(test_type);

    ft::map<char,std::string> mymap;

    mymap['a']="an element";
    mymap['b']="another element";
    mymap['c']=mymap['b'];

    std::cout << "mymap['a'] is " << mymap['a'] << '\n';
    std::cout << "mymap['b'] is " << mymap['b'] << '\n';
    std::cout << "mymap['c'] is " << mymap['c'] << '\n';
    std::cout << "mymap['d'] is " << mymap['d'] << '\n';

    std::cout << "mymap now contains " << mymap.size() << " elements.\n";
}


void        test_count(std::string test_type)
{
    print_test_name(test_type);
    ft::map<char,int> mymap;
    char c;

    mymap ['a']=101;
    mymap ['c']=202;
    mymap ['f']=303;

    for (c='a'; c<'h'; c++)
    {
        //std::cout << c << " -> " << mymap[c] << "   " << mymap.count(c);
        /* [] will add element if it doest not find it */
        std::cout << c;
        if (mymap.count(c)>0)
            std::cout << " is an element of mymap.\n";
        else 
            std::cout << " is NOT an element of mymap.\n";
    }
}

void        test_swap(std::string test_type)
{
    print_test_name(test_type);

    ft::map<char,int> foo,bar;

    foo['x']=100;
    foo['y']=200;

    bar['a']=11;
    bar['b']=22;
    bar['c']=33;

    foo.swap(bar);

    std::cout << "foo contains:\n";
    for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "bar contains:\n";
    for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}

void        test_erase(std::string test_type)
{
    print_test_name(test_type);
    ft::map<char,int> mymap;
    ft::map<char,int>::iterator it, it_end;

    // insert some values:
    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    mymap['d']=40;
    mymap['e']=50;
    mymap['f']=60;
    mymap['g']=70;
    mymap['h']=80;
    mymap['i']=90;
    mymap['j']=100;
    mymap.get_tree().print2D();

    // it=mymap.find('b');
    // std::cout << "\n------ erase 1 element by iterator---------\n";
    // mymap.erase (it);                   // erasing by iterator

    // std::cout << "\n------ erase 1 element by key ---------\n";
    // size_t ret = mymap.erase ('c');                  // erasing by key
    // std::cout << "return value of key erase: " << ret << "\n";

    
    std::cout << "\n------ erase from 'c' to 'h' ---------\n";
    it=mymap.find ('c');
    it_end=mymap.find ('h');
    mymap.erase ( it, it_end );    // erasing by range
    mymap.get_tree().print2D();
    

    // ! Erase by key
    // std::cout << "\n------ erase c -----------------------\n";
    // it=mymap.find ('c');
    // mymap.erase(it);
    // mymap.get_tree().print2D();
    // std::cout << "\n------ erase d -----------------------\n";
    // it = mymap.find('d');
    // mymap.erase(it);
    // mymap.get_tree().print2D();
    // std::cout << "\n------ erase e -----------------------\n";
    // it = mymap.find('e');
    // mymap.erase(it);
    // mymap.get_tree().print2D();
    // std::cout << "\n------ erase f -----------------------\n";
    // it = mymap.find('f');
    // mymap.erase(it);
    // mymap.get_tree().print2D();
    // std::cout << "\n------ erase g -----------------------\n";
    // it = mymap.find('g');
    // mymap.erase(it);
    // mymap.get_tree().print2D();
    // std::cout << "\n------ erase h -----------------------\n";
    // it = mymap.find('h');
    // mymap.erase(it);
    // mymap.get_tree().print2D();

    // show content:
    // std::cout << "Map size is: " << mymap.size() << "\n";
    // for (it=mymap.begin(); it!=mymap.end(); ++it)
    //     std::cout << it->first << " => " << it->second << '\n';

}


void        test_clear(std::string test_type)
{
    print_test_name(test_type);

    ft::map<char,int> mymap;

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    mymap['d']=40;
    mymap['e']=50;
    mymap['f']=60;

    std::cout << "mymap contains:\n";
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    std::cout << "mymap sizes: " << mymap.size() << "\n";
    mymap.get_tree().print2D();

    std::cout << "\n-------------- clear --------------\n";
    mymap.clear();
    std::cout << "mymap sizes: " << mymap.size() << "\n";
    mymap.get_tree().print2D();
}

void        test_map(std::string test_type)
{
    print_test_name(test_type);
    // test_tree_Node("Tree Node");
    // test_red_black_tree("Red Black Tree");
    // test_mapIterator("map iterator");
    // test_constructor("constructor");
    // test_pair("pair");
    // test_empty("empty");
    // test_size("size");
    // test_max_size("max_size");
    // test_insert("insert");
    // test_operator_access("[ ]");
    // test_swap("swap");
    // test_count("count");
    test_erase("erase");
    // test_clear("clear");
}

int main(void)
{
    test_map("MAP");
    return (0);
}