#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "../utils/iterator.hpp"
#include "../utils/iterator_traits.hpp"
#include "../utils/random_access_iterator_tag.hpp"

namespace ft
{

template <typename T>
class vectorIterator: public ft::iterator<ft::random_access_iterator_tag, T>
{
    public:
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category     iterator_category;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type            value_type;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type       difference_type;
        typedef T*               pointer;
        typedef T&             reference;

        // ! Canonical form of of vectorIterator
        vectorIterator(void) {} // todo: X a;
        vectorIterator(pointer ptr): _ptr(ptr) {} // todo: X(ptr) - typecast
        vectorIterator(const vectorIterator&    other) // todo: X b(a)
        {
            *this = other;
        }
        vectorIterator&     operator=(const vectorIterator& rhs) // todo: b = a
        {
            if (this != &rhs)
            {
                _ptr = rhs._ptr;
            }
            return (*this);
        }
        
        virtual ~vectorIterator(void) {} // todo: destructor

        // ! Operator Overload
        bool operator !=(vectorIterator const& rhs) const // todo: a != b
        {
            return (_ptr != rhs._ptr);
        }

        bool operator ==(vectorIterator const& rhs) const // todo: a == b
        {
            return (_ptr == rhs._ptr);
        }

        reference operator *(void) // todo: *a
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

        vectorIterator& operator ++(void) // todo: ++a
        {
            _ptr++;
            return (*this);
        }

        vectorIterator operator ++(int) // todo: a++
        {
            _ptr++;
            return (vectorIterator(_ptr - 1));
        }

        vectorIterator operator --(void) // todo: --a
        {
            _ptr--;
            return (*this);
        }

        vectorIterator operator --(int) // todo: a--
        {
            _ptr--;
            return (vectorIterator(_ptr + 1));
        }

        vectorIterator operator +(difference_type n) const // todo: a+n
        {
            return (vectorIterator(_ptr + n));
        }

        vectorIterator operator -(difference_type n) const // todo: a - n
        {
            return (vectorIterator(_ptr - n));
        }

        bool operator >(vectorIterator const& b) const // todo: a > b
        {
            return (_ptr > b._ptr);
        }
        bool operator <(vectorIterator const& b) const // todo: a < b
        {
            return (_ptr < b._ptr);
        }
        bool operator >=(vectorIterator const& b) const // todo: a >= b
        {
            return (_ptr >= b._ptr);
        }
        bool operator <=(vectorIterator const& b) const // todo: a <= b
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

        reference   operator [](difference_type n) const // todo: a[n]
        {
            return (*(_ptr + n));
        }

        pointer     getPointer(void) const
        {
            return (_ptr);
        }

    private:
        pointer     _ptr;
}; /* class vectorIterator */

template <typename T>
typename ft::vectorIterator<T>::difference_type
operator - (const ft::vectorIterator<T> a, const ft::vectorIterator<T> b) // todo: a - b
{
    return (a.getPointer() - b.getPointer());
}
    
} /* namespace ft */

#endif /* vector_iterator.hpp */