#include<stdio.h>
int main(){
	//Operadores
	//Logicos
	// && -> "y"
	// || -> "o"
	// == -> "Identico a..."
	// != -> "Diferente de..."
	//Aritm�ticos
	// Suma "+"
	// Resta "-"
	// Divisi�n "/"
	// Multiplicaci�n "*"
	// M�dulo "%"
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
