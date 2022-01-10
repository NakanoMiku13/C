#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void Calc(float x,float* dir),Input(float* dir),Show(float r);
int main(){
    float x,r;
    Input(&x);
    Calc(x,&r);
    Show(r);
}
void Calc(float x,float* dir){
    float a=pow(((2*x)+4),0.3333),b=(3*x)+6;
    *dir=(a/b);
}
void Input(float* dir){
    float x;
    scanf("%f",&x);
    *dir=x;
}
void Show(float r){
    printf("El resultado es: %f",r);
}