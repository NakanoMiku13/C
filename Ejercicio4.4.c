#include<stdio.h>
void Funct();
float Input();
int main(){
	Funct();
}
float Input(){
	float x;
	scanf("%f",&x);
	return x;
}
void Funct(){
	float x=Input();
	if(x>=50000) printf("Television, tres p zapatos, 5 camisas, 5 pantalones");
	else if(x<50000 && x>=20000) printf("Grabadora, 3 P zapatos, 5 camisas y 5 pantalones");
	else if(x<20000 && x>=10000) printf("2 P zapatos, 3 camisas, 3 pantalones");
	else printf("Par de zapatos, 2 camisas, 2 pantalones");
}
