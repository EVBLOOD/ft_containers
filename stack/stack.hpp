/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:58:27 by sakllam           #+#    #+#             */
/*   Updated: 2022/09/30 13:10:13 by sakllam          ###   ########.fr       */
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
    template <class T, class Alloc>
        bool operator==(const stack<T,Alloc>& lhs, const stack<T,Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return false;
        int i = 0;
        while (lhs.size() > i)
        {
            if (lhs[i] != rhs[i])
                return false;
            i++;
        }
        return true;
    }
    template <class T, class Alloc>
      bool operator!=(const stack<T,Alloc>& lhs, const stack<T,Alloc>& rhs)
    {
        return !(lhs == rhs);
    }
    template <class T, class Alloc>
      bool operator<(const stack<T,Alloc>& lhs, const stack<T,Alloc>& rhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
    template <class T, class Alloc>
      bool operator>(const stack<T,Alloc>& rhs, const stack<T,Alloc>& lhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
    template <class T, class Alloc>
      bool operator<=(const stack<T,Alloc>& lhs, const stack<T,Alloc>& rhs)
    {
        return !(rhs < lhs);
    }
    template <class T, class Alloc>
      bool operator>=(const stack<T,Alloc>& lhs, const stack<T,Alloc>& rhs)
    {
        return !(lhs < rhs);
    }
}