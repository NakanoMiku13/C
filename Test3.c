#include<stdio.h>
void Input(int* dir){
    scanf("%d",dir);
}
int Dat(){
    return 1;
}
void Count(int* c1,float* c2,float* c3,int M){
    int i;
    for(i=0;i<M;i++){
        int x;
        Input(&x);
        *c3+=x;
        if(x>0){
            *c1+=1;
            *c2+=x;
        }  
   }
}
void Data(){
    int M,i,c1=0;
    float c2=0,c3=0;
    Input(&M);
    Count(&c1,&c2,&c3,M);
    printf("%d %f %f",c1,(c2/c1),(c3/M));
}
int main(){
    Data();
}
