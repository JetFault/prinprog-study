#include <iostream>
using namespace std;

class Rectangle {
  private:
    int width;
    int height;
  public: 
    Rectangle (int x, int y);
    int area ();
    int perimeter ();
    Rectangle operator+ (Rectangle other);
};

int main()
{
  Rectangle a = Rectangle(3,4);
  Rectangle b = Rectangle(2,5);

  cout << a.area() << endl;
  cout << b.perimeter() << endl;

  cout << (a+b).area() << endl;
  return 0;
}

Rectangle::Rectangle (int x, int y) {
  width = x;
  height = y;
}

int Rectangle::area () {
  return width * height;
}

int Rectangle::perimeter () {
  return 2*width + 2*height;
}

Rectangle Rectangle::operator+ (Rectangle other) {
  Rectangle temp = Rectangle(width+other.width, height+other.height);
  return temp;
}
