#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <memory>  //std::allocator
#include <utility> //std::
#include "treeNode.hpp"
#include "tree_iterator.hpp"
#include "pair.hpp"

#define red		"\033[91m"
#define green   "\033[92m"
#define nocolor	"\033[0m"

namespace ft
{
    template <  class T, class Node = ft::treeNode<T>,
                class Type_Alloc = std::allocator<T>,
                class Node_Alloc = std::allocator<Node>
            >
    class RedBlackTree
    {
        public:
            //value_type / T o day la ft::pair
            //Node la ft::treeNode< ft::pair >
            typedef T                       value_type;
            typedef size_t                  size_type;
            typedef ft::treeIterator<Node>   iterator;

            // Todo: iterator and other typedef

            // ! Canonical form

            // Todo: Do not have the form RedBlackTree my_tree(val), instead we use my_tree.insert(val)

            RedBlackTree()
            :   _tree_size(0),
                _alloc_node(Node_Alloc()),
                _root(NULL)
            {
                // _root = _alloc_node.allocate(1);
                // _alloc_node.construct(_root, Node()); // call constructor of treeNode
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
                    this->_tree_size = rhs._tree_size;
                }
                return (*this);
            }

            ~RedBlackTree()
            {
                // deleteTree(_root); // Tam xoa di de dung mymap.get_tree.print2D
                // std::cout << "Tree Deconstructor called\n";

            }

            void    swap(RedBlackTree& x)
            {
                if (&x == this)
                    return ;
                
                size_type               tree_size_tmp;
                std::allocator<Node>    alloc_tmp;
                Node*                   root_tmp;

                tree_size_tmp = this->_tree_size;
                alloc_tmp = this->_alloc_node;
                root_tmp = this->_root;

                this->_tree_size = x._tree_size;
                this->_alloc_node = x._alloc_node;
                this->_root = x._root;

                x._tree_size = tree_size_tmp;
                x._alloc_node = alloc_tmp;
                x._root = root_tmp;
            }

            // * work ok
            Node*   searchByKey(value_type val) const //value_type = ft::pair
            {
                Node*   node = _root; // ! bug here, _root is weird
                Node*   last_node = this->getLastNode();

                if (last_node == NULL)
                    return (node);
                while (node != last_node)
                {
                    if (node->value.first == val.first)
                        return (node);
                    if (node->value.first < val.first)
                        node = node->right;
                    else
                        node = node->left;
                }
                if (node->value.first == val.first)
                    return (node);
                return (NULL);
            }

            // ! Work well
            ft::pair<iterator, bool>    insertValue(const value_type &val)
            {
                Node    *tmp = searchByKey(val);
                if (tmp == NULL)
                {
                    Node    *pt = _alloc_node.allocate(1);
                    _alloc_node.construct(pt, Node(val));
                    _root = BST_Insert(_root, pt);
                    _tree_size++;
                    fixInsertViolation(_root, pt);
                    return (ft::make_pair(iterator(pt), true));
                }
                return (ft::make_pair(iterator(tmp), false));
            }

            void    deleteValue(value_type n) 
            {
                // Tree is empty
                if (_root == NULL)
                    return;
            
                Node* v = searchByKey(n);
                if (v == NULL) 
                {
                    // std::cout << "No node found to delete with value:" << n << std::endl;
                    return;
                }
                deleteNode(v); // bug in here, v van o cho cu, nhung noi dung da bi xoa
                _tree_size--;
            }
            
            void    print2D()
            {
                print2DUtil(_root, 0);
            }

            Node*   getRoot() const
            {
                return (_root);
            }

            size_type   getSize() const
            {
                return (_tree_size);
            }
            
            Node*   getFirstNode() const
            {
                if (_root == NULL)
                    return (NULL);
                Node* tmp = _root;
                while (tmp->left != NULL)
                {
                    tmp = tmp->left;
                }
                return (tmp);
            }

            Node*   getLastNode() const
            {
                if (_root == NULL)
                    return (NULL);
                Node* tmp = _root;
                while (tmp->right != NULL)
                    tmp = tmp->right;
                return (tmp);
            }

            size_type   getMaxSize() const
            {
                return (Node_Alloc().max_size());
            }
            /* public */

        private:

