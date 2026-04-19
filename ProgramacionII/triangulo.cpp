#include <stdio.h>
#include <iostream>
#include <math.h>

/*********************************
	Profesor:  Matias Sarabia
    Desarrollo: Erick Liendo
	Tarea: Calculo del triangulo
**********************************/

/*******FUNCIONES COMPLEMENTSRIAS***********/
void println();
template<typename T, typename... Args>
void println(T arg0, Args... args);
void pausa(char *msg = "\n ENTER para continua");
/*******************************************/

float calcularPitagoras(float valor_1, float valor_2, int despejar = 1);
float calcularArea(float base, float altura);


int main(int argc, char *argv[]){
	bool activo = true; int opcion;
	float valor_1, valor_2, resultado;
	#ifdef _WIN32
		const char *CLS="cls";
	#else
		const char *CLS="clear";
	#endif

	
	println(" Triangulo");
	while (activo) {
		system(CLS);
		println("Que desea calcular");
		println("  1-> Pitagoras(Encontrar un lado)");
		println("  2-> Area(Calcular el area)");
		println("  0-> Salir(Cerra programa)");
		printf("   >> "); scanf("%i", &opcion);
		if (opcion == 0) {activo = false;}
		else if (opcion == 1) {
			system(CLS);
			println("¿Que lado desea encontrar?");
			println("  1-> Hipotenusa");
			println("  2-> Cateto abyacente");
			println("  3-> Cateto opuesto");
			printf("  >>"); scanf("%i", &opcion);
			system(CLS);
			printf("  valor inicial\n   >>");
			scanf("%f", &valor_1);
			printf("  segundo valor\n   >>");
			scanf("%f", &valor_2);
			resultado = calcularPitagoras(valor_1, valor_2, opcion);
			println("resultado: ", resultado);
			pausa();
		}
		else if (opcion == 2) {
			system(CLS);
			println(" Calcular el Area");
			printf("  valor base\n   >>");
			scanf("%f", &valor_1);
			printf("  valor Altura\n   >>");
			scanf("%f", &valor_2);
			println("Area: ", calcularArea(valor_1, valor_2));
			pausa();
		}
	}
return 0;
}

float calcularPitagoras(float valor_1, float valor_2, int despejar) {
	/* ************************************
	TRIANGULO RECTANGULO
	aplicacion del teorema de pitagoras
	formulas:
	  c^2 = a^2 + b^2 -> hipotenusa
	  b^2 = c^2 - a^2  -> cateto abyacente
	  a^2 = c^2 - b^2  -> cateto opuesto
	**************************************/
	float resultado = 0;
	switch (despejar) {
		case 1: //Calculo de hipotenusa
			resultado = pow(valor_1, 2) + pow(valor_2, 2);
			resultado = sqrt(resultado);
			return resultado;
		case 2: //Cateto abyacente
			resultado = pow(valor_1, 2) - pow(valor_2, 2);
			resultado = fabs(resultado);
			resultado = sqrt(resultado);
			return resultado; 
		case 3://Cateto opuesto
			resultado = pow(valor_2, 2) - pow(valor_1, 2);
			resultado = fabs(resultado);
			resultado = sqrt(resultado);
			return resultado;
	}

return resultado;
}
float calcularArea(float base, float altura){
	/***********************************
	FORMULA GENERAL PARA CALCULAR EL AREA
	Area = base * altura / 2
	***********************************/
	float area = (base * altura) / 2;
	return area;
}

/*********FUNCIONES COMPLEMENTARIAS***********
* println -> Recive una lista de argumentos y los muestra en la consola(el tipo de dato no importa).
* pausa -> Imprime un mensaje por pantalla y espera que se pulse enter para continuar.
*/
void println() {std::cout << std::endl;}
template<typename T, typename... Args>
void println(T arg0, Args... args) {
    std::cout << " " << arg0 << " ";
    println(args...);
}

void pausa(char *msg) {
	println(msg);
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 
    getchar(); 
}
