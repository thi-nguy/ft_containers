#ifndef PAIR_HPP
#define PAIR_HPP

#include <memory>       // std::allocator
// #include <utility>      // std::pair
#include <cstddef>      // ptrdiff_t
#include <functional>   //std::less
#include "red_black_tree.hpp"

namespace ft
{
    template <class T1, class T2>
    struct pair
    {
        public:
            typedef T1  first_type;
            typedef T2  second_type;

            first_type      first;
            second_type     second;

            // Constructor
            pair()
            :
                first(T1()),
                second(T2())
            {}

            template<typename U, typename V>
            pair(pair< U, V>const &pr)
            :
                first(pr.first),
                second(pr.second)
            {}
            // pair(const pair& pr)
            // {
            //     *this = pr;
            // }

            pair(first_type const & a, second_type const & b)
            :   first(a),
                second(b)
            {}

            pair &operator=(pair const & rhs)
            {
                if (this != &rhs)
                {
                    this->first = rhs.first;
                    this->second = rhs.second;
                }
                return (*this);
            }

    }; /* struct pair */

    template <typename T1, typename T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return lhs.first == rhs.first && lhs.second==rhs.second; 
    }

    template <typename T1, typename T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return !(lhs==rhs); 
    }

    template <typename T1, typename T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); 
    }

    template <typename T1, typename T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return !(rhs<lhs); 
    }

    template <typename T1, typename T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return rhs<lhs; 
    }

    template <typename T1, typename T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return !(lhs<rhs); 
    }    /* relational operators (pair) */

    // template <class T1, class T2>
    // std::ostream    &operator<<(std::ostream &COUT, const pair<T1, T2> &a_pair)
    // {
    //     COUT << a_pair.second;
    //     return (COUT);
    // }

    template <typename T1, typename T2>
    ft::pair<T1, T2> make_pair(T1 x, T2 y)
    {
        return (ft::pair<T1, T2>(x, y));
    }   /* ft::make_pair */
};

#endif /* namespace ft */
    