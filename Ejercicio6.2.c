#include<stdio.h>
int Input();
void Data(int);

int main(){
    Data(Input());
}
int Input(){
    int x;
    scanf("%d",&x);
    return x;
}
void Data(int x){
    if((x%2==0)&&(x%5==0)){
        printf("Si");
    }
    else{
        printf("No");
    }
}