/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_map_iters.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:29:37 by sakllam           #+#    #+#             */
/*   Updated: 2022/09/22 17:40:12 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iterators_traits.hpp"
#include "Red-Black-Tree/Tree_implemeted.hpp"
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
                        data->value = x.data->value;
                    return *this;
            }
            reference operator*() const
            {
                return data->value;
            }
            
            reference operator->() const
            {
                return data->value;
            }
            
            My_Iter_map &operator++()
            {
                data = RedBlackTree<T>::next(data);
                return *this;
            }
            
            My_Iter_map operator++(int)
            {
                My_Iter_map temp(data);
                data = RedBlackTree<T>::next(data);
                return temp;
            }

            My_Iter_map &operator--()
            {
                data = RedBlackTree<T>::prev(data);
                return *this;
            }
            
            My_Iter_map operator--(int)
            {
                My_Iter_map temp(data);
                data = RedBlackTree<T>::prev(data);
                return temp;
            }

            bool operator==(const pointer cmp) const
            {
                return data->value == cmp->value;
            }

            bool operator!=(const pointer cmp) const
            {
                return data->value != cmp->value;
            }
            
    };
    template<class T>
    class MyRev_Iter_map
    {
        private:
            MyRev_Iter_map(const long x) {
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
                MyRev_Iter_map(const iter &x) : data(&(*x)) {};

            MyRev_Iter_map(T *ptr) : data(ptr) {};

            ~MyRev_Iter_map() {};
            
            MyRev_Iter_map() : data(NULL) {};
            
            bool operator==(const MyRev_Iter_map &in) const { return in.data == data; };
            bool operator!=(const MyRev_Iter_map &in) const { return !(in.data == data); };

            template<class itr>
                itr &operator=(const itr &x)
            {
                    if (&x != this)
                        data->value = x.data->value;
                    return *this;
            }
            reference operator*() const
            {
                return RedBlackTree<T>::prev(data);
            }
            
            reference operator->() const
            {
                return RedBlackTree<T>::prev(data);
            }
            
            MyRev_Iter_map &operator++()
            {
                data = RedBlackTree<T>::prev(data);
                return *this;
            }
            
            MyRev_Iter_map operator++(int)
            {
                MyRev_Iter_map temp(data);
                data = RedBlackTree<T>::prev(data);
                return temp;
            }

            MyRev_Iter_map &operator--()
            {
                data = RedBlackTree<T>::next(data);
                return *this;
            }
            
            MyRev_Iter_map operator--(int)
            {
                MyRev_Iter_map temp(data);
                data = RedBlackTree<T>::next(data);
                return temp;
            }

            bool operator==(const pointer cmp) const
            {
                return data->value == cmp->value;
            }

            bool operator!=(const pointer cmp) const
            {
                return data->value != cmp->value;
            }            
    };
}