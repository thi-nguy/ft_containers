#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../utils/utils.hpp"
#include "../utils/equal.hpp"
#include "../utils/lexicographical_compare.hpp"
#include "vector_iterator.hpp"
#include "vector_reverse_iterator.hpp"
#include <memory>       // Allocator
#include <cstddef>      // nullptr_t(), ptrdiff_t
#include <stdexcept>    // std::out_of_range
#include <iostream>     // std::cout, std::endl, std::cerr

namespace ft
{
    template < typename T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
        // ! MEMBER TYPES
            typedef T                                           value_type;
            typedef Alloc                                       allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            
            typedef typename ft::vectorIterator<T>                      iterator;
            typedef typename ft::vectorIterator<const T>                const_iterator;
            typedef typename ft::VectorReverseIterator<iterator>        reverse_iterator;
            typedef typename ft::VectorReverseIterator<const_iterator>  const_reverse_iterator;

            typedef typename std::ptrdiff_t                     difference_type;
            typedef typename allocator_type::size_type          size_type;

        // * CONSTRUCTOR
            explicit vector (const allocator_type& alloc = allocator_type())
            :   _alloc(alloc),
                _start(NULL),
                _end(NULL),
                _end_capacity(NULL) 
            {
            }

            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
            :   _alloc(alloc),
                _start(NULL),
                _end(NULL),
                _end_capacity(NULL) 
            {
                _start = _alloc.allocate(n);
                _end_capacity = _start + n;
                _end = _start;
                while (n != 0)
                {
                    _alloc.construct(_end, val);
                    _end++;
                    n--;
                }
            }

            template < class InputIterator >
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
            :   _alloc(alloc),
                _start(NULL),
                _end(NULL),
                _end_capacity(NULL) 
            {
                InputIterator tmp = first;
                difference_type size = 0;
                while (tmp != last)
                {
                    tmp++;
                    size++;
                }
                _start = _alloc.allocate(size);
                _end_capacity = _start + size;
                _end = _start;
                while (size)
                {
                    const value_type& val = *first;
                    _alloc.construct(_end, val);
                    first++;
                    _end++;
                    size--;
                }
            }

            vector(const vector& other)
            : 
                _alloc(other._alloc), 
                _start(NULL),
                _end(NULL),
                _end_capacity(NULL)
            {
                *this = other;
            }

            vector&     operator=(const vector& rhs)
            {
                if (this != &rhs)
                {
                    size_type size = rhs.size();
                    _start = _alloc.allocate(size);
                    _end = _start;
                    _end_capacity = _start + size;
                    for (size_type i = 0; i < size; i++)
                    {
                        const value_type& val = rhs.at(i);
                        _alloc.construct(_end, val);
                        _end++;
                    }
                }
                return (*this);
            }

        // ! DESTRUCTOR 
            ~vector(void)
            {
                size_type vector_size = this->size();
                for (size_type i = 0; i < vector_size; i++)
                {
                    _end--;
                    _alloc.destroy(_end);
                }
                _alloc.deallocate(_start, this->capacity());
            }
        
        // ! MEMBER FUNCTIONS - ITERATORs

            iterator    begin(void)
            {
                return (iterator(_start));
            }

            const_iterator begin(void) const
            {
                return (const_iterator(_start));
            }

            iterator    end(void)
            {
                return (iterator(_end));
            }

            const_iterator end(void) const
            {
                return (const_iterator(_end));
            }

            //todo: rbegin, rend
            reverse_iterator    rbegin(void)
            {
                return (reverse_iterator(this->end()));
            }

            const_reverse_iterator  rbegin(void) const
            {
                return (reverse_iterator(this->end()));
            }

            reverse_iterator    rend(void)
            {
                return (reverse_iterator(this->begin()));
            }

            const_reverse_iterator rend(void) const
            {
                return (reverse_iterator(this->begin()));
            }

        // ! MEMBER FUNCTIONS - CAPACITY

            size_type   size(void) const
            {
                return (_end - _start);
            }

            size_type   max_size(void) const
            {
                return (allocator_type().max_size());
            }

