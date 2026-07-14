#include "archivo.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//---------------------------------------------------
// Guarda todas las denuncias en datos.txt
//---------------------------------------------------

void guardarDatos(const Denuncia denuncias[], int cantidad){

    ofstream archivo("datos.txt");

    if(!archivo){

        cout << "Error al abrir el archivo." << endl;

        return;

    }

    for(int i = 0; i < cantidad; i++){

        archivo << denuncias[i].codigo << ";"
                << denuncias[i].nombre << ";"
                << denuncias[i].dni << ";"
                << denuncias[i].tipo << ";"
                << denuncias[i].fecha << ";"
                << denuncias[i].hora << ";"
                << denuncias[i].distrito << ";"
                << denuncias[i].direccion << ";"
                << denuncias[i].descripcion << ";"
                << denuncias[i].gravedad << ";"
                << denuncias[i].estado << endl;

    }

    archivo.close();

}

//---------------------------------------------------
// Carga todas las denuncias desde datos.txt
//---------------------------------------------------

void cargarDatos(Denuncia denuncias[], int &cantidad){

    ifstream archivo("datos.txt");

    if(!archivo){

        return;

    }

    cantidad = 0;

    string linea;

    while(getline(archivo, linea)){

        stringstream ss(linea);
        string dato;

        getline(ss, dato, ';');
        denuncias[cantidad].codigo = stoi(dato);

        getline(ss, denuncias[cantidad].nombre, ';');
        getline(ss, denuncias[cantidad].dni, ';');
        getline(ss, denuncias[cantidad].tipo, ';');
        getline(ss, denuncias[cantidad].fecha, ';');
        getline(ss, denuncias[cantidad].hora, ';');
        getline(ss, denuncias[cantidad].distrito, ';');
        getline(ss, denuncias[cantidad].direccion, ';');
        getline(ss, denuncias[cantidad].descripcion, ';');
        getline(ss, denuncias[cantidad].gravedad, ';');
        getline(ss, denuncias[cantidad].estado);

        cantidad++;

    }

    archivo.close();

}