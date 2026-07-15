#include <iostream>
#include <string>
#include "denuncia.h"
#include "archivo.h" // Vital para poder guardar

using namespace std;

void registrarIncidente(Denuncia denuncias[], int &cantidad) {
    cout << "\n=========================================\n";
    cout << "          NUEVO REPORTE DE INCIDENTE\n";
    cout << "=========================================\n";
    
    // --- INICIO DE LA ADVERTENCIA LEGAL ---
    cout << "\n[ ADVERTENCIA IMPORTANTE ]\n";
    cout << "Este formulario tiene caracter de denuncia oficial. El registro de\n";
    cout << "incidentes falsos, difamatorios o realizados de mala fe con el fin\n";
    cout << "de perjudicar a terceros esta sujeto a severas sanciones legales.\n";
    cout << "Por favor, utilice esta herramienta con total responsabilidad.\n";
    
    char confirmacion;
    cout << "\n¿Comprende esta advertencia y desea continuar con el registro? (S/N): ";
    cin >> confirmacion;
    
    // Limpiamos el buffer para evitar el famoso problema del "Enter fantasma"
    cin.ignore(); 

    if (confirmacion != 'S' && confirmacion != 's') {
        cout << "\n[!] Operacion cancelada. Volviendo al menu principal...\n";
        return; // Esto expulsa al usuario de la función y cancela el registro
    }
    // --- FIN DE LA ADVERTENCIA ---

    denuncias[cantidad].codigo = cantidad + 1; 

    cout << "\nNombre del denunciante (Opcional): ";
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

    denuncias[cantidad].estado = "Pendiente";

    cantidad++; 

    // Se guarda la nueva información en el TXT
    guardarDatos(denuncias, cantidad);

    cout << "\n[!] Incidente registrado. Codigo de caso: " << denuncias[cantidad-1].codigo << "\n";
}

void mostrarIncidentes(const Denuncia denuncias[], int cantidad) {
    cout << "\n=========================================================\n";
    cout << "              LISTA DE INCIDENTES REGISTRADOS\n";
    cout << "=========================================================\n";
    
    if (cantidad == 0) {
        cout << "No hay incidentes registrados en el sistema.\n";
        return; 
    }

    for (int i = 0; i < cantidad; i++) {
        cout << "Codigo: " << denuncias[i].codigo << " | Tipo: " << denuncias[i].tipo << "\n";
        cout << "Distrito: " << denuncias[i].distrito << " | Fecha: " << denuncias[i].fecha << "\n";
        cout << "Gravedad: " << denuncias[i].gravedad << " | Estado: " << denuncias[i].estado << "\n";
        cout << "Descripcion: " << denuncias[i].descripcion << "\n";
        cout << "---------------------------------------------------------\n";
    }
}

