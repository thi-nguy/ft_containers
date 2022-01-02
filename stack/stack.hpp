#ifndef STACK_HPP
#define STACK_HPP

#include "../vector/vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
        public:
            typedef T           value_type;
            typedef Container   container_type;
            typedef size_t      size_type;


            // ! Constructor
            explicit stack(const container_type& ctnr = container_type())
            : my_container(ctnr)
            {}

            // ! Destructor
            ~stack()
            {}

            // ! Member functions
            bool    empty() const
            {
                return (this->my_container.empty());
            }

            size_type   size() const
            {
                return(this->my_container.size());
            }

            // todo : top
            value_type&         top()
            {
                return (this->my_container.back());
            }

            const value_type&   top() const
            {
                return (this->my_container.back());
            }

            void    push(const value_type& val)
            {
                this->my_container.push_back(val);
            }

            void    pop()
            {
                this->my_container.pop_back();
            }
            // ! use friend key word here
            template <class Tn, class ContainerN>
            friend bool operator== (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

			template <class Tn, class ContainerN>
				friend bool operator!= (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);
			
			template <class Tn, class ContainerN>
				friend bool operator< (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

			template <class Tn, class ContainerN>
				friend bool operator<= (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

			template <class Tn, class ContainerN>
				friend bool operator> (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

			template <class Tn, class ContainerN>
				friend bool operator>= (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);


        /* public */

        protected: 
            container_type     my_container;

        /* protected */

    }; /* class stack */
    // ! Non-member function overloads
    template <class T, class Container>
    bool operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
    {
        return (lhs.my_container == rhs.my_container);
    }

    template <class T, class Container>
    bool operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
    {
        return (lhs.my_container != rhs.my_container);
    }


    template <class T, class Container>
    bool operator<  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
    {
        return (lhs.my_container < rhs.my_container)
;    }

    template <class T, class Container>
    bool operator<= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
    {
        return (lhs.my_container <= rhs.my_container);
    }

    template <class T, class Container>
    bool operator>  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
    {
        return (lhs.my_container > rhs.my_container)
;    }

    template <class T, class Container>
    bool operator>= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
    {
        return (lhs.my_container >= rhs.my_container);
    }

} /* namespace ft */

#endif /* stack.hpp */