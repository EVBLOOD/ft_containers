/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:58:27 by sakllam           #+#    #+#             */
/*   Updated: 2022/09/30 16:41:33 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
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

        protected:
        container_type c;

        public:
        explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {}
        bool empty() const
        {
            return c.empty();
        }
        size_type size() const
        {
            return c.size();
        }
        value_type& top()
        {
            return c.back();
        }
        const value_type& top() const
        {
            return c.back();
        }
        void push (const value_type& val)
        {
            return c.push_back(val);
        }
        void pop()
        {
            c.pop_back();
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