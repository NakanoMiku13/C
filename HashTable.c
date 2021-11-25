#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct ht ht,*f;
typedef struct n n;
struct n{
    int v;
    char* hash;
    n* nt;
};
struct ht{
    n* head;
    size_t size;
    f (*ctr)(ht*),(*Add)(ht*,n*),(*Pop)(ht*);
};
f ht_ctr(ht* self){
    self->head=(n*)malloc(sizeof(n));
    self->size=0;
}
n* gHD(int v){
    n* new=(n*)malloc(sizeof(n));
    new->hash=(char*)malloc(sizeof(char)*152);
    char* d="abcdef";/*ghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!/()=;:.";*/
    int i=0;
    for(i=0;i<2;i++) new->hash[i]=d[rand()%8];
    new->v=v;
    return new;
}
f ht_Add(ht* s,n* new){
    if(s->size==0){
        s->head=new;
    }else{
        n* t=s->head;
        new->nt=t;
        s->head=new;
    }
    s->size++;
}
int CountRepeated(ht* s){
    int c=0;
    n* m=s->head,*m2;
    for(int i=0;i<s->size;i++,m=m->nt){
        m2=m;
        m2=m2->nt;
        for(int j=i;j<s->size-1;j++,m2=m2->nt){
            if(m->hash==m2->hash) c++;
        }
    }
    return c;
}
int main(){
    ht hastTable;
    hastTable.ctr=ht_ctr;
    hastTable.Add=ht_Add;
    hastTable.ctr(&hastTable);
    srand(time(NULL));
    for(int i=0;i<10000;i++){
        n* new=gHD(rand()%150000);
        hastTable.Add(&hastTable,new);
    }
    printf("Repeated: %d",CountRepeated(&hastTable));
}