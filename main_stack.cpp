#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "./stack/stack.hpp"
#include "./vector/vector.hpp"
#include "./utils/utils.hpp"

void        print_test_name(std::string name)
{
    std::cout << "\n------- TEST ";
    std::cout << name << " ------------------\n";
}

void        test_constructor(std::string test_type)
{
    print_test_name(test_type);
    ft::vector<int> myvector (2,200);        // vector with 2 elements

    ft::stack<int> first;                    // empty stack
    ft::stack<int,ft::vector<int> > third;  // empty stack using vector
    ft::stack<int,ft::vector<int> > fourth (myvector);

    std::cout << "empty of first: " << first.empty() << '\n';
    std::cout << "empty of third: " << third.empty() << '\n';
    std::cout << "empty of fourth: " << fourth.empty() << '\n';
}

void        test_size(std::string test_type)
{
    print_test_name(test_type);

    ft::stack<int> myints;
    std::cout << "0. size: " << myints.size() << '\n';

    for (int i=0; i<5; i++) myints.push(i);
    std::cout << "1. size: " << myints.size() << '\n';

    myints.pop();
    std::cout << "2. size: " << myints.size() << '\n';
}

void        test_push(std::string test_type)
{
    print_test_name(test_type);
    ft::stack<int> mystack;
    for (int i=0; i<5; ++i) mystack.push(i);

    std::cout << "Popping out elements...";
    while (!mystack.empty())
    {
        std::cout << ' ' << mystack.top();
        mystack.pop();
    }
    std::cout << '\n';
}

void        test_empty(std::string test_type)
{
    print_test_name(test_type);
    ft::stack<int> mystack;
    int sum (0);

    for (int i=1;i<=10;i++) mystack.push(i);

    while (!mystack.empty())
    {
        sum += mystack.top();
        mystack.pop();
    }

  std::cout << "total: " << sum << '\n';
}

void        test_top(std::string test_type)
{
    print_test_name(test_type);
    ft::stack<int> mystack;

    mystack.push(10);
    mystack.push(20);

    mystack.top() -= 5;

    std::cout << "mystack.top() is now " << mystack.top() << '\n';
}

void        test_pop(std::string test_type)
{
    print_test_name(test_type);

 std::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';
}

void        test_operator(std::string test_type)
{
    print_test_name(test_type);
    ft::vector<int> foo_v (3,100);   // three ints with a value of 100
    ft::vector<int> bar_v (2,200);   // two ints with a value of 200
    ft::stack<int, ft::vector<int> > foo (foo_v);
    ft::stack<int, ft::vector<int> > bar (bar_v);


    if (foo == bar) std::cout << "foo and bar are equal\n";
    if (foo != bar) std::cout << "foo and bar are not equal\n";
    if (foo < bar) std::cout << "foo is less than bar\n";
    if (bar > foo) std::cout << "bar is greater than foo\n";
    if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
    if (bar >= foo) std::cout << "bar is greater than or equal to foo\n";

    ft::vector<int> foo2_v (3,100);   // three ints with a value of 100
    ft::stack<int, ft::vector<int> > foo2 (foo2_v);
    if (foo == foo2) std::cout << "foo and foo2 are equal\n";
}

void        test_stack(std::string test_type)
{
    print_test_name(test_type);

    test_constructor("constructor");
    test_empty("empty");
    test_size("size");
    test_top("top");
    test_push("push");
    test_pop("pop");
    test_operator("operator");
}

int main(void)
{
    test_stack("STACK");
    return (0);
}