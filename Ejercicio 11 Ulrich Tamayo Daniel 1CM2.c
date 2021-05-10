#include<stdlib.h>
#include<stdio.h>
float Prom(float a,float b,float c),Percent(float x,float y);
void Input(float* dir),show(float r);
int main(){
    float a,b,c;
    Input(&a);
    Input(&b);
    Input(&c);
    show(Prom(Percent(a*10,30),Percent(b*10,30),Percent(c*10,40)));
}
void Input(float* dir){
    scanf("%f",dir);
}
void show(float r){
    if(r>=60){
        printf("Aprobado");
    }else{
        printf("Reprobado");
    }
}
float Percent(float x,float y){
    return (x*y)/100;
}
float Prom(float a,float b,float c){
    return (a+b+c);
}