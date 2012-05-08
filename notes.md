<pre>
References:
	-references are not pointers
	-a reference to a reference is meaningless

ex)
int x;
int & r=x;
x=11;
r++;

	-no special syntax to use references in a code
	-size of a reference is the size of the initializer variable
	-cannot make an array of references
	
I)
void
swap(int & x, int & y)
{
	int t;
	
	t = x;
	x = y;
	y = t;
}

II)
int a[10];
int * p = a;
int & r = a[0];

r = 37;
r++;
p++;
a[9] = r;
a[8] = *p;


III)
f(int);
f(float);
f(double);
f(char);

f(0);
f((char)0);
f('c');
f(3);
	-the above arguments did not have a return type
	
CONSTRUCTORS AND DESTRUCTORS
Constructors:
	- invoked before main for global and static variables
	- invoked when entering the scope contaiing the variable for automatic variables
Destructors:
	-destructors for global static structures are invoked AFTER main exits
	-no syntax for invoking destructor, they can invoke implicitly
	-destructors for automatic objects are evoked implicitly (without source code) 
	when we exit the scope containing the automatic variable declarations.
	-destructors for dynamically allocated objects will be implicitly invoked when we deallocate the memory for the dynamic object.
	
Deallocation:
	-

EX)
#ifndef ECMblock_h
#define ECMblock_h

#include "Error.h"

class ECMblock {
	char * ptr; //ptr to a block of memory
	unsigned int mingrowth; //a constructor argument, this is the amount of space added to block when more space is needed
	unsigned int memsize; //size of block
	unsigned int space_used; //block space used
	
public:

		ECMblock(unsigned int);
		~ECMblock();
	
	void* append(unsigned int);
	Result append(const voide*, unsigned int);
	void* get_ptr() const;
	unsigned int get_size() const { return space_used; }
	Result drop(unsigned int);
	Result drop(unsigned int, unsigned int);
	Result clear();
	
};
#endif

-private variables CANNOT be accessed outside of the class
-you can expand a block of memory by some size,
-this class can be described as an extensible contiguous block of memory

EX)

#include "ECMblock.h"
#include <stdio.h>
#include <string.h>

//static class instantiation example

static ECMblock block(30);

int main(int argc, char** argv)
{
	int i;
	printf("main() invoked\n");
	for(i = 0; i < argc; i++)
	{
		block.append(argv[i], ::strlen(argv[i]+1));
	}
	printf("main() exits\n");
	return 0;
}

ECMblock::ECMblock(unsigned int minimum) // the :: means append: here, you are initializing the append member function for the ECMbloxck class
{
	::printf("ECMblock constructor invoked\n");
	otr = 0;
	mingrowth = minimum;
	memsize = 0;
	space_used = 0;
}

ECMblock::~ECMblock()
{
	printf("ECMblock destructor invoked\n");
	if(ptr!=0) ::free(ptr;
}

void* ECMblock::append(unsigned int len)
{
	unsigned int x;
	unsigned int oldlen;
	const char* func = "ECMblock::append";
	
	x = (len<mingrowth) ? mingrowth : len;
	if(len == 0)
	{
		return 0;
	}
	else if (len <= (memsize - space_used))
	{
		oldlen = space_used;
		space_used += len;
		return ptr+oldlen;
	}
	else if (ptr = 0)
	{
		if(ptr = (char*)::malloc(c)) == 0)
		{
			space used = 0;
			memsize = 0;
			component_failure("malloc", func, __FILE__, __LINE__);
			return 0;
		}
		else
		{
			if((ptr=(char *)rrealloc(ptr, memsize, memsize+x))==0)
			{
				space used = 0;
				
			}
		}
	
	}
}

-you dont NEED to put your header in a .h file. 	
-inside the member function definition, you are inside the scope of the class declaration
-java stole this beautiful idea from a much better language
-:: will also set a global to 1, so if you declare a global, then inside a function do::var = 2, you will change the ddefinition of the global var



EX)

#include "ECMblock.h"
#include <stdio.h>
#include <string.h>
//global class instantiation example
ECMblock block(30);

int main(int argc, char**argv)
{
	int i;
	
	printf("main() invoked
	for(i=0; i < argc; i++)
	{
		block.append(argv[i], :strlen(argv[i] + 1));
	}
	printf("main() exitsd\n");
	return 0;
}

EX)

#include "ECMblock.h"
#include <stdio.h>
#include <string.h>
//automatic class instantiation example

int main(int argc, char**argv)
{
	printf("main() invoked\n");
	int i;
	ECMblock block(30);

	for(i=0; i < argc; i++)
	{
		block.append(argv[i], :strlen(argv[i] + 1));
	}
	printf("main() exitsd\n");
	return 0;
}
-no garbage collection in C++

#include "ECMblock.h"
#include <stdio.h>
#include <string.h>

//Dynamicall allocated class instantiation example

int main(int argc, char ** argv)
{
	int i;
	ECMblock * pb;
	
	printf("main() invoked.\n");
	pb = new ECMblock(30);
	for(i=0; i<argc; i++)
	{
		pb->appenc(argv[i], ::strlen(argv[i] + 1));
	}
	delete pb;
	printf("main() exits.\n");
	return 0;
}

