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
                // std::cout << "Tree constructor called\n";
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
                // std::cout << "Tree deconstructor called\n";
            }

            // ! Member functions

            void    rotateLeft(Node *&x)
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
                        _root = y;
                    else if (x == x->parent->left)
                        x->parent->left = y;
                    else
                        x->parent->right = y;
                    // put x on y's left
                    y->left = x;
                    x->parent = y;
                }
            }

            void    rotateRight(Node *&x)
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
                    _root = y;
                else if (x == x->parent->left)
                    x->parent->left = y;
                else
                    x->parent->right = y;
                // put x on y's left
                y->right = x;
                x->parent = y;
            }

            // ! Todo : Search & Delete

            // searches for given value
            // if found returns the node (used for delete)
            // else returns the last node while traversing (used in insert)
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

            void fixDoubleBlack(Node *x) 
            {
                if (x == _root)
                // Reached root
                return;
            
                Node *sibling = x->sibling(), *parent = x->parent;
                if (sibling == NULL) {
                // No sibiling, double black pushed up
                fixDoubleBlack(parent);
                } else {
                if (sibling->color == RED) {
                    // Sibling red
                    parent->color = RED;
                    sibling->color = BLACK;
                    if (sibling->isOnLeft()) {
                    // left case
                    rotateRight(parent);
                    } else {
                    // right case
                    rotateLeft(parent);
                    }
                    fixDoubleBlack(x);
                } else {
                    // Sibling black
                    if (sibling->hasRedChild()) {
                    // at least 1 red children
                    if (sibling->left != NULL and sibling->left->color == RED) {
                        if (sibling->isOnLeft()) {
                        // left left
                        sibling->left->color = sibling->color;
                        sibling->color = parent->color;
                        rotateRight(parent);
                        } else {
                        // right left
                        sibling->left->color = parent->color;
                        rotateRight(sibling);
                        rotateLeft(parent);
                        }
                    } else {
                        if (sibling->isOnLeft()) {
                        // left right
                        sibling->right->color = parent->color;
                        rotateLeft(sibling);
                        rotateRight(parent);
                        } else {
                        // right right
                        sibling->right->color = sibling->color;
                        sibling->color = parent->color;
                        rotateLeft(parent);
                        }
                    }
                    parent->color = BLACK;
                    } else {
                    // 2 black children
                    sibling->color = RED;
                    if (parent->color == BLACK)
                        fixDoubleBlack(parent);
                    else
                        parent->color = BLACK;
                    }
                }
                }
            }

            // deletes the given node
            void deleteNode(Node *v) 
            {
                Node *u = BSTreplace(v);
                
                bool uvBlack = ((u == NULL || u->color == BLACK) && (v->color == BLACK)); // True when u and v are both black
                Node *parent = v->parent;
            
                if (u == NULL) 
                {
                    // u is NULL therefore v is leaf
                    if (v == _root)
                    {
                        // v is root, making root null
                        _root = NULL;
                    } 
                    else
                    {
                        if (uvBlack) // u and v both black, v is leaf, fix double black at v
                            fixDoubleBlack(v);
                        else // u or v is red
                            if (v->sibling() != NULL) // sibling is not null, make it red"
                                v->sibling()->color = RED;
                        // delete v from the tree
                        if (v->isOnLeft()) 
                            parent->left = NULL;
                        else
                            parent->right = NULL;
                    }
                    _alloc_node.destroy(v);
                    _alloc_node.deallocate(v, 1);
                    return;
                }
                if (v->left == NULL || v->right == NULL) // v has 1 child
                {
                    
                    if (v == _root) // v is root, assign the value of u to v, and delete u
                    {
                        v->value = u->value;
                        v->left = v->right = NULL;
                        _alloc_node.destroy(u);
                        _alloc_node.deallocate(u, 1);
                    } 
                    else 
                    {
                        // Detach v from tree and move u up
                        if (v->isOnLeft()) 
                            parent->left = u;
                        else 
                            parent->right = u;
                        delete v;
                        u->parent = parent;
                        if (uvBlack) 
                            fixDoubleBlack(u); // u and v both black, fix double black at u
                        else 
                            u->color = BLACK; // u or v red, color u black
                    }
                    return;
                }
                swapValues(u, v); // v has 2 children, swap values with successor and recurse
                deleteNode(u);
            }

             void deleteValue(value_type n) 
             {
                // Tree is empty
                if (_root == NULL)
                    return;
            
                Node *v = searchValue(_root, n);
                if (v == NULL) 
                {
                    std::cout << "No node found to delete with value:" << n << std::endl;
                    return;
                }
                deleteNode(v);
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
                                rotateLeft(parent_pt);
                                pt = parent_pt;
                                parent_pt = pt->parent;
                            }
                            rotateRight(grand_parent_pt);
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
                                rotateRight(parent_pt);
                                pt = parent_pt;
                                parent_pt = pt->parent;
                            }
                            rotateLeft(grand_parent_pt);
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

            Node*   BSTDelete(Node* root, Node* pt)
            {
                if (root == NULL || pt == NULL)
                    return (root);
                if (pt->left == NULL && pt->right == NULL)
                {
                    if (pt->parent->left == pt)
                        pt->parent->left = NULL;
                    else
                        pt->parent->right = NULL;
                    _alloc_node.destroy(pt);
                    _alloc_node.deallocate(pt, 1);
                    // pt = NULL;
                }
                return (root);
            }

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

            // find node that replaces a deleted node in BST
            Node *BSTreplace(Node *x) 
            {
                // when node have 2 children
                if (x->left != NULL and x->right != NULL)
                    return (successor(x->right));
            
                // when leaf
                if (x->left == NULL and x->right == NULL)
                    return NULL;
            
                // when single child
                if (x->left != NULL)
                    return x->left;
                else
                    return x->right;
            }

            void swapValues(Node *u, Node *v) 
            {
                value_type temp;
                temp = u->value;
                u->value= v->value;
                v->value= temp;
            }


            /* 
            ! *& change reference to the pointer value
            pointer's value is changed to point to the other memory.
            */

        private:
            Node                    *_root;
            // node_pointer            _last_node; // ? need it to allocate - construct??
            std::allocator<Node>    _alloc_node;
    }; /* class Red Black Tree */

}; /* namespace ft */





#endif /* red_black_tree.hpp */