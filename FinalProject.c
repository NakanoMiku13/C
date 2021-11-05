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
    FunctionsList (*ctr)(List* self),(*Add)(List* self,Pair),(*Print)(List* self);
};
FunctionsList List_Print(List* self){
    struct NodeList *move=self->Head;
    int i;
    for(i=0;i<self->Size;i++,move=move->Next){
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
int n,m;
int main(){
    List positionList;
    positionList.ctr=List_ctr;
    positionList.Add=List_Add;
    positionList.Print=List_Print;
    positionList.ctr(&positionList);
    int** Face = (int**)malloc(sizeof(int*)*12);
    n=7;
    m=0;
    int Faces[10][10]={
        {2},
        {0},
        {0},
        {0},
        {0},
        {0},
        {1}
    };
    /*int Faces[10][10]={
        {1,1,1,1,1,1},//0
        {1,0,0,0,1,1},//1
        {1,0,1,0,0,1},//2
        {1,0,1,1,0,1},//3
        {1,0,1,0,0,1},//4
        {1,0,0,1,0,1},//5
        {1,3,1,0,0,1},//6
        {1,1,1,2,1,1}//7
       //0 1 2 3 4 5
    };*/
    for(int i=0;i<n;i++) Face[i] = (int*)malloc(sizeof(int)*12);
    Face[0][0]=2; Face[n-1][0]=1;
    for(int i=0;i<n;i++) printf("%d ",Face[i][0]); printf("\n");
    //SearchExit(6,1,Face,&positionList);
    CheckLeftRight(4,0,Face,&positionList);
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
void Up(int y,int x,int** table,List* lst){
    if(x>=0 && x<n){
        if(table[y][x]==2) return;
        Up(y-1,x,table,lst);
        printf("Up %d\n",table[y][x]);
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
void Down(int y,int x,int** table,List* lst){
    if(x>=0 && x<n){
        if(table[y][x]==2) return;
        Down(y-1,x,table,lst);
        printf("Down %d\n",table[y][x]);
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
    if(x>=0 && x<m){
        if(table[y][x]==2) return;
        Right(y,x+1,table,lst);
        printf("Right %d\n",table[y][x]);
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
    if(x>=0 && x<m){
        if(table[y][x]==2) return;
        Left(y,x-1,table,lst);
        printf("Left %d\n",table[y][x]);
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
    //Left(y,x-1,table,lst);
    //Right(y,x+1,table,lst);
    Up(y+1,x,table,lst);
    Down(y-1,x,table,lst);
    /*Pair cordvisited;
    cordvisited.x=x;
    cordvisited.y=y;
    lst->Add(lst,cordvisited);
    printf("y=%d x=%d v=%d\n",y,x,table[y][x]);
    if(table[y][x]!=2){
        if(table[y][x]==3 || table[y][x]==0){
            if(table[y][x-1]==0){
                if(Left(y,x-1,table)==2){
                    printf("Found Exit\n");
                }else if(Left(y,x-1,table)==1){
                    printf("No way\n");
                }else{

                }
            }
        }else{
            if(table[y][x-1]==1 || table[y][x+1]==1){
                printf("Noway\n");
            }else{
                if(table[y][x+1]==2)
                    printf("Found at %d %d\n",y,x+1);
                if(table[y][x-1]==2)
                    printf("Found at %d %d\n",y,x-1);
            }
        }
    }else{
        if(table[y][x+1]==2)
            printf("Found at %d %d\n",y,x+1);
        if(table[y][x-1]==2)
            printf("Found at %d %d\n",y,x-1);
    }*/
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