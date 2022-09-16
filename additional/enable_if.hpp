/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:37:05 by sakllam           #+#    #+#             */
/*   Updated: 2022/08/14 16:37:36 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

namespace ft
{
    template <bool Cond, class T = void> struct enable_if
    {
        typedef T type;
    };

    template <class T> struct enable_if<false, T>
    {
        
    };
}