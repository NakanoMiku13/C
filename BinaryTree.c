#include<stdio.h>
#include<stdlib.h>
typedef struct Tree Tree,*Function;
struct Node{
    int Value;
    struct Node* Right,*Left;
};
struct Tree{
    struct Node* Root;
    Function (*AddSon)(Tree*,int),(*ctr)(Tree*);
};
Function Tree_AddSon(Tree*,int),Tree_ctr(Tree*);
int main(){

}
Function Tree_ctr(Tree* self){
    self->Root=(struct Node*)malloc(sizeof(struct Node));
}
Function Tree_AddSon(Tree* self,int x){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->Value=x;
    if(self->Root==NULL){
        self->Root = new;
    }else{
        struct Node* Move=self->Root;
        if(Move->Left==NULL){
            Move->Left=new;
        }else if(Move->Right==NULL && Move->Left!=NULL){
            Move->Right=new;
        }else if(Move->Right!=NULL && Move->Left!=NULL){
            Move=Move->Left;
        }
    }
}