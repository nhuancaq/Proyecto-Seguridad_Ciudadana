#include <iostream>
#include <string>
#include "denuncia.h"
using namespace std;
void registrarIncidente(Denuncia denuncias[], int &cantidad){
	cout << "\n=========================================\n";
    cout << "          NUEVO REPORTE DE INCIDENTE\n";
    cout << "=========================================\n";
    
    denuncias[cantidad].codigo = cantidad + 1; 

    cout << "Nombre del denunciante (Opcional): ";
    getline(cin >> ws, denuncias[cantidad].nombre);

    cout << "DNI (Opcional): ";
    getline(cin, denuncias[cantidad].dni);

    cout << "Tipo de incidente (Robo, Asalto, Hurto, Violencia, Vandalismo, Otro): ";
    getline(cin, denuncias[cantidad].tipo);

    cout << "Fecha (DD/MM/AAAA): ";
    getline(cin, denuncias[cantidad].fecha);

    cout << "Hora (HH:MM): ";
    getline(cin, denuncias[cantidad].hora);

    cout << "Distrito: ";
    getline(cin, denuncias[cantidad].distrito);

    cout << "Direccion exacta: ";
    getline(cin, denuncias[cantidad].direccion);

    cout << "Breve descripcion del hecho: ";
    getline(cin, denuncias[cantidad].descripcion);

    cout << "Nivel de gravedad (Bajo, Medio, Alto): ";
    getline(cin, denuncias[cantidad].gravedad);

    denuncias[cantidad].estado = "Pendiente"; // El caso inicia como pendiente

    cantidad++; // Aumenta el contador de denuncias

    cout << "\n[!] Incidente registrado. Codigo de caso: " << denuncias[cantidad-1].codigo << "\n";

}

void mostrarIncidentes(const Denuncia denuncias[], int cantidad){
	cout << "\n=========================================================\n";
    cout << "              LISTA DE INCIDENTES REGISTRADOS\n";
    cout << "=========================================================\n";
    
    if (cantidad == 0) {
        cout << "No hay incidentes registrados en el sistema.\n";
        return; // Detiene la función si no hay nada que mostrar
    }

    // Bucle para imprimir todas las denuncias guardadas
    for (int i = 0; i < cantidad; i++) {
        cout << "Codigo: " << denuncias[i].codigo << " | Tipo: " << denuncias[i].tipo << "\n";
        cout << "Distrito: " << denuncias[i].distrito << " | Fecha: " << denuncias[i].fecha << "\n";
        cout << "Gravedad: " << denuncias[i].gravedad << " | Estado: " << denuncias[i].estado << "\n";
        cout << "Descripcion: " << denuncias[i].descripcion << "\n";
        cout << "---------------------------------------------------------\n";
    }

}

void buscarIncidente(const Denuncia denuncias[], int cantidad){

}

void modificarIncidente(Denuncia denuncias[], int cantidad){

}

void eliminarIncidente(Denuncia denuncias[], int &cantidad){

}
