#include<stdio.h>
#include<math.h>
#include<stdlib.h>
const float PI=3.1415;
void Area(float r,float* s),Largo(float r,float* s),Input(float* dir),Show(float x,float y);
int main(){
    float r=0,A=0,L=0;
    Input(&r);
    Area(r,&A);
    Largo(r,&L);
    Show(A,L);
}
void Area(float r,float* s){
    *s=PI*pow(r,2);
}
void Largo(float r,float* s){
    *s=2*PI*r;
}
void Input(float* dir){
    float x;
    scanf("%f",&x);
    *dir=x;
}
void Show(float x,float y){
    printf("El area es: %f\nLa longitud es: %f\n",x,y);
}