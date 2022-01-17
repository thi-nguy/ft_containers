#ifndef MAP_HPP
#define MAP_HPP

#include <memory>       // std::allocator
// #include <utility>      // ft::pair
#include <cstddef>      // ptrdiff_t
#include <functional>   //std::less, std::binary_function
#include "red_black_tree.hpp"
#include "pair.hpp"
#include "map_iterator.hpp"
#include "map_reverse_iterator.hpp"

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
            typedef Key                                                             key_type;
            typedef T                                                               mapped_type;
            typedef ft::pair<const Key, T>                                          value_type;
            typedef Compare                                                         key_compare;
            typedef Alloc                                                           allocator_type;
            typedef typename allocator_type::reference                              reference;
            typedef typename allocator_type::const_reference                        const_reference;
            typedef typename allocator_type::pointer                                pointer;
            typedef typename allocator_type::const_pointer                          const_pointer;
            typedef typename ft::mapIterator<value_type, Compare>::iterator         iterator;
            // typedef typename ft::mapIterator<value_type, Compare>::const_iterator   const_iterator;
            typedef typename ft::MapReverseIterator<iterator>                       reverse_iterator;
            // typedef typename ft::MapReverseIterator<const_iterator>                 const_reverse_iterator;
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
            explicit map
            (
                const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type()
            )
            :
                _alloc(alloc),
                _compare(comp),
                _rbt()
            {
                std::cout << "Empty constructor called\n";
            }

            // template < class InputIterator>
            // map 
            // (
            //     InputIterator first, 
            //     InputIterator last, 
            //     const key_compare& comp = key_compare(), 
            //     const allocator_type& alloc = allocator_type()
            // )
            // {
            //     // ! do something
            //     std::cout << "Range constructor called\n";
            // }

            map(const map& x)
            {
                *this = x;
                std::cout << "Copy constructor called\n";
            }

            map& operator= (const map& x)
			{
				if (this != &x)
                {
                    _alloc = x._alloc;
                    _compare = x._compare;
                    // ! do something
                    // this->clear();
                    // this->insert(x.begin(), x.end());
                }
				return (*this);
			}

            ~map(void)
            {
                std::cout << "Map Deconstructor called\n";

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

            // ! insert

            // single element (1)	

            ft::pair<iterator,bool> insert (const value_type& val)
            {
            }

            // with hint (2)	

            // iterator insert (iterator position, const value_type& val);

            // // range (3)	

            // template <class InputIterator>
            // void insert (InputIterator first, InputIterator last);


            




            



        private:
            allocator_type                 _alloc;
            key_compare                    _compare;
            ft::RedBlackTree<value_type>   _rbt;

    }; /* class map */

}; /* namespace ft */

#endif /* map.hpp */