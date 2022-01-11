#include<stdio.h>
#include<time.h>
#include<stdlib.h>
typedef struct Arbol Arbol,*Funcion;
typedef struct Nodo Nodo;
struct Nodo{
    Nodo* lazo,*cuerda;
};
struct Arbol{
    Nodo* centro;
    int longitud;
    Funcion (*crear)(Arbol*),(*insertar)(Arbol*);
};
Funcion crear(Arbol* ar){
    ar->centro=(Nodo*) malloc(sizeof(Nodo));
    ar->longitud=0;
}
void destruirarbol(Nodo* centro,int longitud){
    if(centro!=NULL && longitud>0){
        destruirarbol(centro->lazo,longitud);
        centro->lazo=NULL;
        destruirarbol(centro->cuerda,longitud);
        centro->cuerda=NULL;
        longitud-=2;
    }
}
void CrearRamas(Nodo* centro,int cont){
    if(cont<6 && cont>=0){
        Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
        int dir = rand()%3;
        if(dir==0){
            if(centro->lazo!=NULL){
                centro->lazo=nuevo;
                printf("Izquierda\n");
                CrearRamas(centro->lazo,cont+1);
            }else{
                printf("Avanza izquierda\n");
                CrearRamas(centro->lazo,cont);
            }
        }else{
            if(centro->cuerda!=NULL){
                centro->cuerda=nuevo;
                printf("Derecha\n");
                CrearRamas(centro->cuerda,cont+1);
            }else{
                printf("Avanza derecha\n");
                CrearRamas(centro->cuerda,cont);
            }
        }
    }
}
Funcion insertar(Arbol* ar){
    //Decimos que lazo es nodo izquierdo y cuerda nodo derecho
    Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
    if(ar->longitud>0){
        int dir = rand() % 3;
        if(dir==0) CrearRamas(ar->centro->lazo,1);
        else CrearRamas(ar->centro->cuerda,1);
        ar->longitud+=6;
    }else{
        //0 izquierda, 1 derecha
        ar->centro = nuevo;
        int dir = rand()%3;
        if(dir==0){
            printf("Inserta nodo 2 izquierda\n");
            nuevo = (Nodo*) malloc(sizeof(Nodo));
            ar->centro->lazo=nuevo;
            CrearRamas(ar->centro->lazo,1);
            ar->longitud+=6;
        }else{
            printf("Inserta nodo 2 derecha\n");
            nuevo = (Nodo*) malloc(sizeof(Nodo));
            ar->centro->cuerda=nuevo;
            CrearRamas(ar->centro->cuerda,1);
            ar->longitud+=6;
        }
    }
}
int main(){
    srand(time(NULL));
    Arbol* ar;
    printf("puto");
    ar->crear=crear;
    ar->insertar=insertar;
    ar->crear(ar);
    ar->insertar(ar);
    ar->insertar(ar);
    ar->insertar(ar);
    ar->insertar(ar);
    ar->insertar(ar);
    ar->insertar(ar);
    ar->insertar(ar);
    printf("t: %d\n",ar->longitud);
    scanf("%d");
}