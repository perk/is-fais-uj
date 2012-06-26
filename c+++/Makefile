#  Autor: Marcin Stożek
#  Sortlib - bilbioteka do wizualizacji procesu sortowania
#  Zaawansowany C++
#  Informatyka Stosowana, Wydział Fizyki, Astronomii i Informatyki Stosowanej, Uniwersytet Jagielloński
# 
#  Makefile

test: clean
	prefix=/usr/include/cppunit
	g++ -Wall -o test.out -I $(prefix)/include -L $(prefix)/lib test.cpp main_test.cpp -l cppunit

przyklad: clean
	g++ -Wall -o przyklad.out przyklad.cpp
	./przyklad.out
	rm -f przyklad.out

sort: clean
	g++ -Wall sortlib.h

clean:
	rm -f *.out *.gch

run: clean test
	./test.out

tar: clean
	tar -cvvf ../sortlib.tar.gz *
