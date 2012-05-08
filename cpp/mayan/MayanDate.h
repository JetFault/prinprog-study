#ifndef _MAYANDATE_H_
#define _MAYANDATE_H_

class MayanDate {

	public:
		//Members
		unsigned int baktun, katun, tun, uinal, kin;


		//Constructor
		/* Bak'tun, Ka'tun, Tun, Uinal, Kin */
		MayanDate(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
		/* Number of days since 0.0.0.0.0 */
		MayanDate(unsigned int);


		//Setter
		void set(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);


		//Member Functions
		/* Return number of days from 0.0.0.0.0 */
		unsigned int absoluteDays();


		//Operators
		//MayanDate & operator++();
		int operator-(MayanDate & );
		MayanDate operator+( unsigned int );
		MayanDate operator-( unsigned int );
		bool operator==( const MayanDate & );

		void get_string( char *, unsigned int );

		void print();
};

#endif
