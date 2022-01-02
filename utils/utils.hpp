#ifndef UTILS_HPP
#define UTILS_HPP

#include "../vector/vector.hpp"

namespace ft
{
    template <class InputIterator1, class InputIterator2>
    bool    equal(InputIterator1 first1, InputIterator1 last1,
                    InputIterator2 first2)
    {
        while (first1 != last1)
        {
            if (!(*first1 == *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

    template <class InputIterator1, class InputIterator2>
    bool    lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                        InputIterator2 first2, InputIterator2 last2)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || *first2 < *first1)
                return false;
            else if( *first1 < *first2)
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }

    template<bool B, class T = void>
    struct enable_if 
    {};
    
    template<class T>
    struct enable_if<true, T>
    { typedef T type; };

    template <bool is_integral, typename T>
    struct is_integral_res {
        typedef T type;
        static const bool value = is_integral;
        };

    template <typename>
    struct is_integral_type : public is_integral_res<false, bool> {};

    /* @brief is_integral_type for bool. "value is true".*/
    template <>
    struct is_integral_type<bool> : public is_integral_res<true, bool> {};

    /* @brief is_integral_type for char. "value is true".*/
    template <>
    struct is_integral_type<char> : public is_integral_res<true, char> {};

    /* @brief is_integral_type for signed char. "value is true".*/
    template <>
    struct is_integral_type<signed char> : public is_integral_res<true, signed char> {};

    /* @brief is_integral_type for short int. "value is true".*/
    template <>
    struct is_integral_type<short int> : public is_integral_res<true, short int> {};
    
    /* @brief is_integral_type for int. "value is true".*/
    template <>
    struct is_integral_type<int> : public is_integral_res<true, int> {};

    /* @brief is_integral_type for long int. "value is true".*/
    template <>
    struct is_integral_type<long int> : public is_integral_res<true, long int> {};

    /* @brief is_integral_type for long long int. "value is true".*/
    template <>
    struct is_integral_type<long long int> : public is_integral_res<true, long long int> {};

    /* @brief is_integral_type for unsigned char. "value is true".*/
    template <>
    struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char> {};

    /* @brief is_integral_type for unsigned short int. "value is true".*/
    template <>
    struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int> {};

    /* @brief is_integral_type for unsigned int. "value is true".*/
    template <>
    struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int> {};

    /* @brief is_integral_type for unsigned long int. "value is true".*/
    template <>
    struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int> {};
    
    /* @brief is_integral_type for unsigned long long int. "value is true".*/
    template <>
    struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};

    template< class T >
    struct is_integral: public is_integral_type<T>
    {};

// todo: iterator 
    class random_access_iterator_tag
    {};

    template <class Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::difference_type      difference_type;
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
        typedef typename Iterator::iterator_category    iterator_category;
    }; /* struct iterator_traits */

    template <class T>
    struct iterator_traits<T*>
    {
        typedef std::ptrdiff_t                          difference_type;
        typedef T                                       value_type;
        typedef T*                                      pointer;
        typedef T&                                      reference;
        typedef ft::random_access_iterator_tag          iterator_category;
    };

    template <class T>
    class iterator_traits<const T*>
    {
        public:
            typedef std::ptrdiff_t                          difference_type;
            typedef T                                       value_type;
            typedef const T*                                pointer;
            typedef const T&                                reference;
            typedef ft::random_access_iterator_tag          iterator_category;
    };

    template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
    class iterator
    {
        public:
            typedef T           value_type;
            typedef Distance    difference_type;
            typedef Pointer     pointer;
            typedef Reference   reference;
            typedef Category    iterator_category;

    };
} /* namespace ft */

#endif