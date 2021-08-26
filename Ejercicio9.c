#include<stdio.h>
#include<math.h>
void Show(float r),Perimetro(float a,float b,float c,float* dir),Area(float a,float b,float c,float p,float* dir),Input(float* dir),Area(float a,float b,float c,float p,float* dir);
int main(){
    float a,b,c,p,r;
    Input(&a);
    Input(&b);
    Input(&c);
    Perimetro(a,b,c,&p);
    Area(a,b,c,p,&r);
    Show(r);
}
void Input(float* dir){
    scanf("%f",*&dir);
}
void Perimetro(float a,float b,float c,float* dir){
    *dir=(a+b+c)/2;
}
void Area(float a,float b,float c,float p,float* dir){
    *dir=sqrt(p*(p-a)*(p-b)*(p-c));
}
void Show(float r){
    printf("El resultado es: %f",r);
}