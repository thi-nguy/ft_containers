#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "./vector/vector.hpp"
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
    {
        std::cout << "Default constructor called\n";
        ft::vector<int> vector_a;
        std::cout << "Size of vector_a: " << vector_a.size() << std::endl << std::endl;

        std::cout << "Range constructor called\n";
        ft::vector<std::string> vector_b(4, "hello");
        std::cout << "First element: " << vector_b.front() << std::endl << std::endl;

        std::cout << "Fill constructor called\n";
        ft::vector<std::string> vector_c(vector_b.begin(), vector_b.end());
        std::cout << "First element: " << vector_c.front() << std::endl << std::endl;

        std::cout << "Copy constructor called\n";
        ft::vector<std::string> vector_d(vector_b);
        std::cout << "Size of vector_d: " << vector_d.size() << std::endl << std::endl;
        std::cout << "Erasing one element of vector_d\n";
        vector_d.erase(vector_d.begin());
        std::cout << "Size of vector_d: " << vector_d.size() << std::endl;
        std::cout << "Size of vector_c: " << vector_b.size() << std::endl << std::endl;

        std::cout << "Assignation Operator called\n";
        ft::vector<std::string> vector_e = vector_d;
        std::cout << "Size of vector_e: " << vector_e.size() << std::endl << std::endl;
        std::cout << "Erasing one element of vector_e\n";
        vector_e.erase(vector_e.begin());
        std::cout << "Size of vector_e: " << vector_e.size() << std::endl;
        std::cout << "Size of vector_d: " << vector_d.size() << std::endl;
    }
}

void      test_begin(std::string test_type)
{
    print_test_name(test_type);
    ft::vector<std::string> vector_b(4, "hello");

    std::cout << "First element of vector_b: " << *(vector_b.begin()) << std::endl;
}

