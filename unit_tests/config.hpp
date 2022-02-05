#ifndef CONFIG_HPP
#define CONFIG_HPP

#define VECTOR			"../../../vector/vector.hpp"
#define STACK			"../../../stack/stack.hpp"
#define MAP			  	"../../../map/map.hpp"
// #define SET			  	"../../../Set.hpp"

/* comment this to turn OFF flags (-WWW, -std=98) */
#define FLAGS   -Wall -Wextra -Werror -std=c++98

/**************************************************/
/*		Change template names of your classes	  */
/**************************************************/
#define	_vector 			ft::vector
#define	_stack	 			ft::stack
#define	_map 				ft::map
// #define	_set	 			ft::Set
#define	_is_integral 		ft::is_integral
#define	_enable_if 			ft::enable_if
#define	_pair 				ft::pair
#define	_make_pair 			ft::make_pair
#define	_lexicographical	ft::lexicographical_compare
#define	_equal				ft::equal

#endif