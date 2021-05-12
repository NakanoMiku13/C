#include<stdio.h>
float Input(),float PromA(float,float,float),float PromGen(float,float);
void Menu();
int main(){
}
float Input(){
	float x;
	scanf("%f",&x);
	return x;
}
void Menu(){
	int n=Input(),i,j,t,pT=0,pG=0;
	float pA=0,r=0;
	for(i=0;i<n;i++){
		int k=Input();
		for(j=0;j<k;j++){
			int l=Input();
			for(t=0;t<l;t++){
				pA+=Input();
			}
			r=pA/l;
		}
	}

}
