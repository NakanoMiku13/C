#include<stdio.h>
#include<math.h>
void Show(float r),Dis(float x1,float x2,float y1,float y2,float* dir),Input(float* dir),Ops();
int main(){
    Ops();
}
void Ops(){
    float x1,x2,y1,y2,l1,l2,l3;
    Input(&x1);
    Input(&x2);
    Input(&y1);
    Input(&y2);
    Dis(x1,x2,y1,y2,&l1);
    Input(&x1);
    Input(&x2);
    Input(&y1);
    Input(&y2);
    Dis(x1,x2,y1,y2,&l2);
    Input(&x1);
    Input(&x2);
    Input(&y1);
    Input(&y2);
    Dis(x1,x2,y1,y2,&l3);
    Show(l1+l2+l3);
}
void Dis(float x1,float x2,float y1,float y2,float* dir){
    *dir=sqrt(((pow((x2-x2),2))+(pow((y2-y1),2))));
}
void Input(float* dir){
    float x;
    scanf("%f",&x);
    *dir=x;
}
void Show(float r){
    printf("El resultado es: %f",r);
}