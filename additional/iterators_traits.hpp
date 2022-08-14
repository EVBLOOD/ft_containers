/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 18:27:17 by sakllam           #+#    #+#             */
/*   Updated: 2022/08/14 16:34:24 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <cstddef>
#include <iterator>
#include "../additional/enable_if.hpp"
#include <type_traits>
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
    struct iterator_traits
    {
        typedef typename  Iterator::value_type          value_type;
        typedef typename  Iterator::difference_type     difference_type;
        typedef typename  Iterator::pointer             pointer;
        typedef typename  Iterator::reference           reference;
        typedef typename  Iterator::iterator_category   iterator_category;
    };
    template <class T>
    struct iterator_traits<T*>
    {
        typedef T                               value_type;
        typedef ptrdiff_t                       difference_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
    template <class T>
        struct iterator_traits<const T*>
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
        private:
            My_Iter(const long x) {};
        public:
        // members ! I may change this one later!
        //      using thw iterator and trait_iterator to work on it in generic
        typedef typename iterator_traits<T *>::value_type           value_type;
        typedef typename iterator_traits<T *>::difference_type      difference_type;
        typedef typename iterator_traits<T *>::pointer              pointer;
        typedef typename iterator_traits<T *>::reference            reference;
        typedef typename iterator_traits<T *>::iterator_category    iterator_category;
        // atributes
        T *data;
                            // constra && deconstra
            explicit My_Iter() : data(NULL) {}; // don't need it for the momnt
             
            template<class iter>
            explicit My_Iter(const iter &x)
            {
                data = &*x;
            };
            explicit My_Iter(T *ptr) : data(ptr) {};
            
            
            ~My_Iter() {};
                            // operators :
            template<class iter>
            iter &operator=(iter const &x)
            {
                if (&x != this)
                    data = x.data;
                return *this;
            }
            
            reference operator*() const
            {
                return *data;
            }
            // const reference operator*() const
            // {
            //     return *data;
            // }
            reference operator->() const
            {
                return *data;
            }
            // const  reference operator->() const
            // {
            //     return *data;
            // }
            My_Iter& operator++()
            {
                ++data;
                return *this;
            }
            My_Iter operator++(int)
            {
                My_Iter<T> temp(data);
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
                My_Iter<T> temp(data);
                --data;
                return temp;
            }
            bool operator==(const pointer cmp) const
            {
                return data == cmp;
            }
            bool operator!=(const pointer cmp)
            {
                return data != cmp;
            }
            // reference   operator->() const
            // {
            //     return *data;
            // }
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
            My_Iter operator+(difference_type x)
            {
                return My_Iter<T>(data + x);
            }
            My_Iter operator-(difference_type x)
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
            reference operator[](difference_type x)
            {
                return *(data + x);
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
