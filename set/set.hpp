/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:23:09 by sakllam           #+#    #+#             */
/*   Updated: 2022/09/29 18:39:25 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// #include <functional>
// #include <iterator>
#include <memory>
// #include <utility>
// #include "../additional/pair.hpp"
// #include "../additional/is_integral.hpp"
#include "../additional/Red-Black-Tree/Tree_implemeted.hpp"
#include "../additional/my_map_iters.hpp"
// #include "../additional/enable_if.hpp"
#include "../vector/vector.hpp"
namespace ft
{
    template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
        class set
    {
         public:
            	typedef T value_type;
            	typedef T key_type;
            	typedef Compare key_compare;
              typedef  key_compare value_compare;
              typedef typename ft::itermap<value_type> iterwrp;
            	typedef Alloc allocator_type;
            	typedef typename allocator_type::reference reference;
            	typedef typename allocator_type::const_reference	const_reference;
            	typedef typename allocator_type::pointer	 pointer;
            	typedef typename allocator_type::const_pointer	const_pointer;
              typedef typename ft::map_iterators<iterwrp, value_compare> iterator;
              typedef const typename ft::map_iterators<iterwrp, value_compare> const_iterator;
              typedef typename ft::revmap_iterators<iterwrp, value_compare> reverse_iterator;
              typedef const typename ft::revmap_iterators<iterwrp, value_compare> const_reverse_iterator;
            	typedef size_t   size_type;
            	static_assert((ft::is_same<typename allocator_type::value_type, value_type>::value), "Error in types: the allocater and the value");
            	private:
			  		R_B_T<value_type, value_compare, typename allocator_type::template rebind<RedBlackTree<value_type> >::other> my_tree; 

			    public:
            		explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : my_tree(typename allocator_type::template rebind<RedBlackTree<value_type> >::other(), value_compare(comp)) {(void)alloc;}
                template <class InputIterator>
                  set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : my_tree(alloc, comp)
					      {
                  while (first != last)
                  {
                    my_tree.insert(*first);
                    first++;
                  }
					      }
                set (const set& x) : my_tree(x.my_tree.ac, x.my_tree.cmpr)
					      {
                  *this = x;
					      }
          ~set()
					{
            my_tree.free();
					}
          set& operator= (const set& x)
					{
            const_iterator b = x.begin();
            const_iterator e = x.end();
            this->my_tree.free();
            while (b != e)
            {
              my_tree.insert(*b);
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
          ft::pair<iterator,bool> insert (const value_type& val)
          {
            ft::pair<bool, RedBlackTree<value_type>* > x;
            my_tree._insert(val, x);
            return (ft::make_pair(iterwrp(my_tree.head, x.second), x.first));
          }
          iterator insert (iterator position, const value_type& val)
          {
            (void)position;
            return this->insert(val).first;
          }
          template <class InputIterator>
            void insert (InputIterator first, InputIterator last)
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
            my_tree.remove(k);
            return my_tree.size;
          }
          void erase (iterator first, iterator last)
          {
            ft::vector<value_type> n;
            while (first != last)
            {
              n.push_back(*first);
              first++;
            }
            typename ft::vector<key_type>::iterator b = n.begin();
            typename ft::vector<key_type>::iterator e = n.end();
            while (b != e)
            {
              my_tree.remove(*b);
              b++;
            }
          }
          void swap (set& x)
          {
            set name(x);
            
            x = *this;
            *this = name;
          }
          void clear()
          {
            my_tree.free();
          }
          key_compare key_comp()
          {
            return key_compare();
          }
          value_compare value_comp() const
          {
            return my_tree.cmpr;
          }
          iterator find (const key_type& k)
          {
            return iterator(my_tree.find(k));
          }
          size_type count (const key_type& k) const
          {
            if (my_tree.exist(k) == true)
              return 1;
            return 0;
          }
          const_iterator find (const key_type& k) const
          {
            return const_iterator(my_tree.find(k));
          }
          iterator lower_bound (const key_type& k)
          {
            iterator x = my_tree.find(k);
            return (x);
          }
          const_iterator lower_bound (const key_type& k) const
          {
            const_iterator x = my_tree.find(k);
            if (x != this->end())
              return (++x);
            return (x);
          }
          iterator upper_bound (const key_type& k)
          {
            iterator x = my_tree.find(k);
            if (x != this->end())
              return (++x);
            return (x);
          }
          const_iterator upper_bound (const key_type& k) const
          {
            const_iterator x = my_tree.find(k);
            if (x != this->end())
              return (--x);
            return (x);
          }
          ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
          {
            const_iterator a = const_iterator(my_tree.find(k));
            if (a == this->end())
              return ft::make_pair(a, a);
            else
              return ft::make_pair(a, ++a);
          }
          ft::pair<iterator,iterator> equal_range (const key_type& k)
          {
            iterator a = iterator(my_tree.find(k));
            if (a == this->end())
              return ft::make_pair(a, a);
            else
              return ft::make_pair(a++, a);
          }
          allocator_type get_allocator() const
          {
            return Alloc();
          }
    };
}
