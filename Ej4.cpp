/*
 Crear un programa que solicite números enteros al usuario hasta que desee, almacenar los
 números en una pila y pedir también un número entero "n". Luego crear una función que
 reciba una pila y un número entero “n”, si el "n" se encuentra en una de las posiciones de la
 pila, devuelve la suma de los números en cada una de las posiciones de la pila hasta llegar a
 "n" (sin incluir a n), si el número "n" no se encuentra en la pila, la función devuelve la suma de
 todos los elementos de la pila. Imprimir primero la pila antes de sumar sus elementos
 */
#include <iostream>
#include "Pila/Pila.h"
using namespace std;
void SumaDePila(Pila<int>&pila, int n){
    Pila<int> pilaAux;
    bool encontrado = false;
    int suma= 0;
    int valor =0;
    while (!encontrado){
        valor = pila.pop();
        if (valor != n){
            pilaAux.push(valor);
        } else{
            encontrado = true;
        }
    }
    while (!pilaAux.esVacia()){
        suma += pilaAux.pop();
    }

    cout << "La suma de los numeros hasta n es: " << suma << endl;

}
void mostrarPila(Pila<int>& pila) {
    Pila<int> pilaAux;

    // Desapilar elementos para mostrar sin perderlos
    while (!pila.esVacia()) {
        int valor = pila.pop();
        cout << valor << " ";
        pilaAux.push(valor);
    }
    cout << endl;

    // Restaurar la pila original
    while (!pilaAux.esVacia()) {
        pila.push(pilaAux.pop());
    }
}
int main(){
    Pila<int> pila;
    pila.push(3);
    pila.push(5);
    pila.push(2);
    pila.push(8);
    pila.push(7);

    int n;
    cout << "Di un numero entero" << endl;
    cin >> n;

    SumaDePila(pila,n);

}
