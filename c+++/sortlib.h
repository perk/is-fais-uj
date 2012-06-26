#ifndef  _sortlib_
#define  _sortlib_

#include <stdlib.h>
#include <iostream>
#include <stdexcept>

/** \mainpage 
 * sortlib.h - biblioteka sluzaca do wizualizacji procesu sortowania\n\n
 * Projekt wykonany jako zaliczenie zajec "Zaawansowany C++"\n
 * Wydzial Fizyki, Astronomii i Informatyki Stosowanej\n
 * Uniwersytet Jagiellonski
 * \author Marcin Stozek
 * \date 02.08.2007
 * \version 1.0
 * */

/** \file sortlib.h
 * \author Marcin Stozek
 * \date 02.08.2007
 * \version 1.0
 *
 * Plik z implementacja biblioteki sortujacej oraz pusta polityka wizualizacji.
 * */

using namespace std;

/** \struct No_visualization 
 * Pusta polityka wizualizacji.
 *
 * */
template <typename T>
struct No_visualization {

/** \fn beforeStep(T*, int, int, int)
 * Funkcja wykonujaca sie przed krokiem sortowania.
 *
 * Moze np. wypisac, ktore elementy zostana zamienione. Funkcja ta zawsze wystepuje razem z funkcja afterStep() (przy czym before jest przed wykonaniem zamiany, a after po wykonaniu zamiany). Przed ta funkcja zawsze wywolywana jest funkcja incCounter().
 *
 * \param T * - wskaznik na tablice
 * \param int - liczba elementow w tablicy
 * \param int - pierwszy element zamieniany
 * \param int - drugi element zamieniany
 *
 * \return funkcja nic nie zwraca
 * */
	static void beforeStep(T*, int, int, int) { /*blank*/ };

/** \fn afterStep(T*, int, int, int)
 * Funkcja wykonujaca sie po kolejnym kroku sortowania
 *
 * Moze wypisac, ktore elementy zostaly zamienione. Funkcja wystepuje razem z beforeStep().
 *
 * \param T * - wskaznik na tablice
 * \param int - liczba elementow w tablicy
 * \param int - pierwszy element zamieniany
 * \param int - drugi element zamieniany
 *
 * \return funkcja nic nie zwraca
 * */
	static void afterStep(T*, int, int, int) { /*blank*/ };

/** \fn comparing(T*, int, int, int)
 * Funkcja comparing() wywolywana jest zawsze wtedy, gdy porownujemy dwa elementy.
 *
 * Moze wypisac, ktore elementy aktualnie porownujemy. Przed ta funkcja zawsze wywolywana jest funkcja incCounter().
 *
 * \param T* - wskaznik na tablice\n
 * \param int - liczba elementow w tablicy\n
 * \param int - pierwszy element porownywany\n
 * \param int - drugi element porownywany
 *
 * \return funkcja nic nie zwraca
 * */
	static void comparing(T*, int, int, int) { /*blank*/ };

/** \fn resetCounter()
 * Funkcja resetCounter() wywolywana jest na poczatku algorytmu sortowania i zeruje licznik porownan
 *
 * \return funkcja nic nie zwraca
 * */
	static void resetCounter() { /*blank*/ };

/** \fn incCounter() 
 * Funkcja zwiekszajaca licznik porownan.
 *
 * Funkcja ta jest zawsze wywolywana przed funkcjami comparing() oraz beforeStep()
 *
 * \return funkcja nic nie zwraca
 * */
	static void incCounter() { /*blank*/ };
};


/** \class Sort
 * Klasa zawierajaca algorytmy sortowania z wywolaniami funkcji dot. wizualizacji.
 *
 * Aby zobaczyc w jaki sposob zaimplementowany jest konkretny algorytm sortowania i kiedy wywolywane sa funkcje zwiazane z wizualizacja prosze spojrzec w kod zrodlowy.
 *
 * \attention Wszystkie publiczne funkcje z klasy wywoluje sie z dwoma parametrami: wskaznikiem na typ T (pierwszym elementem tablicy) oraz wielkoscia tej tablicy, np. jezeli tablica o nazwie TAB ma dziesiec pol, to wywolanie powinno wygladac tak: function(TAB, 10) lub function(&TAB[0], 10). W szczegolnosci mozemy podac jako pierwszy element srodek tablicy i posortowac tylko jej czesc.
 * */
