#include<stdio.h>
void Input(float*),Menu(float),Show(float),Aux(float*,float*);
float Op1(float,float),Op2(float,float),Op3(float,float),Op4(float,float);
int main(){
    float x;
    Input(&x);
    Menu(x);
}
void Input(float* dir){
    scanf("%f",dir);
}
void Show(float x){
    printf("%f",x);
}
void Aux(float* dir1,float* dir2){
    Input(dir1);
    Input(dir2);
}
void Menu(float x){
    int c=x;
    float a,b;
    switch (c)
    {
        case 1:
            Aux(&a,&b);
            Show(Op1(a,b));
            break;
        case 2:
            Aux(&a,&b);
            Show(Op2(a,b));
            break;
        case 3:
            Aux(&a,&b);
            Show(Op3(a,b));
            break;
        case 4:
            Aux(&a,&b);
            Show(Op4(a,b));
            break;
        default:
            printf("Error");
            break;
    }
}
float Op1(float a,float b){
    return a+b;
}
float Op2(float a,float b){
    return a-b;
}
float Op3(float a,float b){
    return a*b;
}
float Op4(float a,float b){
    return a/b;
}