void      test_end(std::string test_type)
{
    print_test_name(test_type);
    ft::vector<int> myvector;
    for (int i=1; i<=5; i++) myvector.push_back(i);

    std::cout << "myvector contains:";
    for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

void         test_size(std::string test_type)
{
    print_test_name(test_type);
    ft::vector<int> first;
    ft::vector<std::string> second(4, "hello");
    std::cout << "size 1: " << first.size() << std::endl;
    std::cout << "size 2: " << second.size() << std::endl;

    second.erase(second.begin());
    std::cout << "After Erase one element of vector\n";
    std::cout << "size 2: " << second.size() << std::endl;
}

void         test_max_size(std::string test_type)
{
    print_test_name(test_type);
    ft::vector<int> first;
    ft::vector<std::string> second(4, "hello");
    std::cout << "max_size 1: " << first.max_size() << std::endl;
    std::cout << "max_size 2: " << second.max_size() << std::endl;

    second.erase(second.begin());
    std::cout << "After Erase one element of vector\n";
    std::cout << "max_size 1: " << first.max_size() << std::endl;
    std::cout << "max_size 2: " << second.max_size() << std::endl;
}

void        test_capacity(std::string test_type)
{
    print_test_name(test_type);
    std::cout << "Original Capacity\n";
    ft::vector<int> first;
    ft::vector<std::string> second(4, "hello");
    ft::vector<std::string> third(second.begin(), second.end());
    ft::vector<std::string> fourth(third);

    std::cout << "capacity 1: " << first.capacity() << std::endl;
    std::cout << "capacity 2: " << second.capacity() << std::endl;
    std::cout << "capacity 3: " << third.capacity() << std::endl;
    std::cout << "capacity 4: " << fourth.capacity() << std::endl;
    
    std::cout << "Capacity after reserving 10 places\n";
    first.reserve(10);
    second.reserve(10);
    third.reserve(10);
    fourth.reserve(10);

    std::cout << "capacity 1: " << first.capacity() << std::endl;
    std::cout << "capacity 2: " << second.capacity() << std::endl;
    std::cout << "capacity 3: " << third.capacity() << std::endl;
    std::cout << "capacity 4: " << fourth.capacity() << std::endl;
}

void      test_empty(std::string test_type)
{
    print_test_name(test_type);
    ft::vector<int> first;
    ft::vector<std::string> second(4, "hello");
    ft::vector<std::string> third(second.begin(), second.end());
    ft::vector<std::string> fourth(third);

    std::cout << "Test empty\n";
    std::cout << "empty 1: " << first.empty() << std::endl;
    std::cout << "empty 2: " << second.empty() << std::endl;
    std::cout << "empty 3: " << third.empty() << std::endl;
    std::cout << "empty 4: " << fourth.empty() << std::endl;
}

void        test_operator(std::string test_type)
{
    print_test_name(test_type);
    ft::vector<int> foo (3,100);   // three ints with a value of 100
    ft::vector<int> bar (2,200);   // two ints with a value of 200

    if (foo == bar) std::cout << "foo and bar are equal\n";
    if (foo != bar) std::cout << "foo and bar are not equal\n";
    if (foo < bar) std::cout << "foo is less than bar\n";
    if (bar > foo) std::cout << "bar is greater than foo\n";
    if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
    if (bar >= foo) std::cout << "bar is greater than or equal to foo\n";

    ft::vector<int> foo2 (2,100);   // two ints with a value of 100
    ft::vector<int> foo3 (2,100);   // two ints with a value of 100
    if (foo2 == foo3) std::cout << "foo2 and foo3 are equal\n";
}

void        test_reserve(std::string test_type)
{
    print_test_name(test_type);
    std::cout << "Original Capacity\n";
    ft::vector<int> first;
    ft::vector<std::string> second(4, "hello");
    ft::vector<std::string> third(second.begin(), second.end());
    ft::vector<std::string> fourth(third);

    std::cout << "capacity 1: " << first.capacity() << std::endl;
    std::cout << "capacity 2: " << second.capacity() << std::endl;
    std::cout << "capacity 3: " << third.capacity() << std::endl;
    std::cout << "capacity 4: " << fourth.capacity() << std::endl;
    
    std::cout << "\nCapacity after reserving -1, 3, 10, max_size + 1 places\n";
    try
    {
        first.reserve(-1);
        std::cout << "capacity 1: " << first.capacity() << std::endl;
    }
    catch(const std::length_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        second.reserve(3);
        std::cout << "capacity 2: " << second.capacity() << std::endl;
    }
    catch(const std::length_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        third.reserve(10);
        std::cout << "capacity 3: " << third.capacity() << std::endl;
    }
    catch(const std::length_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        fourth.reserve(fourth.max_size() + 1);
        std::cout << "capacity 4: " << fourth.capacity() << std::endl;
    }
    catch(const std::length_error& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void        test_operator_access(std::string test_type)
{
    print_test_name(test_type);
    ft::vector<std::string> second(4, "cat");
    second[0] = "dog";
    second[1] = "bird";
    second[2] = "fish";
    print_element(second);

    std::cout << "First element: " << second[0] << std::endl;
    std::cout << "End element: " << second[3] << std::endl;
}

void        test_at(std::string test_type)
{
    print_test_name(test_type);
    ft::vector<std::string> second(4, "songoku");
    second.at(0) = "calic";
    second.at(2) = "buma";
    print_element(second);

    std::cout << "First element: " << second.at(0) << std::endl;
    std::cout << "End element: " << second.at(3) << std::endl;
    try
    {
        std::cout << "Out of range element: " << second.at(second.size()) << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void        test_front(std::string test_type)
{
    print_test_name(test_type);
    ft::vector<std::string> first(1, "cat");
    ft::vector<std::string> second(4, "songoku");
    print_element(second);
    print_element(first);
    std::cout << "Changing the first element.... \n";
    second.front() = "calic";
    first.front() = "dog";
    print_element(second);
    print_element(first);
}

void        test_back(std::string test_type)
{
    print_test_name(test_type);
    ft::vector<std::string> first(1, "hello");
    ft::vector<std::string> second(4, "mama");
    print_element(second);
    print_element(first);
    std::cout << "Changing the end element.... \n";
    second.back() = "dada";
    first.back() = "ciao";
    print_element(second);
    print_element(first);
}

void    test_push_back(std::string test_type)
{
    print_test_name(test_type);
    srand(time(NULL));

    ft::vector<int> myvector;
    for (int i = 0; i < 1; i++)
    {
        int myint = rand() % 1000;
        myvector.push_back (myint);
    }
    std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
    std::cout << "myvector's capacity " << myvector.capacity() << "\n";

    for (int i = 0; i < 2; i++)
    {
        int myint = rand() % 1000;
        myvector.push_back (myint);
    }
    std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
    std::cout << "myvector's capacity " << myvector.capacity() << "\n";

    for (int i = 0; i < 5; i++)
    {
        int myint = rand() % 1000;
        myvector.push_back (myint);
    }
    std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
    std::cout << "myvector's capacity " << myvector.capacity() << "\n";

    for (int i = 0; i < 65; i++)
    {
        int myint = rand() % 1000;
        myvector.push_back (myint);
    }
    std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
    std::cout << "myvector's capacity " << myvector.capacity() << "\n";
}

void    test_pop_back(std::string test_type)
{
    print_test_name(test_type);

    ft::vector<int> myvector;
    for (int i = 0; i < 15; i++)
    {
        myvector.push_back (i);
    }
    print_element(myvector);
    std::cout << "myvector's size = " << int(myvector.size()) << "\n";
    std::cout << "myvector's capacity = " << myvector.capacity() << "\n";
    std::cout << "\nPop 10 elements\n";
    for (int i = 0; i < 10; i++)
        myvector.pop_back();
    print_element(myvector);
    std::cout << "myvector's size = " << int(myvector.size()) << "\n";
    std::cout << "myvector's capacity = " << myvector.capacity() << "\n";
}

void    test_clear(std::string test_type)
{
    print_test_name(test_type);

    ft::vector<int> myvector;
    for (int i = 0; i < 15; i++)
    {
        myvector.push_back (i);
    }
    print_element(myvector);
    std::cout << "myvector's size = " << int(myvector.size()) << "\n";
    std::cout << "myvector's capacity = " << myvector.capacity() << "\n";
    std::cout << "\nClear elements\n";
    myvector.clear();
    print_element(myvector);
    std::cout << "myvector's size = " << int(myvector.size()) << "\n";
    std::cout << "myvector's capacity = " << myvector.capacity() << "\n";
}

void    test_resize(std::string test_type)
{
    print_test_name(test_type);

    ft::vector<int> myvector;
    for (int i = 0; i < 15; i++)
    {
        myvector.push_back (i);
    }
    print_element(myvector);
    std::cout << "myvector's size = " << int(myvector.size()) << "\n";
    std::cout << "myvector's capacity = " << myvector.capacity() << "\n";
    std::cout << "\nResize vector\n";
    myvector.resize(5);
    print_element(myvector);
    std::cout << "myvector's size = " << int(myvector.size()) << "\n";
    std::cout << "myvector's capacity = " << myvector.capacity() << "\n";
    myvector.resize(8,100);
    print_element(myvector);
    std::cout << "myvector's size = " << int(myvector.size()) << "\n";
    std::cout << "myvector's capacity = " << myvector.capacity() << "\n";
    myvector.resize(17);
    print_element(myvector);
    std::cout << "myvector's size = " << int(myvector.size()) << "\n";
    std::cout << "myvector's capacity = " << myvector.capacity() << "\n";
}

void        test_swap(std::string test_type)
{
    print_test_name(test_type);

    ft::vector<int> foo (3, 10);   // three ints with a value of 100
    ft::vector<int> bar (5, 42);   // five ints with a value of 200
    std::cout << "foo contains:";
    print_element(foo);
    std::cout << "foo's size = " << int(foo.size()) << "\n";
    std::cout << "foo's capacity = " << foo.capacity() << "\n";
    std::cout << "bar contains:";
    print_element(bar);
    std::cout << "bar's size = " << int(bar.size()) << "\n";
    std::cout << "bar's capacity = " << bar.capacity() << "\n";
    std::cout << "\nSwap foo, bar\n";
    foo.swap(bar);
    std::cout << "foo contains:";
    print_element(foo);
    std::cout << "foo's size = " << int(foo.size()) << "\n";
    std::cout << "foo's capacity = " << foo.capacity() << "\n";
    std::cout << "bar contains:";
    print_element(bar);
    std::cout << "bar's size = " << int(bar.size()) << "\n";
    std::cout << "bar's capacity = " << bar.capacity() << "\n";
}

void        test_erase(std::string test_type)
{
    print_test_name(test_type);
    ft::vector<int> myvector;

  // set some values (from 1 to 10)
    for (int i=0; i<=10; i++) myvector.push_back(i);
    print_element(myvector);
    std::cout << "Erase 5th element\n";
    myvector.erase (myvector.begin()+5);
    print_element(myvector);
    std::cout << "myvector's size = " << int(myvector.size()) << "\n";
    std::cout << "myvector's capacity = " << myvector.capacity() << "\n";
    std::cout << "Erase first to third element\n";
    myvector.erase (myvector.begin(),myvector.begin()+3);
    print_element(myvector);
    std::cout << "myvector's size = " << int(myvector.size()) << "\n";
    std::cout << "myvector's capacity = " << myvector.capacity() << "\n";

}

void        test_assign(std::string test_type)
{
    print_test_name(test_type);
    ft::vector<int> myvector;
    for (int i=0; i<10; i++) myvector.push_back(i);
    print_element(myvector);
    std::cout << "myvector's size = " << int(myvector.size()) << "\n";
    std::cout << "myvector's capacity = " << myvector.capacity() << "\n";
    std::cout << "\nAssign 7 int with a value of 100\n";
    myvector.assign (7,100);             // 7 ints with a value of 100
    print_element(myvector);
    std::cout << "myvector's size = " << int(myvector.size()) << "\n";
    std::cout << "myvector's capacity = " << myvector.capacity() << "\n";

    std::cout << "\nAssign 5 int with a value of 42 to empty vector\n";
    ft::vector<int> first;
    first.assign(5, 42);
    print_element(first);
    std::cout << "first's size = " << int(first.size()) << "\n";
    std::cout << "first's capacity = " << first.capacity() << "\n";

    std::cout << "\nAssign central values of myvector\n";
    ft::vector<int> myvector2;
    for (int i=0; i<10; i++) myvector2.push_back(i);
    ft::vector<int>::iterator it;
    it = myvector2.begin() + 2;

    ft::vector<int> second;
    second.assign(it, myvector2.end() - 2); // the 5 central values of first
    print_element(second);
    std::cout << "second's size = " << int(second.size()) << "\n";
    std::cout << "second's capacity = " << second.capacity() << "\n";

    std::cout << "\nAssign central values of an array: {1776, 7, 4, 42, 100, 10}\n";
    ft::vector<int> third;
    int myints[] = {1776, 7, 4, 42, 100, 10};
    third.assign(myints + 1, myints + 4);
    print_element(third);
    std::cout << "third's size = " << int(third.size()) << "\n";
    std::cout << "third's capacity = " << third.capacity() << "\n";
}

void        test_insert(std::string test_type)
{
    print_test_name(test_type);

    ft::vector<int> myvector (3,100);
    print_element(myvector);
    std::cout << "size: " << myvector.size() << "\n";
    std::cout << "capacity: " << myvector.capacity() << "\n";

    ft::vector<int>::iterator it;
    it = myvector.begin();
    it = myvector.insert ( it , 200 );
    print_element(myvector);
    std::cout << "size: " << myvector.size() << "\n";
    std::cout << "capacity: " << myvector.capacity() << "\n";

    ft::vector<int> myvector2(1, 42);
    print_element(myvector2);
    std::cout << "size: " << myvector2.size() << "\n";
    std::cout << "capacity: " << myvector2.capacity() << "\n";

    ft::vector<int>::iterator it2;
    it2 = myvector2.begin();
    it2 = myvector2.insert ( it2 , 200 );
    print_element(myvector2);
    std::cout << "size: " << myvector2.size() << "\n";
    std::cout << "capacity: " << myvector2.capacity() << "\n";

    ft::vector<int> myvector3;
    std::cout << "size: " << myvector3.size() << "\n";
    std::cout << "capacity: " << myvector3.capacity() << "\n";

    ft::vector<int>::iterator it3;
    it3 = myvector3.begin();
    it3 = myvector3.insert ( it3 , 200 );
    print_element(myvector3);
    std::cout << "size: " << myvector3.size() << "\n";
    std::cout << "capacity: " << myvector3.capacity() << "\n";

    ft::vector<int> myvector4(2, 42);
    print_element(myvector4);
    std::cout << "size: " << myvector4.size() << "\n";
    std::cout << "capacity: " << myvector4.capacity() << "\n";

    ft::vector<int>::iterator it4;
    it4 = myvector4.begin();
    myvector4.insert ( it4 , 3, 200 );
    print_element(myvector4);
    std::cout << "size: " << myvector4.size() << "\n";
    std::cout << "capacity: " << myvector4.capacity() << "\n";

    ft::vector<int> myvector5 (3,100);
    ft::vector<int>::iterator it5;

    it5 = myvector5.begin();
    it5 = myvector5.insert ( it5 , 200 );
    print_element(myvector5);

    myvector5.insert (it5, 2, 300);
    print_element(myvector5);

    // "it5" no longer valid, get a new one:
    it5 = myvector5.begin();

    ft::vector<int> anothervector (2,400);
    myvector5.insert (it5+2,anothervector.begin(),anothervector.end());

    int myarray [] = { 501,502,503 };
    myvector5.insert (myvector5.begin(), myarray, myarray+3);

    print_element(myvector5);
}

void        test_reverse_iterator(std::string test_type)
{
    print_test_name(test_type);

    ft::vector<int> myvector;
    for (int i=0; i<10; i++) myvector.push_back(i);

    typedef ft::vector<int>::iterator iter_type;

    ft::VectorReverseIterator<iter_type> rev_end (myvector.begin());
    ft::VectorReverseIterator<iter_type> rev_begin (myvector.end());

    std::cout << "myvector:";
    for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

void        test_reverse_iterator_operator_increase(std::string test_type)
{
    print_test_name(test_type);
    ft::vector<int> myvector;
    for (int i=9; i>=0; i--)
        myvector.push_back(i);

    typedef ft::vector<int>::iterator iter_type;
    print_element(myvector);
                                                           // ? 9 8 7 6 5 4 3 2 1 0 ?
    iter_type from (myvector.begin());                     //   ^
                                                           //         ------>
    iter_type until (myvector.end());                      //                       ^
                                                           //
    ft::VectorReverseIterator<iter_type> rev_until (from); // ^
                                                           //         <------
    ft::VectorReverseIterator<iter_type> rev_from (until); //                     ^

    std::cout << "myvector:";
    while (rev_from != rev_until) {
        std::cout << ' ' << *rev_from;
        ++rev_from;
    }
    std::cout << '\n';
}

void        test_reverse_iterator_relation(std::string test_type)
{
     print_test_name(test_type);
    ft::vector<int> myvector;
    for (int i=9; i>=0; i--)
        myvector.push_back(i);

    typedef ft::vector<int>::iterator iter_type;
    print_element(myvector);
                                                           // ? 9 8 7 6 5 4 3 2 1 0 ?
    iter_type from (myvector.begin());                     //   ^
                                                           //         ------>
    iter_type until (myvector.end());                      //                       ^
                                                           //
    ft::VectorReverseIterator<iter_type> rev_x (from + 1); // ^
    ft::VectorReverseIterator<iter_type> rev_z (from + 2); // ^
                                                           //         <------
    ft::VectorReverseIterator<iter_type> rev_y (until - 1);
 
    std::cout
        << std::boolalpha
        << "*rev_x == " << *rev_x << '\n' // 3
        << "*rev_y == " << *rev_y << '\n' // 3
        << "*rev_z == " << *rev_z << '\n' // 2
        << "rev_x == rev_y ? " << (rev_x == rev_y) << '\n' // true
        << "rev_x != rev_y ? " << (rev_x != rev_y) << '\n' // false
        << "rev_x <  rev_y ? " << (rev_x <  rev_y) << '\n' // false
        << "rev_x <= rev_y ? " << (rev_x <= rev_y) << '\n' // true
        << "rev_x == rev_z ? " << (rev_x == rev_z) << '\n' // false
        << "rev_x != rev_z ? " << (rev_x != rev_z) << '\n' // true
        << "rev_x <  rev_z ? " << (rev_x <  rev_z) << '\n' // true!
        << "rev_x <= rev_z ? " << (rev_x <= rev_z) << '\n' // true
        ;
}

void        test_reverse_iterator_operator_addition(std::string test_type)
{
    print_test_name(test_type);
    ft::vector<int> myvector;
    for (int i=0; i<10; i++) 
        myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9
    print_element(myvector);

    typedef ft::vector<int>::iterator iter_type;

    ft::VectorReverseIterator<iter_type> rev_it (myvector.begin() + 4);

    std::cout << "The fourth element from the end is: " << *rev_it << '\n';
}

void        test_rbegin(std::string test_type)
{
    print_test_name(test_type);
    ft::vector<int> myvector (5);  // 5 default-constructed ints
    print_element(myvector);

    int i=0;

    ft::vector<int>::reverse_iterator rit = myvector.rbegin();
    for (; rit!= myvector.rend(); ++rit)
        *rit = ++i;

    std::cout << "myvector contains:";
    for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

void        test_rend(std::string test_type)
{
    print_test_name(test_type);
    ft::vector<int> myvector (5);  // 5 default-constructed ints

    ft::vector<int>::reverse_iterator rit = myvector.rbegin();

    int i=0;
    for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
        *rit = ++i;

    std::cout << "myvector contains:";
    for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

void        test_swap_non_member(std::string test_type)
{
    print_test_name(test_type);
    ft::vector<int> foo (3,100);   // three ints with a value of 100
    ft::vector<int> bar (5,200);   // five ints with a value of 200

    std::cout << "foo ";
    print_element(foo);
    std::cout << "bar ";
    print_element(bar);

    std::cout << "Swap foo <-> bar\n";
    foo.swap(bar);

    std::cout << "foo contains:";
    for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "bar contains:";
    for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

void        test_get_allocator(std::string test_type)
{
    print_test_name(test_type);

    ft::vector<int> myvector;
    int * p;
    unsigned int i;

    // allocate an array with space for 5 elements using vector's allocator:
    p = myvector.get_allocator().allocate(5);

    // construct values in-place on the array:
    for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

    std::cout << "The allocated array contains:";
    for (i=0; i<5; i++) std::cout << ' ' << p[i];
    std::cout << '\n';

    // destroy and deallocate:
    for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
    myvector.get_allocator().deallocate(p,5);
}


void        test_vector(std::string test_type)
{
    print_test_name(test_type);

    test_constructor("constructor");
    // Iterator
    test_begin("begin");
    test_end("end");
    test_rbegin("rbegin");
    test_rend("rend");
    // Capacity
    test_size("size");
    test_max_size("max_size");
    test_resize("resize");
    test_capacity("capacity");
    test_empty("empty");
    test_reserve("reserve");
    // Element access
    test_operator_access("operator []");
    test_at("at");
    test_front("front");
    test_back("back");
    // Modifiers
    test_assign("assign");
    test_push_back("push_back");
    test_pop_back("pop_back");
    test_insert("insert");
    test_erase("erase");
    test_swap("swap");
    test_clear("clear");

    // Reverse Iterator
    test_reverse_iterator("reverse iterator");
    test_reverse_iterator_operator_increase("reverse iterator operator ++");
    test_reverse_iterator_relation("reverse iterator relation");
    test_reverse_iterator_operator_addition("reverse iterator operator +");
    // todo: Allocator
    test_get_allocator("get_allocator");

    // Todo: Non-member function overloads
    test_swap_non_member("swap non member functions");
    test_operator("operator");
}

int main(void)
{
    test_vector("VECTOR");
    return (0);
}