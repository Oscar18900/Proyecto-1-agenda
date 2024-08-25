/*
1) estructura del contacto
2) lista doblemente ligada
3) funcion para agregar contacto
4) Reordenar por apellido
5) Mostrar contactos
6) Buscar contacto por nombre y mostrar información
7) Editar contacto (se debe mantener el orden de la lista, esto es, si cambia la
1ra letra del nombre, reordenar la lista x nombre)
8) Borrar contacto 
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Contacto {
    string nombre;
    string apellidos;
    string correo;
    string celular;
    string fechaNacimiento;
};

struct Nodo {
    Contacto data;
    Nodo* siguiente;
    Nodo* anterior;
};
