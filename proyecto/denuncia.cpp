#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include "denuncia.h"
#include "archivo.h" // Vital para poder guardar

using namespace std;

// --- FUNCIONES AUXILIARES DE VALIDACIÓN Y LIMPIEZA ---

// Convierte un texto a minúsculas y elimina espacios extras para evitar errores de tipeo
string limpiarTexto(string str) {
    // Eliminar espacios al inicio y final si los hubiera
    size_t start = str.find_first_not_of(" \t\n\r");
    if (string::npos == start) return "";
    size_t end = str.find_last_not_of(" \t\n\r");
    str = str.substr(start, (end - start + 1));

    // Convertir todo a minúsculas
    for (char &c : str) {
        c = tolower(static_cast<unsigned char>(c));
    }
    return str;
}

// Revisa que una cadena solo contenga letras, espacios y tildes/ñ
bool esSoloLetras(const string &str) {
    if (str.empty()) return false;
    for (char c : str) {
        unsigned char uc = static_cast<unsigned char>(c);
        if (!isalpha(uc) && uc != ' ' && uc != 'á' && uc != 'é' && uc != 'í' && uc != 'ó' && uc != 'ú' && 
            uc != 'Á' && uc != 'É' && uc != 'Í' && uc != 'Ó' && uc != 'Ú' && uc != 'ñ' && uc != 'Ñ') {
            return false;
        }
    }
    return true;
}

// Revisa que una cadena contenga exclusivamente números (para el DNI)
bool esSoloNumeros(const string &str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isdigit(static_cast<unsigned char>(c))) return false;
    }
    return true;
}

// ------------------------------------------

