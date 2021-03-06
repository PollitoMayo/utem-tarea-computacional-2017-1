// Autores: Jorge Verdugo Chac�n
//          Javiera Vergara Navarro
// Fecha: 2 de julio del 2017
// Secci�n: Secci�n 412
// Asignatura: Estructura de Datos
// Profesor: Mauro Castillo Valdes
// Universidad Tecnol�gica Metropolitana


#include "include/Polinomio.h"
#include "include/funciones.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main() {
    int opcion1, opcion2;
    string cadena;
    Lista listaPolinomios = NULL;

    while(true) {
        system("cls");

        menu(opcion1);

        switch(opcion1){
        case 1:
            system("cls");
            recibirPolinomio(listaPolinomios);
            cout << endl << "Se agrego correctamente el polinomio" << endl << endl;
            system("pause");
            break;
        case 2:
            system("cls");
            if(listaPolinomios == NULL){
                cout << "No hay polinomios registrados." << endl;
            } else {
                cout << "Ingrese el nombre del polinomio que desea eliminar: ";
                cin >> cadena;
                system("cls");
                if(!existePolinomio(cadena, listaPolinomios)) {
                    cout << "No existe ningun polinomio con ese nombre" << endl;
                } else {
                    eliminarPolinomio(listaPolinomios, cadena);
                }
            }
            cout << endl;
            system("pause");
            break;
        case 3:
            system("cls");
            if(listaPolinomios == NULL){
                cout << "No hay polinomios registrados." << endl;
            } else {
                cout << "Eliminando " << contarPolinomios(listaPolinomios) << " polinomio";
                if(contarPolinomios(listaPolinomios) != 1) {
                    cout << "s . . .";
                }
                cout << endl;
                eliminarTodos(listaPolinomios);
            }
            cout << endl;
            system("pause");
            break;
        case 4:
            system("cls");
            if(listaPolinomios == NULL) {
                cout << "No hay polinomios registrados." << endl;
            } else {
                verPolinomios(listaPolinomios);
                cout << endl << "Ingrese el nombre del polinomio que quiere operar: ";
                cin >> cadena;
                while(!existePolinomio(cadena, listaPolinomios)) {
                    system("cls");
                    verPolinomios(listaPolinomios);
                    cout << endl << "Error: No existe ningun polinomio con el nombre " << cadena << endl;
                    cout << "Ingrese el nombre del polinomio que quiere operar: ";
                    cin >> cadena;
                }
                system("cls");
                verPolinomios(listaPolinomios);
                cout << endl << buscarPolinomio(listaPolinomios, cadena) << endl;
                switchSubmenu(opcion2, listaPolinomios, cadena);
            }
            cout << endl;
            system("pause");
            break;
        case 5:
            system("cls");
            cout << "Ingrese la expresion a ejecutar: ";
            cin >> cadena;
            system("cls");
            if(eval(cadena, listaPolinomios).error) {
                cout << "No se pudo operar la expresion '" << cadena << "'. Puede que exista una division incorrecta." << endl;
            } else {
                cout << cadena << " = ";
                cout << eval(cadena, listaPolinomios) << endl;
            }
            cout << endl;
            system("pause");
            break;
        case 6:
            system("cls");
            if(listaPolinomios == NULL) {
                cout << "No hay polinomios registrados." << endl;
            } else {
                cout << "Existen " << contarPolinomios(listaPolinomios) << " polinomios registrados:" << endl << endl;
                verPolinomios(listaPolinomios);
            }
            cout << endl;
            system("pause");
            break;
        case 7:
            system("cls");
            leerArchivo(listaPolinomios);
            cout << endl << endl;
            system("pause");
            break;
        default:
            system("cls");
            cout << "Terminando el programa . . ." << endl;
            return 0;
            break;
        }
    }
}
