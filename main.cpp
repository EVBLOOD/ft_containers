#include "map/map.hpp"

// using namespace ft;
// #include <map>
int main()
{
  ft::map<int, int> x;
  x[1] = 0;
  x.insert({10,2});
  x.erase(1);
  x.erase(1);
  x.begin();
  x.end();
  x.empty();
  x.clear();
  x.find(1);
  ft::map<int, int>::iterator y = x.end();
}