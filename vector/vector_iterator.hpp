#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

namespace ft
{

template <typename T>
class vectorIterator
{
    public:
        typedef T                           value_type;
        typedef T&                          reference;
        typedef const T&                    const_reference;
        typedef T*                          pointer;
        typedef const T*                    const_pointer;
        typedef typename std::ptrdiff_t     difference_type;

        // ! Canonical form of of vectorIterator
        vectorIterator(void) {} // todo: X a;
        vectorIterator(pointer ptr): _ptr(ptr) {} // ! no need? yes!!!
        vectorIterator(const vectorIterator&    other) // todo: X b(a)
        {
            *this = other;
        }
        vectorIterator&     operator=(const vectorIterator& rhs) // todo: b = a
        {
            if (this != &rhs)
            {
                _ptr = rhs._ptr;
            }
            return (*this);
        }
        ~vectorIterator(void) {}
        // ! Operator Overload. Tai sao can no? De co the dung iterator!!
        bool operator !=(vectorIterator const& rhs) const // todo: a != b
        {
            return (_ptr != rhs._ptr);
        }

        vectorIterator operator ++(int) // todo: a++
        {
            _ptr++;
            return (vectorIterator(_ptr - 1));
        }

        reference operator *(void) // todo: *a
        {
            return (*_ptr);
        }

        const_reference operator *() const // todo: *a
        {
            return (*_ptr);
        }





    /* public */
    private:
        pointer     _ptr;
    /* private */




}; /* class vectorIterator */
    
} /* namespace ft */

#endif /* vector_iterator.hpp */