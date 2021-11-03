#include<stdio.h>
#include<stdlib.h>
typedef struct Tree Tree,*Function;
typedef struct List List,*FunctionsList;
typedef struct Pair Pair;
struct Pair{
    int x;
    int y;
};
struct NodeList{
    Pair coordinates;
    struct NodeList *Next;
};
struct List{
    struct NodeList *Head;
    size_t Size;
    FunctionsList (*ctr)(List* self),(*Add)(List* self,Pair),(*Pop)(List* self);
};
FunctionsList List_ctr(List* self){
    self->Head=(struct NodeList*)malloc(sizeof(struct NodeList));
    self->Size=0;
}
FunctionsList List_Add(List* self,Pair coordinates){
    struct NodeList* new = (struct NodeList*)malloc(sizeof(struct NodeList));
    new->coordinates=coordinates;
    if(self->Size==0){
        self->Head=new;
    }else{
        struct NodeList* Move=self->Head;
        int i;
        for(i=0;i<self->Size-1;i++,Move=Move->Next);
        Move->Next=new;
    }
    self->Size++;
}
struct Node{
    int value;
    struct Node* Right,*Left,*Up,*Down;
};
struct Tree{
    struct Node* root;

};
void SearchExit(int,int,int**,List*);
int main(){
    List positionList;
    positionList.ctr=List_ctr;
    positionList.Add=List_Add;
    positionList.ctr(&positionList);
    int** Face = (int**)malloc(sizeof(int*)*12);
    int Faces[10][10]={
        {1,1,1,1,1,1},//0
        {1,0,0,0,1,1},//1
        {1,0,1,0,0,1},//2
        {1,0,1,1,0,1},//3
        {1,0,1,0,0,1},//4
        {1,0,0,1,0,1},//5
        {1,3,1,0,0,1},//6
        {1,1,1,2,1,1}//7
       //0 1 2 3 4 5
    };
    for(int i=0;i<12;i++) Face[i] = (int*)malloc(sizeof(int)*12);
    for(int i=0;i<8;i++) for(int j=0;j<6;j++) Face[i][j]=Faces[i][j];
    SearchExit(6,1,Face,&positionList);
}
int IsVisited(List* list,int x,int y){
    struct NodeList* check=list->Head;
    int i=0;
    for(i=0;i<list->Size;i++,check=check->Next){
        if(check->coordinates.x==x && check->coordinates.y==y) return 1;
    }
    return 0;
}
void SearchExit(int y,int x,int** table,List* list){
    printf("%d %d v: %d\n",y,x,table[y][x]);
    if(table[y][x]!=2){
        if(table[y][x]==3 || table[y][x]==0){
            Pair pair;
            pair.x=x; pair.y=y;
            list->Add(list,pair);
            /*if(table[y+1][x]==0 && table[y][x+1]==0 && table[y][x-1]==0 && table[y-1][x]==0){
                SearchExit(y+1,x,table);
                SearchExit(y,x+1,table);
                SearchExit(y-1,x,table);
                SearchExit(y,x-1,table);
            }else*/
            if((table[y-1][x]==0 && IsVisited(list,x,y-1)==0) && (table[y][x+1]==0 && IsVisited(list,x+1,y)==0)){
                SearchExit(y,x+1,table,list);
                printf("Second half\n");
                SearchExit(y-1,x,table,list);
            }else
            if(table[y+1][x]==0 && table[y][x-1]==0){
                SearchExit(y,x-1,table,list);
                printf("Second half2\n");
                SearchExit(y+1,x,table,list);
            }else
            if(table[y+1][x]==0 && IsVisited(list,x,y+1)==0){
                printf("Down\n");
                SearchExit(y+1,x,table,list);
            }else if(table[y][x+1]==0 && IsVisited(list,x+1,y)==0){
                printf("Right\n");
                SearchExit(y,x+1,table,list);
            }else if(table[y-1][x]==0  ){
                printf("Up\n");
                SearchExit(y-1,x,table,list);
            }else if(table[y][x-1]==0 && IsVisited(list,x-1,y)==0){
                printf("Left\n");
                SearchExit(y,x-1,table,list);
            }else printf("Noway\n");
        }
    }else{
        printf("Result: %d %d\n",y,x);
    }
}