#ifndef UTILS_HPP
#define UTILS_HPP

#include "../vector.hpp"

static class nullptr_t // ! Cái vẹo gì đây ??
{
    public:
    /*
        ** @brief For conversion to any type
        ** of null non-member pointer.
        */
        template < typename T>
        operator T*() const
        {
            return (0);
        }
 /*
        ** @brief For conversion to any type of null
        ** member pointer.
        */
        template < typename T, typename C >
        operator T C::*() const
        {
            return (0);
        }
    private:
        void    operator&() const; // Impossible to get address of a null pointer
}   u_nullptr = {}; // ! cái vẹo gì đây?

namespace ft
{
  
} /* namespace ft */

#endif