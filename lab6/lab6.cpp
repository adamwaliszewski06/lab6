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
		tab[i] = wprowadzInt("Podaj liczbe calkowita do umieszczenia na " + to_string(i) + " pozycji tablicy: "); //to_string jest konieczne, bo + nie mo¿e po³¹czyæ typu string z typem int
	}

	for (int i = 0; i < rozmiar; i++) {
		cout << "[" << i << "]=" << tab[i] << "  ";
	}

	bool wybor;

	while (rozmiar > 0) {
		cout << endl << "Wpisz 1 jesli chcesz usunac element z tablicy lub 0 by zakonczyc program: ";
		cin >> wybor;
		if (wybor == true) { //mo¿e byæ te¿ po prostu if (wybor)
			usun();
		}
		else
			break;
	}
	return 0;
}


int wprowadzInt(string prompt) { // razem z wywo³aniem funkcji w nawiasie nale¿y wpisaæ tekst, który siê wyœwietli - mo¿na u¿yæ tej samej funkcji w ró¿nych kontekstach
	while (true) { //ca³y czas, a¿ pojawi siê return
		int a;
		cout << prompt;
		if (cin >> a) { // operator  >> pomija spacje, tab, nowe linie i czyta znaki, które da siê zinterpretowaæ jako liczbê ca³kowit¹ – czyli if jest prawdziwy jeœli chocia¿ pierwszy znak jest cyfr¹ lub minusem
			// zapisuje tylko cyfry, nawet jeœli w ci¹gu znaków pojawia siê np litera, a liczby po przecinku ucina
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // czyœci bufor wejœcia; 
			// ignore(n, delim) odrzuca do n znaków z wejœcia lub do napotkania znaku delim (tu: '\n'), w zale¿noœci co nast¹pi wczeœniej.
			// "numeric_limits<streamsize>::max()" to bardzo du¿a wartoœæ, wiêc w praktyce ten fragment znaczy "zignoruj wszystko do koñca linii"
			return a;
		}
		//else - nie musi siê pojawiæ, bo jeœli if bêdzie prawdziwy, to pêtla siê skoñczy
		cout << "Niepoprawne dane. Podaj liczbe calkowita." << endl;
		cin.clear(); // "resetuje flagi stanu strumienia (np. failbit), tak aby mo¿na by³o znów u¿ywaæ cin."
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
	rozmiar = rozmiar - 1;
	cout << "Usunieto element na pozycji " << poz << "." << endl;

	cout << "Zawartosc tablicy po usunieciu:" << endl;
	for (int i = 0; i < rozmiar; i++) cout << "[" << i << "]=" << tab[i] << "  ";
	cout << endl;
}
