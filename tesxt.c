//2021630006

//Ejercicio 17: Problema 1

//Archivos de cabecera
#include<stdio.h>
#include <stdlib.h>

#define TAM 50

//Prototipos de funciones
void darNumElem(int *n);
void insertarDatos(int n, float *lista);
void mos(float *listaa, int j);
void mos2(float *listar, int k);
void mos3(float prom);
void opera(float *lista, int n, float *prom, float *listaa, float *listar);


//Funcion principal
void main( ){
	
   	int n;
   	float lista[TAM], listaa[TAM], listar[TAM], prom;
   	darNumElem(&n);
   	insertarDatos(n, lista);
   	opera(lista, n, &prom, listaa, listar);

}

//Cuerpo de las funciones

void darNumElem(int *n){
	printf("Introduzca el numero de calificaciones que desea ingresar\n Nota: Debe ser menor a 50\n");
	scanf("%d", n);
}

void insertarDatos(int n, float *lista){
	int i;
	printf("Introduzca los datos del elemento correspondiente:\n");
	for(i=0; i<n; i++){
		printf("Elemento [%d]:", i+1);
		scanf("%f", &lista[i]);
	}
}

void mos(float *listaa, int j){
	int i;
	printf("Las calificaciones aprobadas son:\n");
	for(i=0; i<j; i++){
		printf("Calificacion[%d]=%d\n", i+1, listaa[i]);
	}
}

void mos2(float *listar, int k){
	int i;
	printf("Las calificaciones reprobadas son:\n");
	for(i=0; i<k; i++){
		printf("Calificacion[%d]=%d\n", i+1, listar[i]);
	}
}

void mos3(float prom){
	printf("\nEl promedio es: %f", prom);
}


void opera(float *lista, int n, float *prom, float *listaa, float *listar){
	int i, j=0, k=0;
	float sum=0;
	for(i=0; i<n; i++){
		sum = sum + lista[i];
		if(lista[i]>=6){
			listaa[j]=lista[i];
			j++;
		}else{
			listar[k]=lista[i];
			k++;
		}
	}
	mos(listaa, j);
	mos2(listar, k);
	*prom = sum/n;
	mos3(*prom);
}