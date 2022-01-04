#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <memory>

enum Color {RED, BLACK};

namespace ft
{
    template <typename T>
    struct treeNode
    {
        public:
            typedef T   value_type;

            value_type  value;
            treeNode*   parent;
            treeNode*   left;
            treeNode*   right;
            bool        color;

            // Constructor
            treeNode()
            :   value(NULL),
                parent(NULL),
                left(NULL),
                right(NULL),
                color(RED)
            {}
            treeNode(value_type val)
            :   value(val),
                parent(NULL),
                left(NULL),
                right(NULL),
                color(RED)
            {}

            treeNode(const treeNode& other)
            {
                *this = other;
            }

            treeNode&   operator=(const treeNode& rhs)
            {
                if (this != &rhs)
                {
                    this->value = other.value;
                    this->parent = other.parent;
                    this->left = other.left;
                    this->right = other.right;
                    this->color = other.color;
                }
                return (*this);
            }

            virtual ~treeNode() {}
    }; /* struct treeNode */

    template <  class T,
                class Node = ft::treeNode<T>,
                class Type_Alloc = std::allocator<T>,
                class Node_Alloc = std::allocator<Node>
                // class Compare = std::less<T> // ! cai nay useful?
            >
    class RedBlackTree
    {
        public:
            typedef T       value_type;
            typedef Node    node_type;
            typedef Node*   node_pointer;
            typedef size_t  size_type;

            // Todo: iterator and other typedef

            // Member Functions
            RedBlackTree(const Node_Alloc& node_alloc = Node_Alloc()) // call constructor of allocator
            :   _root(NULL),
                _alloc_node(node_alloc)
                // _last_node?
            {
                _root = _alloc_node.allocate(1);
                _alloc_node.construct(_root, Node(_root, _root, _root)); // ! What's the hell?
            }

            

            ~RedBlackTree()
            {
                _alloc_node.destroy(_root);
                _alloc_node.deallocate(_root, 1);
            }





        
        protected:

        private:
            node_pointer            _root;
            // node_pointer            _last_node; // need it to allocate - construct
            std::allocator<Node>    _alloc_node;
    };




} /* namespace ft */




#endif