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
    string apellidoP;
    string apellidoM;
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

    // 5) Mostrar contactos
    void mostrarContactos() {
        Nodo* actual = cabeza;
        while (actual) {
            cout << "Nombre: " << actual->data.nombre << endl;
            cout << "Apellido Paterno: " << actual->data.apellidoP << endl;
            cout << "Apellido Materno: " << actual->data.apellidoM << endl;
            cout << "Correo: " << actual->data.correo << endl;
            cout << "Celular: " << actual->data.celular << endl;
            cout << "Fecha de Nacimiento: " << actual->data.fechaNacimiento << endl;
            cout << "-----------------------------------" << endl;
            actual = actual->siguiente;
        }
    }

    void insertarOrdenado(Nodo* nuevoNodo) {
        if (!cabeza || nuevoNodo->data.nombre < cabeza->data.nombre) {
            nuevoNodo->siguiente = cabeza;
            if (cabeza) cabeza->anterior = nuevoNodo;
            cabeza = nuevoNodo;
        } else {
            Nodo* actual = cabeza;
            while (actual->siguiente && actual->siguiente->data.nombre < nuevoNodo->data.nombre) {
                actual = actual->siguiente;
            }
            nuevoNodo->siguiente = actual->siguiente;
            if (actual->siguiente) actual->siguiente->anterior = nuevoNodo;
            actual->siguiente = nuevoNodo;
            nuevoNodo->anterior = actual;
        }
    }

    void agregarContacto(const Contacto& nuevoContacto) {
        Nodo* nuevoNodo = new Nodo{nuevoContacto, nullptr, nullptr};
        insertarOrdenado(nuevoNodo);
    }
}; 

int main() {
    ListaContactos lista;
    int opc; 

    do {
        cout << "\n--- Menu de Gestion de Contactos ---\n";
        cout << "1. Agregar contacto\n";
        cout << "2. Reordenar por apellido\n";
        cout << "3. Mostrar contactos\n";
        cout << "4. Buscar contacto por nombre\n";
        cout << "5. Editar contacto\n";
        cout << "6. Borrar contacto\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opc;

        switch (opc) {
        case 1: {
            Contacto nuevoContacto;
            cout << "Ingrese nombre: ";
            cin >> nuevoContacto.nombre;
            cout << "Ingrese apellido Paterno: ";
            cin >> nuevoContacto.apellidoP;
            cout << "Ingrese apellido Materno: ";
            cin >> nuevoContacto.apellidoM;
            cout << "Ingrese correo: ";
            cin >> nuevoContacto.correo;
            cout << "Ingrese celular: ";
            cin >> nuevoContacto.celular;
            cout << "Ingrese fecha de nacimiento: ";
            cin >> nuevoContacto.fechaNacimiento;
            lista.agregarContacto(nuevoContacto);
            break;
        }
        case 2:
            
            break;
        case 3:
            lista.mostrarContactos(); 
            break;
        case 4:
          
            break;
        case 5:
          
            break;
        case 6:
         
            break;
        }
    } while (opc != 7); 

    return 0;
}




