// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.cpp                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/08/05 17:34:57 by sakllam           #+#    #+#             */
// /*   Updated: 2022/08/11 12:55:33 by sakllam          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <vector>
// #include "vector.hpp"
// #include <iostream>


// int main()
// {
//     // std::vector<int> x;
//     // cout << x.max_size() << "\n"; 
//     // x.push_back(1);
//     // cout << x.max_size() << "\n";
//     // ft::vector<int> x(1, 99);
//     // x.push_back(10);
//     // x.push_back(10);
//     // x.push_back(10);
//     // x.push_back(10);
//     // x.push_back(10);
//     // x.reserve(5);
//     // std::cout << x[0] << "\n";
//     // std::cout << x[25] << "\n";
//     // std::cout << x[5] << "\n";
//     // std::cout << x[7] << "\n";
//     // std::cout << x[8] << "\n";
//     // std::cout << x[9] << "\n";
//     // std::cout << x[10] << "\n";
//     // std::cout << x[200] << "\n";
//     // std::cout << x.capacity() << "\n";
//     // ft::vector<int> *xb = new ft::vector<int>;
//     // std::cout << (*xb)[100] << "\n";
//     /// empty testing
//     // std::cout <<  
//     // std::vector<int> x(-1);
//     // x.push_back(0);
//     // x.push_back(1);
//     // x.push_back(2);
//     // x.push_back(3);
//     // // x.push_back(4);
//     // std::cout << x[0] << "\n";
//     // std::cout << x[1] << "\n";
//     // std::cout << x[2] << "\n";
//     // std::cout << x[3] << "\n";
//     // std::cout << x[4] << "\n";
//     // std::cout << x.capacity() << "\n";
//     // std::cout << x.empty() << "\n";
//     // x.reserve(-1);
//     // std::cout << x.capacity() << "\n";
//     // std::cout << x.empty() << "\n";
//     // std::cout << x[0] << "\n";
//     // std::cout << x[1] << "\n";
//     // std::cout << x[2] << "\n";
//     // std::cout << x[3] << "\n";
//     // std::cout << x[4] << "\n";
//     // std::cout << x[5] << "\n";
//     // std::cout << x[6] << "\n";
//     // std::cout << x[7] << "\n";
//     // std::vector<int> sadone;
//     // sadone.push_back(-1);
//     // sadone.push_back(1);
//     // sadone.push_back(3);

//     // std::cout << "Before\n";
//     // std::cout << sadone[0] << "\n";
//     // // std::cout << sadone[1] << "\n";
//     // // std::cout << sadone[2] << "\n";
//     // std::cout << "cap : " << sadone.capacity() << "\n";
//     // std::cout << "After\n";
//     // sadone.pop_back();
//     // std::cout << sadone[0] << "\n";
//     // std::cout << sadone[1] << "\n";
//     // std::cout << sadone[2] << "\n";
//     // std::cout << "cap : " << sadone.capacity() << "\n";
//     ft::vector<int> foo(3, 100);   // three ints with a value of 100
//     ft::vector<int> bar(5, 200);   // five ints with a value of 200

//     // foo.swap(bar);
//     foo.assign(3, 1);
//     bar.assign(0, 99);

//     std::cout << "foo contains:";
//     for (unsigned i=0; i<foo.size(); i++)
//       std::cout << ' ' << foo[i];
//     std::cout << '\n';

//     std::cout << "bar contains:";
//     for (unsigned i=0; i<bar.size(); i++)
//       std::cout << ' ' << bar[i];
//     std::cout << '\n';
//     return 0;
// }

#include "vector.hpp"
#include <iostream>
#include <vector>

using std::cout;

