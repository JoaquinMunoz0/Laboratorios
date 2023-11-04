#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Estructura del nodo
struct Nodo
{
    int valor;
    Nodo* izquierda;
    Nodo* derecha;
    Nodo(int v) : valor(v), izquierda(nullptr), derecha(nullptr) {}
};

// Crear un nodo en el arbol
Nodo* crearNodo(Nodo* raiz, int valor)
{
    if(raiz == nullptr)
	{
        return new Nodo(valor);
    }
    if(valor <= raiz->valor)
	{
        raiz->izquierda = crearNodo(raiz->izquierda, valor);
    }
	else
	{
        raiz->derecha = crearNodo(raiz->derecha, valor);
    }
    return raiz;
}

// Funciones para recorrer el arbol
void preOrder(Nodo* raiz)
{
    if (raiz == nullptr) return;
    cout << raiz->valor << " ";
    preOrder(raiz->izquierda);
    preOrder(raiz->derecha);
}

void inOrder(Nodo* raiz)
{
    if(raiz == nullptr) return;
    inOrder(raiz->izquierda);
    cout << raiz->valor << " ";
    inOrder(raiz->derecha);
}

void postOrder(Nodo* raiz)
{
    if(raiz == nullptr) return;
    postOrder(raiz->izquierda);
    postOrder(raiz->derecha);
    cout << raiz->valor << " ";
}

// Busqueda por profundidad con recursividad
bool busquedaProfundidad(Nodo* raiz, int valor)
{
    if(raiz == nullptr) return false;
    if(raiz->valor == valor) return true;
    return busquedaProfundidad(raiz->izquierda, valor) || busquedaProfundidad(raiz->derecha, valor);
}

// Busqueda por amplitud con cola
bool busquedaAmplitud(Nodo* raiz, int valor)
{
    if (raiz == nullptr) return false;
    queue<Nodo*> cola;
    cola.push(raiz);
    while (!cola.empty()) {
        Nodo* nodoActual = cola.front();
        cola.pop();
        if (nodoActual->valor == valor) return true;
        if (nodoActual->izquierda != nullptr) cola.push(nodoActual->izquierda);
        if (nodoActual->derecha != nullptr) cola.push(nodoActual->derecha);
    }
    return false;
}

int main()
{
    int valores[] = {21, 18, 6, 9, 10, 7, 19, 15, 12, 5};
    int n = sizeof(valores) / sizeof(valores[0]);

    Nodo* raiz = nullptr;
    for (int i = 0; i < n; ++i)
	{
        raiz = crearNodo(raiz, valores[i]);
    }

    cout << "Recorrido en Pre-Orden: ";
    preOrder(raiz);
    cout << endl;

    cout << "Recorrido en In-Orden: ";
    inOrder(raiz);
    cout << endl;

    cout << "Recorrido en Post-Orden: ";
    postOrder(raiz);
    cout << endl;

    int valorBusqueda = 10;
    if(busquedaProfundidad(raiz, valorBusqueda))
	{
        cout << "El valor " << valorBusqueda << " fue encontrado." << endl;
    }
	else
	{
        cout << "El valor " << valorBusqueda << " no pudo ser encontrado." << endl;
    }

    valorBusqueda = 15;
    if(busquedaAmplitud(raiz, valorBusqueda))
	{
        cout << "El valor " << valorBusqueda << " fue encontrado." << endl;
    }
	else
	{
        cout << "El valor " << valorBusqueda << " no pudo ser encontrado." << endl;
    }

    return 0;
}
