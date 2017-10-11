#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define POS_NULA NULL
#define ELE_NULO NULL
#define FALSE 0
#define TRUE 1
#define LST_NO_INI 2
#define LST_POS_INI 3
#define LST_VAC 4
#define TRI_NO_INI 5
#define STR_NO_PER -1





TLista crear_lista(){
    TLista l=malloc(sizeof(struct lista));
    l->cantidad_elementos=0;
    l->primer_celda=NULL;
    return l;
}

int l_insertar(TLista lista, TPosicion pos, TElemento elem){

    TCelda nueva=malloc(sizeof(struct celda));
    nueva->elemento=elem;
    nueva->proxima_celda=NULL;
    TCelda aux=lista->primer_celda;
    int r=FALSE;

    if(pos==POS_NULA){
        /*LISTA NO VACIA E INSERTAR PRIMERO O VACIA*/
        nueva->proxima_celda = lista->primer_celda;
        lista->primer_celda=nueva;
        lista->cantidad_elementos++;
        r=TRUE;
    }
    else{

        if(lista->primer_celda==pos){/*Pos es el primer elemento de la lista.*/
            nueva->proxima_celda=lista->primer_celda;
            lista->primer_celda=nueva;
            lista->cantidad_elementos++;
        }
        else{ /*Pos no es el primer elemento de la lista, se debe buscar.*/
          while(aux->proxima_celda!=pos && aux->proxima_celda!=POS_NULA)
              aux=aux->proxima_celda;

          if (aux->proxima_celda==pos){/*Lo encontro
              colocar la nueva celda entre aux y pos*/
              nueva->proxima_celda=pos;
              aux->proxima_celda=nueva;
              lista->cantidad_elementos++;
          }
        }
        r=TRUE;
    }

    return r;
}

int l_eliminar(TLista lista, TPosicion pos){

    int r=FALSE;
    TCelda aux;
    if(lista!=NULL && l_size(lista)>0)
        aux=lista->primer_celda;

    if(pos!=POS_NULA){
        if(aux==pos){
            if (lista->cantidad_elementos!=1){//ES LA PRIMER CELDA DE LA LISTA, PERO NO LA UNICA.
                lista->primer_celda=aux->proxima_celda;
            }
            else//Un solo elemento y es pos
                lista->primer_celda=NULL;

        }
        else{
          /*Pos no es la primer celda*/
          while(aux->proxima_celda!=pos && aux->proxima_celda!=POS_NULA)
                aux=aux->proxima_celda;

          if (aux->proxima_celda==pos){/*Lo encontro, elimina celda*/
              aux->proxima_celda=pos->proxima_celda;
          }
        }
        r=TRUE;

        if(pos->elemento!=NULL)
            free(pos->elemento);

        free(pos);
        lista->cantidad_elementos--;
    }
    else
        r=LST_POS_INI;

    return r;
}

TPosicion l_primera(TLista lista){
    TPosicion r=POS_NULA;
    if(lista->cantidad_elementos!=0)
        r=lista->primer_celda;
    return r;
}

TPosicion l_ultima(TLista lista){
    TPosicion r=POS_NULA;
    if(lista->cantidad_elementos!=0){
        TCelda aux=lista->primer_celda;
        while(aux->proxima_celda!=POS_NULA){
            aux=aux->proxima_celda;
        }
        r=aux;
    }
    return r;
}

int l_size(TLista lista){return lista->cantidad_elementos;}

TPosicion l_anterior(TLista lista, TPosicion pos){

    TPosicion aux=POS_NULA;
    if(lista->primer_celda!=pos && pos!=POS_NULA){
        aux=lista->primer_celda;
        while(aux->proxima_celda!=POS_NULA && aux->proxima_celda!=pos)
            aux=aux->proxima_celda;
    }
    return aux;
}

TPosicion l_siguiente(TLista lista,TPosicion pos){

    TPosicion aux=POS_NULA;

    if(pos!=POS_NULA && lista!=NULL && l_size(lista)>0){
        aux=lista->primer_celda;
        while(aux!=pos && aux->proxima_celda!=POS_NULA)
            aux=aux->proxima_celda;
        aux=aux->proxima_celda;
    }

    return aux;
}

TElemento l_recuperar(TLista lista, TPosicion pos){

    TElemento tr=ELE_NULO;
    TCelda aux;

    if(pos!=POS_NULA && lista!=NULL){ /*Lo busco en la lista.*/
        aux=lista->primer_celda;
        while(aux!=pos && aux->proxima_celda!=POS_NULA)
            aux=aux->proxima_celda;

        if(aux==pos) /*Se encontró pos en la lista.*/
            tr=aux->elemento;
    }
    return tr;
}

