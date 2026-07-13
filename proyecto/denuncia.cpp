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
	
	cout << "\n=========================================\n";
    cout << "           BUSCAR INCIDENTE\n";
    cout << "=========================================\n";

    if (cantidad == 0) {
        cout << "No hay incidentes registrados en el sistema.\n";
        return;
    }

    int opcionBusqueda;
    cout << "Criterios de busqueda:\n";
    cout << "1. Buscar por Codigo\n";
    cout << "2. Buscar por Distrito\n";
    cout << "3. Buscar por Tipo de delito\n";
    cout << "4. Buscar por Fecha\n";
    cout << "Seleccione una opcion: ";
    cin >> opcionBusqueda;
    
    
    cin.ignore(); 

    bool encontrado = false; 

    switch (opcionBusqueda) {
        case 1: {
            int codigoBusqueda;
            cout << "\nIngrese el codigo del incidente: ";
            cin >> codigoBusqueda;

            for (int i = 0; i < cantidad; i++) {
                if (denuncias[i].codigo == codigoBusqueda) {
                    cout << "\n--- INCIDENTE ENCONTRADO ---\n";
                    cout << "Codigo: " << denuncias[i].codigo << " | Tipo: " << denuncias[i].tipo << "\n";
                    cout << "Distrito: " << denuncias[i].distrito << " | Fecha: " << denuncias[i].fecha << "\n";
                    cout << "Gravedad: " << denuncias[i].gravedad << " | Estado: " << denuncias[i].estado << "\n";
                    cout << "Descripcion: " << denuncias[i].descripcion << "\n";
                    encontrado = true;
                    break; 
                }
            }
            break;
        }
        case 2: {
            string distritoBusqueda;
            cout << "\nIngrese el distrito a buscar: ";
            getline(cin, distritoBusqueda);

            cout << "\n--- RESULTADOS EN " << distritoBusqueda << " ---\n";
            for (int i = 0; i < cantidad; i++) {
                if (denuncias[i].distrito == distritoBusqueda) {
                    cout << "Codigo [" << denuncias[i].codigo << "] - " << denuncias[i].tipo << " - Fecha: " << denuncias[i].fecha << "\n";
                    encontrado = true;
                }
            }
            break;
        }
        case 3: {
            string tipoBusqueda;
            cout << "\nIngrese el tipo de delito (Robo, Asalto, etc.): ";
            getline(cin, tipoBusqueda);

            cout << "\n--- RESULTADOS PARA " << tipoBusqueda << " ---\n";
            for (int i = 0; i < cantidad; i++) {
                if (denuncias[i].tipo == tipoBusqueda) {
                    cout << "Codigo [" << denuncias[i].codigo << "] - Distrito: " << denuncias[i].distrito << " - Fecha: " << denuncias[i].fecha << "\n";
                    encontrado = true;
                }
            }
            break;
        }
        case 4: {
            string fechaBusqueda;
            cout << "\nIngrese la fecha a buscar (DD/MM/AAAA): ";
            getline(cin, fechaBusqueda);

            cout << "\n--- RESULTADOS DEL " << fechaBusqueda << " ---\n";
            for (int i = 0; i < cantidad; i++) {
                if (denuncias[i].fecha == fechaBusqueda) {
                    cout << "Codigo [" << denuncias[i].codigo << "] - " << denuncias[i].tipo << " - Distrito: " << denuncias[i].distrito << "\n";
                    encontrado = true;
                }
            }
            break;
        }
        default:
            cout << "Opcion de busqueda no valida.\n";
            return;
    }

    
    if (!encontrado) {
        cout << "\n[!] No se encontraron incidentes que coincidan con su busqueda.\n";
    }

}

void modificarIncidente(Denuncia denuncias[], int cantidad){

}

void eliminarIncidente(Denuncia denuncias[], int &cantidad){

}
