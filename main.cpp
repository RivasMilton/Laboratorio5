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


//=============== CODIGO FER =========================


// 5. Mostrar estudiantes reprobados (nota < 6.0)
void mostrarReprobados(Estudiante *raiz)
{
    if (raiz != NULL)
    {
        mostrarReprobados(raiz->izquierdo);

        if (raiz->nota < 6.0)
        {
            cout << "Carnet: " << raiz->carnet << " Nombre: " << raiz->nombre << " Nota: " << raiz->nota << "\n";
        }

        mostrarReprobados(raiz->derecho);
    }
}

// 6. Calcular el promedio de todas las notasArboles binarios 5
float calcularPromedio(Estudiante *raiz, int *contador)
{
    if (raiz == NULL)
    {
        return 0;
    }

    float suma = raiz->nota;
    (*contador) ++;

    suma += calcularPromedio(raiz->izquierdo, contador);
    suma += calcularPromedio(raiz->derecho, contador);

    return suma;

    // Usa el contador para saber cuántos estudiantes hay
}

// 7. Encontrar al estudiante con la nota más alta
Estudiante *encontrarMejorNota(Estudiante *raiz)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    Estudiante* mejor = raiz;
    Estudiante* izq = encontrarMejorNota(raiz->izquierdo);
    Estudiante* der = encontrarMejorNota(raiz->derecho);

    if (izq != NULL && izq->nota > mejor->nota)
    {
        mejor = izq;
    }
    if (der != NULL && der->nota > mejor->nota)
    {
        mejor = der;
    }

    return mejor;
}

//MENU COMO EL QUE HIZO ELIAS EN UNA DISCUSION ===========================================
void menuMostrar(Estudiante* ecampus) {
    int opcion;

    if (ecampus == NULL) {
        cout << "El arbol esta vacio, agrega estudiantes primero bro\n";
        return;
    }

    do {
        cout << "\n====== MENU MOSTRAR =====\n";
        cout << "1. Mostrar todos\n";
        cout << "2. Mostrar aprobados\n";
        cout << "3. Mostrar reprobados\n";
        cout << "4. Mostrar mejor nota\n";
        cout << "5. Mostrar promedio\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\n||===== MENU MOSTRAR ESTUDIANTES =====||\n";
                mostrarEstudiantes(ecampus);
                cout << "||====================================||\n";
                break;

            case 2:
                cout << "\n||===== MENU MOSTRAR APROBADOS =====||\n";
                mostrarAprobados(ecampus);
                cout << "||====================================||\n";
                break;

            case 3:
                cout << "\n||===== MENU MOSTRAR REPROBADOS =====||\n";
                mostrarReprobados(ecampus);
                cout << "||====================================||\n";
                break;

            case 4: {
                Estudiante* mejor = encontrarMejorNota(ecampus);
                cout << "\n||===== MENU MOSTRAR MEJOR ESTUDIANTE =====||\n";
                cout << "Mejor estudiante:\n";
                cout << "Carnet: " << mejor->carnet << " | Nombre: " << mejor->nombre << " | Nota: " << mejor->nota << "\n";
                cout << "||====================================||\n";
                break;
            }

            case 5: {
                cout << "\n||===== MENU MOSTRAR PROMEDIOS DE ESTUDIANTES =====||\n";
                int contador = 0;
                float suma = calcularPromedio(ecampus, &contador);
                cout << "Promedio general: " << suma / contador << "\n";
                cout << "||====================================||\n";
                break;
            }
        }

    } while (opcion != 0);
}

// ================= MENU PRINCIPAL =================
void menu() {
    Estudiante* ecampus = NULL;
    int opcion;

    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Agregar estudiante\n";
        cout << "2. Buscar estudiante\n";
        cout << "3. Mostrar\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "\n||===== MENU INSERTAR ESTUDIANTE =====||\n";
                int carnet;
                char nombre[50];
                float nota;

                cout << "Carnet: ";
                cin >> carnet;

                cin.ignore();
                cout << "Nombre: ";
                cin.getline(nombre, 50);

                cout << "Nota: ";
                cin >> nota;

                ecampus = insertar(ecampus, carnet, nombre, nota);
                cout << "||====================================||\n";
                break;
            }

            case 2:
                cout << "\n||===== MENU BUSCAR ESTUDIANTE =====||\n";
                if (ecampus == NULL)
                    cout << "El arbol esta vacio.\n";
                else {
                    int carnet;
                    cout << "Carnet a buscar: ";
                    cin >> carnet;
                    buscarEstudiante(ecampus, carnet);
                }
                cout << "||====================================||\n";
                break;

            case 3:
                menuMostrar(ecampus);
                break;

            case 0:
                cout << "Saliendo...\n";
                break;
        }

    } while (opcion != 0);
}

int main()
{
    menu();
    return 0;
}