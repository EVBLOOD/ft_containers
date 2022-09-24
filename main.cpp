#include "map/map.hpp"
#include "additional/my_map_iters.hpp"
// #include <iterator>
// using namespace ft;
// #include "vector/vector.hpp"
// #include <map>
#include <vector>
int main()
{
  ft::map<int, int> m;
  ft::map<int, int> n;
  // ft::vector<int> jk;
  m[1] = 0;
  std::vector<int>::iterator c;
  ft::map<int, int>::iterator b = m.begin();
  // int x = b->second;
  // ft::map<int, int> x;
  // ft::map<int, int> n;
  // x[1] = 0;
  m = n;
  // x.insert({10,2});
  // x.erase(1);
  // x.erase(1);
  // x.begin();
  // x.end();
  // x.empty();
  // x.clear();
  // x.find(1);
  // ft::map<int, int>::iterator y = x.end();
  // x.max_size();
  m.swap(n);

}