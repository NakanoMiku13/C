#include<stdio.h>
int main(){
	int cantidadDatos;
	scanf("%d",&cantidadDatos);
	int arreglo[cantidadDatos+5];
	int iterador;
	for(iterador=0;iterador<cantidadDatos;iterador++){
		int temporal;
		scanf("%d",&temporal);
		arreglo[iterador]=temporal;
		// * + - / 
		// ++ --
		int auxiliar = arreglo[iterador];
		auxiliar--;
		auxiliar++;
		auxiliar=12+25-arreglo[iterador];
		arreglo[iterador]=auxiliar;
		/*arreglo[iterador]--;
		arreglo[iterador]++;
		arreglo[iterador]=12+25-arreglo[iterador];
		arreglo[iterador]=12*arreglo[iterador]+12;*/
	}
	for(iterador=0;iterador<cantidadDatos;iterador++){
		int auxiliar=arreglo[iterador];
		printf("El valor en la posicion [%d] es: %d\n",iterador+1,auxiliar);
	}
}
