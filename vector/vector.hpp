/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:39:16 by sakllam           #+#    #+#             */
/*   Updated: 2022/08/06 13:59:29 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <memory>

template<class T, class alloc = std::allocator<T> >
class ft_vector
{
    int _size;
    T   *all;
    typedef ft_vector<T, alloc> * iterator;
    public:
        ft_vector(); // default
        ~ft_vector(); // default
        ft_vector(int nb_clnm, T def); // fill
        ft_vector(ft_vector<T> &cpy); // cpy
        // ft_vector(); // range (bigin iter | end iter)
        iterator *begin();
        iterator *end();




};