/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteartorconst_main.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:15:47 by sakllam           #+#    #+#             */
/*   Updated: 2022/08/14 11:49:32 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

int main()
{
{
    ft::vector<int> x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    ft::vector<int>::const_iterator b = x.begin();
    ft::vector<int>::const_iterator e = x.end();
    for (int i = 0; i < x.size(); ++i) {
      assert(b[i] == x[i]);
    }
    int index = 0;
    for (ft::vector<int>::const_iterator i = b; i < e; ++i) {
      assert(x[index] == *i);
      index++;
    }
    int rindex = x.size();
    for (ft::vector<int>::const_iterator i = e; e != i; --i) {
      rindex--;
      assert(x[rindex] == *i);
    }

    ft::vector<int>::const_iterator b2 = x.begin();
    ft::vector<int>::const_iterator e2 = x.end();
    b2 += 2;
    assert(b2 == b + 2 && *b2 == b[2]);
    e2 -= 2;
    assert(e2 == e - 2 && *e2 == *(e - 2));
    b2 -= 1;
    assert(b2 == b + 1 && *b2 == b[1]);
    assert(*(b++) == x[0]);
    assert(*b == x[1]);
    assert(*(b--) == x[1]);
    assert(*b == x[0]);
    std::cout << "the same iterator tests with const_iterator :: pass\n";
  }
}