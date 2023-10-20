#include <iostream>
#include <string>
#include <time.h>
using namespace std;

enum Categoria
{
	Juvenil,
	Senior,
	Veterano
};

struct Ciclista
{
    string nombreCiclista;
    int edad;
    string club;
    Categoria categoria;
};

struct Registro {
    float nota1, nota2, nota3, promedio;
};

struct Alumno {
    string nombre;
    int edad, numMatricula;
    Registro registro;
};

int funcionSuma(int a, int b);
bool iniciarSesion(const string& usuario, const string& contrasena);
Categoria asignarCategoria(int edad);
Ciclista crearCiclista(string nombreCiclista, int edad, string club);
void ingresarDatos(Alumno &alumno);
void calcularPromedio(Alumno &alumno);
void imprimirDatos(Alumno alumno);

int main()
{
    int entero = 10;
	int enteroTeclado, num1, num2, a, b, edad;
	int intentos = 3;
    float flotante = 3.14f;
    double doble = 2.71828;
    char caracter = 'A';
    string cadena = "Buenas tardes, Profe";
    string cadenaTeclado, nombre, usuario, contrasena, nombreCiclista, club;
    Alumno alumno1, alumno2;
    bool booleano = true;
    srand(time(0));

	//Hola Mundo
    cout << "Hola mundo" << endl;
    
    //Imprimir Variables
    cout << "Entero: " << entero << endl;
    cout << "Float: " << flotante << endl;
    cout << "Caracter: " << caracter << endl;
    cout << "Cadena de caracteres: " << cadena << endl;
    cout << "Booleano: " << booleano << endl;
    
    //Ingresar Variables Enteras
    cout << "Por favor, ingrese un numero entero: ";
    cin >> enteroTeclado;
    cout << "Entero ingresado por teclado: " << enteroTeclado << endl;
    
    //Ingresar Variables String
    cout << "Por favor, ingrese un string por teclado: ";
    cin >> cadenaTeclado;
    cout << "String ingresado por teclado: " << cadenaTeclado << endl;
    
	//Ingresar nombre, saludar, suma, resta, multiplicacion y division de 2 numeros
	cout <<"Ingrese su nombre porfavor: ";
	cin >> nombre;
	
	cout <<"Ingrese el primer numero: ";
	cin >> num1;
	cout <<"Ingrese el segundo numero: ";
	cin >> num2;
	
	//Realizar Operaciones
	
	int suma = num1 + num2;
	int resta = num1 - num2;
	int multiplicacion = num1 * num2;
	double division = (num2 != 0) ? (num1 / num2) : 0;
	float promedio = (suma + resta + multiplicacion + division) / 4;
	
	cout << "Hola, " << nombre << "!" << endl;
	cout << "Suma de ambos numeros: " << suma << endl;
	cout << "Resta de ambos numeros: " << resta << endl;
	cout << "Multiplicacion de ambos numeros: " << multiplicacion << endl;
	cout << "Division de ambos numeros: " << division << endl;
	
	//Bucles
	int limiteInferior = 1, limiteSuperior = 100; // definimos Limites
	//Número aleatorio incluyendo ambos extremos
	int numAleatorio = limiteInferior + rand() % (limiteSuperior + 1 - limiteInferior);
	cout << "Numero Aleatorio: " << numAleatorio << endl;
	
	//Funciones
	cout <<"Ingrese el primer numero: ";
	cin >> a;
	cout <<"Ingrese el segundo numero: ";
	cin >> b;
	int respuesta = funcionSuma(a, b);
	cout << "respuesta de la suma en la funcion: " << respuesta << endl;
    
    do
    {
    	cout << "Por favor, ingrese su nombre de usuario: ";
	    cin >> usuario;
	    cout << "Por favor, ingrese su contrasena: ";
	    cin >> contrasena;
    
	    if(iniciarSesion(usuario, contrasena))
	    {
	    	cout << "Bienvenido " << usuario << "!" << endl;
	    	intentos = 0;
		}
		else
		{
			cout << "Inicio de sesion fallido, porfavor intentelo de nuevo." << endl;
			intentos --;
			cout << "intentos restantes: " << intentos << endl;
		}
	}while(intentos != 0);
	
	cout << "Ingrese nombre del ciclista: ";
    cin >> nombreCiclista;
    cout << "Ingrese edad del ciclista: ";
    cin >> edad;
    cout << "Ingrese club del ciclista: ";
    cin >> club;
    cin.ignore();
    
    //SE CREA LA INSTANCIA USANDO LA FUNCION
    Ciclista ciclista = crearCiclista(nombreCiclista, edad, club);
	
	cout << "\nDatos del ciclista:\n";
    cout << "Nombre: " << ciclista.nombreCiclista << endl;
    cout << "Edad: " << ciclista.edad << endl;
    cout << "Club: " << ciclista.club << endl;
    
    //SE IMPRIME LA CATEGORIA
    cout << "Categoria: ";
    switch(ciclista.categoria) {
        case Juvenil:
            cout << "Juvenil";
            break;
        case Senior:
            cout << "Senior";
            break;
        case Veterano:
            cout << "Veterano";
            break;
    }
    
    //CONTROL Y USO DE ESTRUCTURAS ANIDADAS
    cout << "\nIngrese los datos del primer alumno:" << endl;
    ingresarDatos(alumno1);
    calcularPromedio(alumno1);

    cout << "\nIngrese los datos del segundo alumno:" << endl;
    ingresarDatos(alumno2);
    calcularPromedio(alumno2);

    cout << "\nResultados:" << endl;
    imprimirDatos(alumno1);
    imprimirDatos(alumno2);
	
    return 0;
}

