#include <iostream>
#include "GregorianDate.h"
#include "CalUtils.h"

GregorianDate::GregorianDate(unsigned int m, unsigned int d,
		int y) {


	//I think this is the best you can do, beauty wise
	if  (	m < 1 || m > 12 ||
			d < 1 || d > 31 ||
			(m == 2 && 
			 ((CalUtils::is_leap(y) && d > 29) ||
			  (!CalUtils::is_leap(y) && d > 28)
			 )
			)
		) {
		throw;
	}

	month = m;
	day = d;
	year = y;
}

void GregorianDate::set(unsigned int m,	unsigned int d,
		int y) {

	//I think this is the best you can do, beauty wise
	if  (	m < 1 || m > 12 ||
			d < 1 || d > 31 ||
			(m == 2 &&
			 (CalUtils::is_leap(y) && d > 29) ||
			 (!CalUtils::is_leap(y) && d > 28)
			)
		) {
		throw;
	}

	month = m;
	day = d;
	year = y;
	
	return;
}

/* Number of days from 8/11/-3113 */
unsigned int GregorianDate::operator-(const GregorianDate & rhs) {

	//Check which year is before the other
	bool rhs_before = false;
	if 	( 	(rhs.year < this->year) ||
			(rhs.year == this->year &&
		 	 	rhs.month < this->month) ||
			(rhs.year == this->year &&
		 		rhs.month == this->month &&
		 		rhs.day <= this->day)
		) {
		rhs_before = true;
	}
	int sYear = rhs_before ? rhs.year : this->year;
	int sMonth = rhs_before ? rhs.month : this->month;
	int sDay = rhs_before ? rhs.day : this->day;
	int eYear = !rhs_before ? rhs.year : this->year;
	int eMonth = !rhs_before ? rhs.month : this->month;
	int eDay = !rhs_before ? rhs.day : this->day;


	//If in same month & year as start
	if(sYear == eYear && sMonth == eMonth) {
		return eDay - sDay;
	}

	unsigned int days = 0;

	//How many days have happened in August -3113
	days = CalUtils::days_month(sMonth, sYear) - sDay;
	sMonth++;

	while(!(sYear == eYear && sMonth == eMonth)) {
		days += CalUtils::days_month(sMonth, sYear);
		sMonth++;

		if(sMonth > 12) {
			sMonth = 1;
			sYear++;
		}
	}

	//We are in same month and year, add days
	days += eDay;

	return days;
}

GregorianDate GregorianDate::operator+(unsigned int rhs) {
	unsigned int days = rhs;

	GregorianDate newDate(month, day, year);

	//If we add Days and we are still in August -3113
//	if( (CalUtils::days_month(month, year) - day) >= days) {
//		newDate->day += days;
//		return newDate;
//	}

	while (days > (CalUtils::days_month(newDate.month,newDate.year) - newDate.day) ) {
		days = days - (CalUtils::days_month(newDate.month, newDate.year) - newDate.day + 1);
		newDate.day = 1;
		newDate.month++;

		if(newDate.month > 12) {
			newDate.year++;
			newDate.month = 1;
		}
	}

	newDate.day += days;

	return newDate;
}

void GregorianDate::print() {
	std::cout << month << "/" << day << "/" << year << "\n";
	return;
}
