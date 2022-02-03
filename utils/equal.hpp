#ifndef EQUAL_HPP
#define EQUAL_HPP

namespace ft
{
    template <
        class InputIterator1, 
        class InputIterator2
    >
    bool    equal(
                    InputIterator1 first1, 
                    InputIterator1 last1,
                    InputIterator2 first2
                    )
    {
        while (first1 != last1)
        {
            if (first1 == last1 || *first2 != *first1)
                return false;
            ++first1;
            ++first2;
        }
        return (true);
    }

    // template <class T>
    // bool equal(T& a, T& b)
    // {
    //     return (a == b);
    // }
}

#endif /* equal.hpp */