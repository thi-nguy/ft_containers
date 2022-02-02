#ifndef VECTOR_REVERSE_ITERATOR_HPP
#define VECTOR_REVERSE_ITERATOR_HPP

#include "../utils/utils.hpp"

namespace ft
{
template <class Iter>
class VectorReverseIterator
{
    public:

            typedef Iter                                                       iterator_type;
            typedef typename ft::iterator_traits<Iter>::iterator_category      iterator_category;
            typedef typename ft::iterator_traits<Iter>::value_type             value_type;
            typedef typename ft::iterator_traits<Iter>::difference_type        difference_type;
            typedef typename ft::iterator_traits<Iter>::pointer                pointer;
            typedef typename ft::iterator_traits<Iter>::reference              reference;


            // todo: Construction
            VectorReverseIterator(void)
            :
                _ptr()
            {}

            explicit VectorReverseIterator(iterator_type it)
            :
                _ptr(it)
            {}

            template <class Iterator>
            VectorReverseIterator (const VectorReverseIterator<Iterator>& rev_it)
            :
                _ptr(rev_it.base())
            {}

            // todo: destructor
            virtual ~VectorReverseIterator(void) {}

            // VectorReverseIterator(pointer ptr): _ptr(ptr) {} // todo: X(ptr) - typecast?
            // VectorReverseIterator(vectorIterator<value_type> const &src) 
            // { 
            //     _ptr = src.operator->(); 
            // } 

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

            // ! Base
            iterator_type   base(void) const
            {
                return (_ptr);
            }

            // ! operator *
            reference operator *(void) // todo: *a
            {
                
                return (*_ptr);
            }
            // ! operator +
            VectorReverseIterator operator+(difference_type n) const
            {
                return (VectorReverseIterator(_ptr - n));
            }

            // ! operator ++
            VectorReverseIterator& operator ++(void) // todo: ++a
            {
                --_ptr;
                return (*this);
            }

            VectorReverseIterator operator ++(int) // todo: a++
            {
                VectorReverseIterator tmp = *this;
                ++(*this);
                return (tmp);
            }
            // ! operator +=
            VectorReverseIterator& operator+=(difference_type n)
            {
                _ptr -= n;
                return (*this);
            }
            // ! operator -
            VectorReverseIterator operator-(difference_type n) const
            {
                return (VectorReverseIterator(_ptr + n));
            }
            // ! operator --
            VectorReverseIterator operator --(void) // todo: --a
            {
                ++_ptr;
                return (*this);
            }

            VectorReverseIterator operator --(int) // todo: a--
            {
                VectorReverseIterator tmp = *this;
                --(*this);
                return (tmp);
            }
            // ! operator -=
            VectorReverseIterator& operator-=(difference_type n)
            {
                _ptr += n;
                return (*this);
            }
            // ! operator ->
            pointer operator ->(void)
            {
                return (&(operator*()));
            }

            pointer operator ->(void) const
            {
                return (&(operator*()));
            }
            // ! operator []
            reference operator [] (difference_type b) const
            {
                return (this->base()[-b - 1]);
            }

    private:
        iterator_type _ptr;

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
    return (lhs.base() < rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator>=( const ft::VectorReverseIterator<Iterator1>& lhs, const ft::VectorReverseIterator<Iterator2>& rhs) 
{
    return (lhs.base() <= rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator<( const ft::VectorReverseIterator<Iterator1>& lhs, const ft::VectorReverseIterator<Iterator2>& rhs) 
{
    return (lhs.base() > rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator<=( const ft::VectorReverseIterator<Iterator1>& lhs, const ft::VectorReverseIterator<Iterator2>& rhs) 
{
    return (lhs.base() >= rhs.base());
}

// ! operator +
template <class Iterator>
VectorReverseIterator<Iterator>
operator + (typename VectorReverseIterator<Iterator>::difference_type n, const VectorReverseIterator<Iterator>& it)
{
    return (it + n);
}

// ! operator -
template <class Iterator>
typename VectorReverseIterator<Iterator>::difference_type
operator - (const VectorReverseIterator<Iterator>& lhs, const VectorReverseIterator<Iterator>& rhs)
{
    return (lhs.base() - rhs.base());
}

} /* namespace ft */

#endif