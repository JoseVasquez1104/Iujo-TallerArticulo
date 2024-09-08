#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Integrantes: José Vásquez, Héctor, Jonas Domínguez, Jorge Piña, Samuel Mosquera, Jhosnar, Jesús Arrieche

// Estructura para almacenar los datos de un artículo
struct Articulo {
    string titulo;
    string fecha;
    string directorio;
};

// Funciones para gestionar los artículos
void agregarArticulo(vector<Articulo>& articulos) {
    Articulo nuevoArticulo;
    cout << "Ingrese el título del artículo: ";
    cin.ignore();
    getline(cin, nuevoArticulo.titulo);
    cout << "Ingrese la fecha de publicación (DD/MM/AAAA): ";
    getline(cin, nuevoArticulo.fecha);
    cout << "Ingrese el directorio del archivo (ejemplo.pdf): ";
    getline(cin, nuevoArticulo.directorio);
    articulos.push_back(nuevoArticulo);
    cout << "Artículo agregado exitosamente.\n";
}

void actualizarArticulo(vector<Articulo>& articulos) {
    int index;
    cout << "Ingrese el índice del artículo a actualizar (0 a " << articulos.size() - 1 << "): ";
    cin >> index;
    if (index >= 0 && index < articulos.size()) {
        cout << "Ingrese el nuevo título del artículo: ";
        cin.ignore();
        getline(cin, articulos[index].titulo);
        cout << "Ingrese la nueva fecha de publicación: ";
        getline(cin, articulos[index].fecha);
        cout << "Ingrese el nuevo directorio del archivo: ";
        getline(cin, articulos[index].directorio);
        cout << "Artículo actualizado exitosamente.\n";
    } else {
        cout << "Índice inválido.\n";
    }
}

void eliminarArticulo(vector<Articulo>& articulos) {
    int index;
    cout << "Ingrese el índice del artículo a eliminar (0 a " << articulos.size() - 1 << "): ";
    cin >> index;
    if (index >= 0 && index < articulos.size()) {
        articulos.erase(articulos.begin() + index);
        cout << "Artículo eliminado exitosamente.\n";
    } else {
        cout << "Índice inválido.\n";
    }
}

void mostrarArticulos(const vector<Articulo>& articulos) {
    if (articulos.empty()) {
        cout << "No hay artículos almacenados.\n";
        return;
    }
    cout << "Lista de artículos:\n";
    for (size_t i = 0; i < articulos.size(); ++i) {
        cout << i << ": " << articulos[i].titulo << " | Fecha: " << articulos[i].fecha << " | Archivo: " << articulos[i].directorio << endl;
    }
}

int main() {
    vector<Articulo> articulos;
    int opcion;

    do {
        cout << "\nMenú de Gestión de Artículos\n";
        cout << "1. Agregar Artículo\n";
        cout << "2. Actualizar Artículo\n";
        cout << "3. Eliminar Artículo\n";
        cout << "4. Mostrar Artículos\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
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
                cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}
