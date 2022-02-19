#include<stdio.h>
int main(){
	int matriz[10][10];
	int iteradorX,iteradorY,contador=0;
	for(iteradorY=0;iteradorY<3;iteradorY++){
		for(iteradorX=0;iteradorX<3;iteradorX++,contador++){
			int aux;
			scanf("%d",&aux);
			matriz[iteradorY][iteradorX]=aux;
		}
	}
	for(iteradorY=0;iteradorY<3;iteradorY++){
		for(iteradorX=0;iteradorX<3;iteradorX++){
			printf("[%d]",matriz[iteradorY][iteradorX]);
		}
		printf("\n");
	}
	printf("El numero en la posicion Y: 4 X: 5 es %d\n",matriz[4][5]);
	printf("La suma de dos numeros aleatorios en la matriz es: %d\n",matriz[8][9]+matriz[1][2]);
}
