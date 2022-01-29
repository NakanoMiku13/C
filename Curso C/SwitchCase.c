#include<stdio.h>
int main(){
	int numeroUno;
	printf("Ingresa un digito del menu:\n1)Opcion Uno\n2)Opcion dos\n3)Opcion 3\n");
	scanf("%d",&numeroUno);
	switch(numeroUno){
		//Caso 1
		case 1:
			printf("Escogiste la opcion uno\n");
			break;
		//Caso 2
		case 2:
			printf("Esta es la opcion 2\n");
			break;
		case 3:
			printf("Esta es la opcion 3\n");
			break;
		default:
			printf("No es ninguna de las 3 opciones disponibles, vuelve a intentarlo\n");
			break;
	}
	printf("Este es un menu con char\n");
	printf("Escoge una opcion:\na) Esta es la opcion A\nb) Esta es la opcion B\n");
	char letra;
	getchar();
	scanf("%c",&letra);
	if(letra == 'A'){
		letra = 'a';
	}else{
		if(letra == 'B'){
			letra = 'b';
		}
	}
	switch(letra){
		case 'a':
			printf("Esta es la opcion A que tu escogiste\n");
			break;
		case 'b':
			printf("Esta es la opcion B que tu escogiste\n");
			break;
		default:
			printf("No existe esa opcion, vuelve a intentarlo\n");
			break;
	}
}
