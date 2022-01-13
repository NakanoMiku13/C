#include<stdio.h>
#include<stdlib.h>
typedef struct Nodo Nodo;
typedef struct grafo grafo;
typedef struct NodoLista NodoLista;
typedef struct lista lista;
struct NodoLista{
    grafo* otroNucleo;
    NodoLista* siguiente;
};
struct Nodo{
    //Apuntamos a otro nucleo en ves de unirlo y asi generar enlaces complejos
    Nodo* otroNucleo;
};
struct lista{
    NodoLista* cabeza;
    int longitud;
};
struct grafo{
    Nodo* nucleo;
    lista* otrosAtomos;
    int longitud;
};
void crearLista(lista*),agregarElemento(lista*,grafo*),eliminarElemento(lista*);
void crearMolecula(grafo*),unirAtomo(grafo*,grafo*),eliminarAtomo(grafo*),destruirAtomo(grafo*);
void CrearMoleculas(grafo*);
int main(){
    grafo *molecula,*molecula2;
    printf("Hola\n");
    crearMolecula(molecula);
    crearMolecula(molecula2);
    unirAtomo(molecula,molecula2);
    printf("tam: %d\n",molecula->longitud);
    scanf("%d");
}
void crearLista(lista* ls){
    ls->cabeza = (NodoLista*)malloc(sizeof(NodoLista));
    ls->longitud=0;
}
void agregarElemento(lista* ls,grafo* nodoAjeno){
    NodoLista* nuevoElemento = (NodoLista*)malloc(sizeof(NodoLista));
    nuevoElemento->otroNucleo=nodoAjeno;
    if(ls->longitud>0){
        int i;
        NodoLista* aux = ls->cabeza;
        for(i=0;i<ls->longitud-1;i++,aux=aux->siguiente);
        aux->siguiente=nuevoElemento;
    }else{
        ls->cabeza=nuevoElemento;
    }
    ls->longitud++;
}
void eliminarElemento(lista* ls){
    if(ls->longitud>0){
        NodoLista* aux = ls->cabeza;
        ls->cabeza=aux->siguiente;
        aux=NULL;
        ls->longitud--;
    }
}
void crearMolecula(grafo* molecula){
    molecula->nucleo=(Nodo*)malloc(sizeof(Nodo));
    molecula->longitud=1;
    lista* list = molecula->otrosAtomos;
    crearLista(list);
    molecula->otrosAtomos=list;
}
//molecula es el nodo que vamos a unir a otra molecula
void unirAtomo(grafo* moleculaOrigen,grafo* atomoAjeno){
    printf("debug\n");
    atomoAjeno->nucleo->otroNucleo=moleculaOrigen->nucleo;
    agregarElemento(moleculaOrigen->otrosAtomos,atomoAjeno);
    moleculaOrigen->longitud+=atomoAjeno->longitud;
}
void eliminarAtomo(grafo* molecula){
    if(molecula->longitud>1){
        if(molecula->otrosAtomos->longitud>0){
            eliminarElemento(molecula->otrosAtomos);
        }
    }
}
void destruirAtomo(grafo* molecula){
    if(molecula->longitud>0 && molecula->longitud==1){
        if(molecula->otrosAtomos==0){
            free(molecula);
        }
    }
}
