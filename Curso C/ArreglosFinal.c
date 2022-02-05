#include<stdio.h>
#include<stdlib.h>
int main(){
	int arregloEstatico[10]={
		1,2,3,4,5
	};
	int arregloEstatico2[]={
		6,10,6,7,8,9,10,11,12,13,14,1000
	};
	int numeroDatos;
	scanf("%d",&numeroDatos);
	int arregloDinamico[numeroDatos+5];
	int* arregloPunteroEstatico;
	/*float valor = 13.5;
	char letra = 'a'; //65
	int valor2 = 24 + (int)letra;
	int valor3 = 95; //B
	char letra2 = (char)valor3;*/
	arregloPunteroEstatico = (int*)malloc(sizeof(int)*(10));
	arregloPunteroEstatico[5]=98;
	int* arregloPunteroDinamico=(int*)malloc(sizeof(int)*(numeroDatos+5));
	int iterador;
	for(iterador=0;iterador<numeroDatos;iterador++){
		int temporal;
		scanf("%d",&temporal);
		arregloPunteroEstatico[iterador]=temporal;
		arregloPunteroDinamico[iterador]=temporal;
	}
	for(iterador=0;iterador<numeroDatos;iterador++){
		printf("Arreglo Estatico [%d]: %d\n",iterador+1,arregloPunteroEstatico[iterador]);
		printf("Arreglo Dinamico [%d]: %d\n",iterador+1,arregloPunteroDinamico[iterador]);		
	}
}
