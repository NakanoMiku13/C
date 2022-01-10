#include<stdio.h>
#include<math.h>
int Input();
void Show(int),Func();
int main(){
	Func();
}
int Input(){
	int x;
	scanf("%d",&x);
	return x;
}
void Func(){
	int x=Input(),i,c=1;
	for(i=11;i>=1;i--){
		unsigned int j=pow(10,i);
		if(x>=j){
			int z=x/j,y=z*j;
			x-=y;
			c++;
		}
	}
	Show(c);
}
void Show(int x){
	printf("%d",x);
}
