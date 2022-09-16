/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:41:06 by sakllam           #+#    #+#             */
/*   Updated: 2022/08/16 15:28:39 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <functional>
#include <memory>
#include "../additional/pair.hpp"
#include <iterator>

namespace ft
{
      template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
            class map
      {
            typedef ft::pair<const Key, T> value_type;
            typedef Key key_type;
            typedef T mapped_type;
            typedef Compare key_compare;
            typedef typename key_compare::value_comp value_compare;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference	const_reference;
            typedef typename allocator_type::pointer	 pointer;
            typedef typename allocator_type::const_pointer	const_pointer;
            typedef size_t size_type;

            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            {
                  
            }
              template <class InputIterator>
                map (InputIterator first, InputIterator last,
                     const key_compare& comp = key_compare(),
                     const allocator_type& alloc = allocator_type());	
              map (const map& x);
              ~map();       
              map& operator= (const map& x); 
            //   iterator begin();
            //   const_iterator begin() const;
            //   iterator end();
            //   const_iterator end() const;
            //   reverse_iterator rbegin();
            //   const_reverse_iterator rbegin() const;
            //   reverse_iterator rend();
            //   const_reverse_iterator rend() const;
              bool empty() const;
              size_type size() const;
              size_type max_size() const;
              mapped_type& operator[] (const key_type& k);
            //   pair<iterator,bool> insert (const value_type& val);
            //   iterator insert (iterator position, const value_type& val);
            //   template <class InputIterator>
            //     void insert (InputIterator first, InputIterator last);
            //   void erase (iterator position);
              size_type erase (const key_type& k);
            //   void erase (iterator first, iterator last);
              void swap (map& x);
              void clear();
              key_compare key_comp() const;
              value_compare value_comp() const;
            //   iterator find (const key_type& k);
            //   const_iterator find (const key_type& k) const;
              size_type count (const key_type& k) const;
            //   iterator lower_bound (const key_type& k);
            //   const_iterator lower_bound (const key_type& k) const;
            //   iterator upper_bound (const key_type& k);
            //   const_iterator upper_bound (const key_type& k) const;
            //   pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
            //   pair<iterator,iterator>             equal_range (const key_type& k);
            //   allocator_type get_allocator() const;
      
      };
}