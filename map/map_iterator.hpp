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
                return (&_node->value);
            }

            // ++a
            mapIterator&    operator++()
            {
                if (_node->right != NULL)
                {
                    _node = _node->right;
                    while (_node->left != NULL)
                        _node = _node->left;
                }
                else
                {
                    Node* tmp = _node->parent;
                    while (_node == tmp->right)
                    {
                        _node = tmp;
                        tmp = tmp->parent;
                    }
                    if (_node->right != tmp)
                        _node = tmp;
                }
                return (*this);
            }
            // a++
            mapIterator     operator++(int)
            {
                mapIterator tmp(*this);
                operator++();
                return (tmp);
            }

            // --a
            mapIterator&    operator--()
            {
                if (_node->left != NULL)
                {
                    _node = _node->left;
                    while (_node->right != NULL)
                        _node = _node->right;
                }
                else
                {
                    Node*   tmp = _node->parent;
                    while (_node == tmp->left)
                    {
                        _node = tmp;
                        tmp = tmp->parent;
                    }
                    if (_node->left != tmp)
                        _node = tmp;
                }
                return (*this);
            }

            // a--
            mapIterator     operator--(int)
            {
                mapIterator tmp(*this);
                operator--();
                return (tmp);
            }
            // todo: *a = t

            // *a++ same as *(a++) --> no need to do? --> need to test!! 
            // *a-- same as *(a--)
        private:
           T*       _node;
    };

} /* namespace ft */


#endif /* map_iterator.hpp */