#include<stdio.h>
int main(){
	int numeroRecibido,iterador = 0;
	scanf("%d",&numeroRecibido);
	//iterador = iterador * 10
	//iterador *= 10
	//iterador++
	//iterador--
	while( (iterador < numeroRecibido) && (numeroRecibido % 2 == 0) && (numeroRecibido < 1000)){
		printf("%d\n",iterador+1);
		iterador++;
	}
}