void buscarIncidente(const Denuncia denuncias[], int cantidad) {
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
            cin.ignore();

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
            getline(cin >> ws, distritoBusqueda); // Limpia espacios basura iniciales

            cout << "\n--- RESULTADOS EN " << distritoBusqueda << " ---\n";
            for (int i = 0; i < cantidad; i++) {
                // Buscamos si el distrito guardado CONTIENE lo que el usuario escribió
                if (denuncias[i].distrito.find(distritoBusqueda) != string::npos) {
                    cout << "Codigo [" << denuncias[i].codigo << "] - " << denuncias[i].tipo << " - Fecha: " << denuncias[i].fecha << "\n";
                    encontrado = true;
                }
            }
            break;
        }
        case 3: {
            string tipoBusqueda;
            cout << "\nIngrese el tipo de delito (Robo, Asalto, etc.): ";
            getline(cin >> ws, tipoBusqueda);

            cout << "\n--- RESULTADOS PARA " << tipoBusqueda << " ---\n";
            for (int i = 0; i < cantidad; i++) {
                if (denuncias[i].tipo.find(tipoBusqueda) != string::npos) {
                    cout << "Codigo [" << denuncias[i].codigo << "] - Distrito: " << denuncias[i].distrito << " - Fecha: " << denuncias[i].fecha << "\n";
                    encontrado = true;
                }
            }
            break;
        }
        case 4: {
            string fechaBusqueda;
            cout << "\nIngrese la fecha a buscar (DD/MM/AAAA): ";
            getline(cin >> ws, fechaBusqueda);

            cout << "\n--- RESULTADOS DEL " << fechaBusqueda << " ---\n";
            for (int i = 0; i < cantidad; i++) {
                // La magia: Si hay espacios basura al final de la fecha guardada, los ignora
                if (denuncias[i].fecha.find(fechaBusqueda) != string::npos) {
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

void modificarIncidente(Denuncia denuncias[], int cantidad) {
    cout << "\n=========================================\n";
    cout << "         MODIFICAR INCIDENTE\n";
    cout << "=========================================\n";

    if (cantidad == 0) {
        cout << "No hay incidentes registrados para modificar.\n";
        return;
    }

    int codigoBusqueda;
    cout << "Ingrese el codigo del incidente a modificar: ";
    cin >> codigoBusqueda;
    cin.ignore();

    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        if (denuncias[i].codigo == codigoBusqueda) {
            encontrado = true;
            
            cout << "\n--- INCIDENTE ENCONTRADO ---\n";
            cout << "Tipo: " << denuncias[i].tipo << " | Distrito actual: " << denuncias[i].distrito << "\n";
            cout << "Estado actual: " << denuncias[i].estado << "\n";

            int opcionMod;
            cout << "\n¿Que dato desea actualizar?\n";
            cout << "1. Estado (Pendiente, En investigacion, Resuelto)\n";
            cout << "2. Descripcion\n";
            cout << "3. Gravedad\n";
            cout << "4. Distrito\n";
            cout << "Seleccione una opcion: ";
            cin >> opcionMod;

            switch (opcionMod) {
                case 1:
                    cout << "Nuevo estado: ";
                    getline(cin >> ws, denuncias[i].estado); 
                    cout << "[!] Estado actualizado correctamente a: " << denuncias[i].estado << "\n";
                    break;
                case 2:
                    cout << "Nueva descripcion: ";
                    getline(cin >> ws, denuncias[i].descripcion);
                    cout << "[!] Descripcion actualizada correctamente.\n";
                    break;
                case 3:
                    cout << "Nueva gravedad (Bajo, Medio, Alto): ";
                    getline(cin >> ws, denuncias[i].gravedad);
                    cout << "[!] Gravedad actualizada correctamente.\n";
                    break;
                case 4:
                    cout << "Nuevo distrito: ";
                    getline(cin >> ws, denuncias[i].distrito);
                    cout << "[!] Distrito actualizado correctamente.\n";
                    break;
                default:
                    cout << "[!] Opcion invalida. No se realizaron cambios.\n";
            }

            // ¡Excelente! Guarda el cambio en el TXT
            guardarDatos(denuncias, cantidad);

            break; 
        }
    }

    if (!encontrado) {
        cout << "\n[!] Error: No se encontro ningun incidente con el codigo " << codigoBusqueda << ".\n";
    }
}

void eliminarIncidente(Denuncia denuncias[], int &cantidad) {
    cout << "\n=========================================\n";
    cout << "         ELIMINAR INCIDENTE\n";
    cout << "=========================================\n";

    if (cantidad == 0) {
        cout << "No hay incidentes registrados para eliminar.\n";
        return; 
    }

    int codigoBusqueda;
    cout << "Ingrese el codigo del incidente a eliminar: ";
    cin >> codigoBusqueda;

    bool encontrado = false;
    int posicion = -1; 

    for (int i = 0; i < cantidad; i++) {
        if (denuncias[i].codigo == codigoBusqueda) {
            encontrado = true;
            posicion = i; 
            break;
        }
    }

    if (encontrado) {
        char confirmacion;
        cout << "\n[!] Se encontro el incidente: " << denuncias[posicion].tipo 
             << " en " << denuncias[posicion].distrito << "\n";
        cout << "Esta seguro que desea ELIMINARLO permanentemente? (S/N): ";
        cin >> confirmacion;
        cin.ignore();

        if (confirmacion == 'S' || confirmacion == 's') {
            for (int i = posicion; i < cantidad - 1; i++) {
                denuncias[i] = denuncias[i + 1];
            }
            cantidad--;

            // ¡Excelente! Actualiza el TXT sin la denuncia borrada
            guardarDatos(denuncias, cantidad);

            cout << "\n[!] Incidente eliminado con exito.\n";
            
        } else {
            cout << "\n[!] Operacion cancelada. El incidente esta a salvo.\n";
        }
    } else {
        cout << "\n[!] Error: No se encontro ningun incidente con el codigo " << codigoBusqueda << ".\n";
    }
}
