#include<stdio.h>
#include <stdlib.h>
typedef struct Table Table,*Function;
struct Node{
    int Value;
    struct Node *Next,*Prev,*Top,*Bottom;
};
struct Table{
    struct Node *Head;
    size_t _size,_cols,_rows,_ccols,_crows;
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
    int x,y,i,j;
    printf("Rows and Cols\n");
    scanf("%d %d",&y,&x);
    table._cols=x;
    table._rows=y;
    for(i=0;i<y;i++){
        for(j=0;j<x;j++){
            int d;
            scanf("%d",&d);
            table.Add(&table,d);
        }
    }
    table.Print(&table);
}
Function Table_Ctr(Table *Self){
    Self->Head=(struct Node*)malloc(sizeof(struct Node));
    Self->_size=Self->_cols=Self->_rows=Self->_ccols=Self->_crows=0;
}
Function Table_Add(Table *Self,int value) {
    struct Node* tmp;
    tmp=(struct Node*)malloc(sizeof(struct Node));
    tmp->Value=value;
    if(Self->_size>0){
        if(Self->_ccols<Self->_cols && Self->_crows==0){
            struct Node* _Move=Self->Head;
            int i=0;
            while(i<Self->_ccols-1){
                _Move=_Move->Next;
                i++;
            }
            tmp->Prev=_Move;
            _Move->Next=tmp;
            Self->_ccols++;
        }else if(Self->_ccols<Self->_cols){
            struct Node *_MoveUp=Self->Head;
            struct Node *_Move=Self->Head;
            int i=0;
            if(Self->_rows>0){
                while(i<Self->_crows-1){
                    _MoveUp=_MoveUp->Bottom;
                    i++;
                }
                i=0;
            }
            while(i<Self->_ccols){
                _MoveUp=_MoveUp->Next;
                i++;
            }
            i=0;
            while(i<Self->_crows){
                _Move=_Move->Bottom;
                i++;
            }
            i=0;
            while(i<Self->_ccols-1){
                _Move=_Move->Next;
                i++;
            }
            tmp->Top=_MoveUp;
            tmp->Prev=_Move;
            _Move->Next=tmp;
            Self->_ccols++;
        }else if(Self->_crows<Self->_rows && Self->_ccols==Self->_cols && Self->_crows==0){
            struct Node* _Move=Self->Head;
            tmp->Top=Self->Head;
            _Move->Bottom=tmp;
            _Move=_Move->Bottom;
            Self->_ccols=0;
            Self->_crows++;
            Self->_ccols++;
        }else if(Self->_crows<Self->_rows && Self->_ccols==Self->_cols){
            struct Node* _Move=Self->Head;
            int i=0;
            while(i<Self->_crows){
                _Move=_Move->Bottom;
                i++;
            }
            tmp->Top=_Move;
            _Move->Bottom=tmp;
            Self->_ccols=1;
            Self->_crows++;
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