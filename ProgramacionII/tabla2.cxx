#include <iostream>
#include <string>

using namespace std;

//clase que representa el nodo de la lista almacenada (encapsula los datos)
class persona {
private:
    string nombre;
    string apellido;
    persona* siguiente;

public:
    //constructor
    persona (string nom, string ape) {
        nombre = nom; 
        apellido = ape;
        siguiente = nullptr;
    }

    //metodo get set (encapsulamiento)
    string getnombre() {return nombre ;}
    string getapellido() {return apellido;}

    persona* getsiguiente() {return siguiente;}
    void getsiguiente(persona * sig) {siguiente = sig;}

};

//clase que abministran la tabla hash
class tablahash{
private:
    static const int tamano = 5;
    persona* vectorhash[tamano]; //vector de punteros a objetos persona

    //metodo privado: solo la tabla calcula su propio hash
    int funcionhash(string nombre, string apellido) {
        int suma = 0;
        for (char c : nombre) suma += int(c);
        for (char c : apellido) suma += int(c);
        return suma % tamano;
    }
public:
    //constructor: inicia el vector en nulo
    tablahash() {
        for (int i = 0; i < tamano; i++) {
            vectorhash[i] = nullptr;
        }
    }

    //destructor: se ejecuta automaticamente al detruir el objeto para liberar memoria
    ~tablahash() {
        for (int i = 0; i < tamano; i++){
            persona* actual = vectorhash[i];
            while (actual != nullptr) {
                persona* temporal = actual;
                actual = actual->getsiguiente();
                delete temporal;
            }
            vectorhash[i] = nullptr;
        }
        cout << "\n[sistema] memoria dinamica de la tabla liberada correctamente.\n";
    }
    //metodo para insertar una persona
    void insertar(string nombre, string apellido) {
        int indice = funcionhash(nombre, apellido);
        persona* nuevapersona = new persona(nombre, apellido);

        //si la posicion esta vacia
        if (vectorhash[indice] == nullptr) {
            vectorhash[indice] == nuevapersona;
            cout << "\n[ok] guardado en posicon [" << indice <<"] (sin colision)";
        } 
        // si hay colicion: insercion al inicio de la lista enalazada
        else {
            nuevapersona->getsiguiente(vectorhash[indice]);
            vectorhash[indice] = nuevapersona;
            cout << "\n[!] colicion en posicion ["<< indice <<"]. agregado en la lista. \n";
        }
    }

    //metodo para mostrar la tabla completa
    void mostrar() {
        cout << "\n. --- contenido de la tabla hash (POO) ---\n.";
        for (int i = 0; i < tamano; i++) {
            cout << "posicion {" << i << "}: ";
            
            if (vectorhash[i] == nullptr) {
                cout << "(vacia)" << endl;
            } else {
                persona* actual = vectorhash[i];
                while (actual != nullptr) {
                    cout << "[" << actual->getnombre() << " " << actual->getapellido() << "]";
                    actual = actual->getsiguiente();
                    if (actual != nullptr) {
                        cout << "->";
                    }
                }
                cout << endl;
            }
        }
        cout << "--------------------------------------------\n";
    }
};

// Funcion Principal (Interactua con los objetos)
int main() {
    // Instanciacion del objeto de la tabla hash
    tablahash miTabla;

    int opcion;
    string nom, ape;

    do {
        cout << "\n== MENU TABLA HASH POO ==" << endl;
        cout << "1. Insertar persona" << endl;
        cout << "2. Ver contenido de la tabla" << endl;
        cout << "3. Salir" << endl;
        cout << "Selecionar una opcion: ";
        cin >> opcion;
        cin.ignore(); //Limpiar buffer

        switch (opcion) {
        case 1:
            cout << "\nIngrese Nombre: ";
            getline(cin, nom);
            cout << "Ingrese Apellido: ";
            getline(cin, ape);
            miTabla.insertar(nom, ape); // Llamadas al metodo del objeto
            break;
        case 2:
            miTabla.mostrar(); // LLamada al metodo del objeto
            break;
        case 3:
            cout << "\nSaliendo  del programa..." << endl;
            break;
        default:
            cout << "\nOpcion no valida." << endl;
        }
    }while (opcion != 3);
    //Al salir del main el destructor se activa solo
    return 0;
}
