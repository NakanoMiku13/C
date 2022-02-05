#include<stdio.h>
int main(){
	int variableSimple;
	int arreglo[10]; //Este arreglo puede almacenar desde 1 a 11 datos
	scanf("%d",&variableSimple);
	//Usaremos a variableSimple como la cantidad de numeros que quiero guardar
	int iterador;
	for(iterador=0;iterador<variableSimple;iterador++){
		scanf("%d",&arreglo[iterador]);
	}
	//Aqui lo vamos a imprimir
	for(iterador=0;iterador<variableSimple;iterador++){
		printf("Esta es la posicion [%d] y el valor es: %d\n",iterador+1,arreglo[iterador]);
	}
}
