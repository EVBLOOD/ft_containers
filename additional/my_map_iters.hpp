/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_map_iters.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:29:37 by sakllam           #+#    #+#             */
/*   Updated: 2022/09/28 13:35:11 by sakllam          ###   ########.fr       */
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
        template <class T, class cmp>
       class revmap_iterators    
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
            revmap_iterators(const long x) {
                (void)x;
            };
            pointer data;
        public:
            pointer base() const {return data; }
            revmap_iterators(value_type ptr) : data(new value_type(ptr)) {};
            revmap_iterators(pointer ptr) : data(new value_type(*ptr)) {};
            revmap_iterators(const revmap_iterators &iter) : data(new value_type(*(iter.base()))) {};
            // template<class iter>
            //     revmap_iterators(iter &x) : data(x.base()) {};


            ~revmap_iterators() {
                delete data;
            };
            
            revmap_iterators() : data(NULL) {};
            
            bool operator==(const revmap_iterators &in) const { return in.data->corr == data->corr; };
            bool operator!=(const revmap_iterators &in) const { return !(in.data->corr == data->corr); };

                        template<class itr>
                itr &operator=(const itr &x)
            {
                    if (&x != this)
                        data = x.data;
                    return *this;
            }

            reference_pair *operator-> ()
            {
                return &(R_B_T<typename T::value_type, cmp>::_prev(data).corr->value);
            }
            const_reference_pair *operator-> () const
            {
                return &(R_B_T<typename T::value_type, cmp>::_prev(data).corr->value);
            }
            reference_pair &operator*()
            {
                return (R_B_T<typename T::value_type, cmp>::_prev(data).corr->value);
            }
            const_reference_pair &operator*() const
            {
                return (R_B_T<typename T::value_type, cmp>::_prev(data).corr->value);
            }
            revmap_iterators &operator--()
            {
                *data =  R_B_T<typename T::value_type, cmp>::_next(data);
                return *this;
            }
            const revmap_iterators &operator--() const
            {
                *data =  R_B_T<typename T::value_type, cmp>::_next(data);
                return *this;
            } 
            revmap_iterators operator--(int)
            {
                revmap_iterators temp(data);
                *data = R_B_T<typename T::value_type, cmp>::_next(data);
                return temp;
            }
            const revmap_iterators operator--(int) const
            {
                revmap_iterators temp(data);
                *data = R_B_T<typename T::value_type, cmp>::_next(data);
                return temp;
            }
            revmap_iterators &operator++()
            {
                *data =  R_B_T<typename T::value_type, cmp>::_prev(data);
                return *this;
            }
            const revmap_iterators &operator++() const
            {
                *data =  R_B_T<typename T::value_type, cmp>::_prev(data);
                return *this;
            }
            const revmap_iterators operator++(int) const
            {
                revmap_iterators temp(data);
                *data =  R_B_T<typename T::value_type, cmp>::_prev(data);
                return temp;
            }
            revmap_iterators operator++(int)
            {
                revmap_iterators temp(data);
                *data =  R_B_T<typename T::value_type, cmp>::_prev(data);
                return temp;
            }
            
    };
}