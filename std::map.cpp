/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std::map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:06:39 by sakllam           #+#    #+#             */
/*   Updated: 2022/09/28 13:38:52 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "map/map.hpp"

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main ()
{
  {
    // constructors test + operator[]
    ft::map<char,int> first;
    first['a']  = 10;
    first['a']  = 11;
    first['b']  = 30;
    first['c']  = 50;
    first['d']  = 70;
    ft::map<char,int> second (first.begin(),first.end());
    ft::map<char,int> third (second);
  
    ft::map<char,int,classcomp> fourth;
  
    bool(*fn_pt)(char,char) = fncomp;
    ft::map<char,int,bool(*)(char,char)> fifth (fn_pt);
    first.my_tree._printing();
    std::cout << "=============================================================\n";
    second.my_tree._printing();
    std::cout << "=============================================================\n";
    third.my_tree._printing();
    std::cout << "=============================================================\n";
    fifth.my_tree._printing();
    std::cout << "=============================================================\n";
  }
  std::cout << "=============================================================\n";
  { // assignement operator
    ft::map<char,int> first;
    ft::map<char,int> second;
  
    first['x'] = 8;
    first['y'] = 16;
    first['z'] = 32;
    second['a'] = 32;
  
    second = first;
    first = ft::map<char,int>();
  
    std::cout << "Size of first: " << first.size() << '\n';
    std::cout << "Size of second: " << second.size() << '\n';
    std::cout << "=============================================================\n";
    first.my_tree._printing();
    std::cout << "=============================================================\n";
    second.my_tree._printing();
  }
  std::cout << "=============================================================\n";
  { // iterators begin and end
    ft::map<char,int> mymap;

    mymap['b'] = 100;
    mymap['a'] = 200;
    mymap['c'] = 300;
  
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
      std::cout << it->first << " => " << it->second << '\n';
  }
  std::cout << "=============================================================\n";
  { // iterators rbegin and rend
    ft::map<char,int> mymap;
  
    mymap['x'] = 100;
    mymap['y'] = 200;
    mymap['z'] = 300;
  
    for (ft::map<char,int>::reverse_iterator it=mymap.rbegin(); it!=mymap.rend(); ++it)
      std::cout << it->first << " => " << it->second << '\n';
  }
  std::cout << "=============================================================\n";
  { // empty() + size()
    ft::map<char,int> mymap;
  
    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    mymap['c']=30;

    std::cout << "size before " << mymap.size() << "\n";
    while (!mymap.empty())
    {
      std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
      mymap.erase(mymap.begin());
    }
    std::cout << "size after " << mymap.size() << "\n";
  }
  std::cout << "=============================================================\n";
  return 0;
}