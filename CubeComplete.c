
//Find more interesting codes in https://github.com/NakanoMiku13
//DynamicTable
#include<stdio.h>
#include <stdlib.h>
//Defining the main structs
typedef struct Table Table,*Function;
//Creating the Main Node Structure, that contains a pointer aiming to the next, previous, top and bottom node of the table
struct Node{
    int Value;
    struct Node *Next,*Prev,*Top,*Bottom,*Front,*Back;
};
struct Table{
    struct Node *Head;
    size_t _size,_cols,_rows,_ccols,_crows,_cback,_back;
    Function (*Ctr)(Table *);
    Function (*Add)(Table *,int);
    Function (*Print)(Table *);
};
Function Table_Ctr(Table *),Table_Add(Table *,int),Table_Print(Table *);
int main(){
    struct Table table;
    table.Ctr=Table_Ctr;
    table.Add=Table_Add;
    table.Print=Table_Print;
    table.Ctr(&table);
    int x,y,i,j,o=1,z,k;
    printf("Rows and Cols\n");
    scanf("%d %d %d",&y,&x,&z);
    table._cols=x;
    table._rows=y;
    table._back=z;
    for(i=0;i<y;i++){
        for(j=0;j<x;j++){
            for(k=0;k<z;k++,o++){
                table.Add(&table,o);
            }
        }
    }
    table.Print(&table);
}
Function Table_Ctr(Table *Self){
    Self->Head=(struct Node*)malloc(sizeof(struct Node));
    Self->_size=Self->_cols=Self->_rows=Self->_ccols=Self->_crows=Self->_cback=Self->_back=0;
}
Function Table_Add(Table *Self,int value) {
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
        }else if(Self->_ccols<Self->_cols){
            struct Node *_MoveRight=Self->Head,*_MoveUp=Self->Head,*_MoveBack=Self->Head;
            int i=0;
            for(i=0;i<Self->_cback-1;i++,_MoveBack=_MoveBack->Back);
            for(i=0;i<Self->_ccols;i++,_MoveBack=_MoveBack->Next);
            for(i=0;i<Self->_crows;i++,_MoveBack=_MoveBack->Bottom);

            printf("tt %d %d",Self->Head->Value,Self->Head->Back->Value);
            for(i=0;i<Self->_cback;i++,_MoveUp=_MoveUp->Back){printf("Move %d\n",_MoveUp->Value);}
            printf("Move %d\n",_MoveUp->Value);
            for(i=0;i<Self->_ccols;i++,_MoveUp=_MoveUp->Next);
            for(i=0;i<Self->_crows-1;i++,_MoveUp=_MoveUp->Bottom);
            printf("Move %d\n",_MoveUp->Value);


            for(i=0;i<Self->_cback;i++,_MoveRight=_MoveRight->Back);
            for(i=0;i<Self->_ccols-1;i++,_MoveRight=_MoveRight->Next);
            for(i=0;i<Self->_crows;i++,_MoveRight=_MoveRight->Bottom);
            tmp->Prev = _MoveRight;
            _MoveRight->Next=tmp;
            tmp->Top=_MoveUp;
            _MoveUp->Bottom=tmp;
            tmp->Front=_MoveBack;
            _MoveBack->Back=tmp;
            Self->_ccols++;
        }else if(Self->_crows<Self->_rows && Self->_ccols==Self->_cols && Self->_crows==0 && Self->_cback==0){
            struct Node* _Move=Self->Head;
            tmp->Top=Self->Head;
            _Move->Bottom=tmp;
            _Move=_Move->Bottom;
            Self->_ccols=0;
            Self->_crows++;
            Self->_ccols++;
        }else if(Self->_crows<Self->_rows && Self->_ccols==Self->_cols && Self->_cback==0){
            struct Node* _Move=Self->Head;
            int i=0;
            for(i=0;i<Self->_crows;i++,_Move=_Move->Bottom);
            tmp->Top=_Move;
            _Move->Bottom=tmp;
            Self->_ccols=1;
            Self->_crows++;
        }else if(Self->_cback==0){
            struct Node* _Move=Self->Head;
            tmp->Front=_Move;
            _Move->Back=tmp;
            Self->_ccols=1;
            Self->_crows=0;
            Self->_cback++;
            printf("tt %d %d\n",Self->Head->Value,Self->Head->Back->Value);
            printf("Back\n");
        }else{
            struct Node* _Move=Self->Head;
            int i=0;
            for(i=0;i<Self->_cback-1;i++,_Move=_Move->Back);
            tmp->Front=_Move;
            _Move->Back=tmp;
            Self->_ccols=1;
            Self->_crows=0;
            Self->_cback++;
            printf("Back!=0\n");
        }
    }else{
        Self->Head=tmp;
        Self->_ccols++;
    }

    Self->_size++;
}
Function Table_Print(Table *Self){
    struct Node* _Move=Self->Head;
    struct Node* _Row=Self->Head;
    int i=0,j=0,k=0,l=0;
    while(i<Self->_rows){
        j=0;
        l=0;
        while(l<Self->_cols){
            printf("%d ",_Move->Value);
            _Move=_Move->Next;
            l++;
        }
        _Row=_Row->Bottom;
        _Move=_Row;
        printf("\n");
        i++;
    }
    /*_Move=_Row=Self->Head;
    i=0,j=0,k=0,l=0;
    while(i<Self->_rows){
        j=0;
        l=0;
        while(l<Self->_cols){
            if(_Move->Top!=NULL)
            printf("The value: %d; is linked with: %d, %d and %d",_Move->Value,_Move->Top->Value!=NULL,0,0);
            _Move=_Move->Next;
            l++;
        }
        _Row=_Row->Bottom;
        _Move=_Row;
        printf("\n");
        i++;
    }*/
}