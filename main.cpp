#include <vector>
#include <iostream>
#include <string>

#include "./vector/vector.hpp"

void        print_test_name(std::string name)
{
    std::cout << "------- TEST ";
    std::cout << name << " ------------------\n";
}

void        test_constructor(std::string test_type)
{
    print_test_name(test_type);
    {
        ft::vector<int> first;
        ft::vector<std::string> second(4, "hello");
        ft::vector<std::string> third(second.begin(), second.end());
        ft::vector<std::string> fourth(third);
    }
}

void      test_begin(std::string test_type)
{
    print_test_name(test_type);
    ft::vector<int> first;
    ft::vector<std::string> second(4, "hello");
    ft::vector<std::string> third(second.begin(), second.end());
    ft::vector<std::string> fourth(third);
}

void         test_size(std::string test_type)
{
    print_test_name(test_type);
    ft::vector<int> first;
    ft::vector<std::string> second(4, "hello");
    ft::vector<std::string> third(second.begin(), second.end());
    ft::vector<std::string> fourth(third);
    std::cout << "size 1: " << first.size() << std::endl;
    std::cout << "size 2: " << second.size() << std::endl;
    std::cout << "size 3: " << third.size() << std::endl;
    std::cout << "size 4: " << fourth.size() << std::endl;
}

void        test_capacity(std::string test_type)
{
    print_test_name(test_type);
    ft::vector<int> first;
    ft::vector<std::string> second(4, "hello");
    ft::vector<std::string> third(second.begin(), second.end());
    ft::vector<std::string> fourth(third);

    third.reserve(10);

    std::cout << "Test Capacity\n";
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
    ft::vector<int> foo (3,100);   // three ints with a value of 100
    ft::vector<int> bar (2,200);   // two ints with a value of 200

    if (foo==bar) std::cout << "foo and bar are equal\n";
    if (foo!=bar) std::cout << "foo and bar are not equal\n";
    if (foo< bar) std::cout << "foo is less than bar\n";
    if (foo> bar) std::cout << "foo is greater than bar\n";
    if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
    if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}
void        test_vector(std::string test_type)
{
    print_test_name(test_type);
    test_constructor("constructor");
    test_begin("begin");
    test_capacity("capacity");
    test_empty("empty");
    test_size("size");
    test_operator("operator");
}


int main(void)
{
    test_vector("VECTOR");
    return (0);
}