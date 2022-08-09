/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:34:57 by sakllam           #+#    #+#             */
/*   Updated: 2022/08/05 17:41:28 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

using std::cout;

int main()
{
    std::vector<int> x;
    cout << x.max_size() << "\n"; 
    x.push_back(1);
    cout << x.max_size() << "\n";
}