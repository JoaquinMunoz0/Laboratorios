#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// ESTRUCTURA NODO ARBOL BINARIO
struct NodoArbolBinario
{
    int dato;
    NodoArbolBinario* izquierda;
    NodoArbolBinario* derecha;
    NodoArbolBinario(int val) : dato(val), izquierda(nullptr), derecha(nullptr) {}
};

// ESTRUCTURA NODO ARBOL GENERAL
struct NodoArbolGeneral
{
    int dato;
    vector<NodoArbolGeneral*> hijos;
    NodoArbolGeneral(int val) : dato(val) {}
};

// INSERTAR NODO ARBOL BINARIO
NodoArbolBinario* insertar(NodoArbolBinario* raiz, int dato)
{
    if (raiz == nullptr)
    {
        return new NodoArbolBinario(dato);
    }
    if (dato <= raiz->dato)
    {
        raiz->izquierda = insertar(raiz->izquierda, dato);
    }
    else
    {
        raiz->derecha = insertar(raiz->derecha, dato);
    }
    return raiz;
}

// IMPRIMIR NODOS ARBOL BINARIO
void recorridoEnOrden(NodoArbolBinario* raiz)
{
    if (raiz == nullptr)
    {
        return;
    }
    recorridoEnOrden(raiz->izquierda);
    cout << raiz->dato << " ";
    recorridoEnOrden(raiz->derecha);
}

// BUSCAR VALOR EN ARBOL BINARIO
bool buscar(NodoArbolBinario* raiz, int objetivo)
{
    if (raiz == nullptr)
    {
        return false;
    }
    if (raiz->dato == objetivo)
    {
        return true;
    }
    if (objetivo < raiz->dato)
    {
        return buscar(raiz->izquierda, objetivo);
    }
    else
    {
        return buscar(raiz->derecha, objetivo);
    }
}

// ENCONTRAR VALOR MINIMO ARBOL BINARIO
int encontrarMinimo(NodoArbolBinario* raiz)
{
    if (raiz == nullptr)
    {
        cout << "El arbol esta vacio." << endl;
        return -1;
    }
    if (raiz->izquierda == nullptr)
    {
        return raiz->dato;
    }
    return encontrarMinimo(raiz->izquierda);
}

// ENCONTRAR VALOR MAXIMO ARBOL BINARIO
int encontrarMaximo(NodoArbolBinario* raiz)
{
    if (raiz == nullptr)
    {
        cout << "El arbol esta vacio." << endl;
        return -1;
    }
    if (raiz->derecha == nullptr)
    {
        return raiz->dato;
    }
    return encontrarMaximo(raiz->derecha);
}

// ELIMINAR NODO ARBOL BINARIO
NodoArbolBinario* eliminarNodo(NodoArbolBinario* raiz, int objetivo)
{
    if (raiz == nullptr)
    {
        return raiz;
    }
    if (objetivo < raiz->dato)
    {
        raiz->izquierda = eliminarNodo(raiz->izquierda, objetivo);
    }
    else if (objetivo > raiz->dato)
    {
        raiz->derecha = eliminarNodo(raiz->derecha, objetivo);
    }
    else
    {
        if (raiz->izquierda == nullptr)
        {
            NodoArbolBinario* temp = raiz->derecha;
            delete raiz;
            return temp;
        }
        else if (raiz->derecha == nullptr)
        {
            NodoArbolBinario* temp = raiz->izquierda;
            delete raiz;
            return temp;
        }
        NodoArbolBinario* temp = new NodoArbolBinario(encontrarMinimo(raiz->derecha));
        raiz->dato = temp->dato;
        raiz->derecha = eliminarNodo(raiz->derecha, temp->dato);
    }
    return raiz;
}

// INSERTAR NODO ARBOL GENERAL
NodoArbolGeneral* insertar(NodoArbolGeneral* raiz, int datoPadre, int dato)
{
    if (raiz == nullptr)
    {
        return nullptr;
    }
    if (raiz->dato == datoPadre)
    {
        NodoArbolGeneral* nuevoNodo = new NodoArbolGeneral(dato);
        raiz->hijos.push_back(nuevoNodo);
        return nuevoNodo;
    }
    NodoArbolGeneral* nuevoNodo = nullptr;
    for (auto hijo : raiz->hijos)
    {
        nuevoNodo = insertar(hijo, datoPadre, dato);
        if (nuevoNodo != nullptr)
        {
            return nuevoNodo;
        }
    }
    return nullptr;
}

// IMPRIMIR NODOS ARBOL GENERAL
void imprimirArbolGeneral(NodoArbolGeneral* raiz)
{
    if (raiz == nullptr)
    {
        return;
    }
    cout << raiz->dato << " -> ";
    for (auto hijo : raiz->hijos)
    {
        cout << hijo->dato << " ";
    }
    cout << endl;
    for (auto hijo : raiz->hijos)
    {
        imprimirArbolGeneral(hijo);
    }
}

int main()
{
    NodoArbolBinario* raizArbolBinario = nullptr;
    NodoArbolGeneral* raizArbolGeneral = nullptr;
    int opcion, dato, datoPadre;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Insertar en Arbol Binario" << endl;
        cout << "2. Imprimir Arbol Binario en Orden" << endl;
        cout << "3. Buscar Valor en Arbol Binario" << endl;
        cout << "4. Encontrar Valor Minimo en Arbol Binario" << endl;
        cout << "5. Encontrar Valor Maximo en Arbol Binario" << endl;
        cout << "6. Eliminar un Nodo del Arbol Binario" << endl;
        cout << "7. Insertar en Arbol General" << endl;
        cout << "8. Imprimir Arbol General" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Ingrese el valor a insertar en el Arbol Binario: ";
            cin >> dato;
            raizArbolBinario = insertar(raizArbolBinario, dato);
            break;
        case 2:
            cout << "Arbol Binario en orden: ";
            recorridoEnOrden(raizArbolBinario);
            cout << endl;
            break;
        case 3:
            cout << "Ingrese el valor a buscar en el Arbol Binario: ";
            cin >> dato;
            if (buscar(raizArbolBinario, dato))
            {
                cout << "El valor " << dato << " se encuentra en el Arbol Binario." << endl;
            }
            else
            {
                cout << "El valor " << dato << " no se encuentra en el Arbol Binario." << endl;
            }
            break;
        case 4:
            cout << "El valor minimo en el Arbol Binario es: " << encontrarMinimo(raizArbolBinario) << endl;
            break;
        case 5:
            cout << "El valor maximo en el Arbol Binario es: " << encontrarMaximo(raizArbolBinario) << endl;
            break;
        case 6:
            cout << "Ingrese el valor a eliminar en el Arbol Binario: ";
            cin >> dato;
            raizArbolBinario = eliminarNodo(raizArbolBinario, dato);
            break;
        case 7:
            cout << "Ingrese el valor del nodo padre: ";
            cin >> datoPadre;
            cout << "Ingrese el valor a insertar en el Arbol General: ";
            cin >> dato;
            if (raizArbolGeneral == nullptr)
            {
                raizArbolGeneral = new NodoArbolGeneral(datoPadre);
            }
            insertar(raizArbolGeneral, datoPadre, dato);
            break;
        case 8:
            cout << "Arbol General:" << endl;
            imprimirArbolGeneral(raizArbolGeneral);
            break;
        case 0:
            cout << "Cerrando el programa..." << endl;
            break;
        default:
            cout << "Opcion no valida. Por favor, intente de nuevo." << endl;
        }
    } while (opcion != 0);

    return 0;
}
