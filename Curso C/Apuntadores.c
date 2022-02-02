#include<stdio.h>
int main(){
	/*
	int (enteros)
	float y double (decimales)
	char (letras)
	long 
	
	int* (enteros)
	float* y double* (decimales)
	char* (letras)
	
	*/
	char Juan='a';
	char* Luis = &Juan;
	char* Andrea = &Luis;
	
	printf("Juan vive en: %p\n",&Juan);
	printf("Luis sabe que Juan vive en: %p\nY Luis vive en: %p\n",Luis,&Luis);
	printf("Y Andrea sabe que Luis vive en: %p\nY Andrea vive en: %p\n",Andrea);
	printf("Luis le pregunta por su letra a Juan: %c\n",*Luis);
	printf("Luis le pregunta por su letra a Juan: %c\n",Juan);
}
