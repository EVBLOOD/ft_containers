/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_enable.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:18:39 by sakllam           #+#    #+#             */
/*   Updated: 2022/08/12 15:17:57 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enable_if.hpp"
#include <vector>

// enable_if example: two ways of using enable_if
#include <iostream>
#include <type_traits>

// 1. the return type (bool) is only valid if T is an integral type:
template <class T>
typename ft::enable_if<std::is_integral<T>::value,bool>::type
  is_odd (T i) {return bool(i%2);}

// 2. the second template argument is only valid if T is an integral type:
template < class T, 
           class = typename ft::enable_if<std::is_integral<T>::value>::type>
bool is_even (T i) {return !bool(i%2);}


#include <string>
int main() {

  int i = 1;    // code does not compile if type of i is not integral

  std::cout << std::boolalpha;
  std::cout << "i is odd: " << is_odd(i) << std::endl;
  std::cout << "i is even: " << is_even(i) << std::endl;

  return 0;
}


// #include <type_traits>
// #include <iostream>

// template<bool>
// class enableIf {};

// template<>
// class enableIf<true> {
//   public:
//   typedef void type;
// };

// template <class T>
// void test(T x){
//   std::cout << "not unsigned\n"; 
// };
// // class = typename std::enable_if<std::is_integral<T>::value>::type>
// template <class T,
//           class = typename std::enable_if<std::is_unsigned<T>::value>::type>
// void test(T x) {
//   std::cout << "unsigned\n"; 
// }

// int main() {
//   unsigned long x = 10;
//   test(int());
//   test(double());
// //   test(x);
// }

