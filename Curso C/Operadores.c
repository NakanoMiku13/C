#include<stdio.h>
int main(){
	//Operadores
	//Logicos
	// && -> "y"
	// || -> "o"
	// == -> "Identico a..."
	// != -> "Diferente de..."
	//Aritméticos
	// Suma "+"
	// Resta "-"
	// División "/"
	// Multiplicación "*"
	// Módulo "%"
	// Potencias "**"
	int numeroUno,numeroDos;
	scanf("%d",&numeroUno);
	scanf("%d",&numeroDos);
	int suma = numeroUno + numeroDos;
	int resta = numeroUno - numeroDos;
	int multiplicacion = numeroUno * numeroDos;
	int division = numeroUno / numeroDos;
	printf("Suma: %d\nResta: %d\nMultiplicacion: %d\nDivision: %d\n",suma,resta,multiplicacion,division);
	
}
