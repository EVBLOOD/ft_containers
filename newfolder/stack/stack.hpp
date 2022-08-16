/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:58:27 by sakllam           #+#    #+#             */
/*   Updated: 2022/08/16 12:38:32 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../vector/vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
        class stack
    {
        typedef T           value_type;
        typedef Container   container_type;
        typedef size_t      size_type;

        container_type my_stack;

        public:
        explicit stack (const container_type& ctnr = container_type()) : my_stack(ctnr) {}
        bool empty() const
        {
            return my_stack.empty();
        }
        size_type size() const
        {
            return my_stack.size();
        }
        value_type& top()
        {
            return my_stack.back();
        }
        const value_type& top() const
        {
            return my_stack.back();
        }
        void push (const value_type& val)
        {
            return my_stack.push_back(val);
        }
        void pop()
        {
            my_stack.pop_back();
        }


            

    };
    // (1)	
// template <class T, class Container>
//   bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
// (2)	
// template <class T, class Container>
//   bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
// (3)	
// template <class T, class Container>
//   bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
// (4)	
// template <class T, class Container>
//   bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
// (5)	
// template <class T, class Container>
//   bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
// (6)	
// template <class T, class Container>
//   bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
}