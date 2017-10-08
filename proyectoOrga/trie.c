#include <stdio.h>
#include <stdlib.h>
#include "lista_ordenada.h"
#include <string.h>
#include "trie.h"

#define POS_NULA NULL
#define ELE_NULO NULL
#define FALSE 0
#define TRUE 1
#define LST_NO_INI 2
#define LST_POS_INI 3
#define LST_VAC 4
#define TRI_NO_INI 5
#define STR_NO_PER -1



int f(TNodo* n1, TNodo* n2){
    char c1= (*n1)->rotulo;
    char c2= (*n2)->rotulo;
    int res=0;

    if(c1>c2)
        res=1;
    else
        res=-1;

    return res;
}

int (*funcion)(TNodo *, TNodo *)=f;

TTrie crear_trie(){

    TTrie tri= malloc(sizeof(TTrie));
    TNodo node= malloc(sizeof(TNodo));
    node->hijos=crear_lista_ordenada(funcion);
    tri->raiz=node;
    tri->cantidad_elementos=0;

    return tri;
}


int tr_insertar(TTrie tr, char* str){

    int resultado=TRI_NO_INI;




    return resultado;
}

TNodo tr_recuperarPrimero_auxiliar(TTrie tr, char* str){
    /*uscar y retorna el nodo hijo de la raiz que tenga como rótulo el primer caracter de str
    Si no lo encuentra, retorna NULL*/
    TListaOrdenada hijos;
    TPosicion posActual,siguiente;
    TNodo primerNodo=NULL;
    int salir=0;

    if(tr_size(tr)>0 && strlen(str)>0){


        hijos= tr->raiz->hijos;
        posActual= lo_primera(hijos);
        primerNodo=posActual->elemento;

        while(salir==0 && *str != primerNodo->rotulo){
            //Busco al hijo de la raiz que contenga el primer caracter de la palabra pasada.
            siguiente=lo_siguiente(hijos,posActual);
            if(siguiente==POS_NULA)
                salir=1;
            else{
                posActual=siguiente;
                primerNodo=posActual->elemento;
            }
        }
    }
    return primerNodo;
}

TNodo tr_recuperarHijo_auxiliar(TNodo padre, char* s,TTrie tr){
    /*Buscar y retorna el nodo hijo de un nodo padre pasado por parámetro que tenga como rótulo el primer caracter de s.
    Si no lo encuentra, retorna NULL*/

    TListaOrdenada hijos;
    TPosicion hijoActual;
    TNodo nodoHijo=NULL;
    int salir=0;


    hijos=padre->hijos;

    if(lo_size(hijos)>0){

        hijoActual=lo_primera(hijos);
        nodoHijo=hijoActual->elemento;

        while(salir==0 && *s!=nodoHijo->rotulo){
            //Recorro la lista de hijos hasta hallar el nodo que contiene al caracter apuntado por s
            hijoActual=lo_siguiente(hijos,hijoActual);

            if(hijoActual==NULL)
                salir=1;
            else
                nodoHijo=hijoActual->elemento;
        }

        if(salir==1) nodoHijo=NULL; //No se encontró al nodo hijo que tiene el caracter s
    }
    return nodoHijo;
}

int tr_pertenece_auxiliar(TNodo padre, char* s,int longitud, TTrie tr){
    //función auxiliar y recusivo para la función tr_pertenece.

    TNodo nodoHijo;
    int resultado=FALSE;

    if(padre->contador > 0 && longitud==1 && *s==padre->rotulo)
        resultado= TRUE;
    else{

        if(!(*s!=padre->rotulo || (longitud==1 && padre->contador==0) || (*s==padre->rotulo && longitud>1))){

            nodoHijo=tr_recuperarHijo_auxiliar(padre,s,tr);
                if(nodoHijo!=NULL){ //Se encontro al nodo hijo que tiene el caracter s
                    s++;
                    resultado=tr_pertenece_auxiliar(nodoHijo,s,longitud-1,tr);
                }

            } else resultado=FALSE;
          }

    return resultado;
} //FIN metodo auxiliar recursivo de pertenece.

int tr_pertenece(TTrie tr, char* str){

    int longitud= strlen(str);
    int resultado;

    //Busco al hijo de la raiz que contenga el primer caracter de la palabra pasada.
    TNodo primerNodo=tr_recuperarPrimero_auxiliar(tr,str);

    if(primerNodo!=NULL)
        resultado=tr_pertenece_auxiliar(tr->raiz,str,longitud,tr);


    return resultado;
}

int recuperar(TTrie tr, char* str){

    int resultado= STR_NO_PER;
    TNodo primerNodo=tr_recuperarPrimero_auxiliar(TTrie tr, char* str);
    TNodo auxiliar;


    if(tr_pertenece(tr,str)==TRUE && primerNodo!=NULL){



    }



    return resultado;
}