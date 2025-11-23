/* zadanie 1 

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

*/


/* zad 2 - Napisz program w którym zadeklarujesz globaln¹ tablice o rozmiarze 10 (int tab[10]) i globaln¹ zmienn¹
rozmiar (int rozmiar = 10). W g³ównej funkcji programu wype³nij tê tablicê wartoœciami ca³kowitymi
wprowadzonymi z klawiatury, nastêpnie napisz w³asn¹ funkcjê która usuwa wartoœæ z tablicy, oznacza to,
¿e funkcja usun() prosi u¿ytkownika o podanie pozycji [0,9] z której ma usun¹æ wartoœæ. Poprzez usuniêcie
rozumiemy odpowiednie przesuniêcie pozosta³ych wartoœci w tablicy i zmniejszenie globalnej zmiennej
rozmiar o jeden. Wyœwietl elementy tablicy po usuniêciu.
 */

#include <iostream>
#include <limits>
#include <string>

using namespace std;

int tab[10];
int rozmiar = 10;

int wprowadzInt(string prompt); 
void usun();

int main() {

	for (int i = 0; i < 10; i++) {
		tab[i] = wprowadzInt("Podaj liczbe ca³kowita do umieszczenia na " + to_string(i) + " pozycji tablicy: ");
	}

	for (int i = 0; i < rozmiar; i++) {
		cout << "[" << i << "]=" << tab[i] << "  ";
	}

	usun();

	cout << "Zawartosc tablicy po usunieciu:" << endl;
	for (int i = 0; i < rozmiar; i++) cout << "[" << i << "]=" << tab[i] << "  ";
	cout << endl;

	return 0;
}


int wprowadzInt(string prompt) { // razem z wywo³aniem funkcji w nawiasie nale¿y wpisaæ tekst, który siê wyœwietli - mo¿na u¿yæ tej samej funkcji w ró¿nych kontekstach
	while (true) { //ca³y czas, a¿ pojawi siê return
		int a;
		cout << prompt;
		if (cin >> a) { // operator  >> pomija bia³e znaki i czyta znaki, które da siê zinterpretowaæ jako liczbê ca³kowit¹ – czyli if jest prawdziwy jeœli chocia¿ pierwszy znak jest cyfr¹
			// zapisuje tylko cyfry, nawet jeœli w ci¹gu znaków pojawia siê np litera, a liczby po przecinku ucina
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return a;
		}
		cout << "Niepoprawne dane. Podaj liczbe calkowita." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

void usun() {
	if (rozmiar <= 0) {
		cout << "Tablica jest pusta, brak elementow do usuniecia." << endl;
		return;
	}

	int poz = wprowadzInt("Podaj pozycje, z ktorej chcesz usunac wartosc [0-" + to_string(rozmiar - 1) + "]: ");
	if (poz < 0 || poz >= rozmiar) {
		cout << "Niepoprawny indeks. Operacja przerwana." << endl;
		return;
	}

	for (int i = poz; i < rozmiar - 1; ++i) {
		tab[i] = tab[i + 1];
	}
	--rozmiar;
	cout << "Usunieto element na pozycji " << poz << "." << endl;
}