            void        resize(size_type n, value_type val = value_type())
            {
                if (n < this->size())
                {
                    for (size_type i = this->size(); i > n; i--)
                        this->pop_back();
                }
                else if (n > this->size())
                {
                    for (size_type i = this->size(); i < n; i++)
                        this->push_back(val);
                }
            }

            size_type   capacity(void) const
            {
                return (_end_capacity - _start);
            }

            bool        empty(void) const
            {
                return (this->size() == 0);
            }

            void        reserve(size_type n)
            {
                if (n > this->max_size() || n < 0)
                    throw (std::length_error("vector::reserve"));
                else if (n <= this->capacity())
                    return ;
                pointer     old_start = _start;
                pointer     old_end = _end;
                size_type   old_size = this->size();
                size_type   old_capacity = this->capacity();
                _start = _alloc.allocate(n);
                _end_capacity = _start + n;
                _end = _start;
                while (old_start != old_end)
                {
                    _alloc.construct(_end, *old_start);
                    old_start++;
                    _end++;
                }
                _alloc.deallocate(old_start - old_size, old_capacity);
            }

        // ! MEMBER FUNCTIONs - Element Access
            reference   operator [] (size_type n)
            {
                return (*(_start + n));
            }

            const_reference operator [] (size_type n) const
            {
                return (*(_start + n));
            }

            reference   at(size_type n)
            {
                if (n >= this->size())
                    throw std::out_of_range("vector::_M_range_check");  
                return ((*this)[n]);
            }

            const_reference at(size_type n) const
            {
                if (n >= this->size())
                    throw std::out_of_range("vector::_M_range_check");  
                return ((*this)[n]);
            }

            reference       front(void)
            {
                return (*_start);
            }

            const_reference front(void) const
            {
                return (*_start);
            }

            reference       back(void)
            {
                return (*(_end - 1));
            }
        
            const_reference back(void) const
            {
                return (*(_end - 1));
            }

        // ! MEMBER FUNCTIONs: MODIFIERS

