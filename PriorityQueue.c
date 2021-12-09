#include<stdio.h>
#include<stdlib.h>
typedef struct Queue Queue,*Fn;
typedef struct Node Node;
struct Node{
    int Value;
    char P;
    Node* Next;
};
struct Queue{
    Node* head;
    size_t size;
    Fn (*ctr)(Queue *self),(*Add)(Queue* self,int x,char a),(*Pop)(Queue* self),(*Print)(Queue* self,char a);
};
Fn ctr(Queue* s){
    s->head=(Node*)malloc(sizeof(Node));
    s->size=0;
}
Fn Add(Queue* s,int x,char a){
    Node* new=(Node*)malloc(sizeof(Node));
    new->Value=x;
    new->P=a;
    if(s->size==0){
        s->head=new;
    }else{
        Node* m=s->head;
        for(int i=0;i<s->size-1;i++,m=m->Next);
        m->Next=new;
    }
    s->size++;
}
Fn Print(Queue* s,char a){
    if(s->size>0){
        Node* m=s->head;
        for(int i=0;i<s->size;i++,m=m->Next){
            if(m->P==a){
                printf("%d ",m->Value);
            }
        }
        
    }
}
int main(){
    Queue xd;
    xd.ctr=ctr;
    xd.Add=Add;
    xd.Print=Print;
    xd.ctr(&xd);
    for(int i=0,j=65;i<10;i++,j++){
        xd.Add(&xd,i,(char)j);
    }
    xd.Print(&xd,'C');
}