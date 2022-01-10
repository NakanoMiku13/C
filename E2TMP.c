#include<stdio.h>
#include<stdlib.h>
typedef struct Lista Lista;
struct Nodo{
    char let;
    struct Nodo* sig;
};
struct Lista{
    struct Nodo* Cabeza;
    int tam;
};
void AgregarNodo(Lista*,char),ImprimirLista(Lista);
Lista* Funcion1(Lista* ret,Lista* l,int tam,const int n);
int main(){
    Lista l,*ret;
    l.tam=0;
    int n,i,m;
    printf("De que tamanio sera la lista?\n");
    scanf("%d",&n);
    printf("Ingrese 1 en 1 los caracteres de la lista\n");
    for(i=0;i<n;i++){
        char x;
        scanf("\n%c",&x);
        AgregarNodo(&l,x);
    }
    printf("Ingrese el numero N\n");
    scanf("%d",&m);
    ret=Funcion1(ret,&l,0,n);
    
}
Lista* Funcion2(Lista* l,int n){

}
void ImprimirLista(Lista l){
    if(l.tam>0){
        int i=0;
        for(i=0;i<l.tam;i++){
            printf("%c ",l.Cabeza->let);
            l.Cabeza=l.Cabeza->sig;
        }
    }
}
void AgregarNodo(Lista* l,char let){
    struct Nodo* nuevo=(struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->let=let;
    if(l->tam>0){
        int i;
        struct Nodo* mover=l->Cabeza;
        for(i=0;i<l->tam-1;i++,mover=mover->sig);
        mover->sig=nuevo;
    }else{
        l->Cabeza=(struct Nodo*)malloc(sizeof(struct Nodo));
        l->Cabeza=nuevo;
    }
    l->tam++;
}
Lista* Funcion1(Lista* ret,Lista* l,int tam,const int n){
    if(tam==0){
        ret->tam=0;
        ret->Cabeza=(struct Nodo*)malloc(sizeof(struct Nodo));
    }
    if(tam<n){
        int i;
        char lets[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        char lets2[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        char lets3[]={'1','2','3','4','5','6','7','8','9'};
        struct Nodo* tmp=l->Cabeza;
        for(i=0;i<26;i++){
            if(tmp->let==lets[i]){
                AgregarNodo(ret,lets2[i]);
                l->Cabeza=l->Cabeza->sig;
                return Funcion1(ret,l,tam+1,n);
            }else{
                int j;
                for(j=0;j<26;j++){
                    if(tmp->let==lets2[j]){
                        AgregarNodo(ret,lets2[j]);
                        l->Cabeza=l->Cabeza->sig;
                        return Funcion1(ret,l,tam+1,n);
                    }
                }
                for(j=0;j<10;j++){
                    if(tmp->let==lets3[j]){
                        AgregarNodo(ret,lets3[j]);
                        l->Cabeza=l->Cabeza->sig;
                        return Funcion1(ret,l,tam+1,n);
                    }
                }
            }
        }
    }else{
        return ret;
    }
}