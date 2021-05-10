#include<stdio.h>
void Input(char*),Menu(char,float),Show(float),Aux(float*);
float Data(float,float);
int main(){
    char a;
    float x;
    Input(&a);
    Aux(&x);
    Menu(a,x);
}
void Aux(float* dir){
    scanf("%f",dir);
}
void Input(char* dir){
    scanf("%c",dir);
}
void Show(float x){
    printf("%f",x);
}
char ToUpper(char data){
    if(data=='a'){
        return 'A';
    }else if(data=='b'){
        return 'B';
    }else if(data=='r'){
        return 'R';
    }else{
        return data;
    }
}
void Menu(char x,float d){
    x=ToUpper(x);
    switch (x)
    {
        case 'A':
        Show(Data(d,0.20));
        break;
        case 'R':
        Show(Data(d,0.30));
        break;
        case 'B':
        Show(d);
        break;
        default:
        printf("ERROR");
        break;
    }
}
float Data(float x,float y){
    return (x-(x*y));
}