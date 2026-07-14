#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "denuncia.h"

// Guarda todas las denuncias en datos.txt
void guardarDatos(const Denuncia denuncias[], int cantidad);

// Carga las denuncias desde datos.txt
void cargarDatos(Denuncia denuncias[], int &cantidad);

#endif