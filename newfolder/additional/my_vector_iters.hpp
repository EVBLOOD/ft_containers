/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_vector_iters.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:41:42 by sakllam           #+#    #+#             */
/*   Updated: 2022/08/14 23:36:13 by sakllam          ###   ########.fr       */
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
            My_Iter(const long x) {};
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

    template<class T>
    class my_Reviter : public My_Iter<T>
    {
        
        typedef typename ft::My_Iter<T>::value_type           value_type;
        typedef typename ft::My_Iter<T>::difference_type      difference_type;
        typedef typename ft::My_Iter<T>::pointer              pointer;
        typedef typename ft::My_Iter<T>::reference            reference;
        typedef typename ft::My_Iter<T>::iterator_category    iterator_category;
        
        template<class iter>
            my_Reviter(const iter &x) : My_Iter<T>(x) {};
        my_Reviter(T *ptr) : My_Iter<T>(ptr) {};
        my_Reviter() : My_Iter<T>() {};
        ~my_Reviter() {};
        my_Reviter base()
        {
            return this->data;
        }

        reference operator[](difference_type x) const
        {
            return *(base() + x);
        }

        void operator-=(difference_type x)
        {
            base() += x;
        }

        my_Reviter operator-(difference_type x) const
        {
            return my_Reviter(base() + x);
        }
        
        my_Reviter operator+(difference_type x) const
        {
            return my_Reviter(base() - x);
        }
        my_Reviter &operator++()
        {
            --base();
            return *this;
        }
        my_Reviter operator++(int)
        {
            my_Reviter temp(base());
            --base();
            return temp;
        }
        void operator+=(difference_type x)
        {
            base() -= x;
        }
        reference operator*() const
        {
            return *base();
        }
        my_Reviter &operator--()
        {
            ++base();
            return *this;
        }
        my_Reviter operator--(int)
        {
            my_Reviter temp(base());
            ++base();
            return temp;
        }
    };
}