#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>


namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
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
            typedef


        // ! Canonical form
            vector(void) {
                std::cout << "constructor called\n";
            }
            ~vector(void) {
                std::cout << "Deconstructor called\n";
            }
            vector(vector const& other);
            vector&     operator=(vector const& rhs);
        /* public */

        private:
        /* private */

    }; /* class vector */

} /* namespace ft */

 
#endif /* VECTOR_HPP */