/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_map_iters.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:29:37 by sakllam           #+#    #+#             */
/*   Updated: 2022/09/20 18:39:15 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iterators_traits.hpp"

namespace ft
{
    template<class T>
    class My_Iter_map
    {
        private:
            My_Iter_map(const long x) {
                (void)x;
            };
            T *data;

        public:
            typedef typename ft::iterator_traits<T *>::value_type           value_type;
            typedef typename ft::iterator_traits<T *>::difference_type      difference_type;
            typedef typename ft::iterator_traits<T *>::pointer              pointer;
            typedef typename ft::iterator_traits<T *>::reference            reference;
            typedef typename ft::iterator_traits<T *>::iterator_category    iterator_category;

            template<class iter>
                My_Iter_map(const iter &x) : data(&(*x)) {};

            My_Iter_map(T *ptr) : data(ptr) {};

            ~My_Iter_map() {};
            
            My_Iter_map() : data(NULL) {};
            
            bool operator==(const My_Iter_map &in) const { return in.data == data; };
            bool operator!=(const My_Iter_map &in) const { return !(in.data == data); };

            template<class itr>
                itr &operator=(const itr &x)
            {
                    if (&x != this)
                        data = x.data;
                    return *this;
            }
            reference operator*() const
            {
                return *data;
            }
            
            reference operator->() const
            {
                return *data;
            }
            
            My_Iter_map &operator++()
            {
                data->next();
                return *this;
            }
            
            My_Iter_map operator++(int)
            {
                My_Iter_map temp(data);
                ++data;
                return temp;
            }

            My_Iter_map &operator--()
            {
                --data;
                return *this;
            }
            
            My_Iter_map operator--(int)
            {
                My_Iter_map temp(data);
                --data;
                return temp;
            }

            bool operator==(const pointer cmp) const
            {
                return data == cmp;
            }

            bool operator!=(const pointer cmp) const
            {
                return data != cmp;
            }
            
    };

}