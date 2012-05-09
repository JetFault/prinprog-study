#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
  string foo = "5";
  int bar;
  stringstream(foo) >> bar;
  cout << bar * 2 << endl;
  return 0;
}
