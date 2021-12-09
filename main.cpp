#include <vector>
#include <iostream>
#include <string>

#include "./vector/vector.hpp"

int main(void)
{
    {
        ft::vector<int> first;
        ft::vector<std::string> second(4, "hello");
        ft::vector<std::string> third(second.begin(), second.end());

        ft::vector<std::string> fourth(third);

        std::cout << "size 1: " << first.size() << std::endl;
        std::cout << "size 2: " << second.size() << std::endl;
        std::cout << "size 3: " << third.size() << std::endl;
        std::cout << "size 4: " << fourth.size() << std::endl;

        std::cout << "Test Capacity\n";
        std::cout << "capacity 1: " << first.capacity() << std::endl;
        std::cout << "capacity 2: " << second.capacity() << std::endl;
        std::cout << "capacity 3: " << third.capacity() << std::endl;
        std::cout << "capacity 4: " << fourth.capacity() << std::endl;

        std::cout << "Test empty\n";
        std::cout << "empty 1: " << first.empty() << std::endl;
        std::cout << "empty 2: " << second.empty() << std::endl;
        std::cout << "empty 3: " << third.empty() << std::endl;
        std::cout << "empty 4: " << fourth.empty() << std::endl;

        std::vector<int> real_vector;
        std::vector<int>::iterator it;

    }
    {
        ft::vector<int> myvector (10);   // 10 zero-initialized elements

        ft::vector<int>::size_type sz = myvector.size();

        // assign some values:
        for (unsigned i=0; i<sz; i++) myvector[i]=i;

        // reverse vector using operator[]:
        for (unsigned i=0; i<sz/2; i++)
        {
            int temp;
            temp = myvector[sz-1-i];
            myvector[sz-1-i]=myvector[i];
            myvector[i]=temp;
        }

        std::cout << "myvector contains:";
        for (unsigned i=0; i<sz; i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }
    {
        ft::vector<int> myvector(10);
        try 
        {
            myvector.at(20)=100;      // vector::at throws an out-of-range
        }
        catch (const std::out_of_range& oor) 
        {
            std::cerr << oor.what() << '\n';
        }
    }
    return(0);
}