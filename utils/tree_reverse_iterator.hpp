#ifndef TREE_REVERSE_ITERATOR_HPP
#define TREE_REVERSE_ITERATOR_HPP

#include "../utils/utils.hpp"

namespace ft
{
template <class Iter>
class treeReverseIterator
{
    public:

            typedef Iter                                                       iterator_type;
            typedef typename ft::iterator_traits<Iter>::iterator_category      iterator_category;
            typedef typename ft::iterator_traits<Iter>::value_type             value_type;
            typedef typename ft::iterator_traits<Iter>::difference_type        difference_type;
            typedef typename ft::iterator_traits<Iter>::pointer                pointer;
            typedef typename ft::iterator_traits<Iter>::reference              reference;


            // todo: Construction
            treeReverseIterator(void)
            :
                _ptr()
            {}

            explicit treeReverseIterator(iterator_type it)
            :
                _ptr(it)
            {}

            template <class Iterator>
            treeReverseIterator (const treeReverseIterator<Iterator>& rev_it)
            :
                _ptr(rev_it.base())
            {}

            // todo: destructor
            virtual ~treeReverseIterator(void) {}

            // treeReverseIterator(pointer ptr): _ptr(ptr) {} // todo: X(ptr) - typecast?
            // treeReverseIterator(vectorIterator<value_type> const &src) 
            // { 
            //     _ptr = src.operator->(); 
            // } 

            treeReverseIterator(const treeReverseIterator&    other) // todo: X b(a)
            {
                *this = other;
            }
            treeReverseIterator&     operator=(const treeReverseIterator& rhs) // todo: b = a
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
            treeReverseIterator operator+(difference_type n) const
            {
                return (treeReverseIterator(_ptr - n));
            }

            // ! operator ++
            treeReverseIterator& operator ++(void) // todo: ++a
            {
                --_ptr;
                return (*this);
            }

            treeReverseIterator operator ++(int) // todo: a++
            {
                treeReverseIterator tmp = *this;
                ++(*this);
                return (tmp);
            }
            // ! operator +=
            treeReverseIterator& operator+=(difference_type n)
            {
                _ptr -= n;
                return (*this);
            }
            // ! operator -
            treeReverseIterator operator-(difference_type n) const
            {
                return (treeReverseIterator(_ptr + n));
            }
            // ! operator --
            treeReverseIterator operator --(void) // todo: --a
            {
                ++_ptr;
                return (*this);
            }

            treeReverseIterator operator --(int) // todo: a--
            {
                treeReverseIterator tmp = *this;
                --(*this);
                return (tmp);
            }
            // ! operator -=
            treeReverseIterator& operator-=(difference_type n)
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

}; /* class treeReverseIterator */

// ! Relational operators
template <class Iterator1, class Iterator2>
bool operator==( const ft::treeReverseIterator<Iterator1>& lhs, const ft::treeReverseIterator<Iterator2>& rhs) 
{
    return (lhs.base() == rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator!=( const ft::treeReverseIterator<Iterator1>& lhs, const ft::treeReverseIterator<Iterator2>& rhs) 
{
    return (lhs.base() != rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator>( const ft::treeReverseIterator<Iterator1>& lhs, const ft::treeReverseIterator<Iterator2>& rhs) 
{
    return (lhs.base() < rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator>=( const ft::treeReverseIterator<Iterator1>& lhs, const ft::treeReverseIterator<Iterator2>& rhs) 
{
    return (lhs.base() <= rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator<( const ft::treeReverseIterator<Iterator1>& lhs, const ft::treeReverseIterator<Iterator2>& rhs) 
{
    return (lhs.base() > rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator<=( const ft::treeReverseIterator<Iterator1>& lhs, const ft::treeReverseIterator<Iterator2>& rhs) 
{
    return (lhs.base() >= rhs.base());
}

// ! operator +
template <class Iterator>
treeReverseIterator<Iterator>
operator + (typename treeReverseIterator<Iterator>::difference_type n, const treeReverseIterator<Iterator>& it)
{
    return (it + n);
}

// ! operator -
template <class Iterator>
typename treeReverseIterator<Iterator>::difference_type
operator - (const treeReverseIterator<Iterator>& lhs, const treeReverseIterator<Iterator>& rhs)
{
    return (lhs.base() - rhs.base());
}

} /* namespace ft */

#endif