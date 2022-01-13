#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include "random_access_iterator_tag.hpp"

namespace ft
{
    template <class Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::difference_type      difference_type;
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
        typedef typename Iterator::iterator_category    iterator_category;
    }; /* struct iterator_traits */

    template <class T>
    struct iterator_traits<T*>
    {
        typedef std::ptrdiff_t                          difference_type;
        typedef T                                       value_type;
        typedef T*                                      pointer;
        typedef T&                                      reference;
        typedef ft::random_access_iterator_tag          iterator_category;
    };

    template <class T>
    class iterator_traits<const T*>
    {
        public:
            typedef std::ptrdiff_t                          difference_type;
            typedef T                                       value_type;
            typedef const T*                                pointer;
            typedef const T&                                reference;
            typedef ft::random_access_iterator_tag          iterator_category;
    };

} /* namespace ft */

#endif /* iterator_traits.hpp */