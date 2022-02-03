#include <iostream>

namespace ft
{
    template <class T1, class T2>
    struct pair
    {
        public:
            typedef T1  first_type;
            typedef T2  second_type;

            first_type      first;
            second_type     second;
    }; /* struct pair */

    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return lhs.first == rhs.first && lhs.second==rhs.second; 
    }


    template <  class Key, 
                class T, 
                class Compare = std::less<Key>,
                class Alloc = std::allocator<ft::pair<const Key, T> > 
            >
    class map
    {
        public:
            // value_type = ft::pair<key, T>
            typedef Key                                                             key_type;
            typedef T                                                               mapped_type;
            typedef ft::pair<Key, T>                                                value_type;
            typedef typename ft::RedBlackTree<value_type>::iterator                 iterator;
            typedef typename ft::RedBlackTree<value_type>::const_iterator           const_iterator;

    };

template <class Key, class T, class Compare, class Alloc>
bool operator== ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs )
{
    return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}


}

int main()
{
    ft::map<char,int> foo, foo2;
    foo['a']=100;
    foo['b']=200;
    foo2['a']=100;
    foo2['b']=200;

    if (foo==foo2) std::cout << "foo and foo2 are equal\n";

}

