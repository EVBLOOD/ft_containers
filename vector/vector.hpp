/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:39:16 by sakllam           #+#    #+#             */
/*   Updated: 2022/08/10 18:55:23 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <memory>
#include <exception>
#include <iostream>
// namespace ft
// {
//     template<class T, class alloc = std::allocator<T> >
//     class vector
//     {

//         typedef     alloc       allocator_type;
//         typedef     T           value_type;
//         typedef     size_t       size_type;
//         typedef typename allocator_type::const_reference const_reference;
//         typedef typename allocator_type::reference reference;
//         // well we found something!
//             static_assert(std::is_same<typename allocator_type::value_type, value_type>::value, "Error in types: the allocater and the value");
//                                 // attributes
//         value_type   *my_vec;
//         size_t      _capacity;
//         size_t      _currSize;

//         // typedef ft_vector<T, alloc> * iterator;
//         // public:
//                                 // constracting and deconstracting
//             explicit vector (const allocator_type& _alloc = allocator_type());  // default constra
//             explicit vector (size_type n, const value_type& val = value_type(),
//                  const allocator_type& _alloc = allocator_type()); // fill constra (comlicated types)
//             vector (const vector& x); // copy constra
//             // left one constract (range)
//             ~vector(); // deconstra
//                                 // operators
//             vector& operator= (const vector& x); //operator=
//             reference operator[] (size_type n); //operator[]
//             const_reference operator[] (size_type n) const; //operator[] const return
//                                 // capacity
//             size_type size() const;
//             size_type max_size() const;
//             void resize (size_type n, value_type val = value_type());
//             size_type capacity() const;
//             bool empty() const;
//             void reserve (size_type n);
//                                 // access elements
//             reference at (size_type n);
//             const_reference at (size_type n) const;
//             reference front();
//             const_reference front() const;
//             reference back();
//             const_reference back() const;
//                                 //  Modifiers
//             // template <class InputIterator>
//             // void assign (InputIterator first, InputIterator last);	
//             // void assign (size_type n, const value_type& val);
//             void push_back (const value_type& val);
//             void pop_back();
//             // iterator insert (iterator position, const value_type& val);
//             // void insert (iterator position, size_type n, const value_type& val);
//             // template <class InputIterator>
//             // void insert (iterator position, InputIterator first, InputIterator last);
//             // iterator erase (iterator position);
//             // iterator erase (iterator first, iterator last);
//             void swap (vector& x);
//             void clear();
//                                 // Allocator
//             allocator_type get_allocator() const;
//                                 // Iterators
//             /*
//             iterator begin();
//             const_iterator begin() const;
//             iterator end();
//             const_iterator end() const;
//             reverse_iterator rbegin();
//             const_reverse_iterator rbegin() const;
//             reverse_iterator rend();
//             const_reverse_iterator rend() const;
//             */




//     };
// }

namespace ft
{
    template<class T, class alloc = std::allocator<T> >
    class vector
    {

