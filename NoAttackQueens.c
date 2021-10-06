#include<stdio.h>
#include <stdlib.h>
int Input(),**GenTable(int,int),Line(int,int,int,int,int**),Diagonal(int,int,int,int,int**);
void FillTable(int,int,int**),NoAttackQueens(int,int,int**),SetQueens(int,int,int,int,int**),SetFirstQueen(int,int,int**);
size_t Queens=0;
int main(){
    printf("Type the rows, and the columns of the table:\n");
    int n=Input(),m=Input(),**table=GenTable(n,m);
    FillTable(n,m,table);
    SetFirstQueen(n,m,table);
    NoAttackQueens(n,n,table);
    int i=0,j=0;
    for(;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }
    printf("It exists %d queens.\n",Queens);
}
void SetFirstQueen(int n,int m,int** table){
    printf("Do you want to set the first queen? or I do it?\n1) I want\n2) You choose\nType it down:\n");
    int x=Input();
    if(x==1){
        printf("Nice decision, well, choose from 1 to %d, to the rows and from 1 to %d to the columns:\n",n,m);
        int r=Input(),c=Input();
        r--;
        c--;
        table[c][r]=2;
    }else{
        printf("Well, I choose...\n");
        int r=random()%n,c=random()%m;
        printf("I want it at (%d,%d)\n",c+1,r+1);
        table[c][r]=2;
    }
    Queens++;
}
void NoAttackQueens(int n,int m,int** table){
    int i=0,j=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            SetQueens(i,j,n,m,table);
        }
    }
}
void SetQueens(int y,int x,int n,int m,int** table){
    if(Line(y,x,n,m,table)==1  && Diagonal(y,x,n,m,table)==1 && table[y][x]!=2){
        table[y][x]=2;
        Queens++;
    }
}
int Input(){
    int x;
    scanf("%d",&x);
    return x;
}
int** GenTable(int n,int m){
    int** table = (int**)malloc(sizeof(int*)*n+3),i=0;
    for(;i<n;i++){
        table[i] = (int*)malloc(sizeof(int)*m+3);
    }
    return table;
}
void FillTable(int n,int m,int** table){
    int i=0,j=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            table[i][j]=0;
        }
    }
}
int Diagonal(int y,int x,int n,int m,int** table){
    int i=y-1,j=x-1;
    //Checking up left diagonal
    while(i>=0 && j>=0){
        if(table[i][j]==2){
            //Found a queen
            return -1;
        }
        i--;
        j--;
    }
    i=y-1,j=x+1;
    //Checking up right diagonal
    while(i>=0 && j<=m){
        if(table[i][j]==2){
            //Found a queen
            return -1;
        }
        i--;
        j++;
    }
    i=y+1,j=x-1;
    //Checking down left diagonal
    while(i<n && j>=0){
        if(table[i][j]==2){
            //Found a queen
            return -1;
        }
        i++;
        j--;
    }
    i=y+1,j=x+1;
    //Checking down right diagonal
    while(i<n && j<m){
        if(table[i][j]==2){
            //Found a queen
            return -1;
        }
        i++;
        j++;
    }
    //No queen found
    return 1;
}
int Line(int y,int x,int n,int m,int** table){
    //Cheking rows
    int i=x-1;
    while(i>=0){
        if(table[y][i]==2){
            //Found a queen
            return -1;
        }
        i--;
    }
    i=x+1;
    while(i<n){
        if(table[y][i]==2){
            //Found a queen
            return -1;
        }
        i++;
    }
    //Checking cols
    int j=y-1;
    while(j>=0){
        if(table[j][x]==2){
            //Found a queen
            return -1;
        }
        j--;
    }
    j=y+1;
    while(j<m){
        if(table[j][x]==2){
            //Found a queen
            return -1;
        }
        j++;
    }
    //On the line there is no queen
    return 1;
}
int Search(int x,int y,int n,int m){
    int i=x,j=y;
    //Up
    for(;i<n;i++){

    }
}