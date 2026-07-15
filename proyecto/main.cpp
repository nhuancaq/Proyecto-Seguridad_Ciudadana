#include <iostream>
#include <string>

#include "denuncia.h"
#include "seguridad.h"
#include "archivo.h"

using namespace std;

// Función que muestra el menú principal
void menu(){
    cout << "=========================================================\n";
    cout << "      SISTEMA DE REPORTES DE INSEGURIDAD CIUDADANA\n";
    cout << "                    TACNA - PERU\n";
    cout << "=========================================================\n\n";

    cout << "    [1] Registrar incidente\n\n";
    cout << "    [2] Mostrar incidentes\n\n";
    cout << "    [3] Buscar incidente\n\n";
    cout << "    [4] Modificar incidente\n\n";
    cout << "    [5] Eliminar incidente\n\n";
    cout << "    [6] Consejos de seguridad\n\n";
    cout << "    [0] Salir\n\n";
    cout << "=========================================================\n";
    cout << "Seleccione una opcion: ";
}

// Programa principal
int main(){

    int opcion;
    Denuncia listaDenuncias[100];
    int cantidadActual = 0;

    cargarDatos(listaDenuncias, cantidadActual);

    do{
        system("cls");

        menu();

        // Validación estricta: Solo acepta números y valida que estén entre 0 y 6
        while (!(cin >> opcion) || opcion < 0 || opcion > 6) {
            cin.clear();
            cin.ignore(10000, '\n');
            system("cls");
            menu();
            cout << "\n[!] Error: Opcion invalida. Ingrese unicamente numeros del 0 al 6: ";
        }
        cin.ignore(10000, '\n');

        system("cls");

        switch(opcion){
            case 1:
                registrarIncidente(listaDenuncias, cantidadActual);
                break;
            case 2:
                mostrarIncidentes(listaDenuncias, cantidadActual);
                break;
            case 3:
                buscarIncidente(listaDenuncias, cantidadActual);
                break;
            case 4:
                modificarIncidente(listaDenuncias, cantidadActual);
                break;
            case 5:
                eliminarIncidente(listaDenuncias, cantidadActual);
                break;
            case 6:
                consejosSeguridad();
                break;
            case 0:
                cout << "\nGracias por utilizar el sistema de reportes \n";
                break;
        }

        if(opcion != 0){
            cout << "\nPresione ENTER para continuar...";
            cin.get();
        }

    } while(opcion != 0);

    return 0;
}
