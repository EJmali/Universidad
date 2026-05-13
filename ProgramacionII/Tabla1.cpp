#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Case Alumno con los atributos solicitados
class Alumno 
{
public:
    string nombre_apellido;
    string fecha_nacimiento;
    string lugar_nacimiento;
    string carrera;
    
    // Constructor vació para inicializar el arreglo de la tabla
    Alumno() : nombre_apellido(""), fecha_nacimiento(""), lugar_nacimiento(""), carrera("") {}
    
    Alumno(string n, string f, string l, string c)
        : nombre_apellido(n), fecha_nacimiento(f), lugar_nacimiento(l), carrera(c) {}

        void mostrarDatos()
        {
            cout << "\n --- Datos del Alumno ---" << endl;
            cout << "Nombre: " << nombre_apellido << endl;
            cout << "Fecha de Nacimiento: " << fecha_nacimiento << endl;
            cout << "Lugar de Nacimiento: " << lugar_nacimiento << endl;
            cout << "Carrera: " << carrera << endl;
        }
};

// Funcion Hash simple: Suma los valores ASCII de los caracteres del nombre
int generarHash(string llave, int capacidad)
{
    int hash = 0;
    for (char c: llave)
    {
        hash += c;
    }
    return hash % capacidad; // Retorna el indice dentro del rango del arreglo
}

int main()
{
    const int TAMANO_TABLA = 10;
    Alumno tablaHash[TAMANO_TABLA];
    int opcion;

    do 
    {
        cout << "\n1. Registrar Alumno\n2. Buscar Alumno por Hash\n3. Salir\nSeleccione: ";
        cin >> opcion;
        cin.ignore(); // limpiar el buffer de teclado

        if (opcion == 1)
        {
            string n, f, l, c;
            cout <<  "Nombre y Apellido: ";
            getline(cin, n);
            cout <<  "Fecha de Nacimiento: ";
            getline(cin, f);
            cout <<  "Lugar de Nacimiento: ";
            getline(cin, l);
            cout <<  "Carrera: ";
            getline(cin, c);

            Alumno nuevo(n, f, l, c);
            int indice =generarHash(n, TAMANO_TABLA);

            // Almacenamiento en la posicion generada
            tablaHash[indice] = nuevo;
            cout << ">> Registrado en el incidice Hash: " << indice << endl;
        }
        else if(opcion == 2)
        {
            string nombreBusqueda;
            cout << "Ingrese el Nombre exacto para generar el hash de busqueda: ";
            getline(cin, nombreBusqueda);

            int indiceBusqueda = generarHash(nombreBusqueda, TAMANO_TABLA);

            if (tablaHash[indiceBusqueda].nombre_apellido == nombreBusqueda)
            {
                cout << "Resultado encontrado en el indice: " << indiceBusqueda;
                tablaHash[indiceBusqueda].mostrarDatos();
            }
            else
            {
                cout << "No se encontró registro con ese nombre en el indice: " << indiceBusqueda;
            }
        }

    } while (opcion != 3);
    return 0;
}
