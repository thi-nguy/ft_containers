#ifndef VECTOR_CONST_ITERATOR_HPP
#define VECTOR_CONST_ITERATOR_HPP

#include "vector_iterator.hpp"

namespace ft
{

template <typename T>
class vectorConstIterator: public std::iterator<std::random_access_iterator_tag, T>
{
    public:
        typedef const T                     value_type;
        typedef T&                          reference;
        typedef const T&                    const_reference;
        typedef T*                          pointer;
        typedef const T*                    const_pointer;
        typedef typename std::ptrdiff_t     difference_type;

        vectorConstIterator(void) {} // todo: X a;
        vectorConstIterator(pointer ptr): _ptr(ptr) {} // todo: X(ptr) - typecast
        vectorConstIterator(const vectorConstIterator&    other) // todo: X b(a)
        {
            *this = other;
        }
        vectorConstIterator&     operator=(const vectorConstIterator& rhs) // todo: b = a
        {
            if (this != &rhs)
            {
                _ptr = rhs._ptr;
            }
            return (*this);
        }
        ~vectorConstIterator(void) {} // todo: destructor

        // ! Operator Overload
        bool operator !=(vectorConstIterator const& rhs) const // todo: a != b
        {
            return (_ptr != rhs._ptr);
        }

        bool operator ==(vectorConstIterator const& rhs) const // todo: a == b
        {
            return (_ptr == rhs._ptr);
        }

        reference operator *(void) // todo: *a
        {
            return (*_ptr);
        }

        const_reference operator *(void) const // todo: *a
        {
            return (*_ptr);
        }

        pointer operator ->(void) // todo: a->m
        {
            return (_ptr);
        }

        pointer operator ->(void) const // todo: a->m
        {
            return (_ptr);
        }

        //todo: *a = t

        vectorConstIterator& operator ++(void) // todo: ++a
        {
            _ptr++;
            return (*this);
        }

        vectorConstIterator operator ++(int) // todo: a++
        {
            _ptr++;
            return (vectorConstIterator(_ptr - 1));
        }

        //todo: *a++


        vectorConstIterator operator --(void) // todo: --a
        {
            _ptr--;
            return (*this);
        }

        vectorConstIterator operator --(int) // todo: a--
        {
            _ptr--;
            return (vectorConstIterator(_ptr + 1));
        }

        //todo: *a--

        vectorConstIterator operator +(difference_type n) const // todo: a+n
        {
            return (vectorConstIterator(_ptr + n));
        }

        //todo: n+a
        

        vectorConstIterator operator -(difference_type n) const // todo: a - n
        {
            return (vectorConstIterator(_ptr - n));
        }

        bool operator >(vectorConstIterator const& b) const // todo: a > b
        {
            return (_ptr > b._ptr);
        }
        bool operator <(vectorConstIterator const& b) const // todo: a < b
        {
            return (_ptr < b._ptr);
        }
        bool operator >=(vectorConstIterator const& b) const // todo: a >= b
        {
            return (_ptr >= b._ptr);
        }
        bool operator <=(vectorConstIterator const& b) const // todo: a <= b
        {
            return (_ptr <= b._ptr);
        }

        void    operator +=(difference_type n) // todo: a += n
        {
            _ptr += n;
        }

        void    operator -=(difference_type n) // todo: a -= n
        {
            _ptr -= n;
        }

        reference   operator [](difference_type n) // todo: a[n]
        {
            return (*(_ptr + n));
        }

        const_reference operator [](difference_type n) const // todo: a[n]
        {
            return (*(_ptr + n));
        }

        pointer     getPointer(void) const
        {
            return (_ptr);
        }

    private:
        pointer     _ptr;
}; /* class vectorConstIterator */

template <typename T>
typename ft::vectorConstIterator<T>::difference_type
operator - (const ft::vectorConstIterator<T> a, const ft::vectorConstIterator<T> b) // todo: a - b
{
    return (a.getPointer() - b.getPointer());
}

} /* namespace ft */

#endif