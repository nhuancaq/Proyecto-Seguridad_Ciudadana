#include "archivo.h"

#include <iostream>
#include <fstream>

using namespace std;

// Guarda la información en datos.txt

void guardarDatos(){

    ofstream archivo("datos.txt", ios::app);

    if(!archivo){

        cout<<"Error al abrir el archivo."<<endl;

        return;

    }

    // Aquí se implementará el guardado de los incidentes.

    archivo.close();

}

// Carga la información desde datos.txt

void cargarDatos(){

    ifstream archivo("datos.txt");

    if(!archivo){

        cout<<"No existe el archivo de datos."<<endl;

        return;

    }

    // Aquí se implementará la lectura de los incidentes.

    archivo.close();

}
