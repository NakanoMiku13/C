#include<stdio.h>
#include<math.h>
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
	int r=(a*pow((x),2))+(c*pow((y),2))+(d*x)+(e*y)+f;
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
void Function(){
	printf("a b c d e f x y\n");
	int a=Input(),b=Input(),c=Input(),d=Input(),e=Input(),f=Input(),x=Input(),y=Input(),D=Determinante(a,b,c);
	if(D>0){
		printf("Hiperbole: ");
		Show(Hiper(a,c,e,d,f,x,y));
	}else if(D==0){
		if(a==0 && c==0){
			//Recta
			printf("Recta: ");
			Show(Recta(a,b,c,x,y));
		}else{
			//Parabola
			printf("Parabola: ");
			Show(Parabola(a,d,e,f,x,y));
		}
	}else{
		if(a==c){
			printf("Circunferencia: ");
			Show(Circu(x,y,d,e,f));
		}else{
			//Elipse
			printf("Elipse: ");
			Show(Elipse(a,c,e,d,f,x,y));
		}
	}
}
int main(){
	Function();
}
