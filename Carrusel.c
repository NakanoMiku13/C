#include<stdio.h>
#include<stdlib.h>
typedef struct Cola Cola,*Funcion;
typedef struct Nodo Nodo;
struct Nodo{
    Nodo *lazo,*cuerda;
};
struct Cola{
    Nodo *Caballo,*Elefante;
    int longitud;
    Funcion (*construir)(Cola* cola),(*destruir)(Cola* cola),(*insertar)(Cola* cola),(*eliminar)(Cola* cola);
};
Funcion construir(Cola*),destruir(Cola*),insertar(Cola*),eliminar(Cola*);
int main(){
    Cola* Carrusel;
    Carrusel->construir=construir;
    printf("Listo 2\n");
    Carrusel->insertar=insertar;
    Carrusel->eliminar=eliminar;
    Carrusel->destruir=destruir;
    printf("Listo1\n");
    Carrusel->construir(Carrusel);
    Carrusel->insertar(Carrusel);
    Carrusel->insertar(Carrusel);
    Carrusel->insertar(Carrusel);
    Carrusel->insertar(Carrusel);
    Carrusel->eliminar(Carrusel);
    Carrusel->destruir(Carrusel);
    printf("Listo\n");
    scanf("%d");
}
Funcion construir(Cola* cola){
    //Aqui se construlle el carrusel
    printf("Listo Const\n");
    cola->Elefante=cola->Caballo=(Nodo*)malloc(sizeof(Nodo));
    cola->longitud=0;
}
Funcion insertar(Cola* c){
    //Decimos que caballo es la cabeza y elefante es el ultimo elemento
    //Decimos que lazo es el elemento siguiente y cuerda es el anterior
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if(c->longitud>0){
        int i=0;
        Nodo* m=c->Caballo;
        for(i=0;i<c->longitud-1;i++,m=m->lazo);
        nuevo->cuerda=m;
        m->lazo=nuevo;
        c->Elefante=m->lazo;
        printf("Listo\n");
    }else{
        c->Caballo=nuevo;
        c->Elefante=c->Caballo;
    }
    c->longitud++;
}
Funcion eliminar(Cola* c){
    if(c->longitud>0){
        Nodo* tmp=c->Caballo;
        c->Caballo=c->Caballo->lazo;
        tmp=NULL;
        c->longitud--;
    }
}
Funcion destruir(Cola* cola){
    if(cola->longitud>0){
        while(cola->longitud>0 && cola->Caballo!=NULL){
            eliminar(cola);
        }
    }
}