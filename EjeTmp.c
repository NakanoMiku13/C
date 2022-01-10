#include<stdio.h>
#include<stdlib.h>
typedef struct Stack Stack,*Function;
struct Node{
    int Value;
    struct Node* Next;
};
struct Stack{
    struct Node* Head;
    struct Node* Back;
    size_t size;
    Function (*Set)(Stack *);
    Function (*Add)(Stack *,int);
    Function (*Pop)(Stack *);
    Function (*Process)(Stack *,int);
    Function (*AddFront)(Stack *,int);
    Function (*PopFront)(Stack *);
    Function (*Print)(Stack *);
};
Function Stack_Add(Stack *,int),Stack_Pop(Stack *),Stack_Set(Stack *),Stack_Process(Stack *,int),Stack_AddFront(Stack *,int),Stack_PopFront(Stack *),Stack_Print(Stack *);
int main(){
    struct Stack pila;
    pila.Add=Stack_Add;
    pila.Pop=Stack_Pop;
    pila.Set=Stack_Set;
    pila.AddFront=Stack_AddFront;
    pila.PopFront=Stack_PopFront;
    pila.Process=Stack_Process;
    pila.Print=Stack_Print;
    pila.Set(&pila);
    pila.Add(&pila,5);
    pila.Add(&pila,9);
    pila.Add(&pila,7);
    pila.Add(&pila,5);
    pila.Add(&pila,4);
    int i=1,j=0;
    while(pila.size>0){
        pila.Print(&pila);
        pila.Process(&pila,i);
        if(i==3){
            i=1;
        }else{
            i++;
        }
        j++;
    }
}
Function Stack_Print(Stack *self){
    int i=0;
    struct Node* tmp=self->Head;
    while(i<self->size){
        printf("%d ",tmp->Value);
        tmp=tmp->Next;
        i++;
    }
    printf("\n");
}
Function Stack_Set(Stack *self){
    self->Head=self->Back=(struct Node*)malloc(sizeof(struct Node));
    self->size=0;
}
Function Stack_AddFront(Stack *self,int x){
    struct Node* tmp=self->Head;
    struct Node* value;
    value=(struct Node*)malloc(sizeof(struct Node));
    value->Value=x;
    self->Head=value;
    self->Head->Next=tmp;
    self->size++;
}
Function Stack_PopFront(Stack *self){
    struct Node* tmp=self->Head;
    self->Head=self->Head->Next;
    //free(tmp);
    self->size--;
}
Function Stack_Add(Stack *self,int x){
    struct Node* tmp;
    tmp=(struct Node*)malloc(sizeof(struct Node));
    tmp->Value=x;
    if(self->size>0){
        struct Node* move=self->Head;
        int i=0;
        while(i<self->size-1){
            move=move->Next;
            i++;
        }
        move->Next=tmp;
        self->Back=move->Next;
    }else{
        self->Head=tmp;
        self->Back=self->Head;
    }
    self->size++;
}
Function Stack_Pop(Stack *self){
    if(self->size>0){
        struct Node* tmp;
        tmp=(struct Node*)malloc(sizeof(struct Node));
        tmp=self->Back;
        struct Node* move = self->Head;
        int i=1;
        while(i<self->size-1){
            move=move->Next;
            i++;
        }
        self->Back=move;
        //printf("%d",self->Back->Value);
        //free(tmp);
        self->size--;
    }
}
Function Stack_Process(Stack *self,int x){
    if(x==3){
        int n = rand()%4;
        printf("N= %d\n",n);
        int n1=rand()%10+1,n2=rand()%10+1,n3=rand()%10+1;
        switch(n){
            case 0: break;
            case 1: self->Add(self,n1); break;
            case 2: self->Add(self,n1); self->Add(self,n2); break;
            case 3: self->Add(self,n1); self->Add(self,n2); self->Add(self,n3); break;
            default: break;
        }
    }else{
        struct Node* tmp = self->Head;
        self->PopFront(self);
        if(tmp->Value>3){
            tmp->Value-=3;
            self->Add(self,tmp->Value);
        }
    }
}