#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator.hpp"
#include "iterator_traits.hpp"

namespace ft
{
template <class Iter>
class reverse_iterator
{
    public:

            typedef Iter                                                       iterator_type;
            typedef typename ft::iterator_traits<Iter>::iterator_category      iterator_category;
            typedef typename ft::iterator_traits<Iter>::value_type             value_type;
            typedef typename ft::iterator_traits<Iter>::difference_type        difference_type;
            typedef typename ft::iterator_traits<Iter>::pointer                pointer;
            typedef typename ft::iterator_traits<Iter>::reference              reference;


            // todo: Construction
            reverse_iterator(void)
            :
                _ptr()
            {}

            explicit reverse_iterator(iterator_type it)
            :
                _ptr(it)
            {}

            template <class Iterator>
            reverse_iterator (const reverse_iterator<Iterator>& rev_it)
            :
                _ptr(rev_it.base())
            {}

            // todo: destructor
            virtual ~reverse_iterator(void) {}

            reverse_iterator(pointer ptr): _ptr(ptr) {} // todo: X(ptr) - typecast

            reverse_iterator(const reverse_iterator&    other) // todo: X b(a)
            {
                *this = other;
            }
            reverse_iterator&     operator=(const reverse_iterator& rhs) // todo: b = a
            {
                if (this != &rhs)
                {
                    _ptr = rhs._ptr;
                }
                return (*this);
            }


            // ! operator *
            reference operator *(void) // todo: *a
            {
                
                iterator_type tmp = _ptr;
                return (*(--tmp));
                // return (*_ptr);
            }
            // ! operator +
            reverse_iterator operator+(difference_type n) const
            {
                return (reverse_iterator(_ptr - n));
            }

            // ! operator ++
            reverse_iterator& operator ++(void) // todo: ++a
            {
                --_ptr;
                return (*this);
            }

            reverse_iterator operator ++(int) // todo: a++
            {
                reverse_iterator tmp = *this;
                ++(*this);
                return (tmp);
            }
            // ! operator +=
            reverse_iterator& operator+=(difference_type n)
            {
                _ptr -= n;
                return (*this);
            }
            // ! operator -
            reverse_iterator operator-(difference_type n) const
            {
                return (reverse_iterator(_ptr + n));
            }
            // ! operator --
            reverse_iterator operator --(void) // todo: --a
            {
                ++_ptr;
                return (*this);
            }

            reverse_iterator operator --(int) // todo: a--
            {
                reverse_iterator tmp = *this;
                --(*this);
                return (tmp);
            }
            // ! operator -=
            reverse_iterator& operator-=(difference_type n)
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

            // ! Base
            iterator_type   base(void) const
            {
                return (_ptr);
            }
    private:
        iterator_type _ptr;

}; /* class reverse_iterator */

// ! Relational operators
template <class Iterator1, class Iterator2>
bool operator==( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) 
{
    return (lhs.base() == rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator!=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) 
{
    return (lhs.base() != rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator>( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) 
{
    return (lhs.base() < rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator>=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) 
{
    return (lhs.base() <= rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator<( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) 
{
    return (lhs.base() > rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator<=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) 
{
    return (lhs.base() >= rhs.base());
}

// ! operator +
template <class Iterator>
reverse_iterator<Iterator>
operator + (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& it)
{
    return (it + n);
}

// ! operator -
template <class Iterator>
typename reverse_iterator<Iterator>::difference_type
operator - (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
    return (lhs.base() - rhs.base());
}

} /* namespace ft */

#endif
