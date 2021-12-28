#ifndef VECTOR_CONST_REVERSE_ITERATOR_HPP
#define VECTOR_CONST_REVERSE_ITERATOR_HPP

#include <iterator>

namespace ft
{
template <class Iter>
class VectorConstReverseIterator: public std::iterator_traits<Iter>
{
    public:

            typedef Iter                                                        iterator_type;
            typedef typename std::iterator_traits<Iter>::iterator_category      iterator_category;
            typedef typename std::iterator_traits<Iter>::value_type             value_type;
            typedef typename std::iterator_traits<Iter>::difference_type        difference_type;
            typedef typename std::iterator_traits<Iter>::pointer                pointer;
            typedef typename std::iterator_traits<Iter>::reference              reference;
            typedef typename std::iterator_traits<Iter>::const_reference        const_reference;


            // todo: Construction
            VectorConstReverseIterator(void) {} // todo: X a;
            VectorConstReverseIterator(pointer ptr): _ptr(ptr) {} // todo: X(ptr) - typecast?
            VectorConstReverseIterator(vectorIterator<value_type> const &src) 
            { 
                _ptr = src.operator->(); 
            } 

            VectorConstReverseIterator(const VectorConstReverseIterator&    other) // todo: X b(a)
            {
                *this = other;
            }
            VectorConstReverseIterator&     operator=(const VectorConstReverseIterator& rhs) // todo: b = a
            {
                if (this != &rhs)
                {
                    _ptr = rhs._ptr;
                }
                return (*this);
            }

            virtual ~VectorConstReverseIterator(void) {} // todo: destructor

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
            VectorConstReverseIterator operator+(difference_type n) const
            {
                return (VectorConstReverseIterator(_ptr + n));
            }

            // ! operator ++
            VectorConstReverseIterator& operator ++(void) // todo: ++a
            {
                _ptr--;
                return (*this);
            }

            VectorConstReverseIterator operator ++(int) // todo: a++
            {
                _ptr--;
                return (VectorConstReverseIterator(_ptr + 1));
            }
            // ! operator +=
            VectorConstReverseIterator& operator+=(difference_type n)
            {
                _ptr += n;
                return (*this);
            }
            // ! operator -
            VectorConstReverseIterator operator-(difference_type n) const
            {
                return (VectorConstReverseIterator(_ptr - n));
            }
            // ! operator --
            VectorConstReverseIterator operator --(void) // todo: --a
            {
                _ptr++;
                return (*this);
            }

            VectorConstReverseIterator operator --(int) // todo: a--
            {
                _ptr++;
                return (VectorConstReverseIterator(_ptr - 1));
            }
            // ! operator -=
            VectorConstReverseIterator& operator-=(difference_type n)
            {
                _ptr -= n;
                return (*this);
            }
            // ! operator ->
            pointer operator ->(void)
            {
                return (_ptr);
            }

            pointer operator ->(void) const
            {
                return (_ptr);
            }
            // ! operator []
            reference operator [] (difference_type b)
            {
                return (*(_ptr + b));
            }

            const_reference operator [] (difference_type b) const
            {
                return (*(_ptr + b));
            }


    private:
        pointer _ptr;

}; /* class VectorConstReverseIterator */

// ! Relational operators
template <class Iterator1, class Iterator2>
bool operator==( const ft::VectorConstReverseIterator<Iterator1>& lhs, const ft::VectorConstReverseIterator<Iterator2>& rhs) 
{
    return (lhs.base() == rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator!=( const ft::VectorConstReverseIterator<Iterator1>& lhs, const ft::VectorConstReverseIterator<Iterator2>& rhs) 
{
    return (lhs.base() != rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator>( const ft::VectorConstReverseIterator<Iterator1>& lhs, const ft::VectorConstReverseIterator<Iterator2>& rhs) 
{
    return (lhs.base() > rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator>=( const ft::VectorConstReverseIterator<Iterator1>& lhs, const ft::VectorConstReverseIterator<Iterator2>& rhs) 
{
    return (lhs.base() >= rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator<( const ft::VectorConstReverseIterator<Iterator1>& lhs, const ft::VectorConstReverseIterator<Iterator2>& rhs) 
{
    return (lhs.base() < rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator<=( const ft::VectorConstReverseIterator<Iterator1>& lhs, const ft::VectorConstReverseIterator<Iterator2>& rhs) 
{
    return (lhs.base() <= rhs.base());
}

// ! operator +
template <class Iter>
VectorConstReverseIterator<Iter>
operator + (typename ft::VectorConstReverseIterator<Iter>::difference_type n, const ft::VectorConstReverseIterator<Iter>& it)
{
    return (ft::VectorConstReverseIterator<Iter>(it.base() - n));
}

// ! operator -
template <class Iterator>
typename ft::VectorConstReverseIterator<Iterator>::difference_type
operator - (const ft::VectorConstReverseIterator<Iterator>& lhs, const ft::VectorConstReverseIterator<Iterator>& rhs)
{
    return (rhs.base() - lhs.base());
}

} /* namespace ft */

#endif