#include<stdio.h>
int main(){
	int numeroUno;
	scanf("%d",&numeroUno);
	//Operadores L�gicos
	// == Identico a
	// != Diferente de
	// && "y" "and"
	// || "o" "or"
	// <= Menor igual
	// >= Mayor igual
	// < Menor a
	// > Mayor a
	//Si esta condici�n es verdadera / se cumple
	if(numeroUno != 2){
		//Realiza esta acci�n
		printf("El numero %d es diferente a 2\n",numeroUno);
	}else{
		//Pero si no se cumple, realiza esta acci�n
		printf("El numero es igual a 2\n");
	}
	
	//Condicionales anidadas
	if( (numeroUno % 2) == 0){
		if(numeroUno==2){
			printf("El numero ingresado es par y es 2\n");
		}else{
			printf("El numero ingresado es par, pero no es 2\n");
		}
	}else{
		if(numeroUno%3==0){
			printf("El numero es multiplo de 3\n");
			if(numeroUno!=9){
				printf("Y asi mismo es diferente de 9");
			}else{
				printf("Y es el numero 9");
			}
		}else{
			printf("El numero no es multiplo de 3\n");
		}
	}
}