//struct with sort algorithms
template<typename T = int , typename Visualization_policy = No_visualization<T> >
class Sort {

public:
	// *********************************************************************** BubbleSort
/** \fn bubbleSort(T* tab, int count) 
 * Funkcja sortujaca algorytmem bubblesort.
 *
 * Funkcja sortuje juz przygotowana tablice, ktorej adres dostala jako parametr wywolania.
 * \param tab - wskaznik na element typu T, ktory jest pierwszy w tablicy, ktora bedziemy sortowac
 * \param count - wielkosc tablicy do posortowania
 * \return funkcja nic nie zwraca
 * */
	void bubbleSort(T* tab, int count) {

		Visualization_policy::resetCounter();

		// poczatek algorytmu wlasciwego
		for(int i=0 ; i<count ; i++) {
			bool end = true;

			for(int j=0 ; j<(count-i-1) ; j++) {

				Visualization_policy::incCounter();
				Visualization_policy::comparing(tab,count,j,j+1);

				if((tab[j+1]) < (tab[j])) {

					Visualization_policy::incCounter();
					Visualization_policy::beforeStep(tab,count,j,j+1);

					T temp = tab[j+1];
					tab[j+1] = tab[j];
					tab[j] = temp;
					end = false;

					Visualization_policy::afterStep(tab,count,j,j+1);
						
				}
			}
			if(end == true)
				break;
		}
		// koniec algorytmu wlasciwego
	}
	// *********************************************************************** QuickSort
/** \fn quickSort(T* tab, int count) 
 * Funkcja wywolujaca algorytm quicksort z odpowiednimi danymi.
 *
 * Funkcja sortuje juz przygotowana tablice, ktorej adres dostala jako parametr wywolania.
 * \param tab - wskaznik na element typu T, ktory jest pierwszy w tablicy, ktora bedziemy sortowac
 * \param count - wielkosc tablicy do posortowania
 * \return funkcja nic nie zwraca
 * */
	void quickSort(T* tab, int count) {
		Visualization_policy::resetCounter();
		quickSort_Alg(tab, count, 1, count);
	}

private:
/** \fn quickSort_Alg(T* tab, int count, int lewy, int prawy) 
 * Funkcja sortujaca algorytmem quicksort.
 *
 * \param tab - wskaznik na element typu T, ktory jest pierwszy w tablicy, ktora bedziemy sortowac
 * \param count - wielkosc tablicy do posortowania
 * \param lewy - lewy kraniec aktualnego przedzialu
 * \param prawy - prawy kraniec aktualnego przedzialu
 * \return funkcja nic nie zwraca
 * */
	void quickSort_Alg(T* tab, int count, int lewy, int prawy) {

		// poczatek algorytmu wlasciwego
		if (lewy < prawy) {

			int q = partition(tab, count, lewy, prawy);

			Visualization_policy::incCounter();
			Visualization_policy::comparing(tab,count,lewy-1,q-1);
			quickSort_Alg(tab, count, lewy, q);

			Visualization_policy::incCounter();
			Visualization_policy::comparing(tab,count,q,prawy-1);
			quickSort_Alg(tab, count, q+1, prawy);
		}
		// koniec algorytmu wlasciwego
	} //quickSort_Alg()

/** \fn partition(T* tab, int count, int p, int r)
 * Funkcja pomocnicza wykorzystywana przy quicksort.
 *
 * \param tab - wskaznik na element typu T, ktory jest pierwszy w tablicy, ktora bedziemy sortowac
 * \param count - wielkosc tablicy do posortowania
 * \param p - lewy kraniec przedzialu ktory "porzadkujemy"
 * \param r - prawy kraniec przedzialu ktory "porzadkujemy"
 * \return funkcja zwraca pozycje elementu, ktory jest graniczny dla ciagow z lewej i prawej strony
 * */
	int partition(T* tab, int count, int p, int r) {
		T x = tab[p-1];
		int i = p-1;
		int j = r+1;
		
		while (true) {
			Visualization_policy::incCounter();

			Visualization_policy::comparing(tab,count,i-1,j-1);

			do j--;
			while (tab[j-1] > x);

			do i++;
			while (tab[i-1] < x);

			Visualization_policy::incCounter();
			Visualization_policy::comparing(tab,count,i-1,j-1);

			if (i < j) {
				Visualization_policy::incCounter();
				Visualization_policy::beforeStep(tab,count,i-1,j-1);
				T x=tab[i-1];
				tab[i-1]=tab[j-1];
				tab[j-1]=x;
				Visualization_policy::afterStep(tab,count,i-1,j-1);
			} else
				return j;
		}
	} //partition()

public:


	// *********************************************************************** InsertionSort
/** \fn insertionSort(T* tab, int count)
 * Funkcja sortujaca algorytmem insertionSort.
 *
 * Funkcja sortuje juz przygotowana tablice, ktorej adres dostala jako parametr wywolania.
 * \param tab - wskaznik na element typu T, ktory jest pierwszy w tablicy, ktora bedziemy sortowac
 * \param count - wielkosc tablicy do posortowania
 * \return funkcja nic nie zwraca
 * */
	void insertionSort(T* tab, int count) {

		Visualization_policy::resetCounter();

		// poczatek algorytmu wlasciwego
		for (int i=1 ; i<count ; i++) {
			int j = i;
			
			Visualization_policy::incCounter();

			T temp = tab[j];
				
			while ((j>0 ) && (tab[j-1]>temp)) {
				Visualization_policy::comparing(tab,count,i,j-1);
				Visualization_policy::incCounter();
				j--;
			}

			j = i;

			Visualization_policy::beforeStep(tab,count,j,j);

			while ((j>0 ) && (tab[j-1]>temp)) {
				tab[j] = tab[j-1];
				j--;
			}

			tab[j] = temp;

			Visualization_policy::afterStep(tab,count,j,j);

		}
		// koniec algorytmu wlasciwego
	} //insertionSort()

	// *********************************************************************** SelectionSort
/** \fn selectionSort(T* tab, int count)
 * Funkcja sortujaca algorytmem selectionSort.
 *
 * Funkcja sortuje juz przygotowana tablice, ktorej adres dostala jako parametr wywolania.
 * \param tab - wskaznik na element typu T, ktory jest pierwszy w tablicy, ktora bedziemy sortowac
 * \param count - wielkosc tablicy do posortowania
 * \return funkcja nic nie zwraca
 * */
	void selectionSort(T* tab, int count) {

		Visualization_policy::resetCounter();

		// poczatek algorytmu wlasciwego
		for(int i=0 ; i<count-1 ; i++) {
			
			Visualization_policy::incCounter();
			
			int min = i;

			for(int j=i+1 ; j<count ; j++) {
				Visualization_policy::comparing(tab,count,j,min);
				Visualization_policy::incCounter();
				if (tab[min] > tab[j]) min = j;
			}

			Visualization_policy::beforeStep(tab,count,min,i);

			T temp = tab[min];
			tab[min] = tab[i];
			tab[i] = temp;

			Visualization_policy::afterStep(tab,count,min,i);

		}
		// koniec algorytmu wlasciwego
	} //selectionSort()

}; //class

#endif
