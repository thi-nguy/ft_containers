#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <memory>  //std::allocator
#include <utility> //std::
#include "treeNode.hpp"

#define red		"\033[91m"
#define green   "\033[92m"
#define nocolor	"\033[0m"

namespace ft
{
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
            typedef size_t  size_type;

            // Todo: iterator and other typedef

            // ! Canonical form

            // Todo: Do not have the form RedBlackTree my_tree(val), instead we use my_tree.insert(val)

            RedBlackTree(const Node_Alloc& node_alloc = Node_Alloc()) // call constructor of allocator
            :   _root(NULL),
                _alloc_node(node_alloc)
                // _last_node?
            {
                // _root = _alloc_node.allocate(1);
                // _alloc_node.construct(_root, Node()); // construct 03 nodes: parent, left, right of the new node
                std::cout << "Tree constructor called\n";
            }

            RedBlackTree(const RedBlackTree& other)
            {
                *this = other;
            }

            RedBlackTree& operator=(const RedBlackTree& rhs)
            {
                if (this != &rhs)
                {
                    this->_root = rhs._root;
                    this->_alloc_node = rhs._alloc_node;
                }
                return (*this);
            }

            ~RedBlackTree()
            {
                if (_root != NULL)
                {
                    _alloc_node.destroy(_root);
                    _alloc_node.deallocate(_root, 1);
                }
                std::cout << "Tree deconstructor called\n";
            }

            // ! Member functions

            void    rotateLeft(Node *&root, Node *&x)
            {
                if (x != NULL)
                {
                    // Set y
                    Node *y = x->right;

                    // turn y's left subtree into x's right subtree
                    x->right = y->left;
                    if (y->left != NULL) 
                        y->left->parent = x;
                    // link x's parent to y
                    y->parent = x->parent;
                    if (x->parent == NULL)
                        root = y;
                    else if (x == x->parent->left)
                        x->parent->left = y;
                    else
                        x->parent->right = y;
                    // put x on y's left
                    y->left = x;
                    x->parent = y;
                }
            }

            void    rotateRight(Node *&root, Node *&x)
            {
                // Set y
                Node *y = x->left;

                // turn y's Right subtree into x's right subtree
                x->left = y->right;
                if (y->left != NULL) 
                    y->left->parent = x;
                // link x's parent to y
                y->parent = x->parent;
                if (x->parent == NULL)
                    root = y;
                else if (x == x->parent->left)
                    x->parent->left = y;
                else
                    x->parent->right = y;
                // put x on y's left
                y->right = x;
                x->parent = y;
            }

            void    insertValue(const value_type &val)
            {
                Node    *pt = _alloc_node.allocate(1);
                _alloc_node.construct(pt, Node(val));
                
                // Do a normal BST insert
                _root = BSTInsert(_root, pt);
                // Fix Red Black Tree violation
               fixViolation(_root, pt);
                // std::cout << "Insert function done\n";
            }
            // ! Todo : Search & Delete

            Node*   searchValue(Node* root, value_type val)
            {
                if (root == NULL || root->value == val)
                    return (root);
                if (root->value < val)
                {
                    root = root->right;
                    return (searchValue(root, val));
                }
                else
                {
                    root = root->left;
                    return (searchValue(root, val));
                }
            }

            void    fixViolation(Node *&root, Node *&pt)
            {
                Node *parent_pt = NULL;
                Node *grand_parent_pt = NULL;
                
                if (pt->parent == NULL)
                {
                    root->color = BLACK;
                    return ;
                }
                while (pt != root && pt->color != BLACK && pt->parent->color == RED)     
                {
                    parent_pt = pt->parent;
                    grand_parent_pt = pt->parent->parent;
                    if (parent_pt == grand_parent_pt->left)
                    {
                        Node *uncle_pt = grand_parent_pt->right;
                        if (uncle_pt != NULL && uncle_pt->color == RED)
                        {
                            parent_pt->color = BLACK;
                            uncle_pt->color = BLACK;
                            grand_parent_pt->color = RED;
                            pt = grand_parent_pt;
                        }
                        else
                        {
                            if (pt == parent_pt->right)
                            {
                                rotateLeft(root, parent_pt);
                                pt = parent_pt;
                                parent_pt = pt->parent;
                            }
                            rotateRight(root, grand_parent_pt);
                            std::swap(parent_pt->color, grand_parent_pt->color);
                            pt = parent_pt;
                        }
                    }
                    else
                    {
                        Node *uncle_pt = grand_parent_pt->left;
                        if (uncle_pt != NULL && uncle_pt->color == RED)
                        {
                            parent_pt->color = BLACK;
                            uncle_pt->color = BLACK;
                            grand_parent_pt->color = RED;
                            pt = grand_parent_pt;
                        }
                        else 
                        {
                            if (pt == parent_pt->left)
                            {
                                rotateRight(root, parent_pt);
                                pt = parent_pt;
                                parent_pt = pt->parent;
                            }
                            rotateLeft(root, grand_parent_pt);
                            std::swap(parent_pt->color, grand_parent_pt->color);
                            pt = parent_pt;
                        }
                    }
                }
                root->color = BLACK;
            }
            // Util print the tree
            void print2DUtil(Node* root, int space)
            {
                const char* my_color[] = {"RED", "BLACK"};

                int COUNT = 10;
                // Base case
                if (root == NULL)
                    return;
            
                // Increase distance between levels
                space += COUNT;
            
                // Process right child first
                print2DUtil(root->right, space);
            
                // Print current node after space
                // count
                std::cout << std::endl;
                for (int i = COUNT; i < space; i++)
                    std::cout << " ";
                if (root->color == 0)
                {
                    std::cout << root->value << "/";
                    std::cout << red << my_color[root->color] << nocolor << "\n";
                }
                else
                {
                    std::cout << root->value << "/";
                    std::cout << green << my_color[root->color] << nocolor <<"\n";
                }
            
                // Process left child
                print2DUtil(root->left, space);
            }
            
            // Wrapper over print2DUtil()
            void print2D(void)
            {
                // Pass initial space count as 0
                print2DUtil(_root, 0);
            }

            /* public */

            Node*   getRoot(void) const
            {
                return (_root);
            }
        protected:

            Node* BSTInsert(Node* root, Node* pt)
            {
                // If the tree is empty, return a new node
                if (root == NULL)
                    return (pt);

                // Otherwise, recur down the tree
                if (pt->value < root->value)
                {
                    root->left = BSTInsert(root->left, pt);
                    root->left->parent = root;
                }
                else if (pt->value > root->value)
                {
                    root->right = BSTInsert(root->right, pt);
                    root->right->parent = root;
                }
                return root;
            }


            /* 
            ! *& change reference to the pointer value
            pointer's value is changed to point to the other memory.
            */

        private:
            Node                    *_root;
            // node_pointer            _last_node; // ? need it to allocate - construct??
            std::allocator<Node>    _alloc_node;
    };







}; /* namespace ft */





#endif /* red_black_tree.hpp */