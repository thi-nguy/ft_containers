#include <iostream>     // std::cout
#include <iterator>     // std::iterator_traits
#include <typeinfo>     // typeid

template <typename T>
class myIterator: public iterator
{
    public:
        typedef T                           value_type;
        typedef T&                          reference;
        typedef const T&                    const_reference;
        typedef T*                          pointer;
        typedef const T*                    const_pointer;
        typedef typename std::ptrdiff_t     difference_type;
};


int main() 
{
    if (typeid(std::iterator_traits<myIterator>::iterator_category)==typeid(std::random_access_iterator_tag))
            std::cout << "int* is a random-access iterator\n";
    return 0;
}
