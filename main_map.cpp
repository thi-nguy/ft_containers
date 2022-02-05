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

    // // // ! In noi dung cua searchValue bang 2 cach
    // my_tree.print2D();
    // // std::cout << "first node is: " << my_tree.getFirstNode()->value << "\n";
    // // std::cout << "Last node is: " << my_tree.getLastNode()->value << "\n";

    // std::cout << " -------------------------------------------------------\n";
    // my_tree.deleteValue(pair6);
    // my_tree.deleteValue(pair1);
    // my_tree.print2D();
    // std::cout << "first node is: " << my_tree.getFirstNode()->value << "\n";
    // std::cout << "Last node is: " << my_tree.getLastNode()->value << "\n";

    // ! insertValue, int
    ft::RedBlackTree < ft::pair<int, char> > my_tree2;
    for (int i = 0; i < 15; i++)
        my_tree2.insertValue( ft::pair<int, char>(i, 'x') );
    my_tree2.print2D(); // lam operator << cho ft::pair

    // std::cout << "first node is: " << my_tree2.getFirstNode()->value << "\n";
    // my_tree2.deleteValue(3);
    // std::cout << " -------------------------------------------------------\n";
    // my_tree2.print2D();
    // std::cout << "first node is: " << my_tree2.getFirstNode()->value << "\n";

}

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

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

void        test_constructor(std::string test_type)
{
    print_test_name(test_type);

    ft::map<char,int> first;

    first['a']=10;
    first['b']=30;
    first['c']=50;
    first['d']=70;

    ft::map<char,int> second (first.begin(),first.end());

    ft::map<char,int> third (second);

    ft::map<char,int, classcomp> fourth;                 // class as Compare

    bool(*fn_pt)(char,char) = fncomp;
    ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

}

