//Ejercicios 12: Problema 1

//Archivos de cabecera
#include<stdio.h>

//Prototipos de funciones
void menu(int o, int *i);
void lee(int *o);
void whil(int *i);
void dowhil(int *i);
void fore(int *i);
void mostrar(int i);

//Funcion principal
void main( ){
   
   	int o, i=0;
	menu(o, &i);
	mostrar(i);
}

//Cuerpo de las funciones


void lee(int *o){
	printf("Introduzca el numero entero de la opcion de ciclo repetitivo que desee: \n 1 : While \n 2 : Do While \n 3 : For \n");
	scanf("%d", o);
}

void menu(int o, int *i){
	lee(&o);
	switch(o){
		case 1: whil(i);
		break;
		case 2: dowhil(i);
		break;
		case 3: fore(i);
		break;
		default: printf("Opcion no valida\n");
	}
}

void whil(int *i){
	int n = 10;
	while (n<=100){
		*i= *i+n;
		n+=5;
	}
	mostrar(i);
}

void dowhil(int *i){
	int n = 10;
	do{
		*i= *i+n;
		n+=5;
	}while(n<=100);
	mostrar(i);
}

void fore(int *i){
	int n;
	for(n=10; n<=100; n+=5){
	*i= *i+n;	
	}
	mostrar(i);
}

void mostrar(int i){
	printf("El resultado es: %d\n", i);
}