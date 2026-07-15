Sistema de Reportes de Inseguridad Ciudadana en Tacna
------------------------------------------------------------
1.-Descripción del Problema
------------------------------------------------------------
La inseguridad ciudadana constituye una de las principales preocupaciones 
de la población de Tacna. En muchas ocasiones, los incidentes ocurridos no
quedan organizados en un registro que permita consultar, actualizar o dar 
seguimiento a los reportes realizados.

Este proyecto propone el desarrollo de un sistema que facilite el registro 
y la administración de reportes relacionados con hechos de inseguridad
ciudadana, permitiendo almacenar la información de manera organizada 
mediante archivos de texto y ofrecer una consulta rápida de los incidentes
registrados.

2.-Solución Implementada
--------------------------------------------------------------
Se implementó una aplicación en lenguaje **C++** utilizando programación
modular, donde cada módulo cumple una función específica dentro del sistema.

El proyecto está organizado en los siguientes módulos:

**Denuncia**  

    - Registro de nuevos incidentes
    - Consulta de reportes registrados
    - Búsqueda de incidentes
    - Modificación de Información
    - Eliminación de Reportes
**Archivo**

    - Lectura de reportes Almacenados
    - Escritura de información en el archivo "datos.txt"
    - Actualización permanente de los registros
**Seguridad**

    - Presentación de recomendaciones de seguridad para la ciudadanía
    
3.-Tecnologías y Herramientas utilizadas
----------------------------------------------------------------
- Compilador compatible con **C++** o superior
- IDE recomendado:
      - Dev-C++
      - Code::Blocks
- Sistema Operativo Windows
- El archivo **datos.txt** será utilizado para almacenar permanentemente
  la información registrada
  
4.-Requerimientos Funcionales
-----------------------------------------------------------------
El sistema debe cumplir con los siguientes requerimientos funcionales:

    01-RF: Mostrar un menú principal con las opciones disponibles del sistema.
    02-RF: Registrar nuevos incidentes de inseguridad ciudadana ingresando los datos   correspondientes.
    03-RF: Mostrar todos los incidentes registrados de forma organizada.
    04-RF: Buscar un incidente mediante su código de identificación.
    05-RF: Modificar la información de un incidente previamente registrado.
    06-RF: Eliminar un incidente existente del sistema.
    07-RF: Guardar automáticamente la información de los incidentes en un archivo de texto.
    08-RF: Recuperar la información almacenada al iniciar el sistema.
    09-RF: Mostrar consejos de seguridad y prevención para la ciudadanía.
    10-RF: Permitir la salida segura del sistema.
5.- Conclusiones
------------------------------------------------------------------
- El desarrollo del Sistema de Reportes de Inseguridad Ciudadana permitió aplicar los conocimientos adquiridos en programación C++, integrando estructuras, funciones, archivos y programación modular en una aplicación funcional.
- El sistema facilita el registro, consulta, modificación y eliminación de incidentes de inseguridad ciudadana, contribuyendo a una mejor organización de la información relacionada con los hechos delictivos ocurridos en la ciudad de Tacna.
- La utilización de archivos de texto permite conservar la información registrada, garantizando la disponibilidad de los datos para futuras consultas sin perder la información al cerrar el programa.
- La incorporación de un módulo de consejos de seguridad brinda información preventiva a los usuarios, promoviendo una mayor conciencia sobre las medidas de protección frente a situaciones de inseguridad ciudadana.

6.- Bibligrafía
------------------------------------------------------------------
Municipalidad Provincial de Tacna. (s. f.). Portal institucional de la Municipalidad Provincial de Tacna.             https://www.munitacna.gob.pe/ 

Municipalidad Provincial de Tacna. (s. f.). Teléfonos de Seguridad Ciudadana. https://www.munitacna.gob.pe/pagina/sf/seguridad/telefonos 

Plataforma Digital Única del Estado Peruano. (s. f.). Municipalidad Provincial de Tacna: Contacto y números de emergencia. https://www.gob.pe/institucion/munitacna/contacto-y-numeros-de-emergencias 

--------------------------------------------------------------------
Proyecto desarrollado por estudiantes de la

**Universidad Nacional Jorge Basadre Grohmann**

Escuela Profesional de Ingeniería en Informática y Sistemas

Curso: **Fundamentos de Programación**

Semestre Académico **2026-I**

