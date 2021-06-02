#include<stdio.h>
int Sum(int(*)[12][12],int,int),Mult(int(*)[12][12],int,int);
void Input(int*),Dimension(int*,int*),Fill(int(*)[12][12],int,int),Show(int(*)[12][12],int,int),Menu(int(*)[12][12]),Init(int(*)[12][12]);
int main(){
	int a[12][12];
	Init(&a);
	Menu(&a);
}
void Init(int (*a)[12][12]){
	int i=0,j=0;
	for(;i<12;i++) for(;j<12;j++) *a[i][j]=0;
}
void Input(int* x){
	scanf("%d",x);
}
void Dimension(int* n,int* m){
	Input(n);
	Input(m);
}
void Fill(int (*a)[12][12],int n,int m){
	int i,j;
	for(i=0;i<n;i++) for(j=0;j<m;j++) Input(a[i][j]);
	//for(i=0;i<n;i++) for(j=0;j<m;j++) printf("%d ",*a[i][j]);
}
int Sum(int (*a)[12][12],int n,int m){
	int r=0,i,j;
	for(i=0;i<n;i++) for(j=0;j<m;j++) if(j==(m-1-i)) r+=*a[i][j];
	return r;
}
int Mult(int (*a)[12][12],int n,int m){
	int r=1,i,j;
	for(i=0;i<n;i++) for(j=0;j<=i;j++) r*=(*a[i][j]);
	return r;
}
void Show(int (*a)[12][12],int n,int m){
	int i,j;
	for(i=0;i<n;i++){ for(j=0;j<m;j++) printf("%d ",*a[i][j]); printf("\n");}
}
void Menu(int (*a)[12][12]){
	int n,m,x;
	Init(a);
	do{
		printf("O: ");
		Input(&x);
		switch(x){
			case 1: printf("D: \n"); Dimension(&n,&m); break;
			case 2: printf("F: \n"); Fill(a,n,m); break;
			case 3: printf("S: %d\n",Sum(a,n,m)); break;
			case 4: printf("M: %d\n",Mult(a,n,m)); break;
			case 5: Show(a,n,m); break;
			default: break;
		}
	}while(x<6);
}

