#ifndef TREENODE_HPP
#define TREENODE_HPP

#include <memory>  //std::allocator
#include <utility> //std::

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

            treeNode(treeNode* parent = NULL, treeNode* left = NULL, treeNode* right = NULL)
            :   value(),
                parent(parent),
                left(left),
                right(right),
                color(BLACK)
            {
                // std::cout << "Node Default constructor called\n\n";
            }

            treeNode(const value_type& val, treeNode* parent = NULL, treeNode* left = NULL, treeNode* right = NULL)
            :   value(val),
                parent(parent),
                left(left),
                right(right),
                color(RED)
            {
                // std::cout << "Node Val constructor called\n\n";
            }

            treeNode(const treeNode& other)
            {
                *this = other;
                // std::cout << "Node Copy constructor called\n\n";
            }

            treeNode&   operator=(const treeNode& rhs)
            {
                if (this != &rhs)
                {
                    this->value = rhs.value;
                    this->parent = rhs.parent;
                    this->left = rhs.left;
                    this->right = rhs.right;
                    this->color = rhs.color;
                }
                // std::cout << "Operator = called\n\n";
                return (*this);
            }

            virtual ~treeNode() 
            {
                // std::cout << "Node Deconstructor called\n";
            }
    }; /* struct treeNode */
};

#endif /* namespace ft */