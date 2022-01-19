#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "../utils/iterator.hpp"
#include "../utils/iterator_traits.hpp"
#include "../utils/bidirectional_iterator_tag.hpp"

namespace ft
{
    template <typename T>
    class mapIterator: public ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        public:        
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category     iterator_category;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type            value_type;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type       difference_type;
            typedef T*               pointer;
            typedef T&             reference;

            // Todo: Constructor, Destructor
            mapIterator()
            {
                std::cout << "Empty mapIterator constructor called\n";
            }

            mapIterator(T* node)
            : _node(node)
            {
                std::cout << "Node mapIterator constructor called\n";
            }

            virtual ~mapIterator()
            {
                std::cout << "mapIterator Destructor called\n";
            }

            // Todo: X a; X b(a); b = a;

            mapIterator(const mapIterator& other)
            {
                *this = other;
            }

            mapIterator&    operator=(const mapIterator& rhs)
            {
                if (this != &rhs)
                    _node = rhs._node;
                return (*this);
            }

            // Todo: a == b, a != b
            bool operator==(const mapIterator& rhs) // overload at treeNode
            {
                return (_node == rhs._node);
            }

            bool operator!=(const mapIterator& rhs)
            {
                return (!(this == rhs));
            }

            // Todo: *a, a->m
            reference operator*() const
            {
                return (_node->value);
            }

            pointer     operator->()
            {
                return (&this->_node->value);
            }

            // *a = t
            // ++a
            // a++
            // *a++
            // --a
            // a--
            // *a--
        private:
           T*       _node;
    };

} /* namespace ft */


#endif /* map_iterator.hpp */