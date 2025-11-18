/* #include <iostream>
using namespace std;
int main() { //kod 06_04_sanity
    char str[280];
    cout << "Wpisz tekst: ";
    cin.getline(str, 280);
    cout << "Tekst: " << str << endl;
    return 0;
}
*/

/*
#include <iostream>
using namespace std;
bool conversionFailed = false;
double convertToDouble(const char vector[], int size);

int main() {  //kod 06_06
    char str[280];
    cout << "Wpisz prosze ja ciebie liczbe > 0. Calkowita. O, tutaj ===>  ";
    cin.getline(str, 280);
    int liczba = convertToDouble(str, sizeof(str));
    if (conversionFailed) {
        cout << "Latarnia twojego intelektu nie swieci zbyt mocno, prawda?\n";
        cout << "Tekst: " << str << endl;
        cout << "Liczba: " << liczba << "\n"; //endl lub "\n", wciaz jest to enter
        float dzielnik = 1.0;
        cout << "Uzywam wartosci domyslnej: 1\n";
        cout << "10 podzielone przez 1 to: " << (10.0 / dzielnik) << "\n\n";
    }
    else {
        cout << "Liczba: " << liczba << endl;
        cout << "10 podzielone przez liczbe to: " << (10.0 / (float)liczba) << "\n\n";
    }
    return 0;
}


double convertToDouble(const char vector[], int size) { //code 06_07
    double result = 0.0;
    double fractionalMultiplier = 0.1;
    bool isNegative = false;
    bool isFractional = false;
    bool signRecognised = false;

    for (int i = 0; i < size; ++i) {
        if (vector[i] == '\0')
            break; // Stop processing at the null-terminator

        if (isdigit(vector[i])) {
            if (isFractional) {
                result += (vector[i] - '0') * fractionalMultiplier;
                fractionalMultiplier *= 0.1;
            }
            else {
                result = result * 10.0 + (vector[i] - '0');
            }
        }
        else if (vector[i] == '.' && isFractional == false) {
            isFractional = true; // Start processing fractional part
        }
        else if (vector[i] == '-' && signRecognised == false) {
            signRecognised = true;
            isNegative = true;
        }
        else if (vector[i] == '+' && signRecognised == false) {
            signRecognised = true;
            continue;
        }
        else {
            if (conversionFailed == false) {
                cout << "Wow wow. Very double. Much digit. So wise." << endl;
                conversionFailed = true;
            }
        }
    }

    return isNegative ? -result : result;
}
*/

/* 
#include <iostream>
using namespace std;

void print_table(int argument);
void doNothingImportant();

int vector[10];
int globalCounter = 0;

int main() { //kod 06_08
    doNothingImportant();
    int localVar = 5;
        int n = 10;
    for (globalCounter = 0; globalCounter < n; globalCounter++)
        vector[globalCounter] = globalCounter * 2;

    print_table(localVar);
    cout << "Licznik: " << globalCounter << ", zmienna_lokalna: " << localVar << endl << endl;
    print_table(localVar);
    return 0;
}

void print_table(int argument) {
    cout << "*** print_table start *** licznik: " << globalCounter << ", argument: " << argument << endl;
    cout << "Wektor: ";
    for (int i = 0; i < globalCounter; i++)
        cout << vector[i] << " ";

    cout << endl;
    globalCounter = 10;
    argument = 2;
    cout << "*** print_table end ***  licznik: " << globalCounter << ", argument: " << argument << endl << endl;
}

void doNothingImportant() {
    cout << "    ### program started" << endl;
}

*/