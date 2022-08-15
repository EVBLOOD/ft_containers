/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:02:04 by sakllam           #+#    #+#             */
/*   Updated: 2022/08/15 19:32:58 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <cstddef>
#include <cstring>
#include <memory>
#include <exception>
#include <iostream>
#include <sys/_types/_size_t.h>
#include <type_traits>
#include "../additional/iterators_traits.hpp"
#include "../additional/enable_if.hpp"
#include "../additional/my_vector_iters.hpp"
#include "../additional/lexicographical_compare.hpp"

namespace ft
{
    template<class T, class alloc = std::allocator<T> >
    class vector
    {
		public:
        typedef     alloc       allocator_type;
        typedef     T           value_type;
        typedef     ptrdiff_t       size_type;
        typedef const value_type& const_reference;
        typedef value_type& reference;
		typedef ft::My_Iter<value_type> iterator;
		typedef ft::My_Iter<const value_type> const_iterator;
        typedef typename ft::my_Reviter<value_type> reverse_iterator;
        typedef typename ft::my_Reviter<const value_type> const_reverse_iterator;

        static_assert((std::is_same<typename allocator_type::value_type, value_type>::value), "Error in types: the allocater and the value");
        value_type   *my_vec;
        size_type      _capacity;
        size_type      _currSize;
        allocator_type  _alloc;
        explicit vector (const allocator_type& _alloc = allocator_type()) : my_vec(NULL), _currSize(0), _capacity(0) {}
        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& ac = allocator_type()) : _alloc(ac), _capacity(n), _currSize(n)
        {
            try
            {
                my_vec = _alloc.allocate(n);
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
        vector (const vector& x) : _capacity(x._capacity()), _currSize(x._currSize), _alloc(x._alloc)
        {
            try
            {
                my_vec = allocator_type::allocator(x.capacity());
                int i = 0;
                while (i < _currSize)
                {
                    my_vec[i] = x[i];
                    i++;
                }
            }
            catch (std::length_error e)
            {
                throw std::length_error(": vector");
            }
        }
        ~vector()
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
        template <class InputIterator>
        	vector (typename ft::enable_if<std::is_class< InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type& ac = allocator_type()) : _currSize(0), _capacity(0), my_vec(NULL), _alloc(ac)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

        vector& operator=(const vector& x)
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
            my_vec = _alloc.allocate(_capacity);
            memcpy(my_vec, x.my_vec, _currSize  * sizeof(value_type));
            return *this;
        }
        reference operator[] (size_type n)
        {
            return my_vec[n];
        }
        const_reference operator[] (size_type n) const
        {
            return my_vec[n];
        }
        size_type max_size() const
        {
            if (std::is_same<value_type, char>::value)
                return _alloc.max_size() / 2;
            return _alloc.max_size();
        }
        size_type size() const
        {
            return _currSize;
        }
        size_type capacity() const
        {
            return _capacity;
        }
        bool empty() const
        {
            return (_currSize);
        }
        void reserve (size_type n)
        {
            if (n <= _capacity)
                return ;
            value_type   *new_vec = _alloc.allocate(n, 0);
            memset(new_vec, 0, n  * sizeof(value_type));
            memcpy(new_vec, my_vec, _currSize  * sizeof(value_type));
            _alloc.deallocate(my_vec, _capacity);
            my_vec = new_vec;
            _capacity = n;
        }
        void resize (size_type n, value_type val = value_type())
        {
            if (n < _currSize)
            {
                int i = 0;
                while (i < n)
                {
                    _alloc.destroy(&(my_vec[i]));
                    i++;
                }
                _currSize = n;
                return ;
            }
            if (n > _capacity)
            {
                value_type *nv = _alloc.allocate(n);
                memcpy(nv, my_vec, sizeof(value_type) * _currSize);
                int i = _currSize;
                while (i < n)
                {
                    nv[i] = val;
                    i++;
                }
                _alloc.deallocate(my_vec, _capacity);
                my_vec = nv;
                _capacity = n;
                _currSize = n;
                return ;
            }
            if (n > _currSize)
            {
                int i = _currSize;
                while (i < n)
                {
                    my_vec[i] = val;
                    i++;
                }
                _currSize = n;
                return;
            }
        }
        reference at (size_type n)
        {
            if (n > _currSize)
                throw std::out_of_range("vector: ");
            return my_vec[n];
        }
        const_reference at (size_type n) const
        {
            if (n > _currSize)
                throw std::out_of_range("vector: ");
            return (my_vec[n]);
        }
        reference front()
        {
            return my_vec[0];
        }
        const_reference front() const
        {
            return my_vec[0];
        }
        reference back()
        {
            return my_vec[_currSize - 1];
        }
        const_reference back() const
        {
            return my_vec[_currSize - 1];
        }
        template <class InputIterator> // TODO
            void assign (typename ft::enable_if<std::is_class< InputIterator>::value, InputIterator>::type first, InputIterator last)
        {
                InputIterator tmp = first;
                int x = 0;
                while (tmp != last)
                {
                    x++;
                    tmp++;
                }
                this->assign(x, *first);
                first++;
                x = 1;
                while (first != last)
                {
                    my_vec[x] = *first;
                    first++;
                }
        }
        void assign (size_type n, const value_type& val)
        {
            value_type *nv = my_vec;
            if (n > _capacity)
                nv = _alloc.allocate(n);
            int i = 0;
            while (i < n && i < _currSize)
            {
                _alloc.destroy(&(my_vec[i]));
                i++;
            }
            if (n > _capacity)
                _alloc.deallocate(my_vec, _capacity);
            i = 0;
            while (i < n)
            {
                nv[i] = val;
                i++;
            }
            _currSize = n;
            if (n > _capacity)
                _capacity = _currSize;
            my_vec = nv;
        }
        void push_back (const value_type& val)
        {
            if (_currSize == _capacity)
            {
                size_type oldcp = _capacity;
                if (_capacity == 0 || _capacity == 1)
                    _capacity++;
                else
                    _capacity = _capacity * 2;
                value_type *nv = _alloc.allocate(_capacity);
                memset(nv, 0, _capacity * sizeof(value_type));
                if (my_vec)
                {
                    memcpy(nv, my_vec, _currSize  * sizeof(value_type));
                    int i = 0;
                    while (i < _currSize)
                    {
                        _alloc.destroy(&(my_vec[i]));
                        i++;
                    }
                    _alloc.deallocate(my_vec, oldcp);
                }
                my_vec = nv;
            }
            my_vec[_currSize] = val;
            _currSize++;
        }
        void pop_back()
        {
            _currSize--;
            if (my_vec == NULL)
                return;
            _alloc.destroy(&(my_vec[_currSize - 1]));
        }
        iterator insert (iterator position, const value_type& val)
        {
            int counter = &*position - my_vec;
            if (_currSize == _capacity)
            {
                size_type oldcp = _capacity;
                if (_capacity == 0 || _capacity == 1)
                    _capacity++;
                else
                    _capacity = _capacity * 2;
                value_type *nv = _alloc.allocate(_capacity);
                memset(nv, 0, _capacity * sizeof(value_type));
                if (my_vec)
                {
                    memcpy(nv, my_vec, _currSize  * sizeof(value_type));
                    int i = 0;
                    while (i < _currSize)
                    {
                        _alloc.destroy(&(my_vec[i]));
                        i++;
                    }
                    _alloc.deallocate(my_vec, oldcp);
                }
                my_vec = nv;
            }
            _currSize++;
            value_type *start = my_vec + counter;
            value_type *end = my_vec + _currSize;
            while (start != end)
            {
                end--;
                *end = *(end - 1);
            }
            *start = val;
            return position;
        }
        void insert (iterator position, size_type n, const value_type& val)
        {
            iterator j = this->begin();
            int counter = 0;
            while (j != position && j != this->end())
            {
                j++;
                counter++;
            }
            int i = 0;
            while (i < n)
            {
                iterator x = this->begin() + counter;
                insert(x, val);
                position++;
                counter++;
                i++;
            }
        }
        template <class InputIterator>
            void insert (iterator position, typename ft::enable_if<std::is_class< InputIterator>::value, InputIterator>::type first, InputIterator last)
        {
                iterator j = this->begin();
                int i = 0;
                while (j != position && j != this->end())
                {
                    j++;
                    i++;
                }
                iterator x = this->begin();
                while (first != last)
                {
                    iterator x = this->begin() + i;
                    insert(x, *first);
                    i++;
                    first++;
                }
        }
        iterator erase (iterator position)
        {
            iterator tmp = position;
            iterator en = this->end();
            _alloc.destroy(&*position);
            while (position + 1 != en)
            {
                *position = *(position + 1);
                position++;
            }
            _currSize--;
            return tmp;
        }
        iterator erase (iterator first, iterator last)
        {
            iterator bg = first;
            while (bg != last)
            {
                erase(first);
                bg++;
            }
            return first;
        }
        void swap (vector& x)
        {
            value_type *swapvec = my_vec;
            size_type swapcapa = _capacity;
            size_type swapsize = _currSize;
            alloc swapaloc = _alloc;
            my_vec = x.my_vec;
            _capacity = x._capacity;
            _currSize = x._currSize;
            _alloc = x._alloc;
            x.my_vec = swapvec;
            x._capacity = swapcapa;
            x._currSize = swapsize;
            x._alloc = swapaloc;
        }
        void clear()
        {
            int i = 0;
            while (i < _currSize)
            {
                _alloc.destroy(&(my_vec[i]));
                i++;
            }
            _currSize = 0;
        }
        allocator_type get_allocator() const
        {
            return _alloc;
        }
        iterator begin()
		{
			return iterator(my_vec);
		}
        iterator end()
		{
			return iterator(my_vec + _currSize);
		}
        const_iterator begin() const
		{
			return const_iterator(my_vec);
		}
		const_iterator end() const
		{
			return const_iterator(my_vec + _currSize);
		}
        
        reverse_iterator rbegin()
		{
			return reverse_iterator(my_vec + _currSize);
		}
        reverse_iterator rend()
		{
			return reverse_iterator(my_vec);
		}
        const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(my_vec + _currSize);
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(my_vec);
		}
    };
    template <class T, class Alloc>
        bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return false;
        int i = 0;
        // I geuss I can use the equal function! I just don't know how so far
        while (lhs.size() > i)
        {
            if (lhs[i] != rhs[i])
                return false;
            i++;
        }
        return true;
    }
    template <class T, class Alloc>
      bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(lhs == rhs);
    }
    template <class T, class Alloc>
      bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
    template <class T, class Alloc>
      bool operator>(const vector<T,Alloc>& rhs, const vector<T,Alloc>& lhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
    template <class T, class Alloc>
      bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(rhs < lhs);
    }
    template <class T, class Alloc>
      bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(lhs < rhs);
    }
    template <class T, class Alloc>
        void swap (vector<T, Alloc>& x, vector<T, Alloc>& y)
    {
        vector<T, Alloc> tmp(x);
        x.swap(y);
        y.swap(tmp);
        tmp.clear();
    }
}