int funcionSuma(int a, int b)
{
	int respuesta = a + b;
	return respuesta;
}

bool iniciarSesion(const string& usuario, const string& contrasena)
{
    return (usuario == "user1" && contrasena == "1234");
}

Categoria asignarCategoria(int edad)
{
    if(edad <= 18)
	{
        return Juvenil;
    }
	else if(edad <= 40)
	{
        return Senior;
    }
	else
	{
        return Veterano;
    }
}

Ciclista crearCiclista(string nombreCiclista, int edad, string club)
{
    Ciclista ciclista;
    ciclista.nombreCiclista = nombreCiclista;
    ciclista.edad = edad;
    ciclista.club = club;
    ciclista.categoria = asignarCategoria(edad);
    return ciclista;
}

void ingresarDatos(Alumno &alumno)
{
    cout << "Ingrese el nombre del alumno: ";
    getline(cin, alumno.nombre);
    cout << "Ingrese la edad del alumno: ";
    cin >> alumno.edad;
    cout << "Ingrese el numero de matricula del alumno: ";
    cin >> alumno.numMatricula;
    cout << "Ingrese la nota 1: ";
    cin >> alumno.registro.nota1;
    cout << "Ingrese la nota 2: ";
    cin >> alumno.registro.nota2;
    cout << "Ingrese la nota 3: ";
    cin >> alumno.registro.nota3;
    cin.ignore();
}

void calcularPromedio(Alumno &alumno)
{
    alumno.registro.promedio = (alumno.registro.nota1 + alumno.registro.nota2 + alumno.registro.nota3) / 3.0;
}

void imprimirDatos(Alumno alumno)
{
    cout << "\nDatos del alumno:" << endl;
    cout << "Nombre: " << alumno.nombre << endl;
    cout << "Edad: " << alumno.edad << " anios" << endl;
    cout << "Numero de matricula: " << alumno.numMatricula << endl;
    cout << "Notas:" << endl;
    cout << "Nota 1: " << alumno.registro.nota1 << endl;
    cout << "Nota 2: " << alumno.registro.nota2 << endl;
    cout << "Nota 3: " << alumno.registro.nota3 << endl;
    cout << "Promedio: " << alumno.registro.promedio << endl;
}
