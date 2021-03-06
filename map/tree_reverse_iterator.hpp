#ifndef TREE_REVERSE_ITERATOR_HPP
#define TREE_REVERSE_ITERATOR_HPP

#include "../utils/utils.hpp"

namespace ft
{
template <class Iter>
class tree_reverse_iterator
{
    public:

            typedef Iter                                                       iterator_type;
            typedef typename ft::iterator_traits<Iter>::iterator_category      iterator_category;
            typedef typename ft::iterator_traits<Iter>::value_type             value_type;
            typedef typename ft::iterator_traits<Iter>::difference_type        difference_type;
            typedef typename ft::iterator_traits<Iter>::pointer                pointer;
            typedef typename ft::iterator_traits<Iter>::reference              reference;


            // todo: Construction
            tree_reverse_iterator(void)
            :
                _ptr()
            {}

            explicit tree_reverse_iterator(iterator_type it)
            :
                _ptr(it)
            {}

            template <class Iterator>
            tree_reverse_iterator (const tree_reverse_iterator<Iterator>& rev_it)
            :
                _ptr(rev_it.base())
            {}

            // todo: destructor
            virtual ~tree_reverse_iterator(void) {}

            // tree_reverse_iterator(pointer ptr): _ptr(ptr) {} // todo: X(ptr) - typecast?
            // tree_reverse_iterator(vectorIterator<value_type> const &src) 
            // { 
            //     _ptr = src.operator->(); 
            // } 

            tree_reverse_iterator(const tree_reverse_iterator&    other) // todo: X b(a)
            {
                *this = other;
            }
            tree_reverse_iterator&     operator=(const tree_reverse_iterator& rhs) // todo: b = a
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
            tree_reverse_iterator operator+(difference_type n) const
            {
                return (tree_reverse_iterator(_ptr - n));
            }

            // ! operator ++
            tree_reverse_iterator& operator ++(void) // todo: ++a
            {
                --_ptr;
                return (*this);
            }

            tree_reverse_iterator operator ++(int) // todo: a++
            {
                tree_reverse_iterator tmp = *this;
                ++(*this);
                return (tmp);
            }
            // ! operator +=
            tree_reverse_iterator& operator+=(difference_type n)
            {
                _ptr -= n;
                return (*this);
            }
            // ! operator -
            tree_reverse_iterator operator-(difference_type n) const
            {
                return (tree_reverse_iterator(_ptr + n));
            }
            // ! operator --
            tree_reverse_iterator operator --(void) // todo: --a
            {
                ++_ptr;
                return (*this);
            }

            tree_reverse_iterator operator --(int) // todo: a--
            {
                tree_reverse_iterator tmp = *this;
                --(*this);
                return (tmp);
            }
            // ! operator -=
            tree_reverse_iterator& operator-=(difference_type n)
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

}; /* class tree_reverse_iterator */

// ! Relational operators
template <class Iterator1, class Iterator2>
bool operator==( const ft::tree_reverse_iterator<Iterator1>& lhs, const ft::tree_reverse_iterator<Iterator2>& rhs) 
{
    return (lhs.base() == rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator!=( const ft::tree_reverse_iterator<Iterator1>& lhs, const ft::tree_reverse_iterator<Iterator2>& rhs) 
{
    return (lhs.base() != rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator>( const ft::tree_reverse_iterator<Iterator1>& lhs, const ft::tree_reverse_iterator<Iterator2>& rhs) 
{
    return (lhs.base() < rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator>=( const ft::tree_reverse_iterator<Iterator1>& lhs, const ft::tree_reverse_iterator<Iterator2>& rhs) 
{
    return (lhs.base() <= rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator<( const ft::tree_reverse_iterator<Iterator1>& lhs, const ft::tree_reverse_iterator<Iterator2>& rhs) 
{
    return (lhs.base() > rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator<=( const ft::tree_reverse_iterator<Iterator1>& lhs, const ft::tree_reverse_iterator<Iterator2>& rhs) 
{
    return (lhs.base() >= rhs.base());
}

// ! operator +
template <class Iterator>
tree_reverse_iterator<Iterator>
operator + (typename tree_reverse_iterator<Iterator>::difference_type n, const tree_reverse_iterator<Iterator>& it)
{
    return (it + n);
}

// ! operator -
template <class Iterator>
typename tree_reverse_iterator<Iterator>::difference_type
operator - (const tree_reverse_iterator<Iterator>& lhs, const tree_reverse_iterator<Iterator>& rhs)
{
    return (lhs.base() - rhs.base());
}

} /* namespace ft */

#endif