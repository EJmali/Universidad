/******************************************************************************
 * Compiler https://www.onlinegdb.com/#
Profesor: Matias Sarabia
Cursante: Erick Liendo

Tarea: Agregar datos a la direccion de memoria mediante el uso de punteros
*******************************************************************************/

#include <iostream>
#include <stdio.h>

using namespace std;
int main() {
    string nombre = "Erick";
    int edad = 23;
    string *pnombre = &nombre;
    int *pedad = &edad;
    
    cout << "La direccion es: " << pnombre << "\n el dato es: " << *pnombre << endl;
    cout << "La direccion es: " << pedad << "\n el dato es: " << *pedad << endl;

    return 0;
}
