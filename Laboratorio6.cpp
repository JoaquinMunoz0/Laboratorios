#include <iostream>
#include <string>
#include <cctype>
#include <list>

using namespace std;

int factorial(int n)
{
    if(n == 0)
	{
        return 1;
    }
    else
	{
        return n * factorial(n - 1);
    }
}

int fibonacci(int secuenciaFibonacci)
{
    if(secuenciaFibonacci == 0)
	{
        return 0;
    }
	else if(secuenciaFibonacci == 1)
	{
        return 1;
    }
	else
	{
        return fibonacci(secuenciaFibonacci - 1) + fibonacci(secuenciaFibonacci - 2);
    }
}


int main()
{
    list<int> numeros;
    int numero, numeroFactorial, cantidad;
    int secuenciaFibonacci;
    string palabra;
    int menu;
    
	do
	{
		cout << "Laboratorio 6\n" << endl;
		cout << "1.Ejercicio 1" << endl;
		cout << "2.Ejercicio 2" << endl;
		cout << "3.Ejercicio 3" << endl;
		cout << "4.Ejercicio 4" << endl;
		cout << "5.Cerrar el programa" << endl;
		cout << "\nIngrese la opcion deseada: ";
        cin >> menu;
		
		switch(menu)
		{
			case 1:
				//EJERCICIO 1
				{
					cout << "Ingrese el tamanio de la lista: ";
				    cin >> cantidad;
				    cin.ignore();
				
				    cout << "Ingrese los numeros uno por uno que se encuentran en la lista: " << endl;
				    for(int i = 0; i < cantidad; ++i)
					{
				        cin >> numero;
				        numeros.push_back(numero);
				        cin.ignore();
				    }
				
				    // Calculando la suma
				    int suma = 0;
				    for(int num : numeros)
					{
				        suma += num;
				    }
				
				    // Calculando el promedio
				    float promedio = static_cast<float>(suma) / cantidad;
				
				    // Calculando el producto
				    int producto = 1;
				    for(int num : numeros)
					{
				        producto *= num;
				    }
				
				    // Mostrando los resultados
				    cout << "Suma: " << suma << endl;
				    cout << "Promedio: " << promedio << endl;
				    cout << "Producto: " << producto << endl;
			    }
			    break;
			case 2:
				//EJERCICIO 2
				{
					cout << "Ingrese un numero para calcular su factorial: ";
				    cin >> numeroFactorial;
				    cin.ignore();
				
				    if(numeroFactorial < 0)
					{
				        cout << "El factorial de un numero negativo no esta definido." << endl;
				    }
				    else
					{
				        int resultado = factorial(numeroFactorial);
				        cout << "El factorial de " << numeroFactorial << " es: " << resultado << endl;
				    }
				}
				break;
			case 3:
				//EJERCICIO 3
				{
					cout << "Ingrese el numero de terminos de la secuencia de Fibonacci que desea calcular: ";
				    cin >> secuenciaFibonacci;
				    cin.ignore();
				
				    cout << "Secuencia de Fibonacci hasta el termino " << secuenciaFibonacci << ":" << endl;
				    for(int i = 0; i < secuenciaFibonacci; ++i)
					{
				        cout << fibonacci(i) << " ";
				    }
				    cout << endl;
				}
				break;
			case 4:
				//EJERCICIO 4
				{
					cout << "Ingrese la palabra: " << endl;
					cin >> palabra;
					
					size_t longitud = palabra.length()-1;
					size_t i=0;
					bool esPalindromo = true;
					
					for(i = 0; i < palabra.length()/2 && esPalindromo; i++)
					{
						if(palabra[i]!=palabra[longitud-i])
						{
							esPalindromo = false;
						}
					}
					
					cout<<((true == esPalindromo) ? "es palindromo" : "no es palindromo")<<endl;
				}
				break;
			case 5:
				{
					cout << "Cerrando el programa..." << endl;
				}
				break;
			default:
				{
					cout << "Ingrese una opcion valida." << endl;
				}
				break;
		}
		
	}while(menu!=5);
	
	cout << "Hasta pronto..." << endl;
	
    return 0;
}