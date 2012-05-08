#ifndef _MAYANCALC_H_
#define _MAYANCALC_H_

#include "MayanDate.h"
#include "GregorianDate.h"

/*
 * Our main class and anything we need to do 
 * to handle formatting inputs
 */

/*
 * Print Error Help and exit
 */
void print_error_command_help();
void print_error_date();
void print_error_days();

/**
 * Format the input for a mayan/gregorian date.
 * Return the mayan/gregorian date.
 * Throws exception if incorrectly formatted.
 */
MayanDate format_mayan_input(char *mayan);
GregorianDate format_gregorian_input(char *gregorian);

/**
 * Format the input for days.
 * Return the unsigned int.
 */
unsigned int format_days_input(char *days);
	
#endif
