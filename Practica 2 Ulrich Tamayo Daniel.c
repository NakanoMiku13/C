#include<stdlib.h>
#include<stdio.h>
void Input(float* dir), Determinante(float x1,float x2,float y1,float y2,float* dir),Fin(float Deter,float C1,float* dir);
int main(){
    float a,b,c,d,e,f,x,y,deter,r1,r2;
    Input(&a);
    Input(&b);
    Input(&c);
    Input(&d);
    Input(&e);
    Input(&f);
    Determinante(a,e,b,d,&deter);
    Determinante(c,e,b,f,&x);
    Determinante(a,f,c,d,&y);
    Fin(deter,x,&r1);
    Fin(deter,y,&r2);
    printf("X:%f\n",r1);
    printf("Y:%f",r2);
}
void Input(float* dir){
    scanf("%f",dir);
}
void Determinante(float x1,float x2,float y1,float y2,float* dir){
    float p1=x1*x2,p2=y1*y2,x=p1-p2;
    *dir=x;
}
void Fin(float Deter,float C1,float* dir){
    *dir=C1/Deter;
}
