#include<stdio.h>
#include<stdlib.h>
typedef struct Nodo Nodo;
typedef struct grafo grafo,*funcionGrafo;
typedef struct NodoLista NodoLista;
typedef struct lista lista,*funcionLista;
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
    funcionLista (*crearLista)(lista*),(*agregarElemento)(lista*,grafo*),(*eliminarElemento)(lista*);
};
struct grafo{
    Nodo* nucleo;
    lista* otrosAtomos;
    int longitud;
    funcionGrafo (*crearMolecula)(grafo*),(*unirAtomo)(grafo*,grafo*),(*eliminarAtomo)(grafo*),(*destruirAtomo)(grafo*);
};
funcionLista crearLista(lista*),agregarElemento(lista*,grafo*),eliminarElemento(lista*);
funcionGrafo crearMolecula(grafo*),unirAtomo(grafo*,grafo*),eliminarAtomo(grafo*),destruirAtomo(grafo*);
void CrearMoleculas(grafo*);
int main(){
    grafo *molecula,*molecula2;
    printf("Hola\n");
    CrearMoleculas(molecula);
    CrearMoleculas(molecula2);
    molecula->unirAtomo(molecula,molecula2);
    printf("tam: %d\n",molecula->longitud);
}
funcionLista crearLista(lista* ls){
    ls->cabeza = (NodoLista*)malloc(sizeof(NodoLista));
    ls->longitud=0;
}
funcionLista agregarElemento(lista* ls,grafo* nodoAjeno){
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
funcionLista eliminarElemento(lista* ls){
    if(ls->longitud>0){
        NodoLista* aux = ls->cabeza;
        ls->cabeza=aux->siguiente;
        aux=NULL;
        ls->longitud--;
    }
}
funcionGrafo crearMolecula(grafo* molecula){
    molecula->nucleo=(Nodo*)malloc(sizeof(Nodo));
    molecula->longitud=1;
    molecula->otrosAtomos->agregarElemento = agregarElemento;
    molecula->otrosAtomos->crearLista= crearLista;
    molecula->otrosAtomos->eliminarElemento= eliminarElemento;
    molecula->otrosAtomos->crearLista(molecula->otrosAtomos);
}
//molecula es el nodo que vamos a unir a otra molecula
funcionGrafo unirAtomo(grafo* moleculaOrigen,grafo* atomoAjeno){
    printf("debug\n");
    atomoAjeno->nucleo->otroNucleo=moleculaOrigen->nucleo;
    moleculaOrigen->otrosAtomos->agregarElemento(moleculaOrigen->otrosAtomos,atomoAjeno);
    moleculaOrigen->longitud+=atomoAjeno->longitud;
}
funcionGrafo eliminarAtomo(grafo* molecula){
    if(molecula->longitud>1){
        if(molecula->otrosAtomos->longitud>0){
            molecula->otrosAtomos->eliminarElemento(molecula->otrosAtomos);
        }
    }
}
funcionGrafo destruirAtomo(grafo* molecula){
    if(molecula->longitud>0 && molecula->longitud==1){
        if(molecula->otrosAtomos==0){
            free(molecula);
        }
    }
}
void CrearMoleculas(grafo* molecula){
    printf("debug\n");
    molecula->crearMolecula=crearMolecula;
    molecula->unirAtomo=unirAtomo;
    molecula->eliminarAtomo=eliminarAtomo;
    molecula->destruirAtomo=destruirAtomo;
    printf("debug\n");
    molecula->crearMolecula(molecula);
}