/* zadanie 1 */

#include <iostream>
using namespace std;

int a = 20;
int b = 10;
int suma(int a, int b) {
	int suma = a + b;
	return suma;
}

int main() {
	cout << suma(a, b) << endl; //30, bo uzywa zmiennych globalnych
	int a = 1;
	int b = 2;
	cout << suma(a, b) << endl; // 3, bo uzywa zmiennych lokalnych
	
	return 0;
}