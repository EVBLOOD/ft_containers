/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std::set.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:26:18 by sakllam           #+#    #+#             */
/*   Updated: 2022/09/29 17:45:39 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include <iostream>

bool fncomp (int lhs, int rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};

int main ()
{
  {
    // constructors test
    std::set<int> first;
    first.insert(10);
    first.insert(10);
    first.insert(11);
    first.insert(30);
    first.insert(50);
    first.insert(70);
    std::set<int> second (first.begin(),first.end());
    std::set<int> third (second);
  
    std::set<int, classcomp> fourth;
  
    bool(*fn_pt)(int,int) = fncomp;
    std::set<int,bool(*)(int,int)> fifth (fn_pt);
    // first.my_tree._printing();
    std::cout << "=============================================================\n";
    // second.my_tree._printing();
    std::cout << "=============================================================\n";
    // third.my_tree._printing();
    std::cout << "=============================================================\n";
    // fifth.my_tree._printing();
    std::cout << "=============================================================\n";
  }
  std::cout << "=============================================================\n";
  { // assignement operator
    std::set<char> first;
    std::set<char> second;
  
    first.insert('x');
    first.insert('y');
    first.insert('z');
    second.insert('a');
  
    second = first;
    first = std::set<char>();
  
    std::cout << "Size of first: " << first.size() << '\n';
    std::cout << "Size of second: " << second.size() << '\n';
    std::cout << "=============================================================\n";
    // first.my_tree._printing();
    std::cout << "=============================================================\n";
    // second.my_tree._printing();
  }
  std::cout << "=============================================================\n";
  { // iterators begin and end
    std::set<int> mymap;

    mymap.insert(100);
    mymap.insert(200);
    mymap.insert(300);
  
    for (std::set<int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
      std::cout << *it << " => " << *it << '\n';
  }
  std::cout << "=============================================================\n";
  { // iterators rbegin and rend
    std::set<char> mymap;
  
    mymap.insert('x');
    mymap.insert('y');
    mymap.insert('z');
  
    for (std::set<char>::reverse_iterator it=mymap.rbegin(); it!=mymap.rend(); ++it)
      std::cout << *it << " => " << *it << '\n';
  }
  std::cout << "=============================================================\n";
  { // empty() + size()
    std::set<char> mymap;
  
   mymap.insert('a');
   mymap.insert('b');
   mymap.insert('c');
   mymap.insert('c');

    std::cout << "size before " << mymap.size() << "\n";
    while (!mymap.empty())
    {
      std::cout << *(mymap.begin()) << '\n';
      mymap.erase(mymap.begin());
    }
    std::cout << "size after " << mymap.size() << "\n";
  }
  std::cout << "=============================================================\n";
  { // max_size()
    int i;
    std::set<int> mymap;
  
    if (mymap.max_size() > 1000)
    {
      for (i = 0; i < 1000; i++) mymap.insert(i);
      std::cout << "The set contains 1000 elements.\n";
    }
    else std::cout << "The set could not hold 1000 elements.\n";
  }
  std::cout << "=============================================================\n";
  { // insert
    std::set<char> mymap;
    mymap.insert ('a');
    mymap.insert ('z');
  
    std::pair<std::set<char>::iterator,bool> ret;
    ret = mymap.insert ('z');
    if (ret.second==false) {
      std::cout << "element 'z' already existed\n";
    }
  
    std::set<char>::iterator it = mymap.begin();
    mymap.insert (it, 'b');
    mymap.insert (it,'c');
  
    std::set<char> anothermap;
    anothermap.insert(mymap.begin(),mymap.find('c'));
  
    std::cout << "mymap contains:\n";
    for (it=mymap.begin(); it!=mymap.end(); ++it)
      std::cout << *it << '\n';
  
    std::cout << "anothermap contains:\n";
    for (it=anothermap.begin(); it!=anothermap.end(); ++it)
      std::cout << *it << '\n'; 
  }
  std::cout << "=============================================================\n";
  {
    std::set<char> mymap;
    std::set<char>::iterator it;
    mymap.insert('a');
    mymap.insert('b');
    mymap.insert('c');
    mymap.insert('d');
    mymap.insert('e');
    mymap.insert('f');
    it = mymap.find('b');
    mymap.erase (it);
    
    mymap.erase ('c');
    
    it = mymap.find ('e');
    mymap.erase ( it, mymap.end() );
    
    for (it=mymap.begin(); it!=mymap.end(); ++it)
      std::cout << *it << '\n';
    // mymap.my_tree._printing();
  }
  std::cout << "=============================================================\n";
  { // swap
    std::set<char> foo,bar;
    foo.insert('x');
    foo.insert('y');
    bar.insert('a');
    bar.insert('b');
    bar.insert('c');
    foo.swap(bar);
    std::cout << "foo contains:\n";
    for (std::set<char>::iterator it=foo.begin(); it!=foo.end(); ++it)
      std::cout << *it << '\n';
    std::cout << "bar contains:\n";
    for (std::set<char>::iterator it=bar.begin(); it!=bar.end(); ++it)
      std::cout << *it << '\n';
  }
  std::cout << "=============================================================\n";
  { // clear();
    std::set<char> mymap;
    mymap.insert('x');
    mymap.insert('y');
    mymap.insert('z');
    std::cout << "mymap contains:\n";
    for (std::set<char>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
      std::cout << *it <<  '\n';
    mymap.clear();
    mymap.insert('a');
    mymap.insert('b');
    std::cout << "mymap contains:\n";
    for (std::set<char>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
      std::cout << *it << '\n';
    //  mymap.my_tree._printing();
  }
  std::cout << "=============================================================\n";
  { // key_comp
    std::set<char> mymap;
    
    std::set<char>::key_compare mycomp = mymap.key_comp();
    
    mymap.insert('a');
    mymap.insert('b');
    mymap.insert('c');
    
    std::cout << "mymap contains:\n";
    
    char highest = *mymap.rbegin();
    std::set<char>::iterator it = mymap.begin();
    do {
      std::cout << *it << '\n';
    } while ( mycomp(*it++, highest) );
  }
  std::cout << "=============================================================\n";
  { // value_comp
    std::set<char> mymap;
    mymap.insert('x');
    mymap.insert('y');
    mymap.insert('z');
    std::cout << "mymap contains:\n";
    char highest = *mymap.rbegin();
    std::set<char>::iterator it = mymap.begin();
    do {
      std::cout << *it << '\n';
    } while ( mymap.value_comp()(*it++, highest) );
  }
  std::cout << "=============================================================\n";
  { // find
    std::set<char> mymap;
    std::set<char>::iterator it;
    mymap.insert('a');
    mymap.insert('b');
    mymap.insert('c');
    mymap.insert('d');
    it = mymap.find('b');
    if (it != mymap.end())
      mymap.erase (it);
    std::cout << "elements in mymap:" << '\n';
    std::cout << "a => " << *(mymap.find('a')) << '\n';
    std::cout << "c => " << *(mymap.find('c')) << '\n';
    std::cout << "d => " << *(mymap.find('d')) << '\n';
  }
  {
    std::set<char> mymap;
    char c;
  
    mymap.insert('a');
    mymap.insert('c');
    mymap.insert('f');
    for (c='a'; c<'h'; c++)
    {
      std::cout << c;
      if (mymap.count(c) > 0)
        std::cout << " is an element of mymap.\n";
      else 
        std::cout << " is not an element of mymap.\n";
    }
  }
  std::cout << "=============================================================\n";
  { //lower + upper
    std::set<char> mymap;
    std::set<char>::iterator itlow,itup;
  
     mymap.insert('a');
     mymap.insert('b');
     mymap.insert('c');
     mymap.insert('d');
     mymap.insert('e');
  
    itlow=mymap.lower_bound ('b');
    itup=mymap.upper_bound ('d');
  
    std::cout << *itlow << "\n";
    std::cout << *itup << "\n";
    mymap.erase(itlow,itup);
    // mymap.my_tree._printing();
    for (std::set<char>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
      std::cout << *it << '\n';
  }
  std::cout << "=============================================================\n";
  {
    std::set<char> mymap;

    mymap.insert('a');
    mymap.insert('b');
    mymap.insert('c');

    std::pair<std::set<char>::iterator,std::set<char>::iterator> ret;
    ret = mymap.equal_range('b');
    std::cout << "lower bound points to: ";
    std::cout << *ret.first << '\n';
    std::cout << "upper bound points to: ";
    std::cout << *ret.second << "\n";
  }
  std::cout << "=============================================================\n";
  // system("leaks a.out");
  return 0;
}

