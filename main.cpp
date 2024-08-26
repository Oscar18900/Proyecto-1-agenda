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


class ListaContactos {
private:
    Nodo* cabeza;
public:
    ListaContactos() : cabeza(nullptr) {}
//5)Mostrar contactos
void mostrarContactos() {
        Nodo* actual = cabeza;
        while (actual) {
            cout << "Nombre: " << actual->data.nombre << endl;
            cout << "Apellidos: " << actual->data.apellidos << endl;
            cout << "Correo: " << actual->data.correo << endl;
            cout << "Celular: " << actual->data.celular << endl;
            cout << "Fecha de Nacimiento: " << actual->data.fechaNacimiento << endl;
            cout << "-----------------------------------" << endl;
            actual = actual->siguiente;
        }
    }
}



}
