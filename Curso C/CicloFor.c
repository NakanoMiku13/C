#include<stdio.h>
int main(){
	int numeroIngresado,iterador = 0;
	scanf("%d",&numeroIngresado);
	/*for(iterador;Condicion;Incremento){
		
	}*/
	int iteradorDelFor=0;
	printf("Esta es la numeracion del For\n");
	for(iteradorDelFor = 0; iteradorDelFor < 10; iteradorDelFor++){
		printf("%d ",iteradorDelFor+1);
	}
	printf("\nEsta es la numeracion del While\n");
	iteradorDelFor=0;
	while(iteradorDelFor<10){
		printf("%d ",iteradorDelFor+1);
		iteradorDelFor++;
		//Realizamos una acción
	}
	printf("\nEsta es la numeracion del Do While\n");
	iteradorDelFor=0;
	do{
		printf("%d ",iteradorDelFor+1);
		iteradorDelFor++;
		//Realizamos una acción
	}while(iteradorDelFor<100);
}
