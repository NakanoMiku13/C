#include<stdio.h>
#include<stdlib.h>
int* resultado(int,int*,int);
int main(){
    int n,i=0;
    scanf("%d",&n);
    int* sellos = (int*)malloc(sizeof(int)*10000);
    sellos=resultado(n,(int*)malloc(sizeof(int)*10000),0);
    while(sellos[i]!=0 && (sellos[i]==5 || sellos[i]==4)){
        printf("%d ",sellos[i]);
        i++;
    }
}
int* resultado(int n,int* sellos,int index){
    if(n<=0) return sellos;
    if(n%5==0){
        sellos[index]=5;
        n-=5;
        return resultado(n,sellos,index+1);
    }else if(n%4==0){
        sellos[index]=4;
        n-=4;
        return resultado(n,sellos,index+1);
    }else{
        n-=4;
        sellos[index]=4;
        return resultado(n,sellos,index+1);
    }
}