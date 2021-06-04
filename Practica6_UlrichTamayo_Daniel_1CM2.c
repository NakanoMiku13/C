#include<stdio.h>
#include<stdlib.h>
void Fill(int*, int*,int,int),Input(int*,int),Size(int*,int*),Swap(int*,int*),Sort(int*,int),Union(int*,int*,int,int,int*),Inter(int*,int*,int,int,int*),Menu(int*,int*),Concat(int*,int*,int,int,int),Constant(int*,int*,int*,int,int);
int Intpt();
int main(){
	int* a;
	a=(int*)malloc(sizeof(int)*150);
	int* b;
	b=(int*)malloc(sizeof(int)*150);
	Menu(a,b);
}
int Intpt(){
	int x;
	scanf("%d",&x);
	return x;
}
void Input(int* a,int m){
	int i;
	for(i=0;i<m;i++) a[i]=Intpt();
}
void Size(int* a,int* b){
	printf("Array 1:\n");
	*a=Intpt();
	printf("Array 2:\n");
	*b=Intpt();
}
void Fill(int* a,int* b,int n,int m){
	printf("Array 1:\n");
	Input(a,n);
	printf("Array 2:\n");
	Input(b,m);
}
void Swap(int* a,int* b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
void Sort(int* a,int n){
	int i,j;
	for(i=0;i<n;i++) for(j=i;j<n;j++) if(a[i]>a[j+1]) Swap(&a[i],&a[j+1]);
}
void Concat(int* dest,int* src,int n,int m,int k){
	int i,j=0;
	if(k!=0) for(i=0,j=m+1;i<n;i++,j++) dest[j]=src[i];
	else for(i=0;i<n;i++) dest[i]=src[i];
}
void Constant(int* a,int* b,int* tmp,int n,int m){
	int z=n+m,i;
	Concat(tmp,a,n,z,0);
	Concat(tmp,b,m+1,n,1);
	Sort(tmp,z);
}
int Binary(int* Array,int x, int begin,int end){
	int mid=0;
	while(begin<=end){
		mid=(begin+end)/2;
		if(x==Array[mid]) return 1;
		else if(x>Array[mid]) begin=mid+1;
		else end=mid-1;
	}
	return -1;
}
void Union(int* a,int* b,int n,int m,int* tmp){
	int i,z=n+m;
	Constant(a,b,tmp,n,m);
	printf("Union: ");
	for(i=0;i<=z;i++) if(tmp[i]!=0 && tmp[i]!=tmp[i+1]) printf("%d ",tmp[i]);
	printf("\n");
}
void Inter(int* a,int* b,int n,int m,int* tmp){
	int i,z=n+m,c[z];
	Constant(a,b,tmp,n,m);
	printf("Intersection: ");
	//for
	printf("\n");
}
void Menu(int* a,int* b){
	int n,m,x;
	int* tmp;
	do{
		printf("Option: ");
		x=Intpt();
		switch(x){
			case 1: Size(&n,&m); tmp=(int*)malloc(sizeof(int)*(n+m)); break;
			case 2: Fill(a,b,n,m); break;
			case 3: Union(a,b,n,m,tmp); break;
			case 4: Inter(a,b,n,m,tmp); break;
			default: break;
		}
	}while(x<5);
}
