#include <iostream>
#include <vector>

using namespace std;

//Estructura del grafo
struct Grafo
{
    int numVertices;
    vector<vector<int>> matrizAdyacencia;
    Grafo(int n) : numVertices(n), matrizAdyacencia(n, vector<int>(n, 0)) {}
};

// Agregar arista al grafo
void agregarArista(Grafo& grafo, int origen, int destino)
{
    grafo.matrizAdyacencia[origen - 1][destino - 1] = 1;
    grafo.matrizAdyacencia[destino - 1][origen - 1] = 1;
}

// Imrpimir matriz adyacente
void imprimirMatriz(const Grafo& grafo)
{
    cout << "Matriz de adyacencia:" << endl;
    for(int i = 0; i < grafo.numVertices; ++i)
	{
        for(int j = 0; j < grafo.numVertices; ++j)
		{
            cout << grafo.matrizAdyacencia[i][j] << " ";
        }
        cout << endl;
    }
}

// Funcion para verificar si dos vertices son adyacentes
bool sonAdyacentes(const Grafo& grafo, int vertice1, int vertice2)
{
    return grafo.matrizAdyacencia[vertice1 - 1][vertice2 - 1] == 1;
}

// Funcion para verificar si hay un camino entre dos vertices
void encontrarCamino(const Grafo& grafo, int inicio, int fin, vector<int>& caminoActual, vector<bool>& visitado)
{
    if(inicio == fin)
	{
        cout << "Camino encontrado: ";
        for (int i : caminoActual)
		{
            cout << i << " ";
        }
        cout << fin << endl;
        return;
    }

    visitado[inicio - 1] = true;
    caminoActual.push_back(inicio);

    for(int i = 0; i < grafo.numVertices; ++i)
	{
        if(grafo.matrizAdyacencia[inicio - 1][i] == 1 && !visitado[i])
		{
            encontrarCamino(grafo, i + 1, fin, caminoActual, visitado);
        }
    }

    visitado[inicio - 1] = false;
    caminoActual.pop_back();
}

int main()
{
    // Crear el grafo
    Grafo grafo(8);

    //Si agregue las aristas una por una, horrible
    agregarArista(grafo, 1, 3);
    agregarArista(grafo, 1, 5);
    agregarArista(grafo, 2, 3);
    agregarArista(grafo, 2, 4);
    agregarArista(grafo, 2, 5);
    agregarArista(grafo, 2, 6);
    agregarArista(grafo, 2, 7);
    agregarArista(grafo, 3, 6);
    agregarArista(grafo, 3, 2);
    agregarArista(grafo, 3, 7);
    agregarArista(grafo, 4, 2);
    agregarArista(grafo, 4, 7);
    agregarArista(grafo, 4, 8);
    agregarArista(grafo, 4, 1);
    agregarArista(grafo, 5, 1);
    agregarArista(grafo, 5, 8);
    agregarArista(grafo, 5, 2);
    agregarArista(grafo, 5, 6);
    agregarArista(grafo, 6, 5);
    agregarArista(grafo, 6, 2);
    agregarArista(grafo, 6, 3);
    agregarArista(grafo, 7, 3);
    agregarArista(grafo, 7, 2);
    agregarArista(grafo, 7, 4);
    agregarArista(grafo, 7, 8);
    agregarArista(grafo, 8, 4);
    agregarArista(grafo, 8, 5);
    agregarArista(grafo, 8, 7);

    // Imprimir la matriz de adyacencia
    imprimirMatriz(grafo);

    // Verificar si dos vertices son adyacentes
    int vertice1, vertice2;
    cout << "Ingrese dos vertices para verificar si son adyacentes (separados por espacio): ";
    cin >> vertice1 >> vertice2;
    if(sonAdyacentes(grafo, vertice1, vertice2))
	{
        cout << "Los vertices " << vertice1 << " y " << vertice2 << " son adyacentes." << endl;
    }
	else
	{
        cout << "Los vertices " << vertice1 << " y " << vertice2 << " no son adyacentes." << endl;
    }

    // Encontrar un camino entre dos vértices
    int inicioCamino, finCamino;
    cout << "Ingrese dos vertices para encontrar un camino (separados por espacio): ";
    cin >> inicioCamino >> finCamino;

    vector<int> caminoActual;
    vector<bool> visitado(8, false);

    encontrarCamino(grafo, inicioCamino, finCamino, caminoActual, visitado);

    return 0;
}