        typedef     alloc       allocator_type;
        typedef     T           value_type;
        typedef     size_t       size_type;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::reference reference;
        // typedef ft_vector<T, alloc> * iterator;
                                // well we found something to handle the error!
        static_assert(std::is_same<typename allocator_type::value_type, value_type>::value, "Error in types: the allocater and the value");
                                // attributes
        value_type   *my_vec;
        size_t      _capacity;
        size_t      _currSize;
        allocator_type  _alloc;
        public:
                                // constracting and deconstracting
            explicit vector (const allocator_type& _alloc = allocator_type())  // default constra
            {
                my_vec = NULL;
                _currSize = 0;
                _capacity = 0;
            }
            explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& ac = allocator_type()) : _alloc(ac) // fill constra (comlicated types)
            {
                try
                {
                    my_vec = _alloc.allocate(n * sizeof(value_type));
                    _capacity = n;
                    _currSize = n;
                    // fill with the vals
                    int i = 0;
                    while (i < n)
                    {
                        my_vec[i] = val;
                        i++;
                    }
                }
                catch (std::length_error e)
                {
                    throw std::length_error(": vector");
                }
            }
            vector (const vector& x) // copy constra
            {
                try
                {
                    my_vec = allocator_type::allocator(x.capacity());
                    _capacity = x._capacity();
                    _currSize = x.size();
                    // filling with values
                    int i = 0;
                    while (i < _currSize)
                    {
                        my_vec[i] = x[i]; // I can use the operator[] cause it will be defined.
                        i++;
                    }
                }
                catch (std::length_error e)
                {
                    throw std::length_error(": vector");
                }
            }
            ~vector() // deconstra
            {
                if (my_vec)
                {
                    int i = 0;
                    while (i < _currSize)
                    {
                        _alloc.destroy(&(my_vec[i]));
                        i++;
                    }
                    _alloc.deallocate(my_vec, _capacity);
                }
            }
            // left one constract (range)
                                // operators
            vector& operator= (const vector& x) //operator=
            {
                if (my_vec)
                {
                    int i = 0;
                    while (i < _currSize)
                    {
                        _alloc.destroy(&(my_vec[i]));
                        i++;
                    }
                    _alloc.deallocate(my_vec, _capacity);
                }
                this->_currSize = x._currSize;
                this->_capacity = x._capacity;
                my_vec = _alloc.allocate(sizeof(value_type) * _capacity);
                memccpy(my_vec, x.my_vec, sizeof(value_type) * _currSize);
                return this;
            }
            reference operator[] (size_type n) //operator[]
            {
                return my_vec[n];
            }
            const_reference operator[] (size_type n) const //operator[] const return
            {
                return my_vec[n];
            }
                                // capacity
            size_type size() const // vector current size
            {
                return (_currSize);
            }
            size_type capacity() const // vector current capacity
            {
                return (_capacity);
            }
            bool empty() const // is vector empty?
            {
                return (_currSize);
            }
            void reserve (size_type n) // TODO:
            {
                if (n <= _capacity)
                    return ;
                value_type   *new_vec;
                new_vec = _alloc.allocate(sizeof(value_type) * n, 0);
                memset(new_vec, 0, sizeof(value_type) * n);
                memccpy(new_vec, my_vec, sizeof(value_type) * _currSize);
                _alloc.deallocate(my_vec);
                my_vec = new_vec;
                _capacity = n;
            }
            void resize (size_type n, value_type val = value_type());
                                // access elements
            reference at (size_type n)
            {
                if (n > _currSize)
                    throw std::out_of_range("vector: ");
                return (my_vec[n]);
            }
            const_reference at (size_type n) const
            {
                if (n > _currSize)
                    throw std::out_of_range("vector: ");
                return (my_vec[n]);
            }
            reference front()
            {
                return (my_vec[0]);
            }
            const_reference front() const
            {
                return (my_vec[0]);
            }
            reference back()
            {
                return (my_vec[_currSize - 1]);
            }
            const_reference back() const
            {
                return (my_vec[_currSize - 1]);
            }
                                //  Modifiers
            // template <class InputIterator>
            // void assign (InputIterator first, InputIterator last);	
            // void assign (size_type n, const value_type& val);
            void push_back (const value_type& val)
            {
                if (_currSize == _capacity)
                {
                    if (_capacity == 0 || _capacity == 1)
                        _capacity++;
                    else
                        _capacity = _capacity * 2;
                    value_type *nv = _alloc.allocate(sizeof(value_type) * _capacity);
                    memset(nv, 0, sizeof(value_type) * _capacity);
                    if (my_vec)
                    {
                        memccpy(nv, my_vec, sizeof(value_type) * _currSize);
                        int i = 0;
                        while (i < _currSize)
                        {
                            _alloc.destroy(&(my_vec[i]));
                            i++;
                        }
                        _alloc.deallocate(my_vec);
                    }
                    my_vec = nv;
                }
                my_vec[_currSize] = val;
                _currSize++;
            }
            void pop_back();
            // iterator insert (iterator position, const value_type& val);
            // void insert (iterator position, size_type n, const value_type& val);
            // template <class InputIterator>
            // void insert (iterator position, InputIterator first, InputIterator last);
            // iterator erase (iterator position);
            // iterator erase (iterator first, iterator last);
            void swap (vector& x);
            void clear();
                                // Allocator
            allocator_type get_allocator() const;
                                // Iterators
            /*
            iterator begin();
            const_iterator begin() const;
            iterator end();
            const_iterator end() const;
            reverse_iterator rbegin();
            const_reverse_iterator rbegin() const;
            reverse_iterator rend();
            const_reverse_iterator rend() const;
            */




    };
}
