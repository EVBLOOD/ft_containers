#include <functional>
#include <map>
#include <iostream>
#include <ostream>
int main()
{
    std::map<int, int, std::less<int> > a;
    a[1] = 1;
    a[3] = 1;
    a[0] = 1;
    a[2] = 1;
    a[-1] = 1;
    a[4] = 1;
    // std::map<int, int>::iterator x = a.begin();
    std::cout << "  l l " << NULL << std::endl;
    // while (x != a.end())
    // {
    //     std::cout << "this is it : " << x->first << "\n";
    //     (*x++;
    // }
}

// keep it with me EACH TIME.. means wasting time

// an other way => to go right till you find your shit!
