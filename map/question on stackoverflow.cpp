namespace ft
{
    template <  class Key, class T >
    class map
    {
        public:

            typedef Key                    key_type;
            typedef T                      mapped_type;
            typedef ft::pair<Key, T>       value_type;
            typedef typename ft::RedBlackTree<value_type>::iterator   iterator;
            
            void        erase(iterator first, iterator last)
                {
                    while (first != last)
                        _rbt.deleteValue(*first);;
                }

        private:
            ft::RedBlackTree<value_type>   _rbt;
    };


    template <  class T, class Node = ft::treeNode<T> >
    class RedBlackTree
    {
        public:
            typedef T                       value_type;
            typedef ft::treeIterator<Node>  iterator;

            void    deleteValue(value_type n) 
            {
                // Tree is empty
                if (_root == NULL)
                    return;
            
                Node* v = searchByKey(n); // search Node by key value
                if (v == NULL) 
                    return;
                deleteNode(v);
                _tree_size--;
            }

            void    deleteNode(Node *v) 
            {
                // Delete node v
                _alloc_node.destroy(v);
                _alloc_node.deallocate(v, 1);

                //  Fix violation to keep Red Black Tree form. 
                // At the end _root always has RBT form.
                fixDeleteViolation();
            }
        
        private:
            Node*                   _root;
            std::allocator<Node>    _alloc_node;;
    };

    template <typename T>
    class treeIterator: ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        public:
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference             reference;

            reference operator*() const
            {
                return (this->_node->value);
            }

            bool operator==(const treeIterator& rhs) // overload at treeNode
            {
                return (this->_node == rhs._node);
            }

            bool operator!=(const treeIterator& rhs)
            {
                return (this->_node != rhs._node);
            }
        private:
           T*       _node;
    };

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

            bool operator==(const treeNode& other)
            {
                if (value == other.value)
                    return (true);
                return (false);
            }
   };
}

int main()
{
    ft::map<char,int> mymap;
    ft::map<char,int>::iterator it;

    // insert some values:
    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    mymap['d']=40;
    mymap['e']=50;
    mymap['f']=60;

    mymap.print2D();

    it = mymap.find ('b');
    mymap.erase ( it, mymap.end() );    // erasing by range

    mymap.print2D();
    
    return (0);
}