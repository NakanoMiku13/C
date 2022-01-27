//Ésta es la libreria estandard de entradas y salidas de datos
#include<stdio.h>
//Éste es el método principal/Función principal
//Aquí se ejecuta todo el código
int main(){
	//int hace referencia a Enteros
	//La capacidad de un número entero es (-32k <-> 32k)
	int variableEnteros = 0;
	
	//char hace referencia a Letras
	//La capacidad de un char es de (0 a 255)
	char variableLetras = 'a';

	//float hace referencia a Decimales
	//Float tiene máximo 6 decimales
	//Float tiene una capacidad de (-1.2e38 a 1.2e38)
	float vairableFlotante = 23.32;
	
	//Double hace referencia a Decimales más precisos
	//Double tiene máximo 12-15 decimales
	//Double tiene una capacidad de (-2.3e308 a 2.3e308)
	double variableDoble = 2.121314151617;
	
	//long hace refencia a Enteros más grandes que int
	//Long tiene una capacidad de (-2MM <-> 2MM)
	long variableLong = 9000000;
	
	//long tiene un segundo uso, el cual es expandir el tamaño de
	//ciertas variables
	long double variableDoblementeGrande = 1280000.92039283;
}
