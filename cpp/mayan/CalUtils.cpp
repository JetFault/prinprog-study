#include "CalUtils.h"

namespace CalUtils {

	int days_month(unsigned int month, int year) {
		int days_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		
		int days = days_month[(month-1) % 12];
		if(month == 2 && is_leap(year)) {
			days++;
		}

		return days;
	}

	bool is_leap(int year) {
		
		//1BC = 0, 4BC = -3
		//First leap year is 4BC, -3.
		if(year < 1) {
			year = (year * -1);
		}

		if( ((year % 400) != 0 &&
			 (year % 100) == 0
			) ||
			(year % 4) != 0) {
				return false;
		}
		return true;
	}

	MayanDate gregorian_to_mayan(GregorianDate gregorian) {
		unsigned int daysDiff = gregorian - START_GREG_DATE;
		return MayanDate(daysDiff);
	}

	GregorianDate mayan_to_gregorian(MayanDate mayan) {
		unsigned int days = mayan.absoluteDays();
		
		return START_GREG_DATE + days;	
	}
}
