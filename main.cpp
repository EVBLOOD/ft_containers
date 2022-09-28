#include "map/map.hpp"
#include "additional/my_map_iters.hpp"
// #include <iterator>
// using namespace ft;
// #include "vector/vector.hpp"
#include <map>
#include <vector>
#include <iostream>
int main()
{
  ft::map<int, int> m;
  ft::map<int, int> n;
  // ft::vector<int> jk;
  // m[1] = 0;
  // m[2] = 20;
  // m[3] = 50;
  // m[3] = 10;
  // m[1] = 100;
  m.insert({9,2});
  m.insert({5,2});
  m.insert({11,2});
  m.insert({13,2});
  m.insert({10,2});
  m.insert({8,2});
  ft::map<int, int>::iterator a = m.begin();
  ft::map<int, int>::iterator b = m.end();
  // a++;
  // std::cout << a->first << "s";
  // while (a != m.end())
  // {
  //   puts("heh");
  //   ++a;
  // }
  // if (a == m.end())
  // {
  //   puts("Cccc");
  // }
  // ++a;
  // std::cout << a->first << "\n";
  n.insert(a, b);
  // std::cout << b->first << "\n";
  // m.erase(1);
  // ft::map<int, int>::iterator b = m.begin();
  // ft::map<int, int> x;
  // // ft::map<int, int> n;
  // x[1] = 0;
  // m = n;
  // n = m;
  // m.erase(1);
  // x.erase(1);
  // x.begin();
  // x.end();
  // x.empty();
  // x.clear();
  // x.find(1);
  // ft::map<int, int>::iterator y = x.end();
  // x.max_size();
  // m.swap(n);
  // n.my_tree._printing();
  n.my_tree._printing();
  puts("----------------------------------------------------------");
  m.my_tree._printing();

}