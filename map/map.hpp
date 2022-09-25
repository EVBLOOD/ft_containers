/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:41:06 by sakllam           #+#    #+#             */
/*   Updated: 2022/09/25 19:23:21 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <functional>
#include <iterator>
#include <memory>
#include <utility>
#include "../additional/pair.hpp"
#include "../additional/is_integral.hpp"
#include "../additional/Red-Black-Tree/Tree_implemeted.hpp"
#include "../additional/my_map_iters.hpp"
#include "../additional/enable_if.hpp"
namespace ft
{
        template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
        		class map
        {
          public:
            	typedef std::pair<const Key, T> value_type;
            	typedef Key key_type;
            	typedef T mapped_type;
            	typedef Compare key_compare;
              struct value_compare
                  : public std::binary_function<value_type, value_type, bool>
              {
                  private:
                    key_compare cmp;
                  public:
                  value_compare(const key_compare &x) : cmp(x){};
                  bool operator()(const value_type &a, const value_type &b)
                  {
                    return cmp(a.first, b.first);
                  }
              };
            	typedef Alloc allocator_type;
            	typedef typename allocator_type::reference reference;
            	typedef typename allocator_type::const_reference	const_reference;
            	typedef typename allocator_type::pointer	 pointer;
            	typedef typename allocator_type::const_pointer	const_pointer;
              typedef typename ft::map_iterators<itermap<value_type>, value_compare > iterator;
              typedef typename ft::map_iterators<const itermap<value_type>, value_compare > const_iterator;
              typedef typename ft::revmap_iterators<itermap<value_type> > reverse_iterator;
              typedef typename ft::revmap_iterators<const itermap<value_type> > const_reverse_iterator;
            	typedef size_t size_type;
            	static_assert((ft::is_same<typename allocator_type::value_type, value_type>::value), "Error in types: the allocater and the value");
            	private:
			  		R_B_T<value_type, value_compare, typename allocator_type::template rebind<RedBlackTree<value_type> >::other> my_tree; 

			    public:
            		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : my_tree(typename allocator_type::template rebind<RedBlackTree<value_type> >::other(), value_compare(comp)) {}
                template <class InputIterator>
                  map (ft::enable_if<ft::is_same<typename InputIterator::iterator_category, std::input_iterator_tag>::value, InputIterator> first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : my_tree(comp, alloc)
					      {
                  while (first != last)
                  {
                    my_tree.insert(*first);
                    first++;
                  }
					      }
                map (const map& x) : my_tree(x.my_tree.ac, x.my_tree.cmpr)
					      {
                  *this = x;
					      }
          ~map()
					{
					}
          map& operator= (const map& x)
					{
            const_iterator b = x.begin();
            const_iterator e = x.end();
            this->my_tree.free();
            while (b != e)
            {
            //   my_tree.insert(*b);
              b++;
            }
            return *this;
					}
          iterator begin()
          {
            return iterator(my_tree.begin());
          }
          const_iterator begin() const
          {
            return const_iterator(my_tree.cbegin());
          }
          iterator end()
          {
            return iterator(my_tree.end());
          }
          const_iterator end() const
          {
            return const_iterator(my_tree.cend());
          }
          reverse_iterator rbegin()
          {
            return reverse_iterator(my_tree.end());
          }
          const_reverse_iterator rbegin() const
          {
            return const_reverse_iterator(my_tree.end());
          }
          reverse_iterator rend()
          {
            return reverse_iterator(my_tree.begin());
          }
          const_reverse_iterator rend() const
          {
            return const_reverse_iterator(my_tree.begin());
          }
          bool empty() const
          {
            return my_tree.size == 0;
          }
          size_type size() const
          {
            return my_tree.size;
          }
          size_type max_size() const
          {
            return my_tree.ac.max_size();
          }
          std::pair<iterator,bool> insert (const value_type& val)
          {
            std::pair<bool, RedBlackTree<value_type>* > x;
            my_tree._insert(val, x);
            return (std::make_pair(iterator(x.second), x.first));
          }
          mapped_type& operator[] (const key_type& k)
          {
            RedBlackTree<value_type> *f = my_tree.find(std::make_pair(k, mapped_type()));
            if (f)
             return f->value.second;
            std::pair<iterator, bool> x = insert(std::make_pair(k, mapped_type()));
            return x.first->second;
          }
          iterator insert (iterator position, const value_type& val)
          {
            (void)position;
            my_tree.insert(val);
          }
          template <class InputIterator>
            void insert (ft::enable_if<ft::is_same<typename InputIterator::iterator_category, std::input_iterator_tag>::value, InputIterator> first, InputIterator last)
          {
            while (first != last)
            {
              my_tree.insert(*first);
              first++;
            }
          }
          void erase (iterator position)
          {
            my_tree.remove(*position);
          }
          size_type erase (const key_type& k)
          {
            my_tree.remove(std::make_pair(k, 0));
            return my_tree.size;
          }
          void erase (iterator first, iterator last)
          {
            // I think I'll sort them
            while (first != last)
            {
              my_tree.insert(*first);
              first++;
            }
          }
          void swap (map& x)
          {
            map name(x);
            
            x = *this;
            *this = name;
          }
          void clear()
          {
            my_tree.free();
          }
          key_compare key_comp()
          {
            return my_tree.cmpr;
          }
          value_compare value_comp() const
          {
            return value_compare(my_tree.cmpr);
          }
          iterator find (const key_type& k)
          {
            return iterator(my_tree.find(std::make_pair(k, 0)));
          }
          const_iterator find (const key_type& k) const
          {
            return const_iterator(my_tree.find(k));
          }
          size_type count (const key_type& k) const
          {
            return static_cast<size_type>(my_tree.exists(k));
          }
          iterator lower_bound (const key_type& k)
          {
            iterator x(my_tree.find(k));
            return (++x);
          }
          const_iterator lower_bound (const key_type& k) const
          {
            const_iterator x(my_tree.find(k));
            return (++x);
          }
          iterator upper_bound (const key_type& k)
          {
            iterator x(my_tree.find(k));
            return (--x);
          }
          const_iterator upper_bound (const key_type& k) const
          {
            const_iterator x(my_tree.find(k));
            return (--x);
          }
          std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
          {
            return std::make_pair(const_iterator(my_tree.find(k)), const_iterator(my_tree.find(k)));
          }
              //   pair<iterator,iterator>             equal_range (const key_type& k);
              //   allocator_type get_allocator() const;
        
        };
}