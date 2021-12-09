#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../utils/Utils.hpp"
#include "vector_iterator.hpp"
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
            
            typedef typename ft::vectorIterator<T>              iterator;
            // Todo: iterator member types: const_iterator, reverse_iterator, const_reverse_iterator

            typedef typename std::ptrdiff_t                     difference_type; // Todo: difference_type; (from iterator_traits), no, use ptrdiff_t
            typedef typename allocator_type::size_type          size_type;


        // * CONSTRUCTOR (có 3 kiểu constructors và 1 copy constructor)
            explicit vector (const allocator_type& alloc = allocator_type()) // ! default value, goi constructor của std::allocator on T
            :   _alloc(alloc),
                _start(NULL),
                _end(NULL),
                _end_capacity(NULL) 
            {
                std::cout << "Empty Constructor called\n";
            }

            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
            :   _alloc(alloc),
                _start(NULL),
                _end(NULL),
                _end_capacity(NULL) 
            {
                _start = _alloc.allocate(n); // ! giống malloc n memory vào object _alloc
                _end_capacity = _start + n;
                _end = _start;
                while (n != 0)
                {
                    _alloc.construct(_end, val); // ! đặt giá trị tại _end là val.
                    _end++;
                    n--;
                }
                std::cout << "Fill Constructor called\n";
            }

            template < class InputIterator >
            explicit vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
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
                std::cout << "Range Constructor called \n";
            }

            explicit vector(const vector& other)
            {
                *this = other;
                std::cout << "Copy Constructor called \n";
            }

            vector&     operator=(const vector& rhs)
            {
                if (this != &rhs)
                {
                    _start = rhs._start;
                    _end = rhs._end;
                    _end_capacity = rhs._end_capacity;
                    _alloc = rhs._alloc;
                    std::cout << "Assignation Operator called \n";
                }
                return (*this);
            }

        // ! DESTRUCTOR 
            ~vector(void)  // ! leaks here
            {
                
                std::cout << "Deconstructor called\n";
            }
            // vector(vector const& other);
            // vector&     operator=(vector const& rhs);
        
        // ! MEMBER FUNCTIONS - ITERATORs
        iterator    begin(void)
        {
            return (_start);
        }

        iterator    end(void)
        {
            return (_end);
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
            if (n > this->max_size())
                throw(); // todo: throw exception here
            else if (n <= this->capacity())
                return ;
            // ? allocator::allocate hoat dong nhu nao?, no allocate memory noi vao voi array cu hay sao?
            _alloc.allocate(n);

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
                throw std::out_of_range("Out of range");  
            return ((*this)[n]);
        }

        const_reference at(size_type n) const
        {
            if (n >= this->size())
                throw std::out_of_range("Out of range");  
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

        // ! Member Functions: Modifiers

        // template <class InputIterator>
        // void    assign (InputIterator first, InputIterator last)
        // {

        // }

        // void    assign(size_type n, const value_type& val)
        // {

        // }


        // iterator    erase (iterator position)
        // {
        //     pointer     position_to_erase = &(*position);
        //     _alloc.destroy(position_to_erase);

        //     for (int i = 0; i < _end - position_to_erase; i++)
        //     {
        //         _alloc.construct(position_to_erase, *(position_to_erase + i + 1));
        //         _alloc.destroy(position_to_erase + i + 1);
        //     }
        //     _end--;
        //     return (iterator(position_to_erase));
        // }

        void        clear(void)
        {
            size_type vector_size = this->size();
            for (size_type i = 0; i < vector_size; i++)
            {
                _end--;
                _alloc.destroy(_end);
            }
        }

        // ! destroy: "destroy" data, memory is remained
        // ! deallocate: release memory.








        // ! OVERLOAD cho vector

        // ! Swap
        void    swap(vector& other)
        {
            if (*this == other)
                return ;

            pointer tmp_start = _start;
            pointer tmp_end = _end;
            pointer tmp_end_capacity = _end_capacity;
            allocator_type tmp_alloc = _alloc;

            _start = other._start;
            _end = other._end;
            _end_capacity = other._end_capacity;
            _alloc = other._alloc;

            other._start = tmp_start;
            other._end = tmp_end;
            other._end_capacity = tmp_end_capacity;
            other._alloc = tmp_alloc;
        }





        /* public */


        private:
            allocator_type      _alloc;
            pointer             _start;
            pointer             _end;
            pointer             _end_capacity;

        /* private */

    }; /* class vector */

    // ! OVERLOAD cho vector
    template <class T, class Alloc>
    bool    operator == (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return (false);
        typename ft::vector<T>::iterator begin_lhs = lhs.begin();
        typename ft::vector<T>::iterator begin_rhs = rhs.begin();
        while (begin_lhs != lhs.end())
        {
            if (begin_rhs == rhs.end() || *begin_lhs != *begin_rhs)
                return (false);
            ++begin_lhs;
            ++begin_rhs;
        }
        return (true);
    }

    template <class T, class Alloc>
    bool     operator != (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        return (!(lhs == rhs));
    }

    template <class T, class Alloc>
    bool    operator < (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        typename ft::vector<T>::iterator begin_lhs = lhs.begin();
        typename ft::vector<T>::iterator begin_rhs = rhs.begin();
        while (begin_lhs != lhs.end())
        {
            if (begin_rhs == rhs.end() || *begin_rhs < *begin_lhs)
                return (false);
            else if (*begin_lhs < *begin_rhs)
            {
                ++begin_lhs;
                ++begin_rhs;
            }
        }
        return (true);
    }

    template <class T, class Alloc>
    bool    operator >  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        return (rhs < lhs);
    }

    template <class T, class Alloc>
    bool    operator <= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        return (!(lhs > rhs));
    }

    template <class T, class Alloc>
    bool    operator >= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        return (!(lhs < rhs));
    }

} /* namespace ft */

 
#endif /* VECTOR_HPP */