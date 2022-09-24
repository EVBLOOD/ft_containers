/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_map_iters.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:29:37 by sakllam           #+#    #+#             */
/*   Updated: 2022/09/24 12:10:10 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iterators_traits.hpp"
#include "Red-Black-Tree/Tree_implemeted.hpp"

namespace ft
{
    template <class T>
       class map_iterators
    {
        private:
            map_iterators(const long x) {
                (void)x;
            };
            T *data;
        public:
            typedef typename ft::iterator_traits<T *>::value_type           value_type;
            typedef typename ft::iterator_traits<T *>::difference_type      difference_type;
            typedef typename ft::iterator_traits<T *>::pointer              pointer;
            typedef typename ft::iterator_traits<T *>::reference            reference;
            typedef typename ft::iterator_traits<T *>::iterator_category    iterator_category;
            typedef typename T::type_name&                                  pair_ref;

            template<class iter>
                map_iterators(const iter &x) : data(&*x) {};

            map_iterators(T *ptr) : data(ptr) {};

            ~map_iterators() {};
            
            map_iterators() : data(NULL) {};
            
            bool operator==(const map_iterators &in) const { return in.data->value == data->value; };
            bool operator!=(const map_iterators &in) const { return !(in.data->value == data->value); };

                        template<class itr>
                itr &operator=(const itr &x)
            {
                    if (&x != this)
                        data = x.data;
                    return *this;
            }

            pair_ref operator*() const
            {
                return data->value;
            }
            
            pair_ref operator->() const
            {
                return data->value;
            }
            
            map_iterators &operator++()
            {
                data = RedBlackTree<T>::next(data);
                return *this;
            }
            
            map_iterators operator++(int)
            {
                map_iterators temp(data);
                data = RedBlackTree<T>::next(data);
                return temp;
            }

            map_iterators &operator--()
            {
                data = RedBlackTree<T>::prev(data);
                return *this;
            }
            
            map_iterators operator--(int)
            {
                map_iterators temp(data);
                data = RedBlackTree<T>::prev(data);
                return temp;
            }
            
    };
}