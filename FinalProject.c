#include<stdio.h>
#include<stdlib.h>
typedef struct Tree Tree,*FunctionsTree;
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
    FunctionsList (*ctr)(List* self),(*Add)(List* self,Pair),(*Print)(List* self),(*PopLast)(List* self);
};
FunctionsList List_Print(List* self){
    struct NodeList *move=self->Head;
    int i;
    for(i=0;i<self->Size && move!=NULL;i++,move=move->Next){
        printf("%d %d\n",move->coordinates.y,move->coordinates.x);
    }
}
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
FunctionsList List_Pop(List* self){
    if(self->Size>0){
        int i=0;
        struct NodeList* Move = self->Head;
        for(i=0;i<self->Size-1;i++,Move=Move->Next);
        free(Move);
        self->Size--;
    }
}
struct Node{
    int value;
    Pair Coordinates;
    struct Node* Right,*Left,*Up,*Down;
};
struct Tree{
    struct Node* root;
    FunctionsTree (*ctr)(Tree* self),(*Add)(Tree* self,int position,struct NodeList* node,int Value);
};
FunctionsTree Tree_ctr(Tree* self){
    self->root=(struct Node*)malloc(sizeof(struct Node));
}
FunctionsTree Tree_Add(Tree* self,int position,struct NodeList* node,int Value){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->value=Value;
    new->Coordinates=node->coordinates;
    if(self->root=NULL){
        self->root=new;
    }else{
        switch(position){
            //case 1: //Right 
                
        }
    }
}
void SearchExit(int,int,int**,List*);
void CheckLeftRight(int,int,int**,List*);
int n=8,m=6;
int main(){
    List positionList;
    positionList.ctr=List_ctr;
    positionList.Add=List_Add;
    positionList.Print=List_Print;
    positionList.PopLast=List_Pop;
    positionList.ctr(&positionList);
    int** Face = (int**)malloc(sizeof(int*)*n+1);
    /*int Faces[10][10]={
        {2},
        {0},
        {0},
        {0},
        {0},
        {0},
        {1}
    };*/
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
    for(int i=0;i<n;i++) Face[i] = (int*)malloc(sizeof(int)*m+1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            Face[i][j] = Faces[i][j];
        }
    }
    //SearchExit(6,1,Face,&positionList);
    CheckLeftRight(6,3,Face,&positionList);
    positionList.Print(&positionList);
}
int IsVisited(List* list,int x,int y){
    struct NodeList* check=list->Head;
    int i=0;
    for(i=0;i<list->Size;i++,check=check->Next){
        if(check->coordinates.x==x && check->coordinates.y==y) return 1;
    }
    return 0;
}
void Down(int y,int x,int** table,List* lst){
    if(y<n && table[y][x]!=1){
        if(table[y][x]==2) return;
        if((table[y][x]==0 && IsVisited(lst,x,y)==0) || table[y][x]==3){
            Down(y+1,x,table,lst);
        }
        if(table[y][x]==0){
            Pair cordvisited;
            cordvisited.x=x;
            cordvisited.y=y;
            lst->Add(lst,cordvisited);
        }else{
            return;
        }
    }else{
        return;
    }
}
void Up(int y,int x,int** table,List* lst){
    if(y>0 && table[y][x]!=1){
        if(table[y][x]==2) return;
        if((table[y][x]==0 && IsVisited(lst,x,y)==0) || table[y][x]==3){
            Up(y-1,x,table,lst);
        }
        if(table[y][x]==0){
            Pair cordvisited;
            cordvisited.x=x;
            cordvisited.y=y;
            lst->Add(lst,cordvisited);
        }else{
            return;
        }
    }else{
        return;
    }
}
void Right(int y,int x,int** table,List* lst){
    if(x<m){
        if(table[y][x]==2) return;
        if((table[y][x]==0 && IsVisited(lst,x,y)==0) || table[y][x]==3){
            Right(y,x+1,table,lst);
        }
        if(table[y][x]==0){
            Pair cordvisited;
            cordvisited.x=x;
            cordvisited.y=y;
            lst->Add(lst,cordvisited);
        }else{
            return;
        }
    }else{
        return;
    }
}
void Left(int y,int x,int** table,List* lst){
    if(x>0){
        if(table[y][x]==2) return;
        if((table[y][x]==0 && IsVisited(lst,x,y)==0) || table[y][x]==3){
            Left(y,x-1,table,lst);
        }
        if(table[y][x]==0){
            Pair cordvisited;
            cordvisited.x=x;
            cordvisited.y=y;
            lst->Add(lst,cordvisited);
        }else{
            return;
        }
    }else{
        return;
    }
}
void CheckLeftRight(int y,int x,int** table,List* lst){
    Left(y,x-1,table,lst);
    printf("Left checked\n");
    lst->Print(lst);
    Right(y,x+1,table,lst);
    printf("Right checked\n");
    lst->Print(lst);
    Up(y-1,x,table,lst);
    printf("Up checked\n");
    lst->Print(lst);
    Down(y+1,x,table,lst);
    printf("Down checked\n");
    lst->Print(lst);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }
}
void SearchExit(int y,int x,int** table,List* list){
    
}