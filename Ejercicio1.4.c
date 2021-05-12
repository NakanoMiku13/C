#include<stdio.h>
#include<math.h>
const float PI=3.1415;
void Menu(),FT(),FM(),Show(float),M1(int);
float ConvertToRadian(float),Sin(float),Cos(float),Tan(float),Raiz(float),Pot(float,float),lg(float);
int main(){
	Menu();
}
void M1(int x){
	if(x==0) printf("1) Funciones trigonometricas\n2)Funciones Matematicas\n3)Salir\n");
	else if(x==1) printf("1) Seno\n2) Coseno\n3) Tangente\n4)Regresar\n");
	else printf("1) Potencia\n2) Raiz\n3) Logaritmo\n4) Regresar\n");
}
float Input(){
	float x;
	scanf("%f",&x);
	return x;
}
void Show(float x){
	printf("%f\nDesea continuar? 1=y/2=n\n",x);
	float z=Input();
	if(z==1) Menu();
}
void Menu(){
	M1(0);
	int x=Input();
	switch(x){
		case 1:
			FT();
			break;
		case 2:
			FM();
			break;
		default:
			printf("Error");
			break;
	}
}
void FT(){
	M1(1);
	int x=Input();
	float r,s;
	switch(x){
		case 1:
			s=Input();
			r=Sin(s);
			Show(ConvertToRadian(r));
			break;
		case 2:
			s=Input();
			r=Cos(s);
			Show(ConvertToRadian(r));
			break;
		case 3:
			s=Input();
			r=Tan(s);
			Show(ConvertToRadian(r));
			break;
		case 4:
			Menu();
			break;
		default:
			Menu();
			break;
	}
}
void FM(){
	M1(2);
	int x=Input();
	float s,r,p;
	switch(x){
		case 1:
			s=Input();
			p=Input();
			r=Pot(s,p);
			Show(r);
			break;
		case 2:
			s=Input();
			r=Raiz(s);
			break;
		case 3:
			s=Input();
			r=lg(s);
			break;
		case 4:
			Menu();
			break;
		default:
			Menu();
			break;
	}
}
float ConvertToRadian(float x){
	return x*(PI/180);
}
float Sin(float x){
	return sin(x);
}
float Cos(float x){
	return cos(x);
}
float Tan(float x){
	return tan(x);
}
float Pot(float x,float y){
	return pow(x,y);
}
float Raiz(float x){
	return sqrt(x);
}
float lg(float x){
	return log(x);
}
