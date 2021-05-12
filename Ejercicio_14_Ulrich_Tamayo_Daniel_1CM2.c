#include<stdio.h>
float Input(),Com(float);
void Func();
int main(){
	Func();
}
float Input(){
	float x;
	scanf("%f",&x);
	return x;
}
float Com(float x){
	return x*0.10;
}
void Func(){
	printf("N\n");
	int n=Input(),i,j;
	float r=0,s;
	for(i=0;i<n;i++){
		r=0;
		printf("Trabajador %d\nSueldo Base\n",i+1);
		float sb=Input();
		for(j=0;j<3;j++){
			printf("V%d\n",j+1);
			float x=Input();
			r+=Com(x);
		}
		s=r+sb;
		printf("R=%f\n",s);
	}
}

