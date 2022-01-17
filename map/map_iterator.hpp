#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "../utils/iterator.hpp"
#include "../utils/iterator_traits.hpp"
#include "../utils/bidirectional_iterator_tag.hpp"

namespace ft
{
    template <typename T, class Compare>
    class mapIterator: public ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        public:        
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category     iterator_category;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type            value_type;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type       difference_type;
            typedef T*               pointer;
            typedef T&             reference;

            // Todo: Constructor, Destructor
            mapIterator(const Compare& comp = Compare())
            :
                _node(),
                _last_node(),
                _comp(comp)
            {
                std::cout << "Empty mapIterator called\n";
            }

            mapIterator(T* node, const Compare& comp = Compare())
            :
                _node(node),
                _last_node(),
                _comp(comp)
            {}

            virtual ~mapIterator()
            {}
            // Todo: X a; X b(a); b = a;

            mapIterator(const mapIterator& other)
            {
                *this = other;
            }

            mapIterator&    operator=(const mapIterator& rhs)
            {
                if (this != &rhs)
                {
                    _node = rhs._node;
                    _last_node = rhs._last_node;
                    _comp = rhs._comp;
                }
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




            // *a
            // a->m
            // *a = t
            // ++a
            // a++
            // *a++
            // --a
            // a--
            // *a--
        private:
           T*       _node;
           T*       _last_node;
           Compare  _comp;

    };

} /* namespace ft */


#endif /* map_iterator.hpp */