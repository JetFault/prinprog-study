#include <iostream>
using namespace std;

int main()
{
  int x;
  int& r=x;
  x=11;
  r++;
  cout << "x: " << x << endl;
  cout << "r: " << r << endl;
  return 0;
}
