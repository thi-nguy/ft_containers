#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>      // ptrdiff_t

namespace ft
{
    template <
        class Category, 
        class T, 
        class Distance = std::ptrdiff_t, 
        class Pointer = T*, 
        class Reference = T&
    >
    class iterator
    {
        public:
            typedef Category    iterator_category;
            typedef T           value_type;
            typedef Distance    difference_type;
            typedef Pointer     pointer;
            typedef const Pointer     const_pointer;
            typedef Reference   reference;
            typedef const Reference   const_reference;
    };

} /* namespace ft */

#endif /* iterator.hpp */

