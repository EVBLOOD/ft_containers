/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:34:57 by sakllam           #+#    #+#             */
/*   Updated: 2022/08/10 20:08:11 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include <iostream>


int main()
{
    // std::vector<int> x;
    // cout << x.max_size() << "\n"; 
    // x.push_back(1);
    // cout << x.max_size() << "\n";
    // ft::vector<int> x(1, 99);
    // x.push_back(10);
    // x.push_back(10);
    // x.push_back(10);
    // x.push_back(10);
    // x.push_back(10);
    // x.reserve(5);
    // std::cout << x[0] << "\n";
    // std::cout << x[25] << "\n";
    // std::cout << x[5] << "\n";
    // std::cout << x[7] << "\n";
    // std::cout << x[8] << "\n";
    // std::cout << x[9] << "\n";
    // std::cout << x[10] << "\n";
    // std::cout << x[200] << "\n";
    // std::cout << x.capacity() << "\n";
    // ft::vector<int> *xb = new ft::vector<int>;
    // std::cout << (*xb)[100] << "\n";
    /// empty testing
    // std::cout <<  
    // std::vector<int> x(-1);
    // x.push_back(0);
    // x.push_back(1);
    // x.push_back(2);
    // x.push_back(3);
    // // x.push_back(4);
    // std::cout << x[0] << "\n";
    // std::cout << x[1] << "\n";
    // std::cout << x[2] << "\n";
    // std::cout << x[3] << "\n";
    // std::cout << x[4] << "\n";
    // std::cout << x.capacity() << "\n";
    // std::cout << x.empty() << "\n";
    // x.reserve(-1);
    // std::cout << x.capacity() << "\n";
    // std::cout << x.empty() << "\n";
    // std::cout << x[0] << "\n";
    // std::cout << x[1] << "\n";
    // std::cout << x[2] << "\n";
    // std::cout << x[3] << "\n";
    // std::cout << x[4] << "\n";
    // std::cout << x[5] << "\n";
    // std::cout << x[6] << "\n";
    // std::cout << x[7] << "\n";
    // std::vector<int> sadone;
    // sadone.push_back(-1);
    // sadone.push_back(1);
    // sadone.push_back(3);

    // std::cout << "Before\n";
    // std::cout << sadone[0] << "\n";
    // // std::cout << sadone[1] << "\n";
    // // std::cout << sadone[2] << "\n";
    // std::cout << "cap : " << sadone.capacity() << "\n";
    // std::cout << "After\n";
    // sadone.pop_back();
    // std::cout << sadone[0] << "\n";
    // std::cout << sadone[1] << "\n";
    // std::cout << sadone[2] << "\n";
    // std::cout << "cap : " << sadone.capacity() << "\n";
    ft::vector<int> foo;   // three ints with a value of 100
    ft::vector<int> bar;   // five ints with a value of 200

    foo.swap(bar);

    std::cout << "foo contains:";
    for (unsigned i=0; i<foo.size(); i++)
      std::cout << ' ' << foo[i];
    std::cout << '\n';

    std::cout << "bar contains:";
    for (unsigned i=0; i<bar.size(); i++)
      std::cout << ' ' << bar[i];
    std::cout << '\n';

    return 0;
}