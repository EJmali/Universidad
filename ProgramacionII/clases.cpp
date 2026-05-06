/******************************************************************************

Programacion II
titulo: clases, herencia y polimorfismo.
profesor: Matias Sarabia
desarrollo: Erick Liendo

*******************************************************************************/
#include <iostream>

using namespace std;

//Clase base
class Animal {
public:
    //El destructor virtual es vital para evitar fugas de memoria
    virtual ~Animal(){}
    //funcion virtual: define una interfaz que las hijas deben implementar
    virtual void hacerSonido() const {
        cout << "El Animal hace un sonido generico." << endl;
    }
};
//Clase Derivada 1
class Perro: public Animal {
    public:
        void hacerSonido() const override {//override asegura que estamos sobreescribiendo
            cout << "El perro dice Guau Guau!" << endl;
        }
};
//clase Derivada 2
class Gato: public Animal {
    public:
        void hacerSonido() const override {//override asegura que estamos sobreescribiendo
            cout << "El gato dice Miau!" << endl;
        }
};

int main() {
    // Creamos una lista de punteros de la clase base Animal
    // Pero los llamamos con objetos de clase derivada
    Animal* miMascota1 = new Perro();
    Animal* miMascota2 = new Gato();
    // Polimorfismo en accion.
    // Aunque ambos son punteros tipo Animal*, cada uno ejecuta su propio sonido.
    miMascota1->hacerSonido(); // imprime Guau
    miMascota2->hacerSonido(); // imprime Miau
    return 0;
}
