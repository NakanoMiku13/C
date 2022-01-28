#include<stdio.h>
int main(){
	//Las variables se pueden concatenar así siempre
	//y cuando sean del mismo tipo
	//o sea, no podemos juntar float con int o similar.
	int variableEntera,variableEntera2;
	float variableFloat,estaEsOtra=98.12,estaEsOtraMas=0;
	char variableLetra,otraMas='1',Otra='p';
	//Para ingreso de datos enteros se usa %d
	//Para flotantes se usa %f
	//Para char se usa %c
	scanf("%d",&variableEntera);
	scanf("%f",&variableFloat);
	getchar();
	scanf("%c",&variableLetra);
	//si es suma de char 5+5=55
	//si es una suma de int o float o double 5+5=10
	printf("El valor de la variable entera es: %d\n",variableEntera);
	printf("El valor de la variable flotante es: %f",variableFloat);
	printf("\nLa letra ingresada es: %c",variableLetra);
	
	//Esta es otra forma de imprimir datos
	printf("\n\n\nEl valor entero: %d\nEl valor flotante: %f\nLa letra: %c",variableEntera,estaEsOtra,variableLetra);
}
