/* Autor: Marcin Stożek
 * Sortlib - bilbioteka do wizualizacji procesu sortowania
 * Zaawansowany C++
 * Wydział Fizyki, Astronomii i Informatyki Stosowanej, Uniwersytet Jagielloński
 *
 * test.cpp
 */

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "sortlib.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: struct Special_visualization
template <typename T> 
struct Special_visualization {

	static int counter;

	static void resetCounter() { counter = 0;	};
	static void incCounter() {};
	static void comparing(T* tab, int countTab, int i, int j) {};
	static void beforeStep(T* tab, int countTab, int i, int j){};

	static void afterStep(T* tab, int countTab, int i, int j) {
		counter++;
	};

}; //struct special

template <typename T>
int Special_visualization<T>::counter = 0;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: funkcje pomocnicze
template <typename T>
bool compare(T* first, T* second, int count) {
	for (int i=0; i<count; i++) {
		if (first[i] != second[i])
			return false;
	}
	return true;
};

template <typename T>
void copyTab(T* tab, T* old_tab, int count) {
		for(int i=0; i<count; i++) 
			tab[i] = old_tab[i]; //przepisujemy
};


// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: class Test
class Test : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(Test);
	CPPUNIT_TEST(test_tablica_odwrotnie);
	CPPUNIT_TEST(test_tablica_losowy_pocz);
	CPPUNIT_TEST(test_tablica_losowy_kon);
	CPPUNIT_TEST(test_losowa);
	CPPUNIT_TEST(test_malejaca_rosnaca);
	CPPUNIT_TEST(test_rosnaca_malejaca);
	CPPUNIT_TEST_SUITE_END();

	private:
		Sort<int, Special_visualization<int> > sort;
		int* tab;
		int* comp;

	public:
	void setUp() {
		int temp_tab [13] = {-8,-2,0,1,1,2,3,4,5,6,7,8,9};
		tab = new int[13];
		copyTab<int>(tab, temp_tab, 13);
		comp = new int[4];
	}

	void tearDown() {
		cout << endl;
		delete [] tab;
		delete [] comp;
	}

	void callSorts (int* temp_tab, int count) {
		int assorted [count];

		// bubble
		cout << 'b';
		copyTab<int>(assorted, temp_tab, count);
		sort.bubbleSort(assorted, count);
		CPPUNIT_ASSERT(compare<int>(tab, assorted, count));
		comp[0] = Special_visualization<int>::counter;

		//quick
		cout << 'q';
		copyTab<int>(assorted, temp_tab, count);
		sort.quickSort(assorted, count);
		CPPUNIT_ASSERT(compare<int>(tab, assorted, count));
		comp[1] = Special_visualization<int>::counter;

		//selection
		cout << 's';
		copyTab<int>(assorted, temp_tab, count);
		sort.selectionSort(assorted, count);
		CPPUNIT_ASSERT(compare<int>(tab, assorted, count));
		comp[2] = Special_visualization<int>::counter;

		//insertion
		cout << 'i';
		copyTab<int>(assorted, temp_tab, count);
		sort.insertionSort(assorted, count);
		CPPUNIT_ASSERT(compare<int>(tab, assorted, count));
		comp[3] = Special_visualization<int>::counter;
	};


	// ******************************************************** tablica posortowana odwrotnie
	void test_tablica_odwrotnie() {
		int temp_tab [13] = {9,8,7,6,5,4,3,2,1,1,0,-2,-8};
		callSorts(temp_tab, 13);

		// sprawdzamy, czy ilosc zamian sie zgadza (czy algorytm jest poprawny)
		CPPUNIT_ASSERT(comp[0] == 77);
		CPPUNIT_ASSERT(comp[1] == 7);
		CPPUNIT_ASSERT(comp[2] == 12);
		CPPUNIT_ASSERT(comp[3] == 12);
	}

	// ******************************************************** tablica z losowa liczba na poczatku
	void test_tablica_losowy_pocz() {
		int temp_tab [13] = {-8,9,-2,0,1,1,2,3,4,5,6,7,8};
		callSorts(temp_tab, 13);

		// sprawdzamy, czy ilosc zamian sie zgadza
		CPPUNIT_ASSERT(comp[0] == 11);
		CPPUNIT_ASSERT(comp[1] == 11);
		CPPUNIT_ASSERT(comp[2] == 12);
		CPPUNIT_ASSERT(comp[3] == 12);
	}


	// ******************************************************** tablica z losowa liczba na koncu
	void test_tablica_losowy_kon() {
		int temp_tab [13] = {-8,0,1,1,2,3,4,5,6,-2,7,8,9};
		callSorts(temp_tab, 13);

		// sprawdzamy, czy ilosc zamian sie zgadza
		CPPUNIT_ASSERT(comp[0] == 8);
		CPPUNIT_ASSERT(comp[1] == 7);
		CPPUNIT_ASSERT(comp[2] == 12);
		CPPUNIT_ASSERT(comp[3] == 12);
	};

	// ******************************************************** tablica losowa
	void test_losowa() {
		int temp_tab [13] = {1,-2,3,0,5,2,8,1,7,-8,4,6,9};
		callSorts(temp_tab, 13);

		// sprawdzamy, czy ilosc zamian sie zgadza
		CPPUNIT_ASSERT(comp[0] == 24);
		CPPUNIT_ASSERT(comp[1] == 11);
		CPPUNIT_ASSERT(comp[2] == 12);
		CPPUNIT_ASSERT(comp[3] == 12);
	};

	// ******************************************************** tablica malejaca-rosnaca
	void test_malejaca_rosnaca() {
		int temp_tab [13] = {9,8,7,6,5,4,3,-8,-2,0,1,1,2};
		callSorts(temp_tab, 13);

		// sprawdzamy, czy ilosc zamian sie zgadza
		CPPUNIT_ASSERT(comp[0] == 63);
		CPPUNIT_ASSERT(comp[1] == 14);
		CPPUNIT_ASSERT(comp[2] == 12);
		CPPUNIT_ASSERT(comp[3] == 12);
	};

	// ******************************************************** tablica rosnaca-malejaca
	void test_rosnaca_malejaca() {
		int temp_tab [13] = {-8,-2,0,1,1,2,9,8,7,6,5,4,3};
		callSorts(temp_tab, 13);

		// sprawdzamy, czy ilosc zamian sie zgadza
		CPPUNIT_ASSERT(comp[0] == 21);
		CPPUNIT_ASSERT(comp[1] == 4);
		CPPUNIT_ASSERT(comp[2] == 12);
		CPPUNIT_ASSERT(comp[3] == 12);
	};
};

CPPUNIT_TEST_SUITE_REGISTRATION(Test);
