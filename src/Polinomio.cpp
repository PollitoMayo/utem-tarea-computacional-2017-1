#include "../include/Polinomio.h"
#include "funciones.cpp"
#include <iostream>
#include <sstream>

using namespace std;

Polinomio::Polinomio() {
    g = 0;
    coeficientes = new int[g+1];
}

Polinomio::Polinomio(int gr) {
    g = gr;
    coeficientes = new int[g+1];
}

Polinomio::Polinomio(string cadena) {
    g = obtenerGrado(cadena);
    coeficientes = new int[g+1];
    for(int i=0; i<g+1; i++) {
        coeficientes[i] = 0;
    }
    llenar(cadena);
}

void Polinomio::llenar(string cadena) {
    int almohadillas = 0;
    int coeficiente;
    int exponente;
    string actual;
    for(int i=0; i<cadena.length(); i++) {
        if(cadena[i] == '#' || i == cadena.length()-1) {
            almohadillas++;
            if(i == cadena.length()-1 && cadena[i] != '#') {
                actual += cadena[i];
            }
            if(almohadillas%2 == 0) {
                istringstream(actual) >> exponente;
                coeficientes[exponente] += coeficiente;
            } else if(almohadillas%2 != 0) {
                istringstream(actual) >> coeficiente;
            }
            actual = "";
        } else {
            actual += cadena[i];
        }
    }
}

Polinomio::~Polinomio() {
    delete [] coeficientes;
}

int Polinomio::grado() {
    return g;
}

void Polinomio::listar() {
    for(int i=0; i<g+1; i++) {
        cout << "P[" << i << "]: " << coeficientes[i] << endl;
    }
}

void Polinomio::mostrar() {
    bool primero = true;
    for(int i=0; i<g+1; i++) {
        if(coeficientes[i] != 0) {
            if(coeficientes[i] > 0 && !primero) {
                cout << "+";
            }
            if(coeficientes[i] == -1) {
                cout << "-";
            } else if (coeficientes[i] != 1) {
                cout << coeficientes[i];
            }
            if(i != 0) {
                cout << "x";
                if(i != 1) {
                    cout << "^" << i;
                }
            }
            if(primero) {
                primero = false;
            }
        }

    }
}


