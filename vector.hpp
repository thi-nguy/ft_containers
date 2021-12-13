#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory> // to access Allocator
#include "./utils/Utils.hpp"

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
            // Todo: iterator member types: iterator, const_iterator, reverse_iterator, const_reverse_iterator
            // Todo: difference_type; (from iterator_traits), no, use ptrdiff_t
            typedef typename std::ptrdiff_t                     difference_type;
            typedef typename allocator_type::size_type          size_type;


        // * CONSTRUCTOR (có 3 kiểu constructors và 1 copy constructor)
            explicit vector (const allocator_type& alloc = allocator_type()) // ! default value, constructor của std::allocator?
            :   _alloc(alloc),
                _start(u_nullptr),
                _end(u_nullptr),
                _end_capacity(u_nullptr) 
            {
                std::cout << "Empty constructor called\n";
            }

            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
            :   _alloc(alloc),
                _start(u_nullptr),
                _end(u_nullptr),
                _end_capacity(u_nullptr) 
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
                _start(u_nullptr),
                _end(u_nullptr),
                _end_capacity(u_nullptr) 
            {
                while (first != last)
                {
                    this->push_back(*first);
                    first++;
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
        // * Member function
            void    push_back(const value_type& value)
            {
                if (_end == _end_capacity)
                {
                    // todo: extend the vector, allocate memory
                    int next_capacity = (this->size() > 0) ? (int)(this->size() * 2) : 1;
                    this->reserve(next_capacity);
                }
                _alloc.construct(_end, value);
                _end++;
            }

            size_type   size(void) const { return (this->_end - this->_start); }

            void        reserve (size_type n)
            {
                if (n > this->max_size())
                    throw (std::length_error("vector::reserve"));
                else if (n > this->capacity())
                {
                    pointer prev_start = _start;
                    pointer prev_end = _end;
                    size_type prev_size = this->size();
                    size_type prev_capacity = this->capacity();
                    
                    _start = _alloc.allocate( n );
                    _end_capacity = _start + n;
                    _end = _start;
                    while (prev_start != prev_end)
                    {
                        _alloc.construct(_end, *prev_start);
                        _end++;
                        prev_start++;
                    }
                    _alloc.deallocate(prev_start - prev_size, prev_capacity);
                }
            }

            size_type   max_size(void) const { return allocator_type().max_size(); }

            size_type   capacity (void) const { return (this->_end_capacity - this->_start); }

            pointer getBegin(void)
            {
                return (_start);
            }

            pointer getEnd(void)
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