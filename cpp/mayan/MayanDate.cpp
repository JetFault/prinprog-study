#include <stdlib.h>
#include <iostream>
#include "MayanDate.h"

MayanDate::MayanDate(unsigned int bak, unsigned int kat,
		unsigned int tu, unsigned int uin, unsigned int ki) {

	baktun = bak;
	katun = kat;
	tun = tu;
	uinal = uin;
	kin = ki;
}

MayanDate::MayanDate(unsigned int days) {
	kin = days % 20;
	days /= 20;

	uinal = days % 18;
	days /= 18;

	tun = days % 20;
	days /= 20;

	katun = days % 20;
	days /= 20;

	baktun = days;
}


void MayanDate::set(unsigned int bak, unsigned int kat,
		unsigned int tu, unsigned int uin, unsigned int ki) {

	baktun = bak;
	katun = kat;
	tun = tu;
	uinal = uin;
	kin = ki;
}


unsigned int MayanDate::absoluteDays() {
	return 	kin +
			uinal * 20 +
			tun * 360 +
			katun * 7200 +
			baktun * 144000;
}


int MayanDate::operator-(MayanDate &rhs) {
	unsigned int lhsDays = this->absoluteDays();
	unsigned int rhsDays = rhs.absoluteDays();
	int diff = lhsDays - rhsDays;

	return diff;
}

MayanDate MayanDate::operator+( unsigned int rhs) {
	unsigned int lhsDays = this->absoluteDays();
	unsigned int newDays = lhsDays + rhs;

	return MayanDate(newDays);
}

MayanDate MayanDate::operator-( unsigned int rhs) {
	unsigned int lhsDays = this->absoluteDays();
	unsigned int newDays = lhsDays - rhs;

	if(lhsDays - rhs < 0) {
		newDays = 0;
	}
		
	return MayanDate(newDays);
}

bool MayanDate::operator==(const MayanDate & rhs) {
	if( baktun == rhs.baktun &&
		katun == rhs.katun &&
		tun == rhs.tun &&
		uinal == rhs.uinal &&
		kin == rhs.kin) 
			return true;

	return false;
}

void MayanDate::print() {
	std::cout << baktun << "." << katun << "." << tun << "." << uinal << "." << kin << "\n";
}
