#include<stdio.h>
#include<math.h>
int Input(),Determinante(int,int,int),Parabola(int,int,int,int,int,int),Recta(int,int,int,int,int),Circu(int,int,int,int,int),Hiper(int,int,int,int,int,int,int),Elipse(int,int,int,int,int,int,int);
void Show(int),InputData(int*,int*,int*,int*,int*,int*),InputData2(int*,int*),Cuadrante(int,int),Function();
int main(){
	Function();
}
int Input(){
	int x;
	scanf("%d",&x);
	return x;
}
int Determinante(int a,int b,int c){
	return (pow(b,2))-(4*a*c);
}
int Parabola(int A,int D,int E, int F,int x,int y){
	int r = (A*pow(x,2))+(D*x)+(E*y)+F;
	if(r!=0) return 1;
	else return 0;
}
int Recta(int a,int b,int c,int x,int y){
	int r=(a*x)+(b*y)+c;
	if(r!=0) return 1;
	else return 0;
}
int Circu(int x,int y,int d,int e,int f){
	int r=pow(x,2)+pow(y,2)+(d*x)+(e*y)+f;
	if(r!=0) return 1;
	else return 0;
}
int Hiper(int a,int c,int e,int d,int f,int x,int y){
	int r=(a*(pow((x),2)))+(c*(pow((y),2)))+(d*x)+(e*y)+f;
	if(r!=0) return 1;
	else return 0;
}
int Elipse(int a,int c,int e,int d,int f,int x,int y){
	int r=(a*pow(x,2))+(c*pow(y,2))+(d*x)+(e*y)+f;
	if(r!=0) return 1;
	else return 0;
}
void Show(int x){
	if(x==0) printf("Pertenece");
	else printf("No pertenece");
}
void InputData(int* a,int* b,int* c,int* d,int* e,int* f){
	printf("Ingrese los coeficientes A, B, C, D, E y F:\n");
	*a=Input();
	*b=Input();
	*c=Input();
	*d=Input();
	*e=Input();
	*f=Input();
}
void InputData2(int* x,int* y){
	printf("Ingrese X y Y:\n");
	*x=Input();
	*y=Input();
}
void Cuadrante(int x,int y){
	if(x!=0 && y==0) printf("Eje X\n");
	else if(x==0 && y!=0) printf("Eje Y\n");
	else if(x>0 && y>0) printf("Cuadrante I\n");
	else if(x<0 && y<0) printf("Cuadrante III\n");
	else if(x>0 && y<0) printf("Cuadrante IV\n");
	else if(x<0 && y>0) printf("Cuadrante II\n");
	else printf("Estan en el origen\n");
}
void Function(){
	int a,b,c,d,e,f,x,y,D;
	InputData(&a,&b,&c,&d,&e,&f);
	InputData2(&x,&y);
	D=Determinante(a,b,c);
	if(D>0){
		printf("Hiperbola: ");
		Cuadrante(x,y);
		Show(Hiper(a,c,e,d,f,x,y));
	}else if(D==0){
		if(a==0 && c==0){
			//Recta
			printf("Recta: ");
			Cuadrante(x,y);
			Show(Recta(a,b,c,x,y));
		}else{
			//Parabola
			printf("Parabola: ");
			Cuadrante(x,y);
			Show(Parabola(a,d,e,f,x,y));
		}
	}else{
		if(a==c){
			printf("Circunferencia: ");
			Cuadrante(x,y);
			Show(Circu(x,y,d,e,f));
		}else{
			//Elipse
			printf("Elipse: ");
			Cuadrante(x,y);
			Show(Elipse(a,c,e,d,f,x,y));
		}
	}
}
