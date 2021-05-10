#include<stdio.h>
float Input(),Get(int,float);
void Show(float),Menu();
int main(){
    Menu();
}
float Input(){
    float x;
    scanf("%f",&x);
    return x;
}
void Menu(){
    float salary=Input();
    int category = Input(),extra=Input();
    switch (category)
    {
        case 1:
        Show(salary+(Get(extra,30)));
        break;
        case 2:
        Show(salary+(Get(extra,38)));
        break;
        case 3:
        Show(salary+(Get(extra,50)));
        break;
        case 4:
        Show(salary+(Get(extra,70)));
        break;        
        default:
        Show(salary);
            break;
    }
}
void Show(float x){
    printf("%f",x);
}
float Get(int h,float repo){
    if(h>30){
        return 30*repo;
    }else{
        return h*repo;
    }
}