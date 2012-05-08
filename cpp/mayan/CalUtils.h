#ifndef _CALUTILS_H_
#define _CALUTILS_H_

#include "GregorianDate.h"
#include "MayanDate.h"

namespace CalUtils {
	
	static GregorianDate START_GREG_DATE(8, 11, -3113);

	int days_month(unsigned int, int);

	bool is_leap(int year);

	MayanDate gregorian_to_mayan(GregorianDate gregorian);

	GregorianDate mayan_to_gregorian(MayanDate mayan);
}

#endif
