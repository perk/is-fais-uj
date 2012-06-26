/* Autor: Marcin Stożek
 * Sortlib - bilbioteka do wizualizacji procesu sortowania
 * Zaawansowany C++
 * Wydział Fizyki, Astronomii i Informatyki Stosowanej, Uniwersytet Jagielloński
 *
 * main_test.cpp
 */

#include <iostream>

#include <cppunit/TextTestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

using namespace std;

int main() {
    CppUnit::TextTestRunner runner;
    runner.addTest(CppUnit::TestFactoryRegistry::getRegistry().makeTest());
    bool result = runner.run();
    return result ? 0 : 1;
}
