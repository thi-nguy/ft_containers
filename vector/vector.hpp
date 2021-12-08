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
                std::cout << "Empty constructor called\n";
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
                std::cout << "Constructor with Capacity called\n";
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
                std::cout << "Constructor with Range called \n";
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



        /* public */


        private:
            allocator_type      _alloc;
            pointer             _start;
            pointer             _end;
            pointer             _end_capacity;

        /* private */

    }; /* class vector */

} /* namespace ft */

 
#endif /* VECTOR_HPP */