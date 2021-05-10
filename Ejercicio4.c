#include<math.h>
#include<stdio.h>
#include<stdlib.h>
const float PI=3.1415;
void ConvertToRadian(float x,float* dir),Input(float* dir),CX(float x,float y,float* dir),CY(float x,float y,float* dir),Show(float x,float y);
int main(){
    float x,g,r,Cx,Cy;
    Input(&x);
    Input(&g);
    ConvertToRadian(g,&r);
    CX(x,r,&Cx);
    CY(x,r,&Cy);
    Show(Cx,Cy);
}
void ConvertToRadian(float x,float* dir){
    *dir=x*PI/180;
}
void Input(float* dir){
    float x;
    scanf("%f",&x);
    *dir = x;
}
void CX(float x,float y,float* dir){
    *dir = x*sin(y);
}
void CY(float x,float y,float* dir){
    *dir = x*cos(y);
}
void Show(float x,float y){
    printf("La componente en x es: %f\La componente en y es: %f",x,y);
}