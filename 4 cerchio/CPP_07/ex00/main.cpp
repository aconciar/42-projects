/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:43:07 by aconciar          #+#    #+#             */
/*   Updated: 2024/11/03 12:21:41 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

// int main() {
//     // Test for integers
//     int a = 2;
//     int b = 3;
    
//     std::cout << "Testing swap with integers..." << std::endl;
//     ::swap(a, b);
//     std::cout << "a = " << a << ", b = " << b << std::endl;
    
//     std::cout << "Testing min with integers..." << std::endl;
//     std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    
//     std::cout << "Testing max with integers..." << std::endl;
//     std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

//     // Test for strings
//     std::string c = "chaine1";
//     std::string d = "chaine2";
    
//     std::cout << "\nTesting swap with strings..." << std::endl;
//     ::swap(c, d);
//     std::cout << "c = " << c << ", d = " << d << std::endl;
    
//     std::cout << "Testing min with strings..." << std::endl;
//     std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    
//     std::cout << "Testing max with strings..." << std::endl;
//     std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

//     // Test for floating point numbers
//     float x = 4.2f;
//     float y = 7.3f;
    
//     std::cout << "\nTesting swap with floats..." << std::endl;
//     ::swap(x, y);
//     std::cout << "x = " << x << ", y = " << y << std::endl;
    
//     std::cout << "Testing min with floats..." << std::endl;
//     std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
    
//     std::cout << "Testing max with floats..." << std::endl;
//     std::cout << "max(x, y) = " << ::max(x, y) << std::endl;

//     // Test for characters
//     char char1 = 'a';
//     char char2 = 'z';

//     std::cout << "\nTesting swap with characters..." << std::endl;
//     ::swap(char1, char2);
//     std::cout << "char1 = " << char1 << ", char2 = " << char2 << std::endl;

//     std::cout << "Testing min with characters..." << std::endl;
//     std::cout << "min(char1, char2) = " << ::min(char1, char2) << std::endl;

//     std::cout << "Testing max with characters..." << std::endl;
//     std::cout << "max(char1, char2) = " << ::max(char1, char2) << std::endl;

//     return 0;
// }

class Awesome
{
  public:
    Awesome(void) : _n(0) {}
    Awesome( int n ) : _n( n ) {}
    Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
    bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
    bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
    bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
    bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
    bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
    bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
    int get_n() const { return _n; }
  private:
    int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int main(void)
{
	Awesome a(2), b(4);

        swap(a, b);
        std::cout << a << " " << b << std::endl;
        std::cout << max(a, b) << std::endl;
        std::cout << min(a, b) << std::endl;
        return (0);
}