<b>DYNAMIC ALLOCATION</b>

EX)
int k;
int* p;
char* p3;

p = new int; //p now points to a dynamically allocated integer


-http://stackoverflow.com/questions/240212/what-is-the-difference-between-new-delete-and-malloc-free :this is a good difference between new and malloc
-C++ compilers can have up ot 3 heaps!!!!!!!!

-CANNOT BE OVERLOADED: . , :: , ?:, sizeof, 

EX)
class complex{
float re,im;

public:
	complex();
	complex(float);
	complex(float, float);

complex operator+(const complex &);
complex& operator +=(const complex&)

void set(float, float);

complex
complex::operator+(const complex& c)const
{
	float r, i;
	r = re + c.re
	i - im + c.im;
	return complex(r, i);
}

complex &
complex::operator+=(const complex & c)
{
	re += c.re;
	im += c.im;
	return * this;
}

complex x, y, z;

x.set(3.0, 4.0);
y.set(7.0, 8.0);

x+=y;
complex operator+(const complex &c, floatx) //non member 
{
	return complex(c.re + x, c.im)
}
	complex A, B;
	B = A+7;
A = 7 + B;

-In C++, your friend defines who can touch your private part.
~ I am cute, round, and bouncy
~ You can give another class a ‘friend’ status, which allows another class to edit a classes private variables
~ Friendship is not reciprocal.
~ Friendship is not inheritable


EX)
class Date
{
	date & operator++(); //meant to be postfix
	date & operator++(int); //dummy arg to show postfix

}

-there is no assumption of commutativity for overloaded operators

EX)
#ifndef SearchPath_h
#define SearchPath_h

#include “Vector.h”

enum Direction{ dir_none, dir_left, dir_right, fir_found};

struct SearchStep {
	Item* node;
	Direction

***INCOMPLETE***


#include “SearchPath.h”

SearchStep::SearchStep(Item* p, Direction dir)

SearchPath::SearchPath() : vector(sizeof(SearchStep))
{
	laststep = -1;
}

SearchPath::~SearchPath()
{
}
void
SearchPath::push_step(Item * node, Direction direction)
{
	SearchStep* p;
	p = (SearchStep *)vector.append(sizeof(SearchStep));
	new(p) SearchStep(node, direction); //placement new
	++laststep;
}

int SearchPath::pop_step()
{
	if (laststep < 0)
	{
		laststep = -1;

****INCOMPLETE****

Const:
	int * ptr; //can change the pointer and edit the value being pointed to 
/*
 ptr = &x;
ptr = &y;
*ptr = 4;
*/
	const int * ptr; //can change the pointer, cannot change the data being pointed to
	int * const ptr; //
	const int * const ptr = &x;








struct point
{
	floatx, y;
};

class LineSegment
{
	point p1, p2;

public:
		LineSegment();
	void setP1(float, float);
	void setP2(float, float);
	float length() const; /*appending the word const to the declaration and definition of a member function, i am promising that the compiler will complain to me if i change any of the data members, and that I will not change the data members*/

-it would not make sense to append const to a constructor, because then you couldnt change the data members in the constructor to set them up. 

void
LineSegment::setP1(float x, float y)
{
	p1.x=x;
	p1.y=y;
}

-f if you say const on the declaration, you must declare it in the definition, or the comiler will complain

float LineSegment::length() const
{
	float xdiff, ydiff;
	xdiff = p1.x-p2.x;
	ydiff = p1.y-p2.y;
	return sort(xdiff*xdiff + ydiff*ydif)
}

class intArray
{
	ECMblock eblock;

public:
	int& opterator[](unsigned int);
	int operator[](unsigned int) const;
}

class alpha
{
	:
	void g()
	void h{) const;
};
class delta
{
	alpha a_part;
	void f() const;
}
void delta::f() const
{
	a_part.h() ;//ok
	a_part.h(); //error, because h is a const, and by declaring at such, you promised not to 
      //change the data inside the class.
}

class myClass
{
	int * ptr;
	unsigned int howmany;

public:
	myclass(unsigned int);
	myclass(const myclass &);

	~myclass();

myclass::myclass(unsigned int n)
{
	pts = new int[n];
	howmany = n;
}
myclass ::~myclass()
{
	if(ptr!=0) delete[ ] ptr;
}
myclass::myclass(const myclass &m)
{
if(m.howmany == 0)
{	
	ptr = 0;
		howmany = 
}
else
{
	ptr < net int[m.howmany];
	for (int i = 0; i<m.howmany; i++)
		ptr[i] = m.ptr[i];
	howmany = m.howmany;
}
}
}

class myclass
{
int * ptr;
unsigned int howmany;	
public:
	myclass(unsigned int);
	myclass(const myclass &); //copy constructor
	myclass(myclass); //no!!!!!!
	myclass();
}

class symbolTable
{
private:
	symbolTable & operator = (constsymbolTable &);
	symbolTable(const symbolTable &);





when an exception is thrown, c++ tries to find a catch block in the same function that threw the exception. It uses rules similar to java. if there is no try block or fails to find a matching catch block then it goes to the calling function and tries the same this. if the entire stack pops without finding anything than the program terminates

</pre>
