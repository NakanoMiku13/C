#include<stdio.h>
int main(){
	int numeroRecibido,iterador = 0;
	scanf("%d",&numeroRecibido);
	do{
		printf("%d ",(iterador+1)/2);
		iterador++;
	}while( iterador < numeroRecibido );
}
