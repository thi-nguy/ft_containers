#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft
{
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

} /* namespace ft */

#endif