#ifndef VECTOR_REVERSE_ITERATOR_HPP
#define VECTOR_REVERSE_ITERATOR_HPP

#include "vector_iterator.hpp"

namespace ft
{

template <class Iter>
class VectorReverseIterator
{
    public:

            typedef Iter                                                        iterator_type;
            typedef typename std::iterator_traits<Iter>::iterator_category      iterator_category;
            typedef typename std::iterator_traits<Iter>::value_type             value_type;
            typedef typename std::iterator_traits<Iter>::difference_type        difference_type;
            typedef typename std::iterator_traits<Iter>::pointer                pointer;
            typedef typename std::iterator_traits<Iter>::reference              reference;


            VectorReverseIterator(void) {} // todo: X a;
            VectorReverseIterator(pointer ptr): _ptr(ptr) {} // todo: X(ptr) - typecast?
            VectorReverseIterator(vectorIterator<value_type> const &src) 
            { 
                _ptr = src.operator->(); 
            } 

            VectorReverseIterator(const VectorReverseIterator&    other) // todo: X b(a)
            {
                *this = other;
            }
            VectorReverseIterator&     operator=(const VectorReverseIterator& rhs) // todo: b = a
            {
                if (this != &rhs)
                {
                    _ptr = rhs._ptr;
                }
                return (*this);
            }

            ~VectorReverseIterator(void) {} // todo: destructor


            // ! Base
            iterator_type   base(void) const
            {
                return (this->_ptr);
            }

            // ! operator *
            reference operator *(void) // todo: *a
            {
                return (*_ptr);
            }
            // ! operator +

            // ! operator ++
            VectorReverseIterator& operator ++(void) // todo: ++a
            {
                _ptr--;
                return (*this);
            }

            VectorReverseIterator operator ++(int) // todo: a++
            {
                _ptr--;
                return (VectorReverseIterator(_ptr + 1));
            }
            // ! operator +=
            // ! operator -
            // ! operator --
            VectorReverseIterator operator --(void) // todo: --a
            {
                _ptr++;
                return (*this);
            }

            VectorReverseIterator operator --(int) // todo: a--
            {
                _ptr++;
                return (VectorReverseIterator(_ptr - 1));
            }
            // ! operator -=
            // ! operator ->
            // ! operator []


    private:
        pointer _ptr;

}; /* class VectorReverseIterator */

// ! Relational operators
template <class Iterator1, class Iterator2>
bool operator==( const ft::VectorReverseIterator<Iterator1>& lhs, const ft::VectorReverseIterator<Iterator2>& rhs) 
{
    return (lhs.base() == rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator!=( const ft::VectorReverseIterator<Iterator1>& lhs, const ft::VectorReverseIterator<Iterator2>& rhs) 
{
    return (lhs.base() != rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator>( const ft::VectorReverseIterator<Iterator1>& lhs, const ft::VectorReverseIterator<Iterator2>& rhs) 
{
    return (lhs.base() > rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator>=( const ft::VectorReverseIterator<Iterator1>& lhs, const ft::VectorReverseIterator<Iterator2>& rhs) 
{
    return (lhs.base() >= rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator<( const ft::VectorReverseIterator<Iterator1>& lhs, const ft::VectorReverseIterator<Iterator2>& rhs) 
{
    return (lhs.base() < rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator<=( const ft::VectorReverseIterator<Iterator1>& lhs, const ft::VectorReverseIterator<Iterator2>& rhs) 
{
    return (lhs.base() <= rhs.base());
}

// ! operator +


// ! operator -



} /* namespace ft */


#endif