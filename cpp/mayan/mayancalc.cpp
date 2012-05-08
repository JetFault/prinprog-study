#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mayancalc.h"
#include "CalUtils.h"

using namespace std;

void print_error_command_help() {
	cout << "Not a command" << endl \
	<< "Valid options are:" << endl \
	<< "m+d <Mayan Date> <Days>\n" \
	<< "\tOutputs a new Mayan Date plus that many days.\n" \
	<< "m-d <Mayan Date> <Days>\n" \
	<< "\tOutputs a new Mayan Date minus that many days.\n" \
	<< "m-m <Mayan Date> <Mayan Date>\n" \
	<< "\tOutputs number of days between.\n" \
	<< "g= <Gregorian Date>\n" \
	<< "\tOutputs Mayan Conversion.\n" \
	<< "m= <Mayan Date>\n" \
	<< "\tOutputs Gregorian Conversion.\n" \
	;
	exit(1);
}

void print_error_date() {
	cout << "Not a valid date" << endl;
	exit(2);
}

void print_error_days() {
	cout << "Not a valid number of days" << endl;
	exit(3);
}

MayanDate format_mayan_input(char *mayan) {
	unsigned int baktun, katun, tun, uinal, kin;
	if(sscanf(mayan, "%u.%u.%u.%u.%u", &baktun, &katun,
				&tun, &uinal, &kin) == EOF) {
		throw;
	}

	return MayanDate(baktun, katun, tun, uinal, kin);
}

GregorianDate format_gregorian_input(char *gregorian) {
	unsigned int month, day;
	int year;

	if(sscanf(gregorian, "%u/%u/%d", &month, &day,
				&year) == EOF) {
		throw;
	}

	return GregorianDate(month, day, year);
}

unsigned int format_days_input(char *days) {
	int int_days = 0;

	if(sscanf(days, "%u", &int_days) == EOF) {
		throw;
	}

	return int_days;
}


int main(int argc, char **argv) {
	
	if(argc < 2 || argc > 4) {
		print_error_command_help();
	}

	char* command = argv[1];
	
	int plus = strcmp(command, "m+d");
	if(strcmp(command, "m+d") == 0 || strcmp(command, "m-d") == 0) {
		MayanDate mDate(0);
		unsigned int numDays;

		try {
			mDate = format_mayan_input(argv[2]);
		}
		catch(...) {
			print_error_date();
		}

		try {
			numDays = format_days_input(argv[3]);
		}
		catch(...) {
			print_error_days();
		}

		MayanDate diffMDate(0);

		if(plus == 0) {
			diffMDate = mDate + numDays;
		}
		else {
			diffMDate = mDate - numDays;
		}

		diffMDate.print();
	}
	else if(strcmp(command, "m-m") == 0) {
		MayanDate mDate1(0), mDate2(0);
		try {
			mDate1 = format_mayan_input(argv[2]);
			mDate2 = format_mayan_input(argv[3]);
		}
		catch(...) {
			print_error_date();
		}

		int daysDiff = mDate1 - mDate2;
		
		cout << daysDiff << endl;

	}
	//The below 2 operations only take 1 argument,
	//but forget it, we will just ignore the 2nd argument
	//if the user enters one.
	else if(strcmp(command, "g=") == 0) {
		GregorianDate gDate(1,1,0);
		try {
			gDate = format_gregorian_input(argv[2]);
			MayanDate mDate = CalUtils::gregorian_to_mayan(gDate);
			mDate.print();
		}
		catch(...) {
			print_error_date();
		}
	}
	else if(strcmp(command, "m=") == 0) {
		MayanDate mDate(0);

		try {
			mDate = format_mayan_input(argv[2]);
			GregorianDate gDate = CalUtils::mayan_to_gregorian(mDate);
			gDate.print();
		}
		catch(...) {
			print_error_date();
		}
	}
	else {
		print_error_command_help();
	}

	return 0;
}
