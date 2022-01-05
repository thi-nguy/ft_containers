#ifndef MAP_HPP
#define MAP_HPP

#include <memory>       // std::allocator
// #include <utility>      // ft::pair
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

            // Constructor
            pair()
            {}

            template<class U, class V>
            pair(const ft::pair<U, V>& pr)
            {
                *this = pr;
            }

            pair(const first_type& a, const second_type& b)
            :   first(a),
                second(b)
            {}

            pair&   operator=(const pair& rhs)
            {
                if (this != &rhs)
                {
                    this->first = rhs.first;
                    this->second = rhs.second;
                }
                return (*this);
            }

            ~pair()
            {}

            first_type      first;
            second_type     second;
    }; /* struct pair */

    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return lhs.first == rhs.first && lhs.second==rhs.second; 
    }

    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return !(lhs==rhs); 
    }

    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); 
    }

    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return !(rhs<lhs); 
    }

    template <class T1, class T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return rhs<lhs; 
    }

    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return !(lhs<rhs); 
    }
    /* relational operators (pair) */


    template <class T1, class T2>
    ft::pair<T1, T2> make_pair(T1 x, T2 y)
    {
        return (ft::pair<T1, T2>(x, y));
    }
    
    template <  class Key, 
                class T, 
                class Compare = std::less<Key>,
                class Alloc = std::allocator<ft::pair<const Key, T> > 
            >
    class map
    {
        public:
            typedef Key                                         key_type;
            typedef T                                           mapped_type;
            typedef ft::pair<const key_type, mapped_type>      value_type;
            typedef Compare                                     key_compare;
            // Todo: value_compare
            typedef Alloc                                       allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            // Todo: iterator
            typedef typename std::ptrdiff_t                     difference_type;
            typedef typename allocator_type::size_type          size_type;

            // Todo: Constructor
            



        private:
            allocator_type                              _alloc;
            key_compare                                 _compare;
            ft::RedBlackTree<value_type, key_compare>       _rbt;

    }; /* class map */




} /* namespace ft */

#endif /* map.hpp */