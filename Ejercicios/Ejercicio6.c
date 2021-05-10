#include<math.h>
#include<stdio.h>
#include<stdlib.h>
const float g=9.81;
void Show(float r),Input(float* dir),Calc(float v,float t,float* dir);
int main(){
    float v,t,r;
    Input(&v);
    Input(&t);
    Calc(v,t,&r);
    Show(r);
}
void Calc(float v,float t,float* dir){
    *dir=v+(g*t);
}
void Input(float* dir){
    float x;
    scanf("%f",&x);
    *dir=x;
}
void Show(float r){
    printf("La velocidad final es: %f",r);
}