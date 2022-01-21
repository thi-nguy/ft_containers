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
            typedef T&  reference;
            typedef T*  pointer;

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

            ~treeNode() 
            {
                // std::cout << "Node Deconstructor called\n";
            }

            bool isOnLeft() 
            { 
                return (this == parent->left); 
            }


            treeNode *sibling() 
            {
                // sibling null if no parent
                if (parent == NULL)
                    return NULL;
            
                if (isOnLeft())
                    return (parent->right);
            
                return (parent->left);
            }

            bool hasRedChild() 
            {
                return (left != NULL and left->color == RED) || (right != NULL and right->color == RED);
            }

            bool operator==(const treeNode& other)
            {
                if (value == other.value)
                    return (true);
                return (false);
            }

    }; /* struct treeNode */

    template <typename T>
    treeNode<T> *successor(treeNode<T> *x) 
    {
        treeNode<T> *temp = x;

        while (temp->left != NULL)
            temp = temp->left;

        return temp;
    }
};

#endif /* namespace ft */