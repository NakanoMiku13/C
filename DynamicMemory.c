#include<stdio.h>
#include<stdlib.h>
typedef struct LinkedList LinkedList,*Function;
struct Node{
    int Value;
    struct Node* Next;
};
struct LinkedList{
    struct Node* Head;
    struct Node* Back;
    struct Node* Middle;
    size_t _size;
    int _Empty;
    int FE;
    int BE;
    Function (*Set)(LinkedList *);
    Function (*Empty)(LinkedList *);
    Function (*AddFront)(LinkedList *,int);
    Function (*PopFront)(LinkedList *);
    Function (*AddBack)(LinkedList *,int);
    Function (*PopBack)(LinkedList *);
    Function (*SetMiddle)(LinkedList *,int);
};
Function LinkedList_Set(LinkedList *);
Function LinkedList_Empty(LinkedList *);
Function LinkedList_AddFront(LinkedList *,int);
Function LinkedList_SetMiddle(LinkedList *,int);
Function LinkedList_PopFront(LinkedList *);
Function LinkedList_AddBack(LinkedList *,int);
Function LinkedList_PopBack(LinkedList *);
void Input(LinkedList *),PrintList(LinkedList *),PrintElements(LinkedList *),ListInit(LinkedList *);
int main(){
    struct LinkedList List;
    ListInit(&List);
    List.Set(&List);
    Input(&List);
    PrintElements(&List);
    PrintList(&List);
}
void ListInit(LinkedList *List) {
    List->Set=LinkedList_Set;
    List->Empty=LinkedList_Empty;
    List->AddFront=LinkedList_AddFront;
    List->SetMiddle=LinkedList_SetMiddle;
    List->PopFront=LinkedList_PopFront;
    List->AddBack=LinkedList_AddBack;
    List->PopBack=LinkedList_PopBack;
}
void PrintElements(LinkedList *List){
    List->SetMiddle(List,0);
    printf("Front Value: %d\nBack Value: %d\nMiddle Value: %d\n", List->Head->Value,List->Back->Value,List->Middle->Value);
}
void PrintList(LinkedList *List){
    int i=1,j=0;
    while(List->FE>0){
        printf("Value %d: %d\n",i,List->Head->Value);
        i++;
        List->PopFront(List);
    }
    struct Node* tmp;
    tmp=(struct Node*)malloc(sizeof(struct Node));
    int k=List->BE,l=0;
    for(j=0;j<k;j++,i++){
        tmp=List->Back;
        l=0;
        while(l<List->BE-j-1){
            tmp=tmp->Next;
            l++;
        }
        printf("Value %d: %d\n",i,tmp->Value);
    }
}
void Input(LinkedList *List){
    int x;
    do{
        printf("1) Agregar adelante\n2) Agregar atras\n3) Agregar en medio\n4) Terminar\n");
        scanf("%d",&x);
        if(x<4){
            printf("Ingresa el valor:\n");
            int y;
            scanf("%d",&y);
            if(x==1){
                List->AddFront(List,y);
            }else if(x==2){
                List->AddBack(List,y);
            }else{
                List->SetMiddle(List,y);
            }
        }
    }while(x<4);
}
Function LinkedList_Set(LinkedList *self){
    self->Middle=self->Head=self->Back=(struct Node*)malloc(sizeof(struct Node));
    self->BE=self->FE=self->_Empty=self->_size=0;
}
Function LinkedList_Empty(LinkedList *self){
    if(self->_size>0) self->_Empty=1;
    else self->_Empty=0;
};
Function LinkedList_SetMiddle(LinkedList *self,int x){
    int a=self->FE,b=self->BE, c=a+b;
    struct Node* tmp;
    tmp=(struct Node*)malloc(sizeof(struct Node));
    if(x==0){
        if(a>b){
            tmp=self->Head;
            int i=0;
            while(i<a-1){
                tmp=tmp->Next;
                i++;
            }
        }else{
            tmp=self->Back;
            int i=0;
            while(i<b-1){
                tmp=tmp->Next;
                i++;
            }
        }
        self->Middle=tmp;
    }else{
        struct Node *_Move,*_Values,*_Next;
        _Values=_Next=_Move=(struct Node*)malloc(sizeof(struct Node));
        _Values->Value=x;
        if(a>b){
            tmp=self->Head;
            int i=0;
            while(i<self->FE-1){
                tmp=tmp->Next;
                i++;
            }
            self->FE++;
        }else{
            tmp=self->Back;
            int i=0;
            while(i<self->BE-1){
                tmp=tmp->Next;
                i++;
            }
            self->BE++;
        }
        _Move=tmp;
        _Next=_Move->Next;
        _Move->Next=_Values;
        _Values->Next=_Next;
        self->Middle->Value=x;
    }
}
Function LinkedList_PopFront(LinkedList *self){
    self->Empty=LinkedList_Empty;
    self->Empty(self);
    if(self->_Empty==1 && self->FE>0){
        struct Node* _tmp;
        _tmp=(struct Node*)malloc(sizeof(struct Node));
        _tmp=self->Head;
        self->Head=self->Head->Next;
        free(_tmp);
        self->_size--;
        self->FE--;
    }
}
Function LinkedList_AddFront(LinkedList *self,int x){
    self->Empty=LinkedList_Empty;
    self->SetMiddle=LinkedList_SetMiddle;
    struct Node* _tmp;
    _tmp=(struct Node*)malloc(sizeof(struct Node));
    _tmp->Value=x;
    self->Empty(self);
    if(self->_Empty==1){
        struct Node* _Move=self->Head;
        self->Head=_tmp;
        self->Head->Next=_Move;
        _Move=NULL;
    }else{
        self->Head=_tmp;
        self->Back=self->Head;
    }
    self->_size++;
    self->FE++;
}
Function LinkedList_PopBack(LinkedList *self){
    self->Empty=LinkedList_Empty;
    if(self->_Empty==1 && self->BE>0){
        struct Node* _tmp;
        _tmp=(struct Node*)malloc(sizeof(struct Node));
        _tmp=self->Back;
        self->Back=self->Back->Next;
        free(_tmp);
        self->_size--;
        self->BE--;
    }
}
Function LinkedList_AddBack(LinkedList *self,int x){
    self->Empty=LinkedList_Empty;
    self->SetMiddle=LinkedList_SetMiddle;
    struct Node* _tmp;
    _tmp=(struct Node*)malloc(sizeof(struct Node));
    _tmp->Value=x;
    self->Empty(self);
    if(self->_Empty==1){
        struct Node* _Move=self->Back;
        self->Back=_tmp;
        self->Back->Next=_Move;
        _Move=NULL;
    }else{
        self->Head=_tmp;
        self->Back=self->Head;
    }
    self->_size++;
    self->BE++;
}