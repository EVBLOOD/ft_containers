/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:39:16 by sakllam           #+#    #+#             */
/*   Updated: 2022/08/09 20:06:12 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <memory>
namespace ft
{
    template<class T, class alloc = std::allocator<T> >
    class vector
    {

        typedef     alloc       allocator_type;
        typedef     T           value_type;
        typedef     size_t       size_type;
        // well we found something!
            static_assert(std::is_same<typename allocator_type::value_type, value_type>::value, "Error in types: the allocater and the value");
        // attributes
        // int _size;
        // T   *all;
        // typedef ft_vector<T, alloc> * iterator;
        // public:
                                // constracting and deconstracting
            explicit vector (const allocator_type& _alloc = allocator_type());  // default constra
            explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& _alloc = allocator_type()); // fill constra (comlicated types)
            vector (const vector& x); // copy constra
            // left one constract (range)
            ~vector(); // deconstra

            // iterator *begin();
            // iterator *end();




    };
}
