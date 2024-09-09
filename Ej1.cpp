/*
 Escriba un programa que introduzca una palabra y utilice una pila para imprimir la misma
 palabra invertida.
 */
#include <iostream>
#include "Pila/Pila.h"
using namespace std;
void invertir(Pila<char>&palabra){

}
int main() {
    Pila<char> palabra;
    char caracter;
    while (caracter != '.'){
        cin.get(caracter);
        if (caracter != '.'){
            palabra.push(caracter);
        }
    }

    while (!palabra.esVacia()){
       cout << palabra.pop();
    }
}
