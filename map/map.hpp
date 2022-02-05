#ifndef MAP_HPP
#define MAP_HPP

#include <memory>       // std::allocator
// #include <utility>   // ft::pair
#include <cstddef>      // ptrdiff_t
#include <functional>   //std::less, std::binary_function
// #include <iterator>     //std::distance
#include <exception> //std::exceptioin
#include "red_black_tree.hpp"
#include "pair.hpp"
#include "tree_iterator.hpp"
#include "tree_reverse_iterator.hpp"
#include "../utils/utils.hpp"
#include "../utils/distance_iterator.hpp"
#include "../utils/equal.hpp"
#include "../utils/lexicographical_compare.hpp"

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
            typedef typename ft::treeReverseIterator<iterator>         reverse_iterator;
            typedef typename ft::treeReverseIterator<const_iterator>   const_reverse_iterator;
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
                    this->clear();
                    this->insert(x.begin(), x.end());
                    _alloc = x._alloc;
                    _compare = x._compare;
                }
				return (*this);
			}

            virtual ~map(void)
            {
                // this->clear();
                
                size_type n = this->size();
                if (n >= 0)
                {
                    // std::cout << "size is: " << n << "\n";
                    while (n)
                    {
                        this->erase(this->begin());
                        n--;
                    }

                }
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
                last_it++;
                return (last_it);
            }

            const_iterator  end() const
            {
                const_iterator    last_it = const_iterator(_rbt.getLastNode());
                last_it++;
                return (last_it);
            }

            reverse_iterator rbegin()
			{ 
                iterator it_last = this->_rbt.getLastNode();
                return (reverse_iterator(it_last)); 
            }

            const_reverse_iterator rbegin() const
			{ 
                const_iterator it_last = this->_rbt.getLastNode();
                return (const_reverse_iterator(it_last)); 
            }

            reverse_iterator rend()
			{ 
                iterator rit_begin = this->_rbt.getFirstNode();
                return (reverse_iterator(--rit_begin)); 
            }

            const_reverse_iterator rend() const
			{ 
                
                const_iterator rit_begin = this->_rbt.getFirstNode();
                return (const_reverse_iterator(--rit_begin)); 
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
                // difference_type d = ft::distance(first, last);
                // while (d--)
                //     this->insert(*(first++));
                // iterator it, next;
                // it = first;
                // next = it;
                // next++;
                // while (it != last)
                // {
                //     this->insert(*it); // operator * cua treeIterator
                //     it = next; // operator ++ cuar treeIterator
                //     next++;
                // }
                while (first != last)
                {
                    this->insert(*(first++));
                }
            }
            

            key_compare     key_comp() const
            {
                return (key_compare());
            }

            value_compare   value_comp() const
            {
                return (value_compare(key_compare()));
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
                // iterator it, next;
                // it = first;
                // next = it;
                // next++;
                // while (it != last)
                // {
                //     this->erase(it);
                //     it = next;
                //     next++;
                // }
                while (first != last)
                    this->erase(first++);
            }

            // ! clear
            void        clear()
            {
                size_type n = this->size();
                while (n)
                {
                    this->erase(this->begin());
                    n--;
                }
            }

            // * count Ok
            size_type count (const key_type& k) const
            {
                ft::treeNode<value_type> *myNode = _rbt.searchByKey(ft::make_pair(k, mapped_type()));
                if (myNode == NULL)
                    return (0);
                return (1);
            }

            // ! swap
            void    swap(map& x)
            {
                allocator_type temp_alloc_type = this->_alloc;
                key_compare temp_key_compare = this->_compare;
                // ft::RedBlackTree<value_type> temp_rbt = this->_rbt;

                this->_alloc = x._alloc;
                this->_compare = x._compare;
                // this->_rbt = x._rbt;

                x._alloc = temp_alloc_type;
                x._compare = temp_key_compare;
                _rbt.swap(x._rbt);
                // x._rbt = temp_rbt;
            }

            iterator    lower_bound(const key_type& k)
            {
                iterator it = this->find(k);
                return (it);
            }

            const_iterator  lower_bound(const key_type& k) const
            {
                const_iterator it = this->find(k);
                return (it);
            }

            iterator    upper_bound(const key_type& k)
            {
                iterator it = this->find(k);
                it++;
                return (it);
            }

            const_iterator  upper_bound(const key_type& k) const
            {
                const_iterator it = this->find(k);
                it++;
                return (it);
            }

            pair<const_iterator, const_iterator> equal_range(const key_type& k) const
            {
                const_iterator lower = this->lower_bound(k);
                const_iterator upper = this->upper_bound(k);
                return (ft::make_pair(lower, upper));
            }

            pair<iterator, iterator> equal_range(const key_type& k)
            {
                iterator lower = this->lower_bound(k);
                iterator upper = this->upper_bound(k);
                return (ft::make_pair(lower, upper));
            }

            allocator_type  get_allocator() const
            {
                return (_alloc);
            }


        private:
            allocator_type                 _alloc;
            key_compare                    _compare;
            ft::RedBlackTree<value_type>   _rbt;

            ft::RedBlackTree<value_type> get_tree() const
            {
                return (_rbt);
            }

    }; /* class map */

template <class Key, class T, class Compare, class Alloc>
void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
{
    x.swap(y);
}

template <class Key, class T, class Compare, class Alloc>
bool operator== ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs )
{
    return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class Key, class T, class Compare, class Alloc>
bool operator!= ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs )
{
    return (!(lhs == rhs));
}

template <class Key, class T, class Compare, class Alloc>
bool operator<  ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs )
{
    return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class Key, class T, class Compare, class Alloc>
bool operator>  ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs )
{
    return (rhs < lhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator<= ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs )
{
    return (!(rhs < lhs));
}

template <class Key, class T, class Compare, class Alloc>
bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, 
                    const map<Key,T,Compare,Alloc>& rhs )
{
    return (!(lhs < rhs));
}

}; /* namespace ft */

#endif /* map.hpp */