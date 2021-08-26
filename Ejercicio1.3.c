#include<stdio.h>
void Menu(),Show(int),D1(int*,int),D2(int*,int),D3(int*,int);
int Input(),Recu(int,int);
int main(){
    Menu();
}
void Menu(){
    int x = Input(),z=10,i=10,o=0;
    switch (x)
    {
    case 1: 
        D1(&z,i);
    break;
    case 2: 
        D2(&z,i);
    break;
    case 3:
        D3(&z,i);
    break;
    case 4:
        z=Recu(10,10);
        break;
    default:
    printf("Error\n");
        break;
    }
    Show(z);
}
void Show(int val){
    printf("%d\n",val);
}
int Input(){
    int x;
    scanf("%d",&x);
    return x;
}
int Recu(int x,int i){
    if(i<100){
        i++;
        if(i%5==0){
            x+=i;
        }
        return Recu(x,i);
    }
}
void D1(int* dir,int i){
    while (i<100)
    {
            i++;
            if(i%5==0){
                *dir+=i;
            }
        }
}
void D2(int* dir,int i){
    do{
            i++;
            if(i%5==0){
                *dir+=i;    
            }
        }while (i<100);
}
void D3(int* dir,int i){
        for(;i<=100;){
            i++;
            if(i%5==0){
                *dir+=i;
            }
        }
}
