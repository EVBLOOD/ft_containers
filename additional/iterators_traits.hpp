/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 18:27:17 by sakllam           #+#    #+#             */
/*   Updated: 2022/08/12 19:59:37 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <cstddef>
#include <iterator>

namespace ft {
    template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T&>
          struct iterator
        {
            typedef T         value_type;
            typedef Distance  difference_type;
            typedef Pointer   pointer;
            typedef Reference reference;
            typedef Category  iterator_category;
        };
    template <class Iterator>
    class iterator_traits
    {
        typedef typename  Iterator::value_type          value_type;
        typedef typename  Iterator::difference_type     difference_type;
        typedef typename  Iterator::pointer             pointer;
        typedef typename  Iterator::reference           reference;
        typedef typename  Iterator::iterator_category   iterator_category;
    };
    template <class T>
    class iterator_traits<T*>
    {
        typedef T                               value_type;
        typedef ptrdiff_t                       difference_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
    template <class T>
        class iterator_traits<const T*>
    {
        
        typedef T                               value_type;
        typedef ptrdiff_t                       difference_type;
        typedef const T*                        pointer;
        typedef const T&                        reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
    template<class T>
    class My_Iter // : public iterator_traits<T> <why????????>
    {
        // members ! I may change this one later!
        //      using thw iterator and trait_iterator to work on it in generic
        typedef T                               value_type;
        typedef ptrdiff_t                       difference_type;
        typedef const T*                        pointer;
        typedef const T&                        reference;
        typedef std::random_access_iterator_tag iterator_category;
        // atributes
        T *data;
                            // constra && deconstra
            My_Iter() : data(NULL) {} // don't need it for the momnt 
        public:
            My_Iter(T *ptr) : data(ptr) {}
            ~My_Iter() {}
                            // operators :
            My_Iter &operator=(My_Iter &x)
            {
                if (x != this)
                    data = x.data;
                return *this;
            }
            reference operator*() const
            {
                return *data;
            }
            pointer operator->() const
            {
                return *data;
            }
            My_Iter& operator++() const
            {
                ++data;
                return *this;
            }
            My_Iter& operator++(int) const
            {
                My_Iter<T> temp(data);
                ++data;
                return temp;
            }
            My_Iter &operator--() const
            {
                --data;
                return *this;
            }
            My_Iter &operator--(int) const
            {
                My_Iter<T> temp(data);
                --data;
                return temp;
            }
            bool operator==(const My_Iter& cmp) const
            {
                return data == cmp.data;
            }
            bool operator!=(const My_Iter& cmp)
            {
                return data != cmp.data;
            }
            reference   operator->()
            {
                return *data;
            }
            bool operator<(const My_Iter &cmp)
            {
                return cmp.data > data;
            }
            bool operator>(const My_Iter &cmp)
            {
                return data > cmp.data;
            }
            bool operator<=(const My_Iter &cmp)
            {
                return cmp.data >= data;
            }
            bool operator>=(const My_Iter &cmp)
            {
                return data >= cmp.data;
            }
            My_Iter &operator+(difference_type x)
            {
                return nv(data + x);
            }
            My_Iter &operator-(difference_type x)
            {
                return nv(data - x);
            }
            void operator+=(difference_type x)
            {
                data += x;
            }
            void operator-=(difference_type x)
            {
                data -= x;
            }
            reference operator[](difference_type x)
            {
                return data + x;
            }
            // My_Iter operator+(difference_type x)
            // {
            //     data +=
            // }
            // reference operator* () const 
            // {}
        // My_Iter operator++(int);
        // My_Iter operator++();
        // My_Iter operator--(int);
        // My_Iter operator--();
        // My_Iter<class T>
    };
}
