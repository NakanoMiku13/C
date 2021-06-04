#include<stdio.h>
#include<stdlib.h>
void redimensionar(int*,int*),liberar(int*),mostrar(int*,int),darDatos(int*,int),darDim(int*);
int* crearArregloUni(int);
int main(){
}
void darDim(int* elem){
	printf("Indique la dimension del arreglo:\n");
	scanf("%d",elem);
}
int* crearArregloUni(int elem){
	int* A;
	A=(int*)malloc(elem*sizeof(int));
	if(A==NULL){
		printf("No hay memoria disponible\n");
		exit(0);
	}
}
void darDatos(int* A,int elem){
	int i;
	printf("Ingrese los datos del arreglo\n");
	for(i=0;i<elem;i++){
		printf("\nA[%d]=",i+1);
		scanf("%d",&A[i]);
	}
}
void mostrar(int* A,int elem){
	int i;
	printf("Los datos del arreglo son:\n");
	for(i=0;i<elem;i++) printf("A[%d]=%d\n",i+1,A[i]);
}
void liberar(int* A){
	free(A);
	printf("\nMemoria Liberada");
}
void redimensionar(int* A,int* elem){
	int i,n,nvotam,*B;
	printf("Cuantos elementos va a agregar?\n");
	scanf("%d",&n);
	nvotam=(*elem)+n;
	B=(int*)realloc(A,nvotam*sizeof(int));
	for(i=(*elem);i<nvotam;i++){
		printf("\nA[%d]=",i+1);
		scanf("%d",&B[i]);
	}
	(*elem)=nvotam;
	A=B;
}
