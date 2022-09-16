/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:03:13 by sakllam           #+#    #+#             */
/*   Updated: 2022/08/15 19:39:04 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
    template <class T1, class T2>
        struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

        first_type first;
        second_type second;
        pair() : first(), second() {}
        template<class U, class V>
            pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}
        pair (const first_type& a, const second_type& b) : first(a), second(b) {}
        
        pair& operator= (const pair& pr)
        {
            if (&pr == this)
                return *this;
            this->first = pr.first;
            this->second = pr.second;
            return *this;
        }

    };
    template <class t1, class t2>
        bool operator==(const pair<t1,t2>& lhs, const pair<t1,t2>& rhs)
        {
            return lhs.first == rhs.first && lhs.second == rhs.second;
        }
    template <class t1, class t2>
        bool operator!= (const pair<t1,t2>& lhs, const pair<t1,t2>& rhs)
        {
            return !(lhs == rhs);
        }
    template <class t1, class t2>
        bool operator<  (const pair<t1,t2>& lhs, const pair<t1,t2>& rhs)
        {
            return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
        }
    template <class t1, class t2>
        bool operator<= (const pair<t1,t2>& lhs, const pair<t1,t2>& rhs)
        {
            return !(rhs < lhs);
        }
    template <class t1, class t2>
        bool operator>  (const pair<t1,t2>& lhs, const pair<t1,t2>& rhs)
        {
            return rhs < lhs;
        }
    template <class t1, class t2>
        bool operator>= (const pair<t1,t2>& lhs, const pair<t1,t2>& rhs)
        {
            return !(lhs < rhs);
        }
}