            template <class InputIterator>
            void        assign (InputIterator first, InputIterator last,  typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
            {
                size_type size = last - first;
                this->clear();
                this->reserve(size);
                while (size)
                {
                    const value_type& val = *first;
                    this->push_back(val);
                    first++;
                    size--;
                }
            }

            void        assign(size_type n, const value_type& val)
            {
                this->clear();
                this->reserve(n);
                for (size_type i = 0; i < n; i++)
                    this->push_back(val);
            }


            void        push_back(const value_type& val)
            {
                if (_end == _end_capacity)
                {
                    int new_capacity;
                    if (this->size() > 0)
                        new_capacity = this->capacity() * 2;
                    else
                        new_capacity = 1;
                    this->reserve(new_capacity);
                }
                _alloc.construct(_end, val);
                _end++;
            }

            void        pop_back(void)
            {
                _end--;
                _alloc.destroy(_end);
            }

            iterator    erase (iterator position)
            {
                pointer     position_to_erase = &(*position);
                _alloc.destroy(position_to_erase);

                for (int i = 0; i < _end - position_to_erase; i++)
                {
                    _alloc.construct(position_to_erase + i, *(position_to_erase + i + 1));
                    _alloc.destroy(position_to_erase + i + 1);
                }
                _end--;
                return (iterator(position_to_erase));
            }

            iterator    erase(iterator first, iterator last)
            {
                pointer     first_position_to_erase = &(*first);
                pointer     position_to_erase = &(*first);
                pointer     last_position_to_erase = &(*last);
                difference_type range = _end - last_position_to_erase;
                difference_type size = last_position_to_erase - first_position_to_erase;
                while (position_to_erase != last_position_to_erase)
                {
                    _alloc.destroy(position_to_erase);
                    position_to_erase++;
                }
                for (int i = 0; i < range; i++)
                {
                    _alloc.construct(first_position_to_erase + i, *(last_position_to_erase + i));
                    _alloc.destroy(last_position_to_erase + i);
                }
                _end -= size;
                return (iterator(first_position_to_erase));
            }

            void        clear(void)
            {
                size_type vector_size = this->size();
                for (size_type i = 0; i < vector_size; i++)
                {
                    _end--;
                    _alloc.destroy(_end);
                }
            }

            iterator    insert(iterator position, const value_type& val)
            {
                size_type n = this->size() + 1;
                pointer     old_start = _start;
                pointer     old_end = _end;
                pointer     position_to_insert = &(*position);
                size_type   old_size = this->size();
                size_type   old_capacity = this->capacity();

                _start = _alloc.allocate(n);
                if (old_end == _end_capacity)
                {
                    if (old_size > 0)
                        _end_capacity = _start + old_capacity * 2;
                    else
                        _end_capacity = _start + 1;
                }
                else
                    _end_capacity = _start + n;
                _end = _start;
                while (old_start != position_to_insert)
                {
                    _alloc.construct(_end, *old_start);
                    old_start++;
                    _end++;
                }
                _alloc.construct(_end, val);
                pointer ret = _end;
                _end++;
                while (old_start != old_end)
                {
                    _alloc.construct(_end, *old_start);
                    old_start++;
                    _end++;
                }
                _alloc.deallocate(old_start - old_size, old_capacity); 
                return (iterator(ret));
            }

            void    insert(iterator position, size_type n, const value_type& val)
            {
                size_type   size = this->size() + n;
                pointer     old_start = _start;
                pointer     old_end = _end;
                pointer     position_to_insert = &(*position);
                size_type   old_size = this->size();
                size_type   old_capacity = this->capacity();

                _start = _alloc.allocate(size);
                _end_capacity = _start + size;
                _end = _start;
                while (old_start != position_to_insert)
                {
                    _alloc.construct(_end, *old_start);
                    old_start++;
                    _end++;
                }
                for (size_type i = n; i > 0; i--)
                {
                    _alloc.construct(_end, val);
                    _end++;
                }
                while (old_start != old_end)
                {
                    _alloc.construct(_end, *old_start);
                    old_start++;
                    _end++;
                }
                _alloc.deallocate(old_start - old_size, old_capacity); 
            }

            template <class InputIterator>
            void    insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
            {
                size_type   insert_size = last - first;

                size_type   size = this->size() + insert_size;
                pointer     old_start = _start;
                pointer     old_end = _end;
                pointer     position_to_insert = &(*position);
                size_type   old_size = this->size();
                size_type   old_capacity = this->capacity();

                _start = _alloc.allocate(size);
                _end_capacity = _start + size;
                _end = _start;
                while (old_start != position_to_insert)
                {
                    _alloc.construct(_end, *old_start);
                    old_start++;
                    _end++;
                }
                while (first != last)
                {
                    _alloc.construct(_end, *first);
                    _end++;
                    first++;
                }
                while (old_start != old_end)
                {
                    _alloc.construct(_end, *old_start);
                    old_start++;
                    _end++;
                }
                _alloc.deallocate(old_start - old_size, old_capacity); 
            }

            void    swap(vector& x)
            {
                if (*this == x)
                    return ;

                pointer tmp_start = _start;
                pointer tmp_end = _end;
                pointer tmp_end_capacity = _end_capacity;
                allocator_type tmp_alloc = _alloc;

                _start = x._start;
                _end = x._end;
                _end_capacity = x._end_capacity;
                _alloc = x._alloc;

                x._start = tmp_start;
                x._end = tmp_end;
                x._end_capacity = tmp_end_capacity;
                x._alloc = tmp_alloc;
            }

            // ! ALLOCATOR
            allocator_type  get_allocator(void) const
            {
                return (_alloc);
            }

        /* public */


        private:
            allocator_type      _alloc;
            pointer             _start;
            pointer             _end;
            pointer             _end_capacity;

        /* private */

    }; /* class vector */

    // ! Non member function overloads
    template <class T, class Alloc>
    bool    operator == (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return (false);
        return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template <class T, class Alloc>
    bool     operator != (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        return (!(lhs == rhs));
    }

    template <class T, class Alloc>
    bool    operator < (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class T, class Alloc>
    bool    operator >  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        return (rhs < lhs);
    }

    template <class T, class Alloc>
    bool    operator <= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        return (!(rhs < lhs));
    }

    template <class T, class Alloc>
    bool    operator >= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        return (!(lhs < rhs));
    }

    template <class T, class Alloc>
    void    swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
    {
        vector<T, Alloc> tmp = x;
        x = y;
        y = tmp;
    }



} /* namespace ft */

 
#endif /* VECTOR_HPP */