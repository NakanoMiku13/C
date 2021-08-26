#include<stdio.h>
float Input();
void Func();
int main(){
	Func();
}
float Input(){
	float x;
	scanf("%f",&x);
	return x;
}
void Func(){
	float x=Input();
	if(x<=10) printf("Tarjeta");
	else if(x>10 && x<=100) printf("Chocolates");
	else if(x>100 && x<=250) printf("Flores");
	else printf("Anillo");
}
