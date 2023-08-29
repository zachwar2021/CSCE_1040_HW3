librarysystem: main.o book.o patron.o loan.o books.o loans.o patrons.o
	g++ -o  librarysystem main.o patron.o patrons.o book.o books.o loan.o loans.o

main.o: main.cpp book.h loan.h patron.h loans.h books.h patrons.h
	g++ -c main.cpp

book.o: book.cpp book.h 
	g++ -c book.cpp book.h

patron.o: patron.cpp patron.h
	g++ -c patron.cpp patron.h

loan.o: loan.cpp loan.h
	g++ -c loan.cpp loan.h

books.o: books.cpp book.h books.h
	g++ -c books.cpp book.h books.h

loans.o: loans.cpp loan.h loans.h patrons.h
	g++ -c loans.cpp loan.h loans.h

patrons.o: patrons.cpp patron.h patrons.h
	g++ -c patrons.cpp patron.h patrons.h