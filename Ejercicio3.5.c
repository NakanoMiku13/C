#include<stdio.h>
#include<stdlib.h>
int Input(){
	int x;
	scanf("%d",&x);
	return x;
}
void SetArray(int* x){
	*x=Input();
}
void Fill(int* Array,int n){
	int i=0;
	for(;i<n;i++) Array[i]=Input();
}
void Swap(int* a,int* b){
	int tmp=*a;
	*b=*a;
	*a=tmp;
}
void Sort1(int* Array,int n){
	int i,j,min;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++) if(Array[j]<Array[min]) min=j;
		Swap(&Array[min],&Array[i]);
	}
}
void Reverse(int* Array,int n){
	int i,j=n-1;
	for(i=0;i<n;i++) Swap(&Array[i],&Array[j-i]);
}
void Sort(int* Array,int n){
	int i,j;
	for(i=0;i<n;i++) for(j=i;j<n;j++) if(Array[j]>Array[i+1]) Swap(&Array[j],&Array[i+1]);
	Reverse(Array,n);
}
void Show(int* Array, int n){
	int i=0;
	for(;i<n;i++) printf("%d ",Array[i]);
}
void Menu(){
	int x=0,n;
	int* Array;
	Array=(int*)malloc(sizeof(int)*(103));
	do{
		printf("Option\n");
		n=Input();
		switch(n){
			case 1:
				printf("Set\n");
				SetArray(&x);
				break;
			case 2:
				printf("Fill\n");
				Fill(Array,x);
				break;
			case 3:
				printf("Select Sort\n");
				Sort1(Array,x);
				break;
			case 4:
				printf("Bubble Sort\n");
				Sort(Array,x-1);
				break;
			case 5:
				printf("Show\n");
				Show(Array,x);
				break;
			default:
				break;
		}
	}while(n<6);
}
int main(){
	Menu();
}
