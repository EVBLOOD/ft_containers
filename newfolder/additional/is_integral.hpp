/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:40:37 by sakllam           #+#    #+#             */
/*   Updated: 2022/08/16 11:08:02 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <limits>

namespace ft
{
    template <class T>
        struct is_integral
    {
            typedef T value_type;

            static const bool value = std::numeric_limits<value_type>::is_integer;
    };

    template<typename T, typename U>
        struct is_same 
    {
            static const bool value = false; 
    };
    template<typename T>
        struct is_same<T,T>
    {
            static const bool value = true; 
    };
}
