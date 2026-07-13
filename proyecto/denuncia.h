#ifndef DENUNCIA_H
#define DENUNCIA_H

#include <iostream>
#include <string>
using namespace std; 
struct Denuncia {
    int codigo;
    string nombre;
    string dni;
    string tipo;
    string fecha;
    string hora;
    string distrito;
    string direccion;
    string descripcion;
    string gravedad;
    string estado;
};

void registrarIncidente(Denuncia denuncias[], int &cantidad);
void mostrarIncidentes(const Denuncia denuncias[], int cantidad);
void buscarIncidente(const Denuncia denuncias[], int cantidad);
void modificarIncidente(Denuncia denuncias[], int cantidad);
void eliminarIncidente(Denuncia denuncias[], int &cantidad);

#endif
