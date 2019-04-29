/* The following code example is taken from the book
 * "The C++ Standard Library - A Tutorial and Reference, 2nd Edition"
 * by Nicolai M. Josuttis, Addison-Wesley, 2012
 *
 * (C) Copyright Nicolai M. Josuttis 2012.
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 */
#include <cmath>

#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main()
{
   // use textual representation for bool
   cout << boolalpha;

   // print maximum of integral types
   cout << "max(short): " << numeric_limits<short>::max() << endl;
   cout << "max(int):   " << numeric_limits<int>::max() << endl;
   cout << "max(unsigned int):   " << numeric_limits<unsigned int>::max() << endl;
   cout << "pow(2, 32): " << pow(2, 31) << endl;
   cout << "max(long):  " << (double) numeric_limits<long>::max() << endl;
   cout << endl;

   // print maximum of floating-point types
   cout << "max(float):       "
        << numeric_limits<float>::max() << endl;
   cout << "max(double):      "
        << numeric_limits<double>::max() << endl;
   cout << "max(long double): "
        << numeric_limits<long double>::max() << endl;
   cout << endl;

   // print whether char is signed
   cout << "is_signed(char): "
        << numeric_limits<char>::is_signed << endl;
   cout << endl;

   // print whether numeric limits for type string exist
   cout << "is_specialized(string): " << numeric_limits<string>::is_specialized << endl;
   cout << "is_specialized(int): " << numeric_limits<int>::is_specialized << endl;

   // print epsilon
   cout << "epsilon(float):       " << numeric_limits<float>::epsilon() << endl;
   cout << "epsilon(double):       " << numeric_limits<double>::epsilon() << endl;

   // print infinity
   cout << "has_infinity(float):       " << numeric_limits<float>::has_infinity << endl;
   cout << "infinity(float):       " << numeric_limits<float>::infinity() << endl;
   cout << "infinity(double):       " << numeric_limits<double>::infinity() << endl;
}
