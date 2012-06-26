/* Autor: Marcin Stożek
 * Sortlib - bilbioteka do wizualizacji procesu sortowania
 * Zaawansowany C++
 * Wydział Fizyki, Astronomii i Informatyki Stosowanej, Uniwersytet Jagielloński
 *
 * visualization_policy.h
 */

#ifndef _visualization_policy_
#define _visualization_policy_

using namespace std;

template <typename T> 
struct Text_visualization {

	static int counter;

	static void resetCounter() { counter = 0;	};
	static void incCounter() { counter++ ;};

	static void comparing(T* tab, int countTab, int i, int j) {
		cout << "comp " << counter << ":  ";
		for(int k=0 ; k<countTab ; k++) {
			if ((k == i) || (k == (j))) cout << "\t[" << tab[k] << "]";
			else cout << "\t" << tab[k];
		}
		cout << endl;
	};

	static void beforeStep(T* tab, int countTab, int i, int j) {
		cout << "befs " << counter << ":  ";
		for(int k=0 ; k<countTab ; k++) {
			if ((k == i) || (k == (j))) cout << "\t>" << tab[k] << "<";
			else cout << "\t" << tab[k];
		}
		cout << endl;
	};

	static void afterStep(T* tab, int countTab, int i, int j) {
		cout << "afts " << counter << ":  ";
		for(int k=0 ; k<countTab ; k++) {
			if ((k == i) || (k == (j))) cout << "\t>" << tab[k] << "<";
			else cout << "\t" << tab[k];
		}
		cout << endl;
	};

};

template <typename T>
int Text_visualization<T>::counter = 0;

#endif
