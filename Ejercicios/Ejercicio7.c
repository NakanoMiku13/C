#include<stdio.h>
#include<math.h>
void Calc(float x,float* dir),Input(float* dir),Show(float r);
int main(){
    float x,r;
    Input(&x);
    Calc(x,&r);
    Show(r);
}
void Input(float* dir){
    float x;
    scanf("%f",&x);
    *dir=x;
}
void Calc(float x,float* dir){
    float a = 2*sqrt(x)+1,b = pow(x,2)+sqrt(x)*x+pow(3,0.3333)*x,c=4*sqrt(b);
    *dir=(a/c);
}
void Show(float r){
    printf("El resultado es: %f",r);
}