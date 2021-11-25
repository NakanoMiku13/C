#include<stdio.h>
#include<stdlib.h>
typedef struct Queue Queue,*Function;
typedef struct Node Node;
struct Node{
    int v;
    Node* n;
};
struct Queue{
    Node* head;
    Node* back;
    size_t size;
    Function (*ctr)(Queue* s),(*Push)(Queue* s,int x),(*Pop)(Queue* s),(*Print)(Queue* s);
};
Function ctr(Queue* s){
    s->head=s->back=(Node*)malloc(sizeof(Node));
    s->size=0;
}
Function Push(Queue* s, int x){
    Node* new = (Node*)malloc(sizeof(Node));
    new->v=x;
    if(s->size==0){
        s->back=s->head=new;
    }else{
        Node* move=s->head;
        int i;
        for(i=0;i<s->size-1;i++,move=move->n);
        move->n=new;
        s->back=move->n;
    }
    s->size++;
}
Function Pop(Queue* s){
    if(s->size>0){
        Node* tmp=s->head;
        s->head=s->head->n;
        free(tmp);
        s->size--;
    }
}
Function Print(Queue* s){
    if(s->size>0){
        Node* m=s->head;
        int i;
        for(i=0;i<s->size;i++,m=m->n){
            printf("%d ",m->v);
        }
    }
}
int main(){
    Queue f;
    f.ctr=ctr;
    f.Push=Push;
    f.Pop=Pop;
    f.Print=Print;
    f.ctr(&f);
    f.Push(&f,1);
    f.Push(&f,2);
    f.Push(&f,3);
    printf("H: %d",f.head->v);
    printf("\nB: %d\n",f.back->v);
    f.Print(&f);
    f.Pop(&f);
    printf("\n");
    f.Print(&f);
    f.Pop(&f);
    printf("\n");
    f.Print(&f);
    f.Pop(&f);
    printf("\n");
    f.Print(&f);
}