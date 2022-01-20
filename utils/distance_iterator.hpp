#ifndef DISTANCE_ITERATOR_HPP
#define DISTANCE_ITERATOR_HPP

#include "../utils/iterator.hpp"
#include "../utils/iterator_traits.hpp"
#include "../utils/bidirectional_iterator_tag.hpp"

namespace ft
{
    template<class InputIterator>
    typename ft::iterator_traits<InputIterator>::difference_type
    distance (InputIterator first, InputIterator last)
    {
        typename ft::iterator_traits<InputIterator>::difference_type distance = 0;
        while (first != last)
        {
            first++;
            distance++;
        }
        return (distance);
    }

}

#endif