int main() {
  {
    ft::vector<int> array;
    cout << "vector() default constructor :: pass\n";
  }
  {
    ft::vector<int> array2(10);
    cout << "vector(n) reserve constructor :: pass\n";
  }
  {
    try {
      ft::vector<int> array3(-1);
    } catch (std::length_error &e) {
      std::cout << "catching length error :: pass\n";
    }
  }
  {
    ft::vector<int> x(5);
    x[0] = 1;
    x[1] = 2;
    x[2] = 3;
    x[3] = 4;
    x[4] = 5;
    assert(x[0] == 1);
    assert(x[1] == 2);
    assert(x[2] == 3);
    assert(x[3] == 4);
    assert(x[4] == 5);
    std::cout << "testing [] overloading 1 :: pass\n";
  }
  {
    ft::vector<std::string> s(3);
    s[0] = "hello";
    s[1] = "oussama";
    s[2] = "world";
    assert(s[0] == "hello");
    assert(s[1] == "oussama");
    assert(s[2] == "world");
    std::cout << "testing [] overloading 2 :: pass\n";
  }
  {
    ft::vector<char> x(5, 'c');
    x[0] = 'x';
    x[1] = 'x';
    x[2] = 'x';
    x[3] = 'x';
    x[4] = 'x';
    assert(x[0] == 'x');
    assert(x[1] == 'x');
    assert(x[2] == 'x');
    assert(x[3] == 'x');
    assert(x[4] == 'x');
    std::cout << "testing [] overloading 3 :: pass\n";
  }
  {
    ft::vector<char> x(5, 'c');
    x[0] = 'x';
    x[1] = 'x';
    x.at(2) = 'y';
    x.at(3) = 'y';
    x.at(4) = 'y';
    assert(x.at(0) == 'x');
    assert(x.at(1) == 'x');
    assert(x.at(2) == 'y');
    assert(x.at(3) == 'y');
    assert(x.at(4) == 'y');
    std::cout << "testing at() method:: pass\n";
    try {
      char c = x.at(10);
    } catch (std::out_of_range &e) {
      std::cout << "testing at() method throwing error :: pass\n";
    }
  }
  {
    ft::vector<char> x(5, 'c');
    x[0] = 'x';
    x[1] = 'x';
    x.at(2) = 'y';
    x.at(3) = 'y';
    x.at(4) = 'y';
    assert(x.front() == 'x');
    assert(x.back() == 'y');
    std::cout << "testing front() method throwing error :: pass\n";
    std::cout << "testing back() method throwing error :: pass\n";
  }
  {
    ft::vector<char> x;
    assert(x.capacity() == 0);
    x.reserve(5);
    assert(x.capacity() == 5);
  }
  {
    ft::vector<char> x(5, 'c');
    assert(x.capacity() == 5);
    x.reserve(10);
    assert(x.capacity() == 10);
  }
  {
    ft::vector<char> x(5, 'c');
    assert(x.capacity() == 5);
    x.reserve(2);
    assert(x.capacity() == 5);
    std::cout << "testing reserve() method :: pass\n";
  }
  {
    ft::vector<char> x(5, 'c');
    ft::vector<char> y(5, 'c');
    ft::vector<char> z(5, 'c');
    assert(y.at(0) == 'c');
    assert(y.at(1) == 'c');
    assert(y.at(2) == 'c');
    assert(y.at(3) == 'c');
    assert(y.at(4) == 'c');
    assert(z.at(0) == 'c');
    assert(z.at(1) == 'c');
    assert(z.at(2) == 'c');
    assert(z.at(3) == 'c');
    assert(z.at(4) == 'c');
    y = z = x;
    assert(x.capacity() == y.capacity() && y.capacity() == z.capacity());
    assert(x.size() == y.size() && y.size() == z.size());
    std::cout << "testing assignment overloading :: pass\n";
    std::cout << "testing assignment chaining :: pass\n";
  }
  {
    ft::vector<int> x;
    assert(x.size() == 0);
    assert(x.capacity() == 0);
    x.push_back(1);
    assert(x.at(0) == 1);
    assert(x[0] == 1);
    assert(x.size() == 1);
    assert(x.capacity() == 1);
    x.push_back(2);
    assert(x.at(1) == 2);
    assert(x[1] == 2);
    assert(x.size() == 2);
    assert(x.capacity() == 2);
    x.push_back(4);
    assert(x.at(2) == 4);
    assert(x[2] == 4);
    assert(x.size() == 3);
    assert(x.capacity() == 4);
    x.push_back(5);
    assert(x.at(3) == 5);
    assert(x[3] == 5);
    assert(x.size() == 4);
    assert(x.capacity() == 4);
    x.push_back(6);
    assert(x.at(4) == 6);
    assert(x[4] == 6);
    assert(x.size() == 5);
    assert(x.capacity() == 8);
    x.push_back(8);
    assert(x.at(5) == 8);
    assert(x[5] == 8);
    assert(x.size() == 6);
    assert(x.capacity() == 8);
    std::cout << "testing push_back() method :: pass\n";
  }
  {
    ft::vector<int> test;
    test.push_back(4);
    test.push_back(4);
    assert(test.capacity() == 2);
    assert(test.size() == 2);
    test.pop_back();
    assert(test.capacity() == 2);
    assert(test.size() == 1);
    test.pop_back();
    assert(test.capacity() == 2);
    assert(test.size() == 0);
    // infinite loop ??
    // test.pop_back();
    // assert(test.capacity() == 2);
    // assert(test.size() == 18446744073709551615ul);
    std::cout << "testing pop_back() method :: pass\n";
  }
  {
    ft::vector<int> vec1;
    vec1.push_back(5);
    ft::vector<int> vec2;
    vec1.swap(vec2);
    assert(vec2.at(0) == 5);
    assert(vec2.capacity() == 1);
    assert(vec2.size() == 1);
    assert(vec1.capacity() == 0);
    assert(vec1.size() == 0);
  }
  {
    ft::vector<int> vec3;
    vec3.push_back(5);
    ft::vector<int> vec2;
    vec2.push_back(10);
    vec2.push_back(20);
    vec2.push_back(30);
    // cout << vec1.at(0) << '\n';
    // cout << vec2.at(0) << '\n';
    // cout << vec2.at(1) << '\n';
    // cout << vec2.at(2) << '\n';
    vec3.swap(vec2);
    assert(vec2.capacity() == 1);
    assert(vec2.size() == 1);
    assert(vec3.capacity() == 4);
    assert(vec3.size() == 3);
    assert(vec2.at(0) == 5);
    assert(vec3.at(0) == 10);
    // cout << vec2.at(0) << '\n';
    // cout << vec1.at(0) << '\n';
    // cout << vec1.at(1) << '\n';
    // cout << vec1.at(2) << '\n';
    assert(vec3.at(1) == 20);
    assert(vec3.at(2) == 30);
    std::cout << "testing swap() method :: pass\n";
  }
  {
    ft::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    assert(vec.capacity() == 4 && vec.size() == 3);
    vec.clear();
    assert(vec.capacity() == 4 && vec.size() == 0);
    std::cout << "testing clear() method :: pass\n";
  }
  {
    ft::vector<int> vec;
    std::allocator<int> alloc = vec.get_allocator();
    int *arr = alloc.allocate(4);
    arr[0] = 10;
    arr[1] = 15;
    arr[2] = 20;
    arr[3] = 25;
    assert(arr[0] == 10);
    assert(arr[1] == 15);
    assert(arr[2] == 20);
    assert(arr[3] == 25);
    alloc.deallocate(arr, 4);
    std::cout << "testing get_allocator() method :: pass\n";
  }
  {
    ft::vector<int> x;
    x.push_back(10);
    x.push_back(10);
    x.assign(5, 20);
    assert(x.capacity() == 5);
    assert(x.at(0) == 20);
    assert(x.at(2) == 20);
    assert(x.at(1) == 20);
    assert(x.at(3) == 20);
    assert(x.at(4) == 20);
  } 
  {
    ft::vector<int> x;
    x.push_back(10);
    x.push_back(10);
    x.push_back(10);
    x.push_back(10);
    x.push_back(10);
    x.push_back(10);
    x.push_back(10);
    x.push_back(10);
    x.push_back(10);
    x.assign(5, 20);
    assert(x.capacity() == 16 && x.size() == 5);
    assert(x.at(0) == 20);
    assert(x.at(2) == 20);
    assert(x.at(1) == 20);
    assert(x.at(3) == 20);
    assert(x.at(4) == 20);
  } 
  {
    ft::vector<int> x;
    x.push_back(10);
    x.push_back(10);
    x.assign(0, 0);
    assert(x.capacity() == 2 && x.size() == 0);
    std::cout << "testing assign() method :: pass\n";
  } 

  std::cerr << "all passed\n";
  system("leaks a.out");

  std::vector<int> s1;
  std::vector<char> s2;

  cout << s1.max_size() << "\n";
  cout << s2.max_size() << std::endl;
}