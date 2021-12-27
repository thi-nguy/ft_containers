#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include <iterator>

namespace ft
{

template <class Iterator>
class iterator_traits
{
    public:
        typedef typename Iterator::difference_type      difference_type;
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
        typedef typename Iterator::iterator_category    iterator_category;
}; /* class iterator_traits */

template <class T>
class iterator_traits<T*>
{
    public:
        typedef std::ptrdiff_t                          difference_type;
        typedef T                                       value_type;
        typedef T*                                      pointer;
        typedef T&                                      reference;
        typedef std::random_access_iterator_tag         iterator_category;
};

template <class T>
class iterator_traits<const T*>
{
    public:
        typedef std::ptrdiff_t                          difference_type;
        typedef T                                       value_type;
        typedef const T*                                pointer;
        typedef const T&                                reference;
        typedef std::random_access_iterator_tag         iterator_category;
};

template <typename T>
class vectorIterator: public std::iterator<std::random_access_iterator_tag, T>
{
    public:
        typedef T                           value_type;
        typedef T&                          reference;
        typedef const T&                    const_reference;
        typedef T*                          pointer;
        typedef const T*                    const_pointer;
        typedef typename std::ptrdiff_t     difference_type;

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
        ~vectorIterator(void) {} // todo: destructor

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

        //todo: *a++


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

        //todo: *a--

        vectorIterator operator +(difference_type n) const // todo: a+n
        {
            return (vectorIterator(_ptr + n));
        }

        //todo: n+a
        

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
}; /* class vectorIterator */

template <typename T>
typename ft::vectorIterator<T>::difference_type
operator - (const ft::vectorIterator<T> a, const ft::vectorIterator<T> b) // todo: a - b
{
    return (a.getPointer() - b.getPointer());
}
    
} /* namespace ft */

#endif /* vector_iterator.hpp */