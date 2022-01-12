#ifndef MAP_HPP
#define MAP_HPP

#include <memory>       // std::allocator
// #include <utility>      // ft::pair
#include <cstddef>      // ptrdiff_t
#include <functional>   //std::less
#include "red_black_tree.hpp"
#include "pair.hpp"

namespace ft
{
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

}; /* namespace ft */

#endif /* map.hpp */