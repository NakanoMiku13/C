#include<stdio.h>
#include <stdlib.h>
typedef struct Stack Stack,*Function;
typedef struct Node *Node;
struct Node{
    int Value;
    Node Next;
};
struct Stack{
    Node Head;
    size_t size;
    Function (*ctr)(Stack*),(*Add)(Stack*,int),(*Pop)(Stack*);
};
Function Stack_Add(Stack*,int),Stack_ctr(Stack*),Stack_Pop(Stack*);
void SetT1(Stack*),Print(Stack),Swap(Stack*,Stack*),MoveTo(Stack*,Stack*),Hanoi(Stack*,Stack*,Stack*);
int main(){
    Stack Tower1,Tower2,Tower3;
    Tower1.Add=Tower2.Add=Tower3.Add=Stack_Add;
    Tower1.Pop=Tower2.Pop=Tower3.Pop=Stack_Pop;
    Tower1.ctr=Tower2.ctr=Tower3.ctr=Stack_ctr;
    Tower1.ctr(&Tower1);
    Tower2.ctr(&Tower2);
    Tower3.ctr(&Tower3);
    SetT1(&Tower1);
    Hanoi(&Tower1, &Tower2, &Tower3);
    Print(Tower1);
    printf("\n");
    Print(Tower3);
}
void Hanoi(Stack* T1, Stack* T2, Stack* T3){
}
void Print(Stack t){
    while(t.size>0){
        printf("%d\n",t.Head->Value);
        t.Pop(&t);
    }
}
void SetT1(Stack* T){
    int i=5;
    while(i>0){
        T->Add(T,i);
        i--;
    }
}
void MoveTo(Stack* From,Stack* To){
    int x=From->Head->Value;
    From->Pop(From);
    To->Add(To,x);
}
void Swap(Stack* T1, Stack* T2){
    int x=T1->Head->Value,y=T2->Head->Value;
    T1->Pop(T1);
    T2->Pop(T2);
    T1->Add(T1,y);
    T2->Add(T2,x);
}
Function Stack_ctr(Stack *self){
    self->Head=(Node)malloc(sizeof(Node));
    self->size=0;
}
Function Stack_Add(Stack *self,int x){
    Node tmp = (Node)malloc(sizeof(Node));
    tmp->Value=x;
    if(self->size>0){
        int i=0;
        Node move=self->Head;
        self->Head=tmp;
        self->Head->Next=move;
    }else{
        self->Head=tmp;
    }
    self->size++;
}
Function Stack_Pop(Stack *self){
    if(self->size>0){
        Node tmp=self->Head;
        self->Head=self->Head->Next;
        free(tmp);
        self->size--;
    }
}