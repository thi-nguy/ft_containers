#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "../utils/iterator.hpp"
#include "../utils/iterator_traits.hpp"
#include "../utils/bidirectional_iterator_tag.hpp"

namespace ft
{
    template <typename T, class Compare>
    class mapIterator: public ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        public:        
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category     iterator_category;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type            value_type;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type       difference_type;
            typedef T*               pointer;
            typedef T&             reference;

// X a;
// X b(a);
// b = a;
// a == b
// a != b
// *a
// a->m
// *a = t
// ++a
// a++
// *a++
// --a
// a--
// *a--
        private:
            pointer     _ptr;

    };

} /* namespace ft */


#endif /* map_iterator.hpp */