#ifndef _GREGORIANDATE_H_
#define _GREGORIANDATE_H_

class GregorianDate {

public:
	unsigned int month;
	unsigned int day;
	int year;

	GregorianDate(unsigned int, unsigned int, int);
	void 	set(unsigned int, unsigned int, int);

	GregorianDate & 	operator++();
	bool	operator==(const GregorianDate &);
	bool  	operator!=(const GregorianDate &);
	unsigned int   	operator-(const GregorianDate &);
	GregorianDate 	operator-(unsigned int);
	GregorianDate 	operator+(unsigned int);
      
	void  get_string(char *, unsigned int);

	void print();
};

#endif
