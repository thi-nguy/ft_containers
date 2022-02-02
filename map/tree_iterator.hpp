#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include "../utils/iterator.hpp"
#include "../utils/iterator_traits.hpp"
#include "../utils/bidirectional_iterator_tag.hpp"

namespace ft
{
    template <typename T>
    class treeIterator: ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        public:
        // T is a treeNode. T::value_type is ft::pair        
            typedef typename T::value_type                                                                   value_type; 
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category     iterator_category;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type       difference_type;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer               pointer;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference             reference;

            // Todo: Constructor, Destructor
            treeIterator()
            : _node()
            {
                // std::cout << "Empty treeIterator constructor called\n";
            }

            treeIterator(T* node)
            : _node(node)
            {
                // std::cout << "Node treeIterator constructor called\n";
            }

            virtual ~treeIterator()
            {
                // std::cout << "treeIterator Destructor called\n";
            }

            // Todo: X a; X b(a); b = a;

            treeIterator(const treeIterator& other)
            :   _node(other._node)
            {
            }

            treeIterator&    operator=(const treeIterator& rhs)
            {
                if (this != &rhs)
                    _node = rhs._node;
                return (*this);
            }

            // Todo: a == b, a != b
            bool operator==(const treeIterator& rhs) // overload at treeNode
            {
                return (this->_node == rhs._node);
            }

            bool operator!=(const treeIterator& rhs)
            {
                return (this->_node != rhs._node);
            }

            // Todo: *a, a->m
            reference operator*() const
            {
                return (this->_node->value);
            }

            pointer     operator->() const
            {
                return (&this->_node->value);
            }

            // ++a
            treeIterator&    operator++()
            {
                this->nextNode();
                return (*this);
            }
            // a++
            treeIterator     operator++(int)
            {
                treeIterator tmp(*this);
                this->nextNode();
                return (tmp);
            }

            // --a
            treeIterator&    operator--()
            {
                this->prevNode();
                return (*this);
            }

            // a--
            treeIterator     operator--(int)
            {
                treeIterator tmp(*this);
                this->prevNode();
                return (tmp);
            }
            // todo: *a = t

            // *a++ same as *(a++) --> no need to do? --> need to test!! 
            // *a-- same as *(a--)

            T*      getValue() const
            {
                return (_node);
            }
        private:
           T*       _node;

            void nextNode (void)
            {
                if (_node->right != NULL)
                {
                    _node = _node->right;
                    while (_node->left != NULL)
                        _node = _node->left;
                }
                else if (_node->right == NULL)
                {
                    T* parent = _node->parent;
                    if (parent == NULL)
                    {
                        _node = parent;
                        return ;
                    }
                    while (_node == parent->right)
                    {
                        _node = parent;
                        parent = parent->parent;
                        if (parent == NULL)
                        {
                            _node = parent;
                            return ;
                        }
                    }
                    _node = parent;
                }
                // do something

            }

            void prevNode (void)
            {
                if (_node->left != NULL)
                {
                    _node = _node->left;
                    while (_node->right != NULL)
                        _node = _node->right;
                }
                else if (_node->left == NULL)
                {
                    T*   parent = _node->parent;
                    if (parent == NULL)
                    {
                        _node = parent;
                        return ;
                    }
                    while (_node == parent->left)
                    {
                        _node = parent;
                        parent = parent->parent;
                        if (parent == NULL)
                        {
                            _node = parent;
                            return ;
                        }
                    }
                    _node = parent;
                }
            }
    };

} /* namespace ft */


#endif /* map_iterator.hpp */