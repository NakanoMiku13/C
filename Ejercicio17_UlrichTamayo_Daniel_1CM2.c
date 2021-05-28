#include<stdio.h>
#include<stdlib.h>
float Input(),Prom(float*,int);
void Show(int,float*,float),FillArray(int,float*);
int main(){
	int n=Input();
	float* Array;
	float prom;
	Array=(float*)malloc(sizeof(int)*(53));
	FillArray(n,Array);
	prom=Prom(Array,n);
	Show(n,Array,prom);
}
float Prom(float* Array,int n){
	int i=0;
	float x=0;
	for(;i<n;i++){
		x+=Array[i];
	}
	x/=n;
	return x;
}
float Input(){
	float x;
	scanf("%f",&x);
	return x;
}
void Show(int n,float* Array,float prom){
	int i=0,j=0,k=0;
	float Aprob[53],Reprob[53];
	for(;i<n;i++){
		if(Array[i]<6){
			Reprob[j]=Array[i];
			j++;
		}else{
			Aprob[k]=Array[i];
			k++;
		}
	}
	printf("El promedio es: %f\nMaterias aprobadas (%d): \n",prom,k);
	for(i=0;i<k;i++) printf("Materia %d: %f\n",i,Aprob[i]);
	printf("\nMaterias reprobadas (%d): \n",j);
	for(i=0;i<j;i++) printf("Materia %d: %f\n",i,Reprob[i]);
}
void FillArray(int n,float* Array){
	int i=0;
	for(;i<n;i++){
		printf("Materia %d: ",i+1);
		Array[i]=Input();
	}
}
