CC = g++
CCFLAGS = -g

all: mayancalc

mayancalc: mayancalc.h mayancalc.o MayanDate.o GregorianDate.o CalUtils.o
	$(CC) $(CCFLAGS) -o mayancalc mayancalc.o MayanDate.o GregorianDate.o CalUtils.o

mayancalc.o: mayancalc.cpp mayancalc.h MayanDate.h GregorianDate.h
	$(CC) $(CCFLAGS) -o mayancalc.o -c mayancalc.cpp

MayanDate.o: MayanDate.cpp MayanDate.h
	$(CC) $(CCFLAGS) -o MayanDate.o -c MayanDate.cpp

GregorianDate.o: GregorianDate.cpp GregorianDate.h
	$(CC) $(CCFLAGS) -o GregorianDate.o -c GregorianDate.cpp

CalUtils.o: CalUtils.cpp CalUtils.h MayanDate.h GregorianDate.h
	$(CC) $(CCFLAGS) -o CalUtils.o -c CalUtils.cpp

clean:
	rm -f *.o
	rm mayancalc
