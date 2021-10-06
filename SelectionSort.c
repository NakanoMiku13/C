#include <stdio.h>
#include <stdlib.h>
int Arre[500];
int main(){

}
int Input(){
    int x;
    scanf("%d",&x);
    return x;
}
void Fill(int n){
    int i=0;
    for(;i<n;i++){
        Arre[i]=Input();
    }
}
void Swap(int* a,int* b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void Sort(int n){
    int i=0,in;
    while(i<n){
        int j=i;
        int x=Arre[i];
        while(j<n){
            if()
        }
        
    }
}