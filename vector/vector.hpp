#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory> // to access Allocator
#include "../utils/Utils.hpp"
#include "vector_iterator.hpp"
#include <cstddef> // nullptr_t(), ptrdiff_t

namespace ft
{
    template < typename T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
        // ! Member types
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
                _start(std::nullptr_t()),
                _end(std::nullptr_t()),
                _end_capacity(std::nullptr_t()) 
            {
                std::cout << "Empty Constructor called\n";
            }

            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
            :   _alloc(alloc),
                _start(std::nullptr_t()),
                _end(std::nullptr_t()),
                _end_capacity(std::nullptr_t()) 
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
                _start(std::nullptr_t()),
                _end(std::nullptr_t()),
                _end_capacity(std::nullptr_t()) 
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
                    std::cout << "Assignation Operator called \n";
                    _start = rhs._start;
                    _end = rhs._end;
                    _end_capacity = rhs._end_capacity;
                    _alloc = rhs._alloc;
                }
                return (*this);
            }

        // * DESTRUCTOR 
            ~vector(void) 
            {
                std::cout << "Deconstructor called\n";
            }
            // vector(vector const& other);
            // vector&     operator=(vector const& rhs);
        
        // * MEMBER FUNCTIONS
        iterator    begin(void)
        {
            return (_start);
        }

        iterator    end(void)
        {
            return (_end);
        }

        // OVERLOAD



        /* public */


        private:
            allocator_type      _alloc;
            pointer             _start;
            pointer             _end;
            pointer             _end_capacity;

        /* private */

    }; /* class vector */

    template <class T, class Alloc>
    bool    operator ==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        typename ft::vector<T>::iterator begin_lhs = lhs.begin();
        typename ft::vector<T>::iterator begin_rhs = rhs.begin();
        while (begin_lhs != lhs.end())
        {
            if (begin_rhs == rhs.end() || *begin_rhs != *begin_lhs)
                return (false);
            ++begin_lhs;
            ++begin_rhs;
        }
        return (true);
    }

    template <class T, class Alloc>
    bool     operator !=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
        {
            return (!(lhs == rhs));
        }

} /* namespace ft */

 
#endif /* VECTOR_HPP */