void registrarIncidente(Denuncia denuncias[], int &cantidad) {
    
    if (cantidad >= 100) {
        cout << "\n[!] ERROR: La base de datos esta llena. No se pueden registrar mas incidentes.\n";
        return;
    }
    
    cout << "\n=========================================\n";
    cout << "          NUEVO REPORTE DE INCIDENTE\n";
    cout << "=========================================\n";
    
    cout << "\n[ PROTOCOLO DE REGISTRO OFICIAL ]\n";
    cout << "ATENCION: Como agente operador, lea la siguiente advertencia al ciudadano:\n";
    cout << "-----------------------------------------------------------------------\n";
    cout << "\"Le informamos que este formulario tiene caracter de denuncia oficial.\n";
    cout << "El registro de incidentes falsos, difamatorios o realizados de mala fe\n";
    cout << "esta sujeto a severas sanciones legales segun el Codigo Penal.\"\n";
    cout << "-----------------------------------------------------------------------\n";
    
    char confirmacion;
    do {
        cout << "\n¿El ciudadano comprende la advertencia y confirma su declaracion? (S/N): ";
        cin >> confirmacion;
        cin.ignore(10000, '\n'); 

        if (confirmacion != 'S' && confirmacion != 's' && confirmacion != 'N' && confirmacion != 'n') {
            cout << "[!] Error: Ingrese unicamente 'S' para confirmar o 'N' para cancelar.\n";
        }
    } while (confirmacion != 'S' && confirmacion != 's' && confirmacion != 'N' && confirmacion != 'n');

    if (confirmacion == 'N' || confirmacion == 'n') {
        cout << "\n[!] Operacion abortada por negativa del ciudadano. Volviendo al menu...\n";
        return; 
    }

    denuncias[cantidad].codigo = cantidad + 1; 

    // Validación estricta para el Nombre (Solo letras, sin números)
    do {
        cout << "\nNombre del denunciante (Solo letras): ";
        getline(cin >> ws, denuncias[cantidad].nombre);
        if (!esSoloLetras(denuncias[cantidad].nombre)) {
            cout << "[!] Error: El nombre no puede contener numeros ni caracteres especiales.\n";
        }
    } while (!esSoloLetras(denuncias[cantidad].nombre));

    // Validación estricta para el DNI (Exactamente 8 dígitos numéricos)
    do {
        cout << "DNI (Exactamente 8 numeros): ";
        getline(cin >> ws, denuncias[cantidad].dni);
        if (!esSoloNumeros(denuncias[cantidad].dni) || denuncias[cantidad].dni.length() != 8) {
            cout << "[!] Error: El DNI debe contener unicamente 8 digitos numericos.\n";
        }
    } while (!esSoloNumeros(denuncias[cantidad].dni) || denuncias[cantidad].dni.length() != 8);

    do {
        cout << "Tipo de incidente (Robo, Asalto, Hurto, Violencia, Vandalismo, Otro): ";
        getline(cin >> ws, denuncias[cantidad].tipo);
        if (denuncias[cantidad].tipo.empty()) cout << "[!] Error: Este campo es obligatorio.\n";
    } while (denuncias[cantidad].tipo.empty());

    do {
        cout << "Fecha (DD/MM/AAAA): ";
        getline(cin >> ws, denuncias[cantidad].fecha);
    } while (denuncias[cantidad].fecha.empty());

    do {
        cout << "Hora (HH:MM): ";
        getline(cin >> ws, denuncias[cantidad].hora);
    } while (denuncias[cantidad].hora.empty());

    do {
        cout << "Distrito: ";
        getline(cin >> ws, denuncias[cantidad].distrito);
        if (denuncias[cantidad].distrito.empty()) cout << "[!] Error: El distrito es obligatorio.\n";
    } while (denuncias[cantidad].distrito.empty());

    do {
        cout << "Direccion exacta: ";
        getline(cin >> ws, denuncias[cantidad].direccion);
    } while (denuncias[cantidad].direccion.empty());

    do {
        cout << "Breve descripcion del hecho: ";
        getline(cin >> ws, denuncias[cantidad].descripcion);
    } while (denuncias[cantidad].descripcion.empty());

    // Validación de Gravedad flexible a mayúsculas/minúsculas y espacios
    do {
        string entradaGravedad;
        cout << "Nivel de gravedad (Bajo, Medio, Alto): ";
        getline(cin >> ws, entradaGravedad);
        
        string gravedadLimpia = limpiarTexto(entradaGravedad);

        if (gravedadLimpia == "bajo") {
            denuncias[cantidad].gravedad = "Bajo";
            break;
        } else if (gravedadLimpia == "medio") {
            denuncias[cantidad].gravedad = "Medio";
            break;
        } else if (gravedadLimpia == "alto") {
            denuncias[cantidad].gravedad = "Alto";
            break;
        } else {
            cout << "[!] Error: Por favor, ingrese exactamente: Bajo, Medio o Alto.\n";
        }
    } while (true);

    denuncias[cantidad].estado = "En investigacion"; 

    cantidad++; 

    guardarDatos(denuncias, cantidad);

    cout << "\n[!] Incidente registrado exitosamente en el sistema policial.\n";
    cout << "[!] Codigo oficial de caso asignado: " << denuncias[cantidad-1].codigo << "\n";
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
    cout << "Seleccione una opcion (1-4): ";
    
    do {
        while (!(cin >> opcionBusqueda)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "[!] Error: Ingrese unicamente un numero valido del menu (1-4): ";
        }
        cin.ignore(10000, '\n');

        if (opcionBusqueda < 1 || opcionBusqueda > 4) {
            cout << "[!] Opcion fuera de rango. Seleccione una opcion valida (1-4): ";
        }
    } while (opcionBusqueda < 1 || opcionBusqueda > 4);

    bool encontrado = false; 

    switch (opcionBusqueda) {
        case 1: {
            int codigoBusqueda;
            cout << "\nIngrese el codigo del incidente: ";
            
            while (!(cin >> codigoBusqueda)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "[!] Error: Codigo invalido. Ingrese solo numeros: ";
            }
            cin.ignore(10000, '\n');

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
            getline(cin >> ws, distritoBusqueda); 

            cout << "\n--- RESULTADOS EN " << distritoBusqueda << " ---\n";
            for (int i = 0; i < cantidad; i++) {
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
                if (denuncias[i].fecha.find(fechaBusqueda) != string::npos) {
                    cout << "Codigo [" << denuncias[i].codigo << "] - " << denuncias[i].tipo << " - Distrito: " << denuncias[i].distrito << "\n";
                    encontrado = true;
                }
            }
            break;
        }
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
    
    while (!(cin >> codigoBusqueda)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "[!] Error: Codigo invalido. Ingrese solo numeros: ";
    }
    cin.ignore(10000, '\n');

    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        if (denuncias[i].codigo == codigoBusqueda) {
            encontrado = true;
            
            cout << "\n--- INCIDENTE ENCONTRADO ---\n";
            cout << "Tipo: " << denuncias[i].tipo << " | Distrito actual: " << denuncias[i].distrito << "\n";
            cout << "Estado actual: " << denuncias[i].estado << "\n";

            int opcionMod;
            cout << "\n¿Que dato desea actualizar?\n";
            cout << "1. Estado Oficial\n";
            cout << "2. Descripcion\n";
            cout << "3. Gravedad\n";
            cout << "4. Distrito\n";
            cout << "Seleccione una opcion (1-4): ";
            
            do {
                while (!(cin >> opcionMod)) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "[!] Error: Ingrese unicamente un numero valido del menu (1-4): ";
                }
                cin.ignore(10000, '\n');

                if (opcionMod < 1 || opcionMod > 4) {
                    cout << "[!] Opcion fuera de rango. Seleccione una opcion valida (1-4): ";
                }
            } while (opcionMod < 1 || opcionMod > 4);

            switch (opcionMod) {
                case 1:
                    do {
                        string entradaEstado;
                        cout << "Nuevo estado (En investigacion, Resuelto, Archivado): ";
                        getline(cin >> ws, entradaEstado);
                        
                        string estadoLimpio = limpiarTexto(entradaEstado);

                        if (estadoLimpio == "en investigacion") {
                            denuncias[i].estado = "En investigacion";
                            break;
                        } else if (estadoLimpio == "resuelto") {
                            denuncias[i].estado = "Resuelto";
                            break;
                        } else if (estadoLimpio == "archivado") {
                            denuncias[i].estado = "Archivado";
                            break;
                        } else {
                            cout << "[!] Error: Ingrese un estado valido policial (En investigacion, Resuelto o Archivado).\n";
                        }
                    } while (true);
                    cout << "[!] Estado actualizado correctamente a: " << denuncias[i].estado << "\n";
                    break;
                case 2:
                    do {
                        cout << "Nueva descripcion: ";
                        getline(cin >> ws, denuncias[i].descripcion);
                    } while(denuncias[i].descripcion.empty());
                    cout << "[!] Descripcion actualizada correctamente.\n";
                    break;
                case 3:
                    do {
                        string entradaGravedad;
                        cout << "Nueva gravedad (Bajo, Medio, Alto): ";
                        getline(cin >> ws, entradaGravedad);
                        
                        string gravedadLimpia = limpiarTexto(entradaGravedad);

                        if (gravedadLimpia == "bajo") {
                            denuncias[i].gravedad = "Bajo";
                            break;
                        } else if (gravedadLimpia == "medio") {
                            denuncias[i].gravedad = "Medio";
                            break;
                        } else if (gravedadLimpia == "alto") {
                            denuncias[i].gravedad = "Alto";
                            break;
                        } else {
                            cout << "[!] Error: Por favor, ingrese exactamente: Bajo, Medio o Alto.\n";
                        }
                    } while (true);
                    cout << "[!] Gravedad actualizada correctamente a: " << denuncias[i].gravedad << "\n";
                    break;
                case 4:
                    do {
                        cout << "Nuevo distrito: ";
                        getline(cin >> ws, denuncias[i].distrito);
                    } while(denuncias[i].distrito.empty());
                    cout << "[!] Distrito actualizado correctamente.\n";
                    break;
            }

            guardarDatos(denuncias, cantidad);
            break; 
        }
    }

    if (!encontrado) {
        cout << "\n[!] Error: No se encontro ningun incidente con el codigo ingresado.\n";
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
    
    while (!(cin >> codigoBusqueda)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "[!] Error: Codigo invalido. Ingrese solo numeros: ";
    }
    cin.ignore(10000, '\n');

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
        cin.ignore(10000, '\n');

        if (confirmacion == 'S' || confirmacion == 's') {
            for (int i = posicion; i < cantidad - 1; i++) {
                denuncias[i] = denuncias[i + 1];
            }
            cantidad--;

            guardarDatos(denuncias, cantidad);
            cout << "\n[!] Incidente eliminado con exito.\n";
            
        } else {
            cout << "\n[!] Operacion cancelada. El incidente esta a salvo.\n";
        }
    } else {
        cout << "\n[!] Error: No se encontro ningun incidente con el codigo ingresado.\n";
    }
}
