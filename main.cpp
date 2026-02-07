#include <iostream>
using namespace std;
struct Estudiante {
 int carnet;
 char nombre[50];
 float nota;
 Estudiante* izquierdo;
 Estudiante* derecho;
};
Estudiante* crearEstudiante(int carnet, char nom[], float nota) {
    Estudiante* nuevo = new Estudiante();
    nuevo->carnet = carnet;
    nuevo->nota = nota;
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;

    int i = 0;
    while(nom[i] != '\0' && i < 49) {
        nuevo->nombre[i] = nom[i];
        i++;
    }
    nuevo->nombre[i] = '\0';

    return nuevo;
}


// TODO: Implementar estas funciones
// 1. Insertar un estudiante en el árbol (ordenado por carnet)
Estudiante* insertar(Estudiante* raiz, int carnet, char nombre[], float nota) {
    if (raiz == NULL) {
        return crearEstudiante(carnet, nombre, nota);
    }

    if (carnet < raiz->carnet) {
        raiz->izquierdo = insertar(raiz->izquierdo, carnet, nombre, nota);
    }

    else if (carnet > raiz->carnet) {
        raiz->derecho = insertar(raiz->derecho, carnet, nombre, nota);
    }
    return raiz;
}
void mostrarEstudiantes(Estudiante* raiz) {
    if (raiz != NULL) {
        mostrarEstudiantes(raiz->izquierdo);

        cout << "Carnet: " << raiz->carnet
             << " Nombre: " << raiz->nombre
             << " Nota: " << raiz->nota << endl;

        mostrarEstudiantes(raiz->derecho);
    }
}
void buscarEstudiante(Estudiante* raiz, int carnet) {
    if (raiz == NULL) {
        cout << "Estudiante no encontrado." << endl;
        return;
    }

    if (carnet == raiz->carnet) {
        cout << "Estudiante encontrado:" << endl;
        cout << "Carnet: " << raiz->carnet
             << " Nombre: " << raiz->nombre
             << " Nota: " << raiz->nota << endl;
    }
    else if (carnet < raiz->carnet) {
        buscarEstudiante(raiz->izquierdo, carnet);
    }
    else {
        buscarEstudiante(raiz->derecho, carnet);
    }
}
void mostrarAprobados(Estudiante* raiz) {
    if (raiz != NULL) {

        mostrarAprobados(raiz->izquierdo);

        if (raiz->nota >= 6.0) {
            cout << "Carnet: " << raiz->carnet
                 << " Nombre: " << raiz->nombre
                 << " Nota: " << raiz->nota << endl;
        }

        mostrarAprobados(raiz->derecho);
    }
}
// 5. Mostrar estudiantes reprobados (nota < 6.0)
void mostrarReprobados(Estudiante* raiz) {
 // Tu código aquí
}
// 6. Calcular el promedio de todas las notasArboles binarios 5
float calcularPromedio(Estudiante* raiz, int* contador) {
 // Tu código aquí
 // Usa el contador para saber cuántos estudiantes hay
}
// 7. Encontrar al estudiante con la nota más alta
Estudiante* encontrarMejorNota(Estudiante* raiz) {
 // Tu código aquí
}
int main() {
 Estudiante* sistema = NULL;
 int opcion;

 do {
 cout << "\n===== SISTEMA DE GESTION DE ESTUDIANTES=====\n";
 cout << "1. Agregar estudiante\n";
 cout << "2. Mostrar todos los estudiantes\n";
 cout << "3. Buscar estudiante por carnet\n";
 cout << "4. Mostrar estudiantes aprobados\n";
 cout << "5. Mostrar estudiantes reprobados\n";
 cout << "6. Calcular promedio general\n";
 cout << "7. Mostrar estudiante con mejor nota\n";
 cout << "8. Salir\n";
 cout << "Opcion: ";
 cin >> opcion;

 // Implementa el switch con las opciones

 } while(opcion != 8);

 return 0;
}