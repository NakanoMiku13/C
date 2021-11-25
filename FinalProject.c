#include<stdio.h>
#include<stdlib.h>
#define n 8
typedef struct Tree Tree,*FunctionsTree;
typedef struct List List,*FunctionsList;
typedef struct Table Table,*FunctionTable;
typedef struct ListOfTrees ListOfTrees,*FunctionsListOfTrees;
typedef struct Pair Pair;
struct Pair{
    int x;
    int y;
};
struct Node{
    int Value;
    struct Node *Next,*Prev,*Top,*Bottom,*Front,*Back;
};
struct NodeList{
    Pair coordinates;
    struct NodeList *Next;
};
struct NodeListTree{
    Tree* tree;
    struct NodeListTree* Next;
};
struct ListOfTrees{
    struct NodeListTree* Head;
    size_t size;
    FunctionsListOfTrees (*ctr)(ListOfTrees* self),
    (*Add)(ListOfTrees* self,Tree* tree),
    (*PrintList)(ListOfTrees* self);
};
struct NodeTree{
    int value;
    Pair Coordinates;
    struct NodeTree* Right,*Left,*Up,*Down;
};
struct List{
    struct NodeList *Head;
    size_t Size;
    FunctionsList (*ctr)(List* self),
    (*Add)(List* self,Pair),
    (*Print)(List* self),
    (*PopLast)(List* self),
    (*Clear)(List* self),
    (*OrderByHigher)(List* self,char coordinate),
    (*OrderByLower)(List* self,char coordinate),
    (*DeleteRepeated)(List* self);
};
struct Table{
    struct Node *Head;
    size_t _size,_cols,_rows,_ccols,_crows,_cback,_back;
    FunctionTable (*Ctr)(Table *),
    (*Add)(Table *,int),
    (*Print)(Table *),
    (*SumFace)(Table*,int),
    (*FrontFace)(Table* From,int** To),
    (*BackFace)(Table* From,int** To),
    (*RightFace)(Table* From,int** To),
    (*LeftFace)(Table* From,int** To),
    (*TopFace)(Table* From,int** To),
    (*BottomFace)(Table* From,int** To);
};
struct Tree{
    struct NodeTree* root;
    char* Face;
    size_t size;
    FunctionsTree (*ctr)(Tree* self),
    (*AddList)(Tree* self,List* pstlist,Pair Initial,char* Face),
    (*PrintTree)(Tree* self);
};
void SearchExit(int x,int y,int** table,List* visited,List* pending,Pair* exit),
Initialize(List*,List*,Table*,ListOfTrees*),
InitializeTree(Tree* self),
SetFaces(int x,int y,int Fn,Table* table,List* visited,List* pending,Pair* exit,ListOfTrees* dTL);
int** CreateFace(Table* table,int face);
FunctionsList List_ctr(List* self),
List_Add(List* self,Pair coordinates),
List_Pop(List* self),List_Print(List* self),
List_Clear(List* self),
List_OrderByHigher(List* self,char coordinate),
List_OrderByLower(List* self,char coordinate),
List_DeleteRepeated(List* self);
FunctionTable Table_Ctr(Table *),
Table_Add(Table *,int),
Table_Print(Table *),
Table_FrontFace(Table*,int**),
Table_BackFace(Table*,int**),
Table_RightFace(Table*,int**),
Table_LeftFace(Table*,int**),
Table_TopFace(Table*,int**),
Table_BottomFace(Table*,int**);
FunctionsTree Tree_ctr(Tree* self),
Tree_AddList(Tree* self,List* pstlist,Pair Initial,char* Face),
Tree_Print(Tree* self);
FunctionsListOfTrees LOT_ctr(ListOfTrees* self),
LOT_Print(ListOfTrees* self),
LOT_Add(ListOfTrees* self,Tree* new);
int main(){
    List positionList,Pending;
    Table table;
    Pair ExitCoordinates;
    ListOfTrees decisionTrees;
    Initialize(&positionList,&Pending,&table,&decisionTrees);
    SetFaces(1,6,1,&table,&positionList,&Pending,&ExitCoordinates,&decisionTrees);
    printf("x=%d y=%d",ExitCoordinates.x,ExitCoordinates.y);
}
void PrintFace(int** table){
    int i=0,j=0;
    for(i=0;i<n;i++){ 
        for(int j=0;j<n;j++){
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
void SetFaces(int x,int y,int Fn,Table* table,List* pslst,List* pndlst,Pair* Exit,ListOfTrees* dTL){
    int** Face;
    pslst->Clear(pslst);
    pndlst->Clear(pndlst);
    Face=CreateFace(table,Fn);
    Face[y][x]=3;
    SearchExit(y,x,Face,pslst,pndlst,Exit);
    Pair initial;
    initial.x=x;
    initial.y=y;
    pslst->OrderByLower(pslst,'X');
    Tree dT;
    InitializeTree(&dT);
    printf("Before Create a Tree\n");
    pslst->Print(pslst);
    printf("Exit: x %d y %d\n",Exit->x,Exit->y);
    dT.AddList(&dT,pslst,initial,"");
    printf("After Create a Tree\n\n");
    dTL->Add(dTL,&dT);
    if(Face[Exit->y][Exit->x]==5) printf("Exit Found\n");
    else{
        //Right Face
        if(Exit->x<=n && (Face[Exit->y][Exit->x]==2 || Face[Exit->y][Exit->x+1]==2) && Fn==1){
            int x=0;
            int y=Exit->y;
            Exit->x=0; Exit->y=0;
            SetFaces(x,y,3,table,pslst,pndlst,Exit,dTL);
        //Back Face
        }else if(Exit->x<=n && (Face[Exit->y][Exit->x]==2 || Face[Exit->y][Exit->x+1]==2) && Fn==3){
            int x=Exit->x;
            int y=Exit->y;
            Exit->x=0; Exit->y=0;
            SetFaces(x,y,2,table,pslst,pndlst,Exit,dTL);
        //Bottom Face
        }else if(Exit->y<=n && (Face[Exit->y][Exit->x]==2 || Face[Exit->y+1][Exit->x]==2) && Fn==2){
            int x=Exit->y;
            int y=Exit->x;
            Exit->x=0; Exit->y=0;
            SetFaces(x,y,6,table,pslst,pndlst,Exit,dTL);
        //Left Face
        }else if(Exit->y>=0 && (Face[Exit->y][Exit->x]==2 || Face[Exit->y-1][Exit->x]==2) && Fn>=6){
            int x=Exit->x;
            int y=n-1;
            Exit->x=0; Exit->y=0;
            SetFaces(x,y,4,table,pslst,pndlst,Exit,dTL);
        }else if(Fn==4){
            int x=Exit->x;
            int y=Exit->y;
            Exit->x=0; Exit->y=0;
            SetFaces(x,y,5,table,pslst,pndlst,Exit,dTL);
        }
    }
}
int IsVisited(List* list,int x,int y){
    struct NodeList* check=list->Head;
    int i=0;
    for(i=0;i<list->Size;i++,check=check->Next){
        if(check->coordinates.x==x && check->coordinates.y==y) return 1;
    }
    return 0;
}
int** CreateFace(Table* s,int face){
    int** Face = (int**)malloc(sizeof(int*)*n+1),i,j;
    for(i=0;i<n;i++) Face[i]=(int*)malloc(sizeof(int)*n+1);
    switch(face){
        //front face
        case 1:
            s->FrontFace(s,Face);
            break;
        //back face
        case 2:
            s->BackFace(s,Face);
            break;
        //right face
        case 3:
            s->RightFace(s,Face);
            break;
        //left face
        case 4:
            s->LeftFace(s,Face);
            break;
        //top face
        case 5:
            s->TopFace(s,Face);
            break;
        //bottom face
        default:
            s->BottomFace(s,Face);
            break;
    }
    return Face;
}
struct NodeTree* FoundRoot(struct NodeList* lst, struct NodeTree* root){
    if(root->Up==NULL || root->Coordinates.y==lst->coordinates.y) return root;
    else if(root!=NULL && root->Coordinates.y!=lst->coordinates.y && root->Coordinates.x!=lst->coordinates.x) return FoundRoot(lst,root->Up);
    else if(root!=NULL && root->Coordinates.y!=lst->coordinates.y && root->Coordinates.x!=lst->coordinates.x) return FoundRoot(lst,root->Down);
}
void AsignTable(Table* s){
    int i,j,k;
    s->_cols=s->_rows=s->_back=n;
    int fill[10][10][10]={
        {{1,1,1,1,1,1,1,1},
        {1,0,1,0,1,0,0,2},
        {1,0,0,0,0,0,1,1},
        {1,0,1,0,1,0,1,1},
        {1,0,0,0,0,0,0,1},
        {1,0,1,1,1,0,1,1},
        {1,3,1,0,0,0,0,1},
        {1,1,1,1,1,1,1,1}},

        {{2,0,1,1,0,0,0,1},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {1,0,0,0,1,0,0,1}},
        

        {{1,0,1,0,0,1,0,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {0,1,1,1,1,1,1,1},
        {0,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,0},
        {1,0,1,0,0,0,0,1}},
        
        {{1,0,1,0,0,0,1,1},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {1,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {1,1,1,1,1,1,1,0},
        {1,0,1,1,0,1,1,1}},
        
        {{1,0,0,0,0,0,5,1},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,1},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,1},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,1},
        {2,0,1,0,0,0,0,1}},

        {{1,0,0,0,0,1,0,1},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {1,1,1,1,1,1,1,1},
        {0,1,1,1,1,1,1,0},
        {1,1,1,0,1,0,1,1}},

        {{1,0,1,0,0,0,1,1},
        {0,1,1,1,1,1,1,0},
        {1,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,1},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {1,0,0,0,0,0,0,1}},

        {{1,1,1,1,1,1,1,1},
        {1,1,0,0,1,0,0,1},
        {1,0,1,0,0,0,0,1},
        {1,0,0,0,1,1,0,1},
        {1,1,0,1,0,0,0,1},
        {1,0,0,0,0,1,0,1},
        {1,0,1,0,1,0,0,2},
        {1,2,1,1,1,1,1,1}}

    };
    for(i=0;i<n;i++) for(j=0;j<n;j++) for(k=0;k<n;k++) s->Add(s,fill[i][j][k]);
}
void InitializeList(List* s){
    s->ctr=List_ctr;
    s->Add=List_Add;
    s->Print=List_Print;
    s->PopLast=List_Pop;
    s->Clear=List_Clear;
    s->OrderByHigher=List_OrderByHigher;
    s->OrderByLower=List_OrderByLower;
    s->DeleteRepeated=List_DeleteRepeated;
    s->ctr(s);
}
void InitializeListOfTrees(ListOfTrees* self){
    self->ctr=LOT_ctr;
    self->Add=LOT_Add;
    self->PrintList=LOT_Print;
    self->ctr(self);
}
void InitializeTable(Table* s){
    s->Ctr=Table_Ctr;
    s->Add=Table_Add;
    s->Print=Table_Print;
    s->FrontFace=Table_FrontFace;
    s->BackFace=Table_BackFace;
    s->RightFace=Table_RightFace;
    s->LeftFace=Table_LeftFace;
    s->TopFace=Table_TopFace;
    s->BottomFace=Table_BottomFace;
    s->Ctr(s);
}
void InitializeTree(Tree* s){
    s->ctr=Tree_ctr;
    s->AddList=Tree_AddList;
    s->PrintTree=Tree_Print;
    s->ctr(s);
}
void Initialize(List* positionList, List* PendingPositionList,Table* table,ListOfTrees* LOT){
    InitializeList(positionList);
    InitializeList(PendingPositionList);
    InitializeTable(table);
    AsignTable(table);
    InitializeListOfTrees(LOT);
}
void CheckLeftRight(int x,int y,int** table,List* pnd,List* visited,Pair* exit){
    Pair pending;
    if(table[y][x+1]==0 && table[y][x-1]==0 && IsVisited(visited,x+1,y)==0  && IsVisited(visited,x-1,y)==0){
        pending.x=x+1; pending.y=y;
        pnd->Add(pnd,pending);
        pending.x=x-1; pending.y=y;
        pnd->Add(pnd,pending);
    }else if(table[y][x+1]==0 && IsVisited(visited,x+1,y)==0){
        pending.x=x+1; pending.y=y;
        pnd->Add(pnd,pending);
    }else if(table[y][x-1]==0 && IsVisited(visited,x-1,y)==0){
        pending.x=x-1; pending.y=y;
        pnd->Add(pnd,pending);
    }else{
        if(table[y][x+1]==2 || table[y][x+1]==5){
            exit->x=x+1;
            exit->y=y;
        }else if(table[y][x-1]==2 || table[y][x-1]==5){
            exit->x=x-1;
            exit->y=y;
        }else{
            return;
        }
    }
}
void Down(int y,int x,int** table,List* lst,List* pnd,Pair* exit){
    if(y<n && table[y][x]!=1){
        if(table[y][x]==5){
            exit->x=x;
            exit->y=y;
            return;
        }
        if(table[y][x]==2){
            exit->x=x;
            exit->y=y;
            return;
        }
        if((y+1)<n && table[y+1][x]==2){
            exit->x=x;
            exit->y=y+1;
            return;
        }
        if((table[y][x]==0 && IsVisited(lst,x,y)==0) || table[y][x]==3 && y+1<n){
            Down(y+1,x,table,lst,pnd,exit);
        }
        if(table[y][x]==0){
            CheckLeftRight(x,y,table,pnd,lst,exit);
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
void Up(int y,int x,int** table,List* lst,List* pnd,Pair* exit){
    if(y>0 && table[y][x]!=1){
        if(table[y][x]==5){
            exit->x=x;
            exit->y=y;
            return;
        }
        if(table[y][x]==2){
            exit->x=x;
            exit->y=y;
            return;
        }
        if(table[y-1][x]==2){
            exit->x=x;
            exit->y=y-1;
            return;
        }
        if((table[y][x]==0 && IsVisited(lst,x,y)==0) || table[y][x]==3){
            Up(y-1,x,table,lst,pnd,exit);
        }
        if(table[y][x]==0){
            CheckLeftRight(x,y,table,pnd,lst,exit);
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
void CheckUpDown(int x,int y,List* pnd,int** table, List* visited,Pair* exit){
    Pair pending;
    if(table[y+1][x]==0 && table[y-1][x]==0 && IsVisited(visited,x,y-1)==0 && IsVisited(visited,x,y+1)==0){
        pending.x=x; pending.y=y-1;
        pnd->Add(pnd,pending);
        pending.x=x; pending.y=y+1;
        pnd->Add(pnd,pending);
    }else if(table[y-1][x]==0 && IsVisited(visited,x,y-1)==0){
        pending.x=x; pending.y=y-1;
        pnd->Add(pnd,pending);
    }else if(table[y+1][x]==0 && IsVisited(visited,x,y+1)==0){
        pending.x=x; pending.y=y+1;
        pnd->Add(pnd,pending);
    }else{
        if(table[y-1][x]==2 || table[y-1][x]==5){
            exit->x=x;
            exit->y=y-1;
        }else if(table[y+1][x]==2 || table[y+1][x]==5){
            exit->x=x;
            exit->y=y+1;
        }else{
            return;
        }
    }
}
void Right(int y,int x,int** table,List* lst,List* pnd,Pair* exit){
    if(x<n){
        if(table[y][x]==5){
            exit->x=x;
            exit->y=y;
            return;
        }
        if(table[y][x+1]==2){
            exit->x=x+1;
            exit->y=y;
            return;
        }else if(table[y][x]==2){
            exit->x=x;
            exit->y=y;
            return;
        }
        if((table[y][x]==0 && IsVisited(lst,x,y)==0) || table[y][x]==3){
            Right(y,x+1,table,lst,pnd,exit);
        }
        if(table[y][x]==0){
            CheckUpDown(x,y,pnd,table,lst,exit);
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
void Left(int y,int x,int** table,List* lst,List* pnd,Pair* exit){
    if(x>0){
        if(table[y][x]==5){
            exit->x=x;
            exit->y=y;
            return;
        }
        if(table[y][x-1]==2){
            exit->x=x-1;
            exit->y=y;
            return;
        }else if(table[y][x]==2){
            exit->x=x;
            exit->y=y;
            return;
        }
        if((table[y][x]==0 && IsVisited(lst,x,y)==0) || table[y][x]==3){
            Left(y,x-1,table,lst,pnd,exit);
        }
        if(table[y][x]==0){
            CheckUpDown(x,y,pnd,table,lst,exit);
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
void SearchExit(int y,int x,int** table,List* lst,List* pnd,Pair* exit){
    //Checking if we have a pending position or coordinate
    if(exit==NULL || (exit->x==0 && exit->y==0)){
        if(y==0 && table[y+1][x]==0 && (table[y][x]==2 || table[y][x]==3) ) y++;
        else if(y<=n && table[y-1][x]==0 && (table[y][x]==2 || table[y][x]==3) ) y--;
        if(x==0 && table[y][x+1]==0 && (table[y][x]==2 || table[y][x]==3)) x++;
        else if(x==n && table[y][x-1]==0 && (table[y][x]==2 || table[y][x]==3) ) x--;
        if(table[y][x]==5 || table[y][x]==2){
            exit->x=x; exit->y=y;
            return;
        }
        if(pnd->Size>0){
            struct NodeList* move = pnd->Head;
            int i=0;
            for(i=0;i<pnd->Size-1;i++,move=move->Next);
            int x1=move->coordinates.x,y1=move->coordinates.y;
            lst->Add(lst,move->coordinates);
            pnd->PopLast(pnd);
            Left(y1,x1-1,table,lst,pnd,exit);
            Right(y1,x1+1,table,lst,pnd,exit);
            Up(y1-1,x1,table,lst,pnd,exit);
            Down(y1+1,x1,table,lst,pnd,exit);
        }else if(table[y][x+1]!=1 && table[y][x-1]!=1 && IsVisited(lst,x,y)==0){
            //Check Right and left
            Left(y,x-1,table,lst,pnd,exit);
            Right(y,x+1,table,lst,pnd,exit);
        }else if(table[y+1][x]!=1 && table[y-1][x]!=1 && IsVisited(lst,x,y)==0){
            //Check Up and Down
            Up(y-1,x,table,lst,pnd,exit);
            Down(y+1,x,table,lst,pnd,exit);
        }else{
            Left(y,x-1,table,lst,pnd,exit);
            Right(y,x+1,table,lst,pnd,exit);
            Up(y-1,x,table,lst,pnd,exit);
            Down(y+1,x,table,lst,pnd,exit);
        }
        if(pnd->Size>0){
            SearchExit(y,x,table,lst,pnd,exit);
        }
    }
}
void SwapPairElements(Pair* from,Pair* to){
    Pair tmp;
    tmp.x=from->x;
    tmp.y=from->y;
    from->x=to->x;
    from->y=to->y;
    to->x=tmp.x;
    to->y=tmp.y;
}
void SetLeafs(struct NodeTree* root,struct NodeList* head){
    if(head->Next==NULL || head==NULL && root!=NULL) return;
    struct NodeTree* new = (struct NodeTree*) malloc(sizeof(struct NodeTree));
    new->Coordinates.x=head->coordinates.x;
    new->Coordinates.y=head->coordinates.y;
    if(root->Coordinates.x<=head->coordinates.x){
        if(root->Right==NULL){
            if(root->Coordinates.x+1==head->coordinates.x){
                new->Left=root;
                root->Right=new;
                root=FoundRoot(head->Next,root);
                SetLeafs(root,head->Next);
            }else{
                if(root->Coordinates.x==head->coordinates.x && root->Coordinates.y>head->coordinates.y){
                    new->Up=root;
                    root->Down=new;
                }else{
                    new->Down=root;
                    root->Up=new;
                }
            }
        }else{
            SetLeafs(root->Right,head);
        }
    }else{
        if(root->Left==NULL){
            if(root->Coordinates.x-1==head->coordinates.x){
                new->Right=root;
                root->Left=new;
                root=FoundRoot(head->Next,root);
                SetLeafs(root,head->Next);
            }else{
                if(root->Coordinates.x==head->coordinates.x && root->Coordinates.y>head->coordinates.y){
                    new->Up=root;
                    root->Down=new;
                }else{
                    new->Down=root;
                    root->Up=new;
                }
            }
        }else{
            SetLeafs(root->Left,head);
        }
    }
}
void AddTreeNodes(struct NodeList* head,struct NodeTree* root,int c,int i){
    if(head!=NULL){
        printf("ii: %d\n",i);
        struct NodeTree* new= (struct NodeTree*)malloc(sizeof(struct NodeTree));
        if(i!=0){
            printf("Head:\nX: %d Y: %d\nRoot:\nX: %d Y: %d\n",head->coordinates.x,head->coordinates.y,root->Coordinates.x,root->Coordinates.y);
            root=FoundRoot(head,root);
            printf("Roots: x %d y: %d\n",root->Coordinates.x,root->Coordinates.y);
            //Aqui
            SetLeafs(root,head);
            AddTreeNodes(head->Next,root,c+1,i+1);
        }else if(head->coordinates.y<=root->Coordinates.y && (head->coordinates.x==root->Coordinates.x)){
            if(c==0 && head->coordinates.y+1==root->Coordinates.y-1 && i==0){
                new->Coordinates.x=head->coordinates.x;
                new->Coordinates.y=head->coordinates.y+1;
                new->Down=root;
                root->Up=new;
                struct NodeTree* tmp=(struct NodeTree*)malloc(sizeof(struct NodeTree));
                tmp->Coordinates.x=head->coordinates.x;
                tmp->Coordinates.y=head->coordinates.y;
                tmp->Down=root->Up;
                root->Up->Up=tmp;
                if(head->Next!=NULL)
                AddTreeNodes(head->Next,root->Up->Up,c+1,i);
            }else{
                if(root->Coordinates.x==head->coordinates.x && head->Next!=NULL){
                    new->Coordinates.x=head->Next->coordinates.x;
                    new->Coordinates.y=head->Next->coordinates.y;
                    new->Down=root;
                    root->Up=new;
                    if(head->Next!=NULL)
                    AddTreeNodes(head->Next,root->Up,c+1,i);
                }
            }
        }else if(head->coordinates.y>root->Coordinates.y && (head->coordinates.x==root->Coordinates.x)){
            if(c==0 && head->coordinates.y-1==root->Coordinates.y+1){
                new->Coordinates.x=head->coordinates.x;
                new->Coordinates.y=head->coordinates.y-1;
                new->Up=root;
                root->Down=new;
                new = (struct NodeTree*)malloc(sizeof(struct NodeTree));
                new->Coordinates.x=head->coordinates.x;
                new->Coordinates.y=head->coordinates.y;
                new->Up=root->Down;
                root->Down->Down=new;
                AddTreeNodes(head->Next,root->Up,c+1,i);
            }else{
                if(root->Coordinates.x==head->coordinates.x && head->Next!=NULL){
                    new->Coordinates.x=head->Next->coordinates.x;
                    new->Coordinates.y=head->Next->coordinates.y;
                    new->Up=root;
                    root->Down=new;
                    AddTreeNodes(head->Next,root->Up,c+1,i);
                }
            }
        }
    }
}
void PrintTree(struct NodeTree* root){
    if(root!=NULL){
        printf("\nRoot:\nX: %d Y: %d\n\n",root->Coordinates.x,root->Coordinates.y);
        PrintTree(root->Right);
        PrintTree(root->Left);
        PrintTree(root->Up);
        PrintTree(root->Down);
    }
}
List SegmentationList(int number,char coordinate,List* initialList){
    List tmpList;
    int i=0;
    struct NodeList* move = initialList->Head;
    InitializeList(&tmpList);
    if(coordinate=='x' || coordinate=='X'){
        for(i=0;i<initialList->Size && move->coordinates.x!=number;i++,move=move->Next);
        while(i<initialList->Size && number==move->coordinates.x){
            tmpList.Add(&tmpList,move->coordinates);
            move=move->Next;
            i++;
        }
    }else if(coordinate=='y' || coordinate=='Y'){
        for(i=0;i<initialList->Size && move->coordinates.y!=number;i++,move=move->Next);
        while(i<initialList->Size && number==move->coordinates.y){
            tmpList.Add(&tmpList,move->coordinates);
            move=move->Next;
            i++;
        }
    }
    if(tmpList.Size==0) return SegmentationList(number+1,coordinate,initialList);
    move=NULL;
    return tmpList;
}
FunctionsList List_Print(List* self){
    struct NodeList *move=self->Head;
    int i;
    if(self->Size>0)
    for(i=0;i<self->Size && move!=NULL;i++,move=move->Next){
        printf("Y:%d X:%d\n",move->coordinates.y,move->coordinates.x);
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
        Move=NULL;
        self->Size--;
    }
}
FunctionsList List_Clear(List* self){
    if(self->Size>0){
        self->PopLast(self);
        List_Clear(self);
    }else{
        self->ctr(self);
    }
}
FunctionsList List_SearchElements(List* self,char coordinate,int number,List* tmpList){
    int i=0;
    struct NodeList* move = self->Head;
    tmpList->Clear(tmpList);
    if(coordinate=='x' || coordinate=='X'){
        for(i=0;i<self->Size;i++,move=move->Next){
            if(move->coordinates.x==number) tmpList->Add(tmpList,move->coordinates);
        }
    }else{
        for(i=0;i<self->Size;i++,move=move->Next){
            if(move->coordinates.x==number) tmpList->Add(tmpList,move->coordinates);
        }
    }
}
FunctionsList List_OrderByHigher(List* self,char coordinate){
    int i,j;
    struct NodeList* move=self->Head,*move2=self->Head;
    if(coordinate=='x' || coordinate=='X'){
        for(i=0;i<self->Size-1;i++,move=move->Next){
            move2=move;
            for(j=i;j<self->Size;j++,move2=move2->Next){
                if(move->coordinates.x<move2->coordinates.x) SwapPairElements(&move->coordinates,&move2->coordinates);
            }
        }
    }else{
        for(i=0;i<self->Size-1;i++,move=move->Next){
            move2=move;
            for(j=i;j<self->Size;j++,move2=move2->Next){
                if(move->coordinates.y<move2->coordinates.y) SwapPairElements(&move->coordinates,&move2->coordinates);
            }
        }
    }
    move=move2=NULL;
}
FunctionsList List_OrderByLower(List* self,char coordinate){
    int i,j;
    struct NodeList* move=self->Head,*move2=self->Head;
    if(coordinate=='x' || coordinate=='X'){
        for(i=0;i<self->Size-1;i++,move=move->Next){
            move2=move;
            for(j=i;j<self->Size;j++,move2=move2->Next){
                if(move->coordinates.x>move2->coordinates.x) SwapPairElements(&move->coordinates,&move2->coordinates);
            }
        }
    }else{
        for(i=0;i<self->Size-1;i++,move=move->Next){
            move2=move;
            for(j=i;j<self->Size;j++,move2=move2->Next){
                if(move->coordinates.y>move2->coordinates.y) SwapPairElements(&move->coordinates,&move2->coordinates);
            }
        }
    }
    move=move2=NULL;
}
FunctionsList List_DeleteRepeated(List* self){
    struct NodeList* move=self->Head,*Last;
    List new;
    InitializeList(&new);
    int c=0;
    for(int i=0;i<self->Size-1;i++,move=move->Next){
        if(move->coordinates.x==move->Next->coordinates.x && move->coordinates.y!=move->Next->coordinates.y){
            new.Add(&new,move->coordinates);
        }else if(move->coordinates.x!=move->Next->coordinates.x && move->coordinates.y==move->Next->coordinates.y){
            new.Add(&new,move->coordinates);
        }
    }
    new.Add(&new,move->coordinates);
    self->Head=new.Head;
}
FunctionTable Table_Ctr(Table *Self){
    Self->Head=(struct Node*)malloc(sizeof(struct Node));
    Self->_size=Self->_cols=Self->_rows=Self->_ccols=Self->_crows=Self->_cback=Self->_back=0;
}
FunctionTable Table_Add(Table *Self,int value) {
    struct Node* tmp;
    tmp=(struct Node*)malloc(sizeof(struct Node));
    tmp->Value=value;
    if(Self->_size>0){
        if(Self->_ccols<Self->_cols && Self->_crows==0 && Self->_cback==0){
            struct Node* _Move=Self->Head;
            int i=0;
            for(i=0;i<Self->_ccols-1;i++,_Move=_Move->Next);
            tmp->Prev=_Move;
            _Move->Next=tmp;
            Self->_ccols++;
        }else if(Self->_ccols<Self->_cols && Self->_cback==0){
            struct Node *_MoveUp=Self->Head;
            struct Node *_Move=Self->Head;
            int i=0;
            if(Self->_rows>0) for(i=0;i<Self->_crows-1;i++,_MoveUp=_MoveUp->Bottom);
            for(i=0;i<Self->_ccols;i++,_MoveUp=_MoveUp->Next);
            for(i=0;i<Self->_crows;i++,_Move=_Move->Bottom);
            for(i=0;i<Self->_ccols-1;i++,_Move=_Move->Next);
            tmp->Top=_MoveUp;
            _MoveUp->Bottom=tmp;
            tmp->Prev=_Move;
            _Move->Next=tmp;
            Self->_ccols++;
        }else if(Self->_ccols<Self->_cols && Self->_cback<Self->_back){
            struct Node *_MoveRight=Self->Head,*_MoveUp=Self->Head,*_MoveBack=Self->Head,*test=Self->Head;
            int i=0;
            for(i=0;i<Self->_cback-1;i++,_MoveBack=_MoveBack->Back);
            for(i=0;i<Self->_ccols;i++,_MoveBack=_MoveBack->Next);
            for(i=0;i<Self->_crows;i++,_MoveBack=_MoveBack->Bottom);
            for(i=0;i<Self->_cback;i++,_MoveUp=_MoveUp->Back);
            if(Self->_crows>0){
                for(i=0;i<Self->_crows-1;i++,_MoveUp=_MoveUp->Bottom);
                for(i=0;i<Self->_ccols;i++,_MoveUp=_MoveUp->Next);
            }
            for(i=0;i<Self->_cback;i++,_MoveRight=_MoveRight->Back);
            for(i=0;i<Self->_ccols-1;i++,_MoveRight=_MoveRight->Next);
            if(Self->_crows>0) for(i=0;i<Self->_crows;i++,_MoveRight=_MoveRight->Bottom);
            tmp->Prev = _MoveRight;
            _MoveRight->Next=tmp;
            tmp->Top=_MoveUp;
            _MoveUp->Bottom=tmp;
            tmp->Front=_MoveBack;
            _MoveBack->Back=tmp;
            Self->_ccols++;
        }else if(Self->_crows<Self->_rows-1 && Self->_crows==0 && Self->_cback==0){
            struct Node* _Move=Self->Head;
            tmp->Top=Self->Head;
            _Move->Bottom=tmp;
            _Move=_Move->Bottom;
            Self->_ccols=0;
            Self->_crows++;
            Self->_ccols++;
        }else if(Self->_crows<Self->_rows-1 && Self->_cback==0){
            struct Node* _Move=Self->Head;
            int i=0;
            for(i=0;i<Self->_crows;i++,_Move=_Move->Bottom);
            tmp->Top=_Move;
            _Move->Bottom=tmp;
            Self->_ccols=1;
            Self->_crows++;
        }else if(Self->_crows<Self->_rows-1 && Self->_cback!=0 && Self->_cback<Self->_back){
            struct Node* _Move=Self->Head,*_Move2=Self->Head;
            int i=0;
            for(i=0;i<Self->_crows;i++,_Move=_Move->Bottom);
            for(i=0;i<Self->_cback;i++,_Move=_Move->Back);
            for(i=0;i<=Self->_crows;i++,_Move2=_Move2->Bottom);
            for(i=0;i<Self->_cback-1;i++,_Move2=_Move2->Back);
            tmp->Top=_Move;
            _Move->Bottom=tmp;
            tmp->Front=_Move2;
            _Move2->Back=tmp;
            Self->_crows++;
            Self->_ccols=1;
        }else if(Self->_cback!=0 && Self->_cback<Self->_back-1){
            struct Node* _Move=Self->Head;
            int i=0;
            for(i=0;i<Self->_cback;i++,_Move=_Move->Back);
            tmp->Front=_Move;
            _Move->Back=tmp;
            Self->_ccols=1;
            Self->_crows=0;
            Self->_cback++;
        }else if(Self->_cback==0 && Self->_crows<Self->_rows){
            struct Node* _Move=Self->Head;
            tmp->Front=_Move;
            _Move->Back=tmp;
            Self->_ccols=1;
            Self->_crows=0;
            Self->_cback++;
        }
    }else{
        Self->Head=tmp;
        Self->_ccols++;
    }

    Self->_size++;
}
FunctionTable Table_Print(Table *Self){
    struct Node* _Move=Self->Head,*_Move2=Self->Head,*_Move3=Self->Head;
    int i=0,j=0,k=0;
    for(i=0;i<Self->_back;i++,_Move3=_Move3->Back){
        _Move2=_Move3;
        for(j=0;j<Self->_rows;j++,_Move2=_Move2->Bottom){
            _Move=_Move2;
            for(k=0;k<Self->_cols;k++,_Move=_Move->Next){
                printf("%d ",_Move->Value);
            }
            printf("\n");
        }
        printf("\n");
    }
}
FunctionTable Table_FrontFace(Table* self,int** table){
    int i,j;
    struct Node *move=self->Head,*move2=self->Head;
    for(i=0;i<self->_rows;i++,move=move->Bottom){
        move2=move;
        for(j=0;j<self->_cols;j++,move2=move2->Next){
            table[i][j]=move2->Value;
        }
    }
}
FunctionTable Table_BackFace(Table* self,int** table){
    int i,j,k;
    struct Node* move=self->Head,*move2=self->Head;
    for(i=0;i<self->_back-1;i++,move=move->Back,move2=move2->Back);
    for(i=0;i<self->_rows;i++,move=move->Bottom){
        move2=move;
        for(j=0;j<self->_cols;j++,move2=move2->Next){
            table[i][j]=move2->Value;
        }
    }
}
FunctionTable Table_RightFace(Table* self,int** table){
    int i,j;
    struct Node* move=self->Head,*move2=self->Head;
    for(i=0;i<self->_cols-1;i++,move=move->Next,move2=move->Next);
    for(i=0;i<self->_rows;i++,move=move->Bottom){
        move2=move;
        for(j=0;j<self->_back;j++,move2=move2->Back){
            table[i][j]=move2->Value;
        }
    }
}
FunctionTable Table_LeftFace(Table* self,int** table){
    int i,j;
    struct Node* move=self->Head,*move2=self->Head;
    for(i=0;i<self->_rows;i++,move=move->Bottom){
        move2=move;
        for(j=0;j<self->_back;j++,move2=move2->Back){
            table[i][j]=move2->Value;
        }
    }
}
FunctionTable Table_TopFace(Table* self,int** table){
    int i,j;
    struct Node* move=self->Head,*move2=self->Head;
    for(i=0;i<self->_cols;i++,move=move->Next){
        move2=move;
        for(j=0;j<self->_back;j++,move2=move2->Back){
            table[i][j]=move2->Value;
        }
    }
}
FunctionTable Table_BottomFace(Table* self,int** table){
    int i,j;
    struct Node* move=self->Head,*move2=self->Head;
    for(i=0;i<self->_rows-1;i++,move=move->Bottom,move2=move2->Bottom);
    for(i=0;i<self->_cols;i++,move=move->Next){
        move2=move;
        for(j=0;j<self->_back;j++,move2=move2->Back){
            table[i][j]=move2->Value;
        }
    }
}
FunctionsTree Tree_ctr(Tree* self){
    self->root=(struct NodeTree*)malloc(sizeof(struct NodeTree));
    self->Face=(char*)malloc(sizeof(char)*(20));
    self->size=0;
}
FunctionsTree Tree_AddList(Tree* self,List* pstlist,Pair Initial,char* Face){
    int i=0;
    if(self->root==NULL || self->size==0){
        struct NodeTree *new=(struct NodeTree *)malloc(sizeof(struct NodeTree));
        new->Coordinates.x=Initial.x;
        new->Coordinates.y=Initial.y;
        self->root=new;
        self->size++;
        self->Face=Face;
        Tree_AddList(self,pstlist,Initial,Face);
    }else{
        List pnd;
        InitializeList(&pnd);
        for(i=0;i<6;i++){
            List segmentedList=SegmentationList(i+1,'X',pstlist);
            //Necesitas enviar la lista segmentada en base a la Raiz
            //Ya que se envia una lista artificial y no puede agregar los nodos
            segmentedList.OrderByHigher(&segmentedList,'Y');
            segmentedList.DeleteRepeated(&segmentedList);
            segmentedList.Print(&segmentedList);
            struct NodeTree* move=self->root;
            printf("MainRoot\n");
            while(move->Up!=NULL){
                printf("x: %d y: %d\n",move->Coordinates.x,move->Coordinates.y);
                move=move->Up;
            }
            AddTreeNodes(segmentedList.Head,self->root,0,i);
            segmentedList.Head=NULL;
        }
    }
}
FunctionsTree Tree_Print(Tree* self){
    if(self!=NULL){
        PrintTree(self->root);
    }
}
FunctionsListOfTrees LOT_ctr(ListOfTrees* self){
    self->Head=(struct NodeListTree*)malloc(sizeof(struct NodeListTree));
    self->size=0;
}
FunctionsListOfTrees LOT_Add(ListOfTrees* self,Tree* new){
    struct NodeListTree* newNode=(struct NodeListTree*)malloc(sizeof(struct NodeListTree));
    newNode->tree=new;
    printf("size of list: %d\n",self->size);
    if(self->Head==NULL && self->size==0){
        self->Head=newNode;
    }else{
        struct NodeListTree* move=self->Head;
        while(move->Next!=NULL) move=move->Next;
        move->Next=newNode;
    }
    self->size++;
}
FunctionsListOfTrees LOT_Print(ListOfTrees* self){
    if(self->size>0){
        struct NodeListTree* move=self->Head;
        int i=0;
        for(i=0;i<self->size;i++,move=move->Next){
            move->tree->PrintTree(move->tree);
        }
    }
}