            void    deleteTree(Node* node)
            {
                if(node == NULL)
                    return ;
                deleteTree(node->left);
                deleteTree(node->right);
                _alloc_node.destroy(node);
                _alloc_node.deallocate(node, 1);
            }

            // ! Xoa node b, truoc khi xoa thi point node b vao node c
            void    deleteNode(Node *v) // ! bug here, in map.erase, cannot delete last element
            {
                Node *u = BST_Get_Replaced_Node(v);
                
                bool uvBlack = ((u == NULL || u->color == BLACK) && (v->color == BLACK)); // True when u and v are both black
                Node *parent = v->parent;
            
                if (u == NULL) // v is leaf
                {
                    if (v == _root)
                    {
                        // v is root, making root null
                        _root = NULL;
                    } 
                    else
                    {
                        if (uvBlack) // u and v both black, v is leaf, fix double black at v
                            fix_Delete_Node_Violation(v);
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
                        _alloc_node.destroy(v);
                        _alloc_node.deallocate(v, 1);
                        u->parent = parent;
                        if (uvBlack) 
                            fix_Delete_Node_Violation(u); // u and v both black, fix double black at u
                        else 
                            u->color = BLACK; // u or v red, color u black
                    }
                    return;
                }
                swapNodeValues(u, v); // v has 2 children, swap values with successor and recurse
                deleteNode(u);
            }

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

            void    fix_Delete_Node_Violation(Node *x) 
            {
                if (x == _root)
                // Reached root
                return;
            
                Node *sibling = x->sibling(), *parent = x->parent;
                if (sibling == NULL) {
                // No sibiling, double black pushed up
                fix_Delete_Node_Violation(parent);
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
                    fix_Delete_Node_Violation(x);
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
                        fix_Delete_Node_Violation(parent);
                    else
                        parent->color = BLACK;
                    }
                }
                }
            }

            // deletes the given node

            Node*   BST_Delete(Node* root, Node* pt)
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
                }
                return (root);
            }

            Node*   BST_Insert(Node* root, Node* pt)
            {
                // If the tree is empty, return a new node
                if (root == NULL)
                    return (pt);

                // Otherwise, recur down the tree
                if (pt->value < root->value)
                {
                    root->left = BST_Insert(root->left, pt);
                    root->left->parent = root;
                }
                else if (pt->value > root->value)
                {
                    root->right = BST_Insert(root->right, pt);
                    root->right->parent = root;
                }
                return root;
            }

            // find node that replaces a deleted node in BST
            Node*   BST_Get_Replaced_Node(Node *x) 
            {
                // when node have 2 children
                if (x->left != NULL && x->right != NULL)
                    return (successor(x->right));
            
                // when leaf
                if (x->left == NULL && x->right == NULL)
                    return NULL;
            
                // when single child
                if (x->left != NULL)
                    return x->left;
                else
                    return x->right;
            }

            void    swapNodeValues(Node *u, Node *v) 
            {
                value_type value_temp;
                Node* parent_tmp;
                Node* left_tmp;
                Node* right_tmp;
                bool color_tmp;

                value_temp = u->value;
                u->value= v->value;
                v->value= value_temp;

                parent_tmp = u->parent;
                u->parent = v->parent;
                v->parent = parent_tmp;

                left_tmp = u->left;
                u->left = v->left;
                v->left = left_tmp;

                right_tmp = u->right;
                u->right = v->right;
                v->right = right_tmp;

                color_tmp = u->color;
                u->color = v->color;
                v->color = color_tmp;
            }

            void    fixInsertViolation(Node *&root, Node *&pt)
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
            void    print2DUtil(Node* root, int space)
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
                    std::cout << root->value.first << "=>" << root->value.second << " /";
                    std::cout << red << my_color[root->color] << nocolor << "\n";
                }
                else
                {
                    std::cout << root->value.first << "=>" << root->value.second << " /";
                    std::cout << green << my_color[root->color] << nocolor <<"\n";
                }
            
                // Process left child
                print2DUtil(root->left, space);
            }

            size_type               _tree_size;
            std::allocator<Node>    _alloc_node;
            Node*                   _root;
    }; /* class Red Black Tree */

}; /* namespace ft */





#endif /* red_black_tree.hpp */