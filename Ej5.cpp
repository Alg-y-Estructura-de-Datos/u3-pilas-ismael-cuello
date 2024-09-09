/*
 Crear un programa e implementar una función que reciba una pila de números enteros y
dado un número “n” por el usuario devuelva una nueva pila con la suma de cada uno de los
elementos de la pila original más el n dado por el usuario. Los elementos en la nueva pila
deben tener el orden que tenían en la pila original, y la pila original debe quedar en el mismo
estado a la inicial, mostrar por pantalla ambas pilas.
Por ejemplo, se tiene la pila de enteros [ 1, 2, 3, 6, 2] (tope es el número 2), y la función
sumarNro recibe como parámetros la pila y n=1 (devuelve la suma entre el número 1 y el
número recibido en cada posición de la pila original), la pila resultante debe ser [ 2, 3, 4, 7, 3]
(el tope es el número 3)

 */
#include <iostream>
#include "Pila/Pila.h"
using namespace std;
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
Pila<int> sumarNro(Pila<int>pila,int n){
    Pila<int> pilaAUX;
    Pila<int> pilaResultado;
    int valor = 0;
    while (!pila.esVacia()){
        valor = pila.pop();
        pilaAUX.push(valor);
    }

    while (!pilaAUX.esVacia()){
        valor = pilaAUX.pop();
        pilaResultado.push(valor+n);
    }
    while (!pilaAUX.esVacia()){
        pila.push(pilaAUX.pop());
    }
    return pilaResultado;
}
int main(){
    Pila<int>pila;
    pila.push(2);
    pila.push(6);
    pila.push(3);
    pila.push(2);
    pila.push(1);

    cout << "Pila original " << endl;
    mostrarPila(pila);

    int n;
    cout << "Elige un entero para sumar a casa elemento" << endl;
    cin >> n;

    Pila<int>pilaResultado = sumarNro(pila,n);

    cout << "Pila original despues de la operacion " << endl;
    mostrarPila(pila);

    cout << "Pila resultado despues de la funcion " << endl;
    mostrarPila(pilaResultado);

}