#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Integrantes: Jos� V�squez, H�ctor, Jonas Dom�nguez, Jorge Pi�a, Samuel Mosquera, Jhosnar, Jes�s Arrieche

// Estructura para almacenar los datos de un art�culo
struct Articulo {
    string titulo;
    string fecha;
    string directorio;
};

// Funciones para gestionar los art�culos
void agregarArticulo(vector<Articulo>& articulos) {
    Articulo nuevoArticulo;
    cout << "Ingrese el t�tulo del art�culo: ";
    cin.ignore();
    getline(cin, nuevoArticulo.titulo);
    cout << "Ingrese la fecha de publicaci�n (DD/MM/AAAA): ";
    getline(cin, nuevoArticulo.fecha);
    cout << "Ingrese el directorio del archivo (ejemplo.pdf): ";
    getline(cin, nuevoArticulo.directorio);
    articulos.push_back(nuevoArticulo);
    cout << "Art�culo agregado exitosamente.\n";
}

void actualizarArticulo(vector<Articulo>& articulos) {
    int index;
    cout << "Ingrese el �ndice del art�culo a actualizar (0 a " << articulos.size() - 1 << "): ";
    cin >> index;
    if (index >= 0 && index < articulos.size()) {
        cout << "Ingrese el nuevo t�tulo del art�culo: ";
        cin.ignore();
        getline(cin, articulos[index].titulo);
        cout << "Ingrese la nueva fecha de publicaci�n: ";
        getline(cin, articulos[index].fecha);
        cout << "Ingrese el nuevo directorio del archivo: ";
        getline(cin, articulos[index].directorio);
        cout << "Art�culo actualizado exitosamente.\n";
    } else {
        cout << "�ndice inv�lido.\n";
    }
}

void eliminarArticulo(vector<Articulo>& articulos) {
    int index;
    cout << "Ingrese el �ndice del art�culo a eliminar (0 a " << articulos.size() - 1 << "): ";
    cin >> index;
    if (index >= 0 && index < articulos.size()) {
        articulos.erase(articulos.begin() + index);
        cout << "Art�culo eliminado exitosamente.\n";
    } else {
        cout << "�ndice inv�lido.\n";
    }
}

void mostrarArticulos(const vector<Articulo>& articulos) {
    if (articulos.empty()) {
        cout << "No hay art�culos almacenados.\n";
        return;
    }
    cout << "Lista de art�culos:\n";
    for (size_t i = 0; i < articulos.size(); ++i) {
        cout << i << ": " << articulos[i].titulo << " | Fecha: " << articulos[i].fecha << " | Archivo: " << articulos[i].directorio << endl;
    }
}

int main() {
    vector<Articulo> articulos;
    int opcion;

    do {
        cout << "\nMen� de Gesti�n de Art�culos\n";
        cout << "1. Agregar Art�culo\n";
        cout << "2. Actualizar Art�culo\n";
        cout << "3. Eliminar Art�culo\n";
        cout << "4. Mostrar Art�culos\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarArticulo(articulos);
                break;
            case 2:
                actualizarArticulo(articulos);
                break;
            case 3:
                eliminarArticulo(articulos);
                break;
            case 4:
                mostrarArticulos(articulos);
                break;
            case 5:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opci�n inv�lida. Intente de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}
