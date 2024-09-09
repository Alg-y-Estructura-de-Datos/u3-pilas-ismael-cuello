/*
Crear una función que reciba una pila por referencia y un número. La función debe sacar la
primera ocurrencia de dicho valor de la pila sino se repite el valor en la pila, de lo contrario
debe eliminar todos los valores repetidos a excepción de la primera ocurrencia. Si el valor no
se encuentra en la pila muestra un mensaje indicando que no pertenece a la pila. Imprimir la
pila al final para verificar si hubo o no modificaciones.
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
void repes(Pila<int>&pila,int numero){
    Pila<int>pilaAUX;
    bool encontraod = false;
    int contador=0;
    while (!pila.esVacia()){
        int  valor = pila.pop();
        if (numero == valor){
            if(!encontraod){
                encontraod = true;
                pilaAUX.push(valor);
            }
            contador++;

        }else{
            pilaAUX.push(valor);
        }
    }
    while (!pilaAUX.esVacia()){
        pila.push(pilaAUX.pop());
    }
    if (contador == 0){
        cout << "El valor: " << numero << "no existe en la pila" << endl;
    }else if(contador>1){
        cout << "Eliminadas " << contador-1 << "ocurrencias adicionales del valor" << numero << endl;
    }else{
        cout << "se mantuvo la unica ocurrencia del valor" << numero <<"en la pila"<<endl;
    }

}

int main() {
    Pila<int>pila;
    pila.push(3);
    pila.push(3);
    pila.push(2);
    pila.push(5);
    pila.push(3);
    pila.push(9);

    cout << "Pila original"<< endl;
    mostrarPila(pila);

    cout << "Eliminando ocurrencias del valor 5 de la pila..." << endl;
    repes(pila,5);

    cout<< "pila sin las ocurrencias del valor 5" << endl;
    mostrarPila(pila);

    cout << "Eliminando ocurrencias del valor 3 de la pila..." << endl;
    repes(pila,3);

    cout<< "Pila sin las ocurrencias del valor 3 "<< endl;
    mostrarPila(pila);
}
