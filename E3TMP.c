#include<stdio.h>
#include<stdlib.h>
typedef struct Nodo Nodo;
typedef struct Conjunto Conjunto;
struct Nodo{
    char l;
    Nodo* sig;
};
struct Conjunto{
    Nodo* cabeza;
    int tam;
};
void Insertar(char Elemento,Conjunto* con){
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->l=Elemento;
    if(con->tam>0){
        int i;
        Nodo* tmp=con->cabeza;
        for(i=0;i<con->tam-1;i++,tmp=tmp->sig);
        tmp->sig=nuevo;
    }else{
        con->cabeza=(Nodo*)malloc(sizeof(Nodo));
        con->cabeza=nuevo;
    }
    con->tam++;
}
void Eliminar(char Elemento,Conjunto* con){
    if(con->tam>0){
        int i;
        Nodo* mover=con->cabeza;
        for(i=0;i<con->tam;i++,mover=mover->sig){
            if(mover->l==Elemento){
                if(mover->sig!=NULL && mover->sig->sig!=NULL){
                    mover=mover->sig->sig;
                    con->tam--;
                    return;
                }
            }
        }
    }
}
void Imprimir(Conjunto con){
    if(con.tam>0){
        printf("%c ",con.cabeza->l);
        con.cabeza=con.cabeza->sig;
        con.tam--;
        Imprimir(con);
    }
}
Conjunto Union(Conjunto un1,Conjunto un2){
    Conjunto nuevo;
    nuevo.tam=0;
    if(un1.tam>0 && un2.tam>0){
        int i;
        for(i=0;i<un1.tam;i++,un1.cabeza=un1.cabeza->sig){
            Insertar(un1.cabeza->l,&nuevo);
        }
        for(i=0;i<un2.tam;i++,un2.cabeza=un2.cabeza->sig){
            int j;
            for(j=0;j<nuevo.tam;j++){
                if(un2.cabeza->l);
            }
        }
        return nuevo;
    }
    
}
Conjunto Interseccion(Conjunto u1,Conjunto u2){
    Conjunto nuevo;
    nuevo.tam=0;
    if(u1.tam>0 && u2.tam>0){
        int i;
        Conjunto tmp1=u1,tmp2=u2,tmp3=nuevo;
        for(i=0;i<u1.tam;i++,tmp1.cabeza=tmp1.cabeza->sig){
            if(tmp1.cabeza->l==tmp2.cabeza->l){
                int j,r=0;
                for(j=0;j<nuevo.tam;j++,tmp3.cabeza=tmp3.cabeza->sig){
                    if(tmp1.cabeza->l==tmp3.cabeza->l){
                        r=1;
                        break;
                    }
                }
                if(r==0){
                    Insertar(tmp1.cabeza->l,&nuevo);
                }
            }
        }
        tmp1=u1,tmp2=u2,tmp3=nuevo;
        for(i=0;i<u2.tam;i++,tmp2.cabeza=tmp2.cabeza->sig){
            if(tmp1.cabeza->l==tmp2.cabeza->l){
                int j,r=0;
                for(j=0;j<nuevo.tam;j++,tmp3.cabeza=tmp3.cabeza->sig){
                    if(tmp2.cabeza->l==tmp3.cabeza->l){
                        r=1;
                        break;
                    }
                }
                if(r==0){
                    Insertar(tmp2.cabeza->l,&nuevo);
                }
            }
        }
        return nuevo;
    }
}
int main(){
    Conjunto con;
    Conjunto con2;
    con2.tam=0;
    con.tam=0;
    Insertar('a',&con);
    Insertar('2',&con);
    Insertar('e',&con);
    Insertar('c',&con);
    Insertar('x',&con);
    Insertar('A',&con2);
    Insertar('2',&con2);
    Insertar('e',&con2);
    Insertar('3',&con2);
    Insertar('x',&con2);

    Conjunto con3 = Union(con2,con2);
    Imprimir(con3);
    int x;
    scanf("%d",&x);

}
