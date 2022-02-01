#ifndef MAP_HPP
#define MAP_HPP

#include <memory>       // std::allocator
// #include <utility>   // ft::pair
#include <cstddef>      // ptrdiff_t
#include <functional>   //std::less, std::binary_function
// #include <iterator>     //std::distance
#include "red_black_tree.hpp"
#include "pair.hpp"
#include "tree_iterator.hpp"
#include "../vector/vector_reverse_iterator.hpp"
#include "../utils/utils.hpp"
#include "../utils/distance_iterator.hpp"

namespace ft
{
    template <  class Key, 
                class T, 
                class Compare = std::less<Key>,
                class Alloc = std::allocator<ft::pair<const Key, T> > 
            >
    class map
    {
        public:

            // Todo: Member types:
            // value_type = ft::pair<key, T>
            typedef Key                                                             key_type;
            typedef T                                                               mapped_type;
            typedef ft::pair<Key, T>                                                value_type;
            typedef Compare                                                         key_compare;
            typedef Alloc                                                           allocator_type;
            typedef typename allocator_type::reference                              reference;
            typedef typename allocator_type::const_reference                        const_reference;
            typedef typename allocator_type::pointer                                pointer;
            typedef typename allocator_type::const_pointer                          const_pointer;
            typedef typename ft::RedBlackTree<value_type>::iterator                 iterator;
            typedef typename ft::RedBlackTree<value_type>::const_iterator           const_iterator;
            typedef typename ft::VectorReverseIterator<iterator>         reverse_iterator;
            typedef typename ft::VectorReverseIterator<const_iterator>   const_reverse_iterator;
            typedef typename std::ptrdiff_t                                         difference_type;
            typedef typename allocator_type::size_type                              size_type;
            
            // Todo: Member classes
            class value_compare: std::binary_function<value_type, value_type, bool>
            {
                friend class map<Key, T>;
                protected:
                    Compare comp;
                    value_compare (Compare c): comp(c) {}// constructed with map's comparison object
                public:
                    typedef bool    result_type;
                    typedef value_type  first_argument_type;
                    typedef value_type  second_argument_type;


                    bool operator() (const value_type& x, const value_type& y) const
                    {
                        return (comp(x.first, y.first));
                    }
            };

            // Todo: Constructor
            explicit map (
                const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type()
            )
            :
                _alloc(alloc),
                _compare(comp),
                _rbt()
            {
                // std::cout << "Map Empty constructor called\n";
            }

            template < class InputIterator>
            map (
                InputIterator first,
                InputIterator last,
                const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type(),
                typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL
            )
            :
                _alloc(alloc),
                _compare(comp),
                _rbt()
            {
                this->insert(first, last);
                // std::cout << "Range constructor called\n";
            }

            map(const map& x)
            {
                *this = x;
                // std::cout << "Copy constructor called\n";
            }

            map& operator= (const map& x)
			{
				if (this != &x)
                {
                    _alloc = x._alloc;
                    _compare = x._compare;
                    _rbt = x._rbt;
                    // ! do something
                    // this->clear();
                    // this->insert(x.begin(), x.end());
                }
				return (*this);
			}

            ~map(void)
            {
                // std::cout << "Map Deconstructor called\n";

            }
            // Todo: Capacity

            bool empty() const
            {
                return (_rbt.getRoot() == NULL);
            }
            
            size_type   size() const
            {
                return (_rbt.getSize());
            }
            
            iterator    begin()
            {
                return (iterator(_rbt.getFirstNode()));
            }

            const_iterator begin() const
            {
                return (const_iterator(_rbt.getFirstNode()));
            }

            iterator    end()
            {
                iterator    last_it = iterator(_rbt.getLastNode());
                ++last_it;
                return (last_it);
            }

            const_iterator  end() const
            {
                const_iterator    last_it = const_iterator(_rbt.getLastNode());
                return (++last_it);

            }

            reverse_iterator rbegin()
			{ 
                iterator it_last = this->end();
                it_last++;
                return (reverse_iterator(it_last)); 
            }

            const_reverse_iterator rbegin() const
			{ 
                const_iterator it_last = this->end();
                it_last++;
                return (const_reverse_iterator(it_last)); 
            }

            reverse_iterator rend()
			{ 
                iterator it_begin = this->begin();
                it_begin--;
                return (reverse_iterator(it_begin)); 
            }

            const_reverse_iterator rend() const
			{ 
                
                const_iterator it_begin = this->begin();
                it_begin--;
                return (const_reverse_iterator(it_begin)); 
            }
            
            // ! insert
            // single element (1)	
            ft::pair<iterator, bool> insert (const value_type& val)
            {
                return (_rbt.insertValue(val));
            }
            // with hint (2)	
            iterator insert (iterator position, const value_type& val)
            {
                (void)position;
                return (_rbt.insertValue(val).first);
            }

            // range (3)	
            template <class InputIterator>
            void insert (
                InputIterator first, 
                InputIterator last,
                typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL
                )
            {
                // difference_type d = ft:distance(first, last);
                iterator it, next;
                it = first;
                next = it;
                next++;
                while (it != last)
                {
                    this->insert(*it); // operator * cua treeIterator
                    it =next; // operator ++ cuar treeIterator
                    next++;
                }
            }
            
            iterator    find(const key_type& k)
            {
                
                iterator ret = iterator(_rbt.searchByKey(ft::make_pair(k, mapped_type())));
                return(ret);
            }

            const_iterator  find(const key_type& k) const
            {
                const_iterator ret = const_iterator(_rbt.searchByKey(ft::make_pair(k, mapped_type())));
                return(ret);
            }

            key_compare     key_comp() const
            {
                return (key_compare());
            }

            value_compare   value_comp() const
            {
                return (value_compare(key_compare()));
            }


            // * [] Ok
            mapped_type&    operator[] (const key_type& k)
            {
                iterator tmp = this->find(k);
                if (tmp == NULL)
                {
                    this->insert(ft::make_pair(k, mapped_type()));
                    tmp = this->find(k);
                }
                return ((*tmp).second);
            }

            // ! max_size
            size_type   max_size() const
            {
                return (_rbt.getMaxSize());
            }

            // ! erase - bug
            void    erase(iterator position)
            {
                _rbt.deleteValue(*position);
            }

            size_type   erase(const key_type& k)
            {
                if (this->find(k) == this->end())
                    return (0);
                this->erase(this->find(k));
                return (1);
            }

            void        erase(iterator first, iterator last)
            {
                iterator it, next;
                it = first;
                next = it;
                next++;
                while (it != last)
                {
                    this->erase(it);
                    it = next;
                    next++;
                }
            }

            // ! clear - bug
            void        clear()
            {
                this->erase(this->begin(), this->end());
            }

            // * count Ok
            size_type count (const key_type& k) const
            {
                ft::treeNode<value_type> *myNode = _rbt.searchByKey(ft::make_pair(k, mapped_type()));
                if (myNode == NULL)
                    return (0);
                return (1);
            }

            // ! lower_bound
            // iterator    lower_bound(const key_type& k)
            // {


            // }

            // ! swap
            void    swap(map& x)
            {
                _rbt.swap(x._rbt);
            }



            




            

            ft::RedBlackTree<value_type> get_tree() const
            {
                return (_rbt);
            }

        private:
            allocator_type                 _alloc;
            key_compare                    _compare;
            ft::RedBlackTree<value_type>   _rbt;

    }; /* class map */

}; /* namespace ft */

#endif /* map.hpp */