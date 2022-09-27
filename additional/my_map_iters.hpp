/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_map_iters.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:29:37 by sakllam           #+#    #+#             */
/*   Updated: 2022/09/27 15:57:39 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iterators_traits.hpp"
#include "Red-Black-Tree/Tree_implemeted.hpp"

namespace ft
{
    template <class T, class cmp>
       class map_iterators    
{
        public:
            typedef typename ft::iterator_traits<T *>::value_type           value_type;
            typedef typename ft::iterator_traits<T *>::difference_type      difference_type;
            typedef typename ft::iterator_traits<T *>::pointer              pointer;
            typedef typename ft::iterator_traits<T *>::reference            reference;
            typedef typename ft::iterator_traits<T *>::iterator_category    iterator_category;
            typedef typename T::value_type                                  reference_pair;
            typedef const typename T::value_type                             const_reference_pair;
        private:
            map_iterators(const long x) {
                (void)x;
            };
            pointer data;
        public:
            pointer base() const {return data; }
            map_iterators(value_type ptr) : data(new value_type(ptr)) {};
            map_iterators(pointer ptr) : data(new value_type(*ptr)) {};
            map_iterators(const map_iterators &iter) : data(new value_type(*(iter.base()))) {};
            // template<class iter>
            //     map_iterators(iter &x) : data(x.base()) {};


            ~map_iterators() {
                delete data;
            };
            
            map_iterators() : data(NULL) {};
            
            bool operator==(const map_iterators &in) const { return in.data->corr == data->corr; };
            bool operator!=(const map_iterators &in) const { return !(in.data->corr == data->corr); };

                        template<class itr>
                itr &operator=(const itr &x)
            {
                    if (&x != this)
                        data = x.data;
                    return *this;
            }

            reference_pair *operator-> ()
            {
                return &(data->corr->value);
            }
            const_reference_pair *operator-> () const
            {
                return &(data->corr->value);
            }
            reference_pair &operator*()
            {
                return data->corr->value;
            }
            const_reference_pair &operator*() const
            {
                return data->corr->value;
            }
            map_iterators &operator++()
            {
                puts("li");
                *data =  R_B_T<typename T::value_type, cmp>::_next(data);
                return *this;
            }
            const map_iterators &operator++() const
            {
                *data =  R_B_T<typename T::value_type, cmp>::_next(data);
                return *this;
            } 
            map_iterators operator++(int)
            {
                puts("li 1");
                map_iterators temp(data);
                *data = R_B_T<typename T::value_type, cmp>::_next(data);
                return temp;
            }
            const map_iterators operator++(int) const
            {
                map_iterators temp(data);
                *data = R_B_T<typename T::value_type, cmp>::_next(data);
                return temp;
            }
            map_iterators &operator--()
            {
                *data =  R_B_T<typename T::value_type, cmp>::_prev(data);
                return *this;
            }
            const map_iterators &operator--() const
            {
                *data =  R_B_T<typename T::value_type, cmp>::_prev(data);
                return *this;
            }
            const map_iterators operator--(int) const
            {
                map_iterators temp(data);
                *data =  R_B_T<typename T::value_type, cmp>::_prev(data);
                return temp;
            }
            map_iterators operator--(int)
            {
                map_iterators temp(data);
                *data =  R_B_T<typename T::value_type, cmp>::_prev(data);
                return temp;
            }
            
    };

        template <class T>
       class revmap_iterators
    {
        public:
            typedef typename ft::iterator_traits<T *>::value_type           value_type;
            typedef typename ft::iterator_traits<T *>::difference_type      difference_type;
            typedef typename ft::iterator_traits<T *>::pointer              pointer;
            typedef typename ft::iterator_traits<T *>::reference            reference;
            typedef typename ft::iterator_traits<T *>::iterator_category    iterator_category;
            typedef typename T::type_name&                                   reference_pair;
            typedef const typename T::type_name                              const_reference_pair;
        private:
            revmap_iterators(const long x) {
                (void)x;
            };
            pointer data;
        public:
            revmap_iterators(const pointer ptr) : data(ptr) {};
            template<class iter>
                revmap_iterators(const iter &x) : data(&(*x)) {};


            ~revmap_iterators() {};
            
            revmap_iterators() : data(NULL) {};
            
            bool operator==(const revmap_iterators &in) const { return in.data->value == data->value; };
            bool operator!=(const revmap_iterators &in) const { return !(in.data->value == data->value); };

                        template<class itr>
                itr &operator=(const itr &x)
            {
                    if (&x != this)
                        data = x.data;
                    return *this;
            }

            reference_pair &operator*()
            {
                return ((*data).value);
            }
            
            const_reference_pair operator*() const
            {
                return ((*data).value);
            }
            reference_pair &operator->()
            {
                return ((*data).value);
            }
            const_reference_pair &operator->() const
            {
                return ((*data).value);
            }
            revmap_iterators &operator++()
            {
                puts("here");
                data = RedBlackTree<T>::next(data);
                if (data.corr == NULL)
                    puts("ahah");
                return *this;
            }
            
            revmap_iterators operator++(int)
            {
                 puts("here +");
                revmap_iterators temp(data);
                data = RedBlackTree<T>::next(data);
                return temp;
            }

            revmap_iterators &operator--()
            {
                data = RedBlackTree<T>::prev(data);
                return *this;
            }
            
            revmap_iterators operator--(int)
            {
                revmap_iterators temp(data);
                data = RedBlackTree<T>::prev(data);
                return temp;
            }
            
    };
}