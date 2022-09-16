/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_vector_iters.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:41:42 by sakllam           #+#    #+#             */
/*   Updated: 2022/08/16 12:43:39 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iterators_traits.hpp"

namespace ft
{
    template<class T>
    class My_Iter
    {
        private:
            My_Iter(const long x) {
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
                My_Iter(const iter &x) : data(&*x) {};

            My_Iter(T *ptr) : data(ptr) {};

            ~My_Iter() {};
            
            My_Iter() : data(NULL) {};
            
            bool operator==(const My_Iter &in) const { return in.data == data; };
            bool operator!=(const My_Iter &in) const { return !(in.data == data); };

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
            
            My_Iter &operator++()
            {
                ++data;
                return *this;
            }
            
            My_Iter operator++(int)
            {
                My_Iter temp(data);
                ++data;
                return temp;
            }

            My_Iter &operator--()
            {
                --data;
                return *this;
            }
            
            My_Iter operator--(int)
            {
                My_Iter temp(data);
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
            
            bool operator<(const My_Iter &cmp) const
            {
                return cmp.data > data;
            }
            
            bool operator>(const My_Iter &cmp) const
            {
                return data > cmp.data;
            }
            
            bool operator<=(const My_Iter &cmp) const
            {
                return cmp.data >= data;
            }

            bool operator>=(const My_Iter &cmp) const
            {
                return data >= cmp.data;
            }
            
            My_Iter operator+(difference_type x) const
            {
                return My_Iter(data + x);
            }
            
            My_Iter operator-(difference_type x) const
            {
                return My_Iter(data - x);
            }
            
            void operator+=(difference_type x)
            {
                data += x;
            }

            void operator-=(difference_type x)
            {
                data -= x;
            }
            
            reference operator[](difference_type x) const
            {
                return *(data + x);
            }
    };

    template<class T, class I = My_Iter<T> >
    class my_Reviter
    {
        private:

            I iter;
            my_Reviter(const long x) {
                (void)x;
            };

        public:

            typedef typename I::value_type           value_type;
            typedef typename I::difference_type      difference_type;
            typedef typename I::pointer              pointer;
            typedef typename I::reference            reference;
            typedef typename I::iterator_category    iterator_category;
            
            template<class iter>
                my_Reviter(const iter &x) : iter(x) {};
            my_Reviter(T *ptr) : iter(ptr) {};
            my_Reviter() : iter() {};
            ~my_Reviter() {};
            My_Iter<T> base()
            {
                return (iter);;
            }
            template<class itr>
                my_Reviter &operator=(const my_Reviter &x)
            {
                return (iter = x.iter);
            }

            reference operator*() const
            {
                return *(iter - 1);
            }
            reference operator->() const
            {
                return *(iter - 1);
            }
            
            my_Reviter &operator++()
            {
                --iter;
                return *this;
            }
            my_Reviter operator++(int)
            {
                my_Reviter temp(iter);
                --iter;
                return temp;
            }
            my_Reviter &operator--()
            {
                ++iter;
                return *this;
            }
            my_Reviter operator--(int)
            {
                my_Reviter temp(iter);
                ++iter;
                return temp;
            }
            bool operator==(const my_Reviter cmp) const
            {
                return iter != cmp;
            }
            bool operator!=(const my_Reviter cmp) const
            {
                return iter == cmp;
            }
            bool operator<(const my_Reviter &cmp) const
            {
                return cmp.iter < iter;
            }
            bool operator>(const my_Reviter &cmp) const
            {
                return iter < cmp.iter;
            }
            bool operator<=(const my_Reviter &cmp) const
            {
                return cmp.iter <= iter;
            }
            bool operator>=(const my_Reviter &cmp) const
            {
                return iter >= cmp.iter;
            }
            my_Reviter operator+(difference_type x) const
            {
                return my_Reviter(iter - x);
            }
            my_Reviter operator-(difference_type x) const
            {
                return my_Reviter(iter + x);
            }
            void operator+=(difference_type x)
            {
                iter -= x;
            }
            void operator-=(difference_type x)
            {
                iter += x;
            }
            reference operator[](difference_type x) const
            {
                return *(iter + x);
            }
    };
}