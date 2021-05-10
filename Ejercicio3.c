#include<stdlib.h>
#include<stdio.h>
#include<math.h>
void Input(float* dir),Calc(float a,float b,float* dir),Show(float x);
int main(){
    float a,b,c;
    Input(&a);
    Input(&b);
    Calc(a,b,&c);
    Show(c);
}
void Input(float* dir){
    float x;
    scanf("%f",&x);
    *dir=x;
}
void Calc(float a,float b,float* dir){
    *dir=sqrt((pow(a,2)+pow(b,2)));
}
void Show(float x){
    printf("El resultado es: %f",x);
}