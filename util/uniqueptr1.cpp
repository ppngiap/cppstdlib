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
#include <iostream>
#include <string>
#include <memory>    // for unique_ptr
#include <dirent.h>  // for opendir(), ...
#include <cstring>   // for strerror()
#include <cerrno>    // for errno
#include <cassert>
using namespace std;

class Hello
{
  public:
    Hello(const string& m) : msg(m) {}
    ~Hello() { cout << msg << endl; }

  private:
    string msg;
};

void sink(unique_ptr<Hello> u)
{

}

int main()
{
    unique_ptr<Hello> a{new Hello("a")};
    assert(a);
    sink(std::move(a));
    assert(!a);
    unique_ptr<Hello> b{new Hello("b")};
    assert(b);
}
