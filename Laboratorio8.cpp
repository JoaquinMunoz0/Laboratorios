#include<iostream>
#include<vector>

class Rectangulo
{
	private:
	double longitud;
	double ancho;
	    
	public:	
    Rectangulo(double l, double w) : longitud(l), ancho(w)
	{
		
	}

    double calcularArea()
	{
        return longitud * ancho;
    }
};

class Punto
{
	private:	
	double x;
	double y;
	    
	public:
	Punto(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}
	
	double obtenerX()
	{
	    return x;
	}

    double obtenerY()
	{
        return y;
    }
};

class Nodo
{	
	public:
    int dato;
    Nodo* siguiente;
    Nodo(int valor) : dato(valor), siguiente(nullptr)
	{
		
	}
    
};

class ListaEnlazada
{
	private:
    Nodo* cabeza;
	public:
    ListaEnlazada() : cabeza(nullptr) {}

    void insertar(int valor)
	{
        Nodo* nuevoNodo = new Nodo(valor);
        if(cabeza == nullptr)
		{
            cabeza = nuevoNodo;
        }
		else
		{
            Nodo* temp = cabeza;
            while(temp->siguiente != nullptr)
			{
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoNodo;
        }
    }

    bool buscar(int valor)
	{
        Nodo* temp = cabeza;
        while(temp != nullptr)
		{
            if(temp->dato == valor)
			{
                return true;
            }
            temp = temp->siguiente;
        }
        return false;
    }

    void eliminar(int valor)
	{
        if(cabeza == nullptr)
		{
            return;
        }

        if(cabeza->dato == valor)
		{
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            return;
        }

        Nodo* temp = cabeza;
        while(temp->siguiente != nullptr && temp->siguiente->dato != valor)
		{
            temp = temp->siguiente;
        }

        if(temp->siguiente == nullptr)
		{
            return;
        }

        Nodo* aEliminar = temp->siguiente;
        temp->siguiente = temp->siguiente->siguiente;
        delete aEliminar;
    }

    void imprimir()
	{
        Nodo* temp = cabeza;
        while (temp != nullptr)
		{
            std::cout << temp->dato << " ";
            temp = temp->siguiente;
        }
        std::cout << std::endl;
    }
};

class NodoArbol
{
	public:
    int dato;
    NodoArbol* izquierda;
    NodoArbol* derecha;
    NodoArbol(int valor) : dato(valor), izquierda(nullptr), derecha(nullptr)
	{
		
	}
};

class ArbolBinario
{
	private:
    NodoArbol* raiz;
    
	public:
    ArbolBinario() : raiz(nullptr)
	{
		
	}

    void insertar(int valor)
	{
        raiz = insertarRecursivo(raiz, valor);
    }

    NodoArbol* insertarRecursivo(NodoArbol* nodo, int valor)
	{
        if(nodo == nullptr)
		{
            return new NodoArbol(valor);
        }

        if(valor < nodo->dato)
		{
            nodo->izquierda = insertarRecursivo(nodo->izquierda, valor);
        }
		else if(valor > nodo->dato)
		{
            nodo->derecha = insertarRecursivo(nodo->derecha, valor);
        }

        return nodo;
    }

    bool buscar(int valor)
	{
        return buscarRecursivo(raiz, valor);
    }

    bool buscarRecursivo(NodoArbol* nodo, int valor)
	{
        if(nodo == nullptr)
		{
            return false;
        }

        if(nodo->dato == valor)
		{
            return true;
        }
		else if(valor < nodo->dato)
		{
            return buscarRecursivo(nodo->izquierda, valor);
        }
		else
		{
            return buscarRecursivo(nodo->derecha, valor);
        }
    }

    void recorridoEnOrden(NodoArbol* nodo)
	{
        if(nodo == nullptr)
		{
            return;
        }

        recorridoEnOrden(nodo->izquierda);
        std::cout << nodo->dato << " ";
        recorridoEnOrden(nodo->derecha);
    }

    void imprimir()
	{
        recorridoEnOrden(raiz);
        std::cout << std::endl;
    }
};

class NodoArbolGeneral
{
	public:
    int dato;
    std::vector<NodoArbolGeneral*> hijos;
    NodoArbolGeneral(int valor) : dato(valor)
	{
		
	}
};

class ArbolGeneral
{
	private:
    NodoArbolGeneral* raiz;
    
	public:
    ArbolGeneral() : raiz(nullptr)
	{
		
	}

    void insertar(int valorPadre, int valor)
	{
        if(raiz == nullptr)
		{
            raiz = new NodoArbolGeneral(valorPadre);
            raiz->hijos.push_back(new NodoArbolGeneral(valor));
            return;
        }

        insertarRecursivo(raiz, valorPadre, valor);
    }

    void insertarRecursivo(NodoArbolGeneral* nodo, int valorPadre, int valor)
	{
        if(nodo == nullptr)
		{
            return;
        }

        if(nodo->dato == valorPadre)
		{
            nodo->hijos.push_back(new NodoArbolGeneral(valor));
            return;
        }

        for(NodoArbolGeneral* hijo : nodo->hijos)
		{
            insertarRecursivo(hijo, valorPadre, valor);
        }
    }

    bool buscar(int valor)
	{
        return buscarRecursivo(raiz, valor);
    }

    bool buscarRecursivo(NodoArbolGeneral* nodo, int valor)
	{
        if(nodo == nullptr)
		{
            return false;
        }

        if(nodo->dato == valor)
		{
            return true;
        }

        for(NodoArbolGeneral* hijo : nodo->hijos)
		{
            if(buscarRecursivo(hijo, valor))
			{
                return true;
            }
        }

        return false;
    }

    void recorridoPreOrden(NodoArbolGeneral* nodo)
	{
        if(nodo == nullptr)
		{
            return;
        }

        std::cout << nodo->dato << " ";
        for(NodoArbolGeneral* hijo : nodo->hijos)
		{
            recorridoPreOrden(hijo);
        }
    }

    void imprimir()
	{
        recorridoPreOrden(raiz);
        std::cout << std::endl;
    }
};

int main()
{

    //EJERCICIO 1
    Rectangulo rect(5.0, 3.0);
    std::cout << "Area del rectangulo: " << rect.calcularArea() << std::endl;

    //EJERCICIO 2
    Punto punto(2.5, 3.5);
    std::cout << "Coordenadas del punto: (" << punto.obtenerX() << ", " << punto.obtenerY() << ")" << std::endl;

    //EJERCICIO 3
    ListaEnlazada lista;
    lista.insertar(1);
    lista.insertar(2);
    lista.insertar(3);
    lista.insertar(4);
    lista.insertar(5);
    std::cout << "Elementos de la lista: ";
    lista.imprimir();

    //EJERCICIO 4
    ArbolBinario arbol;
    arbol.insertar(5);
    arbol.insertar(3);
    arbol.insertar(7);
    std::cout << "Recorrido En-orden del arbol binario: ";
    arbol.imprimir();

    //EJERCICIO 5
    ArbolGeneral arbolGeneral;
    arbolGeneral.insertar(1, 2);
    arbolGeneral.insertar(1, 3);
    arbolGeneral.insertar(2, 4);
    arbolGeneral.insertar(2, 5);
    std::cout << "Recorrido Pre-orden del arbol general: ";
    arbolGeneral.imprimir();

    return 0;
}
