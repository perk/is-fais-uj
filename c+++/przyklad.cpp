/* Autor: Marcin Stożek
 * Sortlib - bilbioteka do wizualizacji procesu sortowania
 * Zaawansowany C++
 * Wydział Fizyki, Astronomii i Informatyki Stosowanej, Uniwersytet Jagielloński
 *
 * przyklad.cpp
 */

#include <iostream>

#include "sortlib.h"
#include "visualization_policy.h"

using namespace std;

int main() {

//Rozne sposoby konstrukcji obiektu sort
	Sort<int, Text_visualization<int> > l;
	//Sort<int> l;

	int tablica[11] = {1,-2,3,5,2,1,7,-8,4,6,9};

	cout << "nieposortowana tablica" << endl;
	for(int i=0; i<11; i++)
		cout << tablica[i] << " ";
	cout << endl;

//	l.selectionSort(tablica, 11);
	l.insertionSort(tablica, 11);
//	l.quickSort(&tablica[0], 11);
//	l.selectionSort(tablica, 11);

	cout << "posortowana tablica" << endl;
	for(int i=0; i<11; i++)
		cout << tablica[i] << ",";
	cout << endl;

}
