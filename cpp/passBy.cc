//Demo of passing by reference and passing by value
#include <iostream>
using namespace std;

int squareValue (int x) {
  x *= x;
  return x;
}

int squareReference (int& x) {
  x *= x;
  return x;
}


int main()
{
  int foo = 5;
  cout << foo << " after it's value is squared: ";
  squareValue(foo);
  cout << foo << "\n";

  int bar = 5;
  cout << bar << " after it's reference is squared: ";
  squareReference(bar);
  cout << bar << "\n";
  return 0;
}