void        test_insert(std::string test_type)
{
    print_test_name(test_type);

    ft::map<char,int> mymap;

    // first insert function version (single parameter):
    mymap.insert ( ft::pair<char,int>('a',100) );
    mymap.insert ( ft::pair<char,int>('b',200) );
    mymap.insert ( ft::pair<char,int>('c',100) );
    mymap.insert ( ft::pair<char,int>('d',200) );
    
    ft::pair<ft::map<char,int>::iterator,bool> ret;
    ret = mymap.insert ( ft::pair<char,int>('z',500) ); // ! Tao them mot tree nua la sao?
    if (ret.second==false) {
        std::cout << "element 'z' already existed";
        std::cout << " with a value of " << ret.first->second << '\n';
    }

    // second insert function version (with hint position):
    ft::map<char,int>::iterator it = mymap.begin();
    mymap.insert ( ft::pair<char,int>('h',100) );
    mymap.insert ( ft::pair<char,int>('x',200) );
    mymap.insert ( ft::pair<char,int>('z',200) );
    mymap.insert ( ft::pair<char,int>('f',100) );
    mymap.insert ( ft::pair<char,int>('g',200) );
    mymap.insert (it, ft::pair<char,int>('e',300));  // max efficiency inserting
    mymap.insert (it, ft::pair<char,int>('i',400));  // no max efficiency inserting
    // mymap.insert(ft::make_pair("g", 123));
    
    // showing contents:
    std::cout << "mymap contains:\n";
    it = mymap.begin();
    ft::map<char, int>::iterator it_end = mymap.end();
    while(it != it_end)
    {
        std::cout << it->first << " => " << it->second << '\n';
        ++it;
    }

    // third insert function version (range insertion):
    ft::map<char,int> anothermap;
    anothermap.insert(mymap.begin(), mymap.find('c'));

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
    // mymap.get_tree().print2D();

    it=mymap.find('b');
    std::cout << "\n------ erase element 'b' by iterator---------\n";
    mymap.erase (it);                   // erasing by iterator
    std::cout << "Map size is: " << mymap.size() << "\n";
    for (it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "\n------ erase element 'c' by key ---------\n";
    size_t ret = mymap.erase ('c');                  // erasing by key
    std::cout << "return value of key erase: " << ret << "\n";

    std::cout << "Map size is: " << mymap.size() << "\n";
    for (it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    
    
    std::cout << "\n------ erase range from 'd' to 'h' ---------\n";
    it=mymap.find('d');
    it_end=mymap.find ('h');
    mymap.erase ( it, it_end );    // erasing by range
    // mymap.get_tree().print2D();

    // show content:
    std::cout << "Map size is: " << mymap.size() << "\n";
    for (it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

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
    // mymap.get_tree().print2D();

    std::cout << "\n-------------- after clear --------------\n";
    mymap.clear();
    std::cout << "mymap sizes: " << mymap.size() << "\n";
    // mymap.get_tree().print2D();
}

void        test_find(std::string test_type)
{
    print_test_name(test_type);

    ft::map<char,int> mymap;
    ft::map<char,int>::iterator it;

    mymap['a']=50;
    mymap['b']=100;
    mymap['c']=150;
    mymap['d']=200;

    it = mymap.find('b');
    if (it != mymap.end())
        mymap.erase (it);

    // print content:
    std::cout << "elements in mymap:" << '\n';
    std::cout << "a => " << mymap.find('a')->second << '\n';
    std::cout << "c => " << mymap.find('c')->second << '\n';
    std::cout << "d => " << mymap.find('d')->second << '\n';


}

void        test_key_comp(std::string test_type)
{
    print_test_name(test_type);
    ft::map<char,int> mymap;

    ft::map<char,int>::key_compare mycomp = mymap.key_comp();

    mymap['a']=100;
    mymap['b']=200;
    mymap['c']=300;

    std::cout << "mymap contains:\n";

    ft::map<char, int>::reverse_iterator rev_it = mymap.rbegin();
    char highest = rev_it->first;     // key value of last element
    std::cout << "highest value: " << highest << '\n';
    ft::map<char,int>::iterator it = mymap.begin();
    do {
        std::cout << it->first << " => " << it->second << '\n';
    } while ( mycomp((*it++).first, highest) );

    std::cout << '\n';
}

void        test_value_comp(std::string test_type)
{
    print_test_name(test_type);

    ft::map<char,int> mymap;

    mymap['x']=1001;
    mymap['y']=2002;
    mymap['z']=3003;

    std::cout << "mymap contains:\n";

    ft::pair<char,int> highest = *mymap.rbegin();          // last element

    ft::map<char,int>::iterator it = mymap.begin();
    do {
        std::cout << it->first << " => " << it->second << '\n';
    } while ( mymap.value_comp()(*it++, highest) );

}

void        test_rbegin(std::string test_type)
{
    print_test_name(test_type);

    ft::map<char,int> mymap;

    mymap['x'] = 100;
    mymap['y'] = 200;
    mymap['z'] = 300;

    // show content:
    ft::map<char,int>::reverse_iterator rit;
    for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
        std::cout << rit->first << " => " << rit->second << '\n';

}

void        test_rend(std::string test_type)
{
    print_test_name(test_type);

    ft::map<char,int> mymap;

    mymap['x'] = 100;
    mymap['y'] = 200;
    mymap['z'] = 300;

    // show content:
    ft::map<char,int>::reverse_iterator rit;
    for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
        std::cout << rit->first << " => " << rit->second << '\n';

}

void    test_begin(std::string test)
{
    print_test_name(test);

    ft::map<char,int> mymap;

    mymap['b'] = 100;
    mymap['a'] = 200;
    mymap['c'] = 300;

    // show content:
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}

void    test_end(std::string test)
{
    print_test_name(test);

    ft::map<char,int> mymap;

    mymap['b'] = 100;
    mymap['a'] = 200;
    mymap['c'] = 300;

    // show content:
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}

void        test_make_pair(std::string test)
{
    print_test_name(test);
    
    ft::pair <int,int> foo;
    ft::pair <int,int> bar;

    foo = ft::make_pair (10,20);
    bar = ft::make_pair (11 , 22); // ok: implicit conversion from pair<double,char>

    std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
    std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
}


void        test_operator_equal(std::string test)
{
    print_test_name(test);

    ft::map<char,int> first;
    ft::map<char,int> second;

    first['x']=8;
    first['y']=16;
    first['z']=32;

    second=first;                // second now contains 3 ints
    first=ft::map<char,int>();  // and first is now empty

    std::cout << "Size of first: " << first.size() << '\n';
    std::cout << "Size of second: " << second.size() << '\n';
}

void        test_lower_bound(std::string test)
{
    print_test_name(test);

    ft::map<char,int> mymap;
    ft::map<char,int>::iterator itlow,itup;

    mymap['a']=20;
    mymap['b']=40;
    mymap['c']=60;
    mymap['d']=80;
    mymap['e']=100;

    itlow=mymap.lower_bound ('b');  // itlow points to b
    itup=mymap.upper_bound ('d');   // itup points to e (not d!)

    mymap.erase(itlow,itup);        // erases [itlow,itup)

    // print content:
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}

void        test_upper_bound(std::string test)
{
    print_test_name(test);

    ft::map<char,int> mymap;
    ft::map<char,int>::iterator itlow,itup;

    mymap['a']=20;
    mymap['b']=40;
    mymap['c']=60;
    mymap['d']=80;
    mymap['e']=100;

    itlow=mymap.lower_bound ('b');  // itlow points to b
    itup=mymap.upper_bound ('d');   // itup points to e (not d!)

    mymap.erase(itlow,itup);        // erases [itlow,itup)

    // print content:
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}

void    test_equal_range(std::string test)
{
    print_test_name(test);

    ft::map<char,int> mymap;

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;

    ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
    ret = mymap.equal_range('b');

    std::cout << "lower bound points to: ";
    std::cout << ret.first->first << " => " << ret.first->second << '\n';

    std::cout << "upper bound points to: ";
    std::cout << ret.second->first << " => " << ret.second->second << '\n';

}

void    test_get_allocator(std::string test)
{
    print_test_name(test);

    int psize;
    ft::map<char,int> mymap;
    ft::pair<const char,int>* p;

    // allocate an array of 5 elements using mymap's allocator:
    p=mymap.get_allocator().allocate(5);

    // assign some values to array
    psize = sizeof(ft::map<char,int>::value_type)*5;

    std::cout << "The allocated array has a size of " << psize << " bytes.\n";

    mymap.get_allocator().deallocate(p,5);

}

void    test_relational_operator(std::string test)
{
    print_test_name(test);

    ft::map<char,int> foo, foo2, bar;
    foo['a']=100;
    foo['b']=200;
    foo2['a']=100;
    foo2['b']=200;
    bar['a']=10;
    bar['z']=1000;

    // foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
    if (foo == foo2) std::cout << "foo and foo2 are equal\n";
    if (foo != bar) std::cout << "foo and bar are not equal\n";
    if (bar < foo) std::cout << "bar is less than foo\n";
    if (foo > bar) std::cout << "foo is greater than bar\n";
    if (bar <= foo) std::cout << "bar is less than or equal to foo\n";
    if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";
}

void    test_swap_non_member(std::string test)
{
    print_test_name(test);

    ft::map<char,int> foo,bar;

    foo['x']=100;
    foo['y']=200;

    bar['a']=11;
    bar['b']=22;
    bar['c']=33;

    ft::swap(foo,bar);

    std::cout << "foo contains:\n";
    for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "bar contains:\n";
    for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}

void    test_swap_moving_pointer(std::string test)
{
    print_test_name(test);

    ft::map<char,int> foo,bar;

    foo['x']=100;
    foo['y']=200;

    bar['a']=11;
    bar['b']=22;
    bar['c']=33;

    std::cout << "Begin of foo: " << foo.begin()->first << "\n";
    std::cout << "Begin of bar: " << bar.begin()->first << "\n";

    std::cout << "After swaping:\n";

    ft::swap(foo, bar);
    std::cout << "Begin of foo: " << foo.begin()->first << "\n";
    std::cout << "Begin of bar: " << bar.begin()->first << "\n";

    ft::pair<int, int> pair1, pair2;
    pair1 = ft::make_pair(1, 2);
    pair2 = ft::make_pair(3, 4);
    ft::map<int, int> map1;
    map1.insert(pair1);
    ft::map<int, int>::iterator it1 = map1.begin();
    ft::map<int, int> map2;
    map2.insert(pair2);
    ft::map<int, int>::iterator it2 = map2.begin();

    ft::swap(map1, map2);
    std::cout << (it1 == map1.begin()) << std::endl;
	std::cout << (it2 == map2.begin()) << std::endl;


}

void    test_time_insert(std::string test)
{
    print_test_name(test);

    ft::map<int, char> mymap;

    clock_t start, end;
    start = clock();
    for (int i = 0; i <= 1000000; i++)
    {
        mymap.insert ( ft::pair<int, char>(i, 'a'));
    }
    end = clock();
    std::cout << "Process took: " << (double(end - start) / CLOCKS_PER_SEC) << " seconds" << "\n";

}


void    test_time_erase(std::string test)
{
    print_test_name(test);

    ft::map<int, char> mymap;

    clock_t start, end;
    start = clock();
    for (int i = 0; i <= 1000000; i++)
    {
        mymap.insert ( ft::pair<int, char>(i, 'a'));
    }
    for (int i = 0; i <= 1000000; i++)
    {
        mymap.erase(mymap.begin());
    }
    end = clock();
    std::cout << "Process took: " << (double(end - start) / CLOCKS_PER_SEC) << " seconds" << "\n";

}

void    test_time_clear(std::string test)
{
    print_test_name(test);

    ft::map<int, char> mymap;

    clock_t start, end;
    start = clock();
    for (int i = 0; i <= 1000000; i++)
    {
        mymap.insert ( ft::pair<int, char>(i, 'a'));
    }
    mymap.clear();
    end = clock();
    std::cout << "Process took: " << (double(end - start) / CLOCKS_PER_SEC) << " seconds" << "\n";

}

int main(void)
{
    print_test_name("TEST MAP");
    // test_tree_Node("Tree Node");
    // test_red_black_tree("Red Black Tree");
    // test_G("map iterator");

    test_pair("pair");
    test_make_pair("make pair");

    test_constructor("constructor");
    test_operator_equal(" operator = ");
    
    test_begin("begin");
    test_end("end");
    test_rbegin("rbegin");
    test_rend("rend");

    test_empty("empty");
    test_size("size");
    test_max_size("max_size");
    
    test_operator_access("[ ]");

    test_insert("insert");
    test_erase("erase");
    test_swap("swap");
    test_clear("clear");

    test_key_comp("key compare");
    test_value_comp("Value_compare");

    test_find("find");
    test_count("count");
    test_lower_bound("lower bound");
    test_upper_bound("upper bound");
    test_equal_range("equal_range");

    test_get_allocator("get_allocator");

    test_swap_non_member("Swap non member");
    test_relational_operator("Relational operators");

    test_swap_moving_pointer("Swap moving pointer, not data");
    test_time_insert("Time function the map - Insert");
    test_time_erase("Time function the map - Erase");
    test_time_clear("Time function the map - Clear");
    // while (1);
    return (0);


}
