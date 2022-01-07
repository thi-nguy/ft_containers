#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <memory>  //std::allocator
#include <utility> //std::swap

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
                color()
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
                // _alloc_node.construct(_root, Node(_root, _root, _root)); // construct 03 nodes: parent, left, right of the new node
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
            void    insert(const value_type &val)
            {
                Node    *pt = _alloc_node.allocate(1);
                _alloc_node.construct(pt, Node(val));
                
                // Do a normal BST insert
                _root = BSTInsert (_root, pt);
                // Fix Red Black Tree violation
                fixViolation(_root, pt);
                std::cout << "Insert function done\n";
            }













        // Util print the tree
            void print2DUtil(Node* root, int space)
            {
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
                std::cout << root->value<<"\n";
            
                // Process left child
                print2DUtil(root->left, space);
            }
            
            // Wrapper over print2DUtil()
            void print2D(void)
            {
                // Pass initial space count as 0
                print2DUtil(_root, 0);
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

            void    fixViolation(Node *&root, Node *&pt)
            {
                Node *parent_pt = NULL;
                Node *grand_parent_pt = NULL;
            
                while ((pt != root) && (pt->color != BLACK) &&
                    (pt->parent->color == RED))
                {
            
                    parent_pt = pt->parent;
                    grand_parent_pt = pt->parent->parent;
                    if (grand_parent_pt == NULL)
                        return ;
                    /*  Case : A
                        Parent of pt is left child
                        of Grand-parent of pt */
                    if (parent_pt == grand_parent_pt->left)
                    {
            
                        Node *uncle_pt = grand_parent_pt->right;
            
                        /* Case : 1
                        The uncle of pt is also red
                        Only Recoloring required */
                        if (uncle_pt != NULL && uncle_pt->color ==
                                                            RED)
                        {
                            grand_parent_pt->color = RED;
                            parent_pt->color = BLACK;
                            uncle_pt->color = BLACK;
                            pt = grand_parent_pt;
                        }
            
                        else
                        {
                            /* Case : 2
                            pt is right child of its parent
                            Left-rotation required */
                            if (pt == parent_pt->right)
                            {
                                rotateLeft(root, parent_pt);
                                pt = parent_pt;
                                parent_pt = pt->parent;
                            }
            
                            /* Case : 3
                            pt is left child of its parent
                            Right-rotation required */
                            rotateRight(root, grand_parent_pt);
                            std::swap(parent_pt->color,
                                    grand_parent_pt->color);
                            pt = parent_pt;
                        }
                    }
            
                    /* Case : B
                    Parent of pt is right child
                    of Grand-parent of pt */
                    else
                    {
                        Node *uncle_pt = NULL;
                        if (grand_parent_pt != NULL)
                            uncle_pt = grand_parent_pt->left;
            
                        /*  Case : 1
                            The uncle of pt is also red
                            Only Recoloring required */
                        if ((uncle_pt != NULL) && (uncle_pt->color == RED))
                        {
                            grand_parent_pt->color = RED;
                            parent_pt->color = BLACK;
                            uncle_pt->color = BLACK;
                            pt = grand_parent_pt;
                        }
                        else
                        {
                            /* Case : 2
                            pt is left child of its parent
                            Right-rotation required */
                            if (pt == parent_pt->left)
                            {
                                rotateRight(root, parent_pt);
                                pt = parent_pt;
                                parent_pt = pt->parent;
                            }
            
                            /* Case : 3
                            pt is right child of its parent
                            Left-rotation required */
                            rotateLeft(root, grand_parent_pt);
                            std::swap(parent_pt->color,
                                    grand_parent_pt->color);
                            pt = parent_pt;
                        }
                    }
                }
            }



        private:
            Node                    *_root;
            // node_pointer            _last_node; // ? need it to allocate - construct??
            std::allocator<Node>    _alloc_node;
    };







}; /* namespace ft */





#endif /* red_black_tree.hpp */