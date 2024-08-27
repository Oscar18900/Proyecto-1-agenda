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
#include <limits> 

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
    
	//Para que cada vez que se ingrese las palabras en mayusculas a minisculas 
    string toLowerCase(const string& str) {
        string lowerStr = str;
        transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
        return lowerStr;
    }

public:
    ListaContactos() : cabeza(nullptr) {}

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
        if (!cabeza || toLowerCase(nuevoNodo->data.nombre) < toLowerCase(cabeza->data.nombre)) {
            nuevoNodo->siguiente = cabeza;
            if (cabeza) cabeza->anterior = nuevoNodo;
            cabeza = nuevoNodo;
        } else {
            Nodo* actual = cabeza;
            while (actual->siguiente && toLowerCase(actual->siguiente->data.nombre) < toLowerCase(nuevoNodo->data.nombre)) {
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

    Nodo* buscarContacto(const string& nombre) {
        Nodo* actual = cabeza;
        string nombreLower = toLowerCase(nombre);
        while (actual && toLowerCase(actual->data.nombre) != nombreLower) {
            actual = actual->siguiente;
        }
        return actual;
    }

    void editarContacto(const string& nombre) {
        Nodo* contacto = buscarContacto(nombre);
        if (contacto) {
            cout << "Ingrese nuevo nombre: ";
            getline(cin, contacto->data.nombre);
            cout << "Ingrese nuevo apellido Paterno: ";
            getline(cin, contacto->data.apellidoP);
            cout << "Ingrese nuevo apellido Materno: ";
            getline(cin, contacto->data.apellidoM);
            cout << "Ingrese nuevo correo: ";
            getline(cin, contacto->data.correo);
            cout << "Ingrese nuevo celular: ";
            getline(cin, contacto->data.celular);
            cout << "Ingrese nueva fecha de nacimiento: ";
            getline(cin, contacto->data.fechaNacimiento);

            // Reordenar la lista si el nombre ha cambiado
            if (contacto->anterior) contacto->anterior->siguiente = contacto->siguiente;
            if (contacto->siguiente) contacto->siguiente->anterior = contacto->anterior;
            if (contacto == cabeza) cabeza = contacto->siguiente;

            insertarOrdenado(contacto);
        } else {
            cout << "Contacto no encontrado." << endl;
        }
    }
}; 

void borrarContacto(const string& nombre) {
    Nodo* contacto = buscarContacto(nombre);
    if (contacto) {
        if (contacto->anterior) contacto->anterior->siguiente = contacto->siguiente;
        if (contacto->siguiente) contacto->siguiente->anterior = contacto->anterior;
        if (contacto == cabeza) cabeza = contacto->siguiente;
        delete contacto;
        cout << "Contacto eliminado." << endl;
    } else {
        cout << "Contacto no encontrado." << endl;
    }
}


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

        // Validar entrada
        if (cin.fail()) {
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada inválida
            cout << "Entrada invalida. Por favor, ingrese un numero." << endl;
            continue;
        }

        cin.ignore(); // Ignorar el salto de línea residual

        switch (opc) {
        case 1: {
            Contacto nuevoContacto;
            cout << "Ingrese nombre: ";
            getline(cin, nuevoContacto.nombre);
            cout << "Ingrese apellido Paterno: ";
            getline(cin, nuevoContacto.apellidoP);
            cout << "Ingrese apellido Materno: ";
            getline(cin, nuevoContacto.apellidoM);
            cout << "Ingrese correo: ";
            getline(cin, nuevoContacto.correo);
            cout << "Ingrese celular: ";
            getline(cin, nuevoContacto.celular);
            cout << "Ingrese fecha de nacimiento: ";
            getline(cin, nuevoContacto.fechaNacimiento);
            lista.agregarContacto(nuevoContacto);
            break;
        }
        case 2:
            // Implementar reordenar por apellido
            break;
        case 3:
            lista.mostrarContactos(); 
            break;
        case 4: {
            string nombre;
            cout << "Ingrese el nombre del contacto a buscar: ";
            getline(cin, nombre);
            Nodo* contacto = lista.buscarContacto(nombre);
            if (contacto) {
                cout << "Contacto encontrado:\n";
                cout << "Nombre: " << contacto->data.nombre << endl;
                cout << "Apellido Paterno: " << contacto->data.apellidoP << endl;
                cout << "Apellido Materno: " << contacto->data.apellidoM << endl;
                cout << "Correo: " << contacto->data.correo << endl;
                cout << "Celular: " << contacto->data.celular << endl;
                cout << "Fecha de Nacimiento: " << contacto->data.fechaNacimiento << endl;
            } else {
                cout << "Contacto no encontrado." << endl;
            }
            break;
        }
        case 5: {
            string nombre;
            cout << "Ingrese el nombre del contacto a editar: ";
            getline(cin, nombre);
            lista.editarContacto(nombre);
            break;
        }
        case 6:
            string nombre;
			cout << "Ingrese el nombre del contacto a borrar: ";
			getline(cin, nombre);
			lista.borrarContacto(nombre);
            break;
        }
    } while (opc != 7); 

    return 0;
}
