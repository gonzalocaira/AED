#ifndef RED_BLACK_H
#define RED_BLACK_H
#include <iostream>
#include "nodo.h"
using namespace std;
const char NEGRO='n';
const char ROJO='r';

template <class T>
class red_black{
public:
  nodo<T> *root;
private:
  void insercion_caso1(nodo<T> *&n);
  void insercion_caso2(nodo<T> *&n);
  void insercion_caso3(nodo<T> *&n);
  void insercion_caso4(nodo<T> *&n);
  void insercion_caso5(nodo<T> *&n);
  nodo<T>* abuelo(nodo<T> *n);
  nodo<T>* tio(nodo<T> *n);

  void eliminar_caso1(nodo<T> *n);
  void eliminar_caso2(nodo<T> *n);
  void eliminar_caso3(nodo<T> *n);
  void eliminar_caso4(nodo<T> *n);
  void eliminar_caso5(nodo<T> *n);
  void eliminar_caso6(nodo<T> *n);
  nodo<T>* hermano(nodo<T> *n);

  bool find(T d,nodo<T> **&p);

public:
  red_black(){
    root=NULL;
  }
  void insert(T d);
  void del(T d);
  void elimina_un_hijo(T d);
  void rotar_izda(nodo<T> *p);
  void rotar_dcha(nodo<T> *p);

void llenar(nodo<T>*  p, ostream & os){
    int temp=p->dato;
//colores
    if(p->color=='n'){
        os<<"structNodo"<<temp<<"[style=filled ,fillcolor=grey26 label="<<p->dato<<"];"<<endl;
    }
    if(p->color=='r'){
        os<<"structNodo"<<temp<<"[style=filled ,fillcolor=red label="<<p->dato<<"];"<<endl;
    }
    //os<<"structNodo"<<temp<<"[label="<<p->dato<<"];"<<endl;
    if(p->son[0]){
        llenar(p->son[0],os);
    os<<"structNodo"<<temp<<"->"<<"structNodo"<<(p->son[0])->dato<<";"<<endl;
    }
    if(!(p->son[0])){
        os<<"structNULLL"<<temp<<"[style=filled ,fillcolor=grey26"<<" label=vacio];"<<endl;
    os<<"structNodo"<<temp<<"->"<<"structNULLL"<<temp<<";"<<endl;
    }
    if(p->son[1]){
        llenar(p->son[1],os);
    os<<"structNodo"<<temp<<"->"<<"structNodo"<<(p->son[1])->dato<<";"<<endl;
    }
    if(!(p->son[1])){
        os<<"structNULLR"<<temp<<"[style=filled ,fillcolor=grey26"<<" label=vacio];"<<endl;
    os<<"structNodo"<<temp<<"->"<<"structNULLR"<<temp<<";"<<endl;
    }
  }
void print_very_first_time(nodo<T> *  p, ostream & os){
         os<<"digraph structs {"<<endl;
         os<<"node [shape=record];"<<endl;
         llenar(p,os);
         os<<"}"<<endl;
  }
  friend red_black<T> & operator<<(red_black<T> & L, T d)
  {
         L.insert(d);
         return L;
  }

 friend ostream & operator<<(ostream & os, red_black<T> & L)
  {
         L.print_very_first_time(L.root,os);
         return os;
  }
};
template<typename T>
void red_black<T>::insert(T d){
    //repeat = false;
    nodo<T> *temp;
    nodo<T> *q;
    //if(p->dato == d)	return;
    if(!root){
        root = new nodo<T>(d);
        temp=root;
    }
    else{
        temp = root;
        q = temp;
        while(temp){
            if(temp->dato == d) return; //return
            q = temp;
            temp = temp->son[ temp->dato < d ];
        }
        temp=new nodo<T>(d);
        q->son[ q->dato < d ] = temp;
        temp->padre = q;
        temp = q->son[ q->dato < d ];
    }
    insercion_caso1(temp);
}/*
template <class T>
void red_black<T>::rotar_izda(nodo<T> *&p){
    nodo<T> **aux=&root;
    if(p->padre!=NULL && p->padre->son[1]==p)
        aux=&(p->padre->son[1]);
    else if(p->padre!=NULL && p->padre->son[0]==p)
        aux=&(p->padre->son[0]);

    *aux=p->son[1];
    (*aux)->padre=p->padre;
    p->padre=*aux;
    p->son[1]=(*aux)->son[0];
    (*aux)->son[0]=p;

    if(p->son[1]!=NULL) p->son[1]->padre=p;
}
template <class T>
void red_black<T>::rotar_dcha(nodo<T> *&p){
    nodo<T> **aux=&root;
    if(p->padre!=NULL && p->padre->son[1]==p)
        aux=&(p->padre->son[1]);
    else if(p->padre!=NULL && p->padre->son[0]==p)
        aux=&(p->padre->son[0]);

    *aux=p->son[0];
    (*aux)->padre=p->padre;
    p->padre=*aux;
    p->son[1]=(*aux)->son[1];
    (*aux)->son[1]=p;

    if(p->son[0]!=NULL) p->son[1]->padre=p;
}*/
template <class T>
void red_black<T>::rotar_izda(nodo<T> *p) {
    nodo<T> *right_child = p->son[1];
    p->son[1] = right_child->son[0];
    cout<<p->dato<<endl;
    if (p->son[1] != NULL)
        p->son[1]->padre = p;

    right_child->padre = p->padre;

    if (p->padre == NULL)
        root = right_child;
    else{
        if (p == p->padre->son[0])
            (p->padre)->son[0] = right_child;
        else
            (p->padre)->son[1] = right_child;
    }
    right_child->son[0] = p;
    p->padre = right_child;
}
template <class T>
void red_black<T>::rotar_dcha(nodo<T> *p) {
    nodo<T> *left_child = p->son[0];
    p->son[0] = left_child->son[1];

    if (p->son[0] != NULL)
        p->son[0]->padre = p;

    left_child->padre = p->padre;

    if (p->padre == NULL)
        root = left_child;
    else if (p == p->padre->son[0])
        p->padre->son[0] = left_child;
    else
        p->padre->son[1] = left_child;

    left_child->son[1] = p;
    p->padre = left_child;
}
template <class T>
void red_black<T>::insercion_caso1(nodo<T> *&n){
    if(n->padre == NULL){
        n->color = NEGRO;
        return;
    }
    else
        insercion_caso2(n);
}
template <class T>
void red_black<T>::insercion_caso2(nodo<T> *&n){
    nodo<T> *a=n->padre;
    if(a->color == NEGRO)   return;
    else
        insercion_caso3(n);
}
template <class T>
void red_black<T>::insercion_caso3(nodo<T> *&n){
    nodo<T> *t = tio(n), *a;

    if ((t != NULL) && (t->color == ROJO)) {
        n->padre->color = NEGRO;
        t->color = NEGRO;
        a = abuelo(n);
        a->color = ROJO;
        insercion_caso1(a);
    }
    else{
        insercion_caso4(n);
        }

}
template <class T>
void red_black<T>::insercion_caso4(nodo<T> *&n){
    nodo<T> *a = abuelo(n);
    if ((n == n->padre->son[1]) && (n->padre == a->son[0])) {
        cout<<n->padre->dato<<" "<<n->dato<<endl;
        rotar_izda(n->padre);
        cout<<n->padre->dato<<" "<<n->dato<<endl;
        n=n->son[0];
    } else if ((n == n->padre->son[0]) && (n->padre == a->son[1])) {
        rotar_dcha(n->padre);
        n=n->son[1];
        cout<<n->padre->dato<<endl;
    }
    insercion_caso5(n);
}
template <class T>
void red_black<T>::insercion_caso5(nodo<T> *&n){
    nodo<T> *a = abuelo(n);

    n->padre->color = NEGRO;
    a->color = ROJO;
    if ((n == n->padre->son[0]) && (n->padre == a->son[0])) {
        rotar_dcha(a);
    } else {
        // En este caso, (n == n->padre->dcho) && (n->padre == a->dcho).
        rotar_izda(a);
    }
}
template <class T>
nodo<T>* red_black<T>::abuelo(nodo<T> *n){
    if ((n != NULL) && (n->padre != NULL))
        return n->padre->padre;
    else
        return NULL;
}
template <class T>
nodo<T>* red_black<T>::tio(nodo<T> *n){
    nodo<T> *a = abuelo(n);
    if (n->padre == a->son[0])
        return a->son[1];
    else
        return a->son[0];
}
//////delete..
template <class T>
bool red_black<T>::find(T d,nodo<T> **&p){
  p=&root;
  while(*p){
    if((*p)->dato == d) return true;
    p=&((*p)->son[(*p)->dato < d]);
  }
  return false;
}
template <class T>
nodo<T>* red_black<T>::hermano(nodo<T> *n){
    if (n == n->padre->son[0])
        return n->padre->son[1];
    else
        return n->padre->son[0];
}
template <class T>
void red_black<T>::del(T d){
    nodo<T> **q,*p;
    find(d,q);
    p=*q;
    if(p->son[0]==NULL && p->son[1]==NULL){
        if(p->padre->son[0] == p) p->padre->son[0]=p->son[1];
        else    p->padre->son[1]=p->son[1];
        if(p->color==NEGRO && p!=root) eliminar_caso1(p->padre);
        delete p;
    }
    if(p->son[1]!=NULL && p->son[0]==NULL){
        if(p->padre->son[0] == p) p->padre->son[0]=p->son[1];
        else    p->padre->son[1]=p->son[1];
        p->son[1]->padre=p->padre;
        eliminar_caso1(p->padre);
        delete p;
    }
    if(p->son[0]!=NULL && p->son[1]==NULL){
        if(p->padre->son[0] == p) p->padre->son[0]=p->son[0];
        else    p->padre->son[1]=p->son[0];
        p->son[0]->padre=p->padre;
        eliminar_caso1(p->padre);
        delete p;
    }
    if(p->son[0]!=NULL && p->son[1]!=NULL){
        nodo<T> *temp=(p->son[1]);
        while(temp){
            if(temp->son[0]==NULL)  break;
            temp=temp->son[0];
        }
        if(p->padre->son[0] == p) p->padre->son[0]=temp;
        else    p->padre->son[1]=temp;
        temp->padre->son[0]=temp->son[1];
        temp->padre=p->padre;
        temp->son[0]=p->son[0];
        p->son[0]->padre=temp;
        if(temp != p->son[1])   temp->son[1]=p->son[1];
        eliminar_caso1(p->padre);
        delete p;
    }
}
template <class T>
void red_black<T>::elimina_un_hijo(T d){
    nodo<T> **p,*n,*hijo;
    find(d,p);
    n=(*p)->padre;
    hijo=*p;
    eliminar_caso1(n);
    //nodo<T> *hijo = es_hoja(n->son[1]) ? n->son[0] : n->son[1];

    //reemplazar_nodo(n, hijo);
    /*if (hijo->color == NEGRO) {
        if (n->color == ROJO)
            n->color = NEGRO;
        else
            eliminar_caso1(n);
    }*/
    delete(hijo);
}
//wiki
template <class T>
void red_black<T>::eliminar_caso1(nodo<T> *n){
    if (n->padre!= NULL)
        eliminar_caso2(n);
}
template <class T>
void red_black<T>::eliminar_caso2(nodo<T> *n){
    nodo<T> *hm = hermano(n);

    if (hm->color == ROJO) {
        n->padre->color = ROJO;
        hm->color = NEGRO;
        if (n == n->padre->son[0])
            rotar_izda(n->padre);
        else
            rotar_dcha(n->padre);
    }
    eliminar_caso3(n);
}
template <class T>
void red_black<T>::eliminar_caso3(nodo<T> *n){
    nodo<T> *hm = hermano(n);

    if ((n->padre->color == NEGRO) &&
     (hm->color == NEGRO) &&
     (hm->son[0]->color == NEGRO) &&
     (hm->son[1]->color == NEGRO)) {
        hm->color = ROJO;
        eliminar_caso1(n->padre);
    } else
        eliminar_caso4(n);
}
template <class T>
void red_black<T>::eliminar_caso4(nodo<T> *n){
    nodo<T> *hm = hermano(n);

    if ((n->padre->color == ROJO) &&
     (hm->color == NEGRO) &&
     (hm->son[0]->color == NEGRO) &&
     (hm->son[1]->color == NEGRO)) {
        hm->color = ROJO;
        n->padre->color = NEGRO;
    } else
        eliminar_caso5(n);
}
template <class T>
void red_black<T>::eliminar_caso5(nodo<T> *n){
    nodo<T> *hm = hermano(n);

    if ((n == n->padre->son[0]) &&
     (hm->color == NEGRO) &&
     (hm->son[0]->color == ROJO) &&
     (hm->son[1]->color == NEGRO)) {
        hm->color = ROJO;
        hm->son[0]->color = NEGRO;
        rotar_dcha(hm);
    } else if ((n == n->padre->son[1]) &&
     (hm->color == NEGRO) &&
     (hm->son[1]->color == ROJO) &&
     (hm->son[0]->color == NEGRO)) {
        hm->color = ROJO;
        hm->son[1]->color = NEGRO;
        rotar_izda(hm);
    }
    eliminar_caso6(n);
}
template <class T>
void red_black<T>::eliminar_caso6(nodo<T> *n){
    nodo<T> *hm = hermano(n);

    hm->color = n->padre->color;
    n->padre->color = NEGRO;
    if (n == n->padre->son[0]) {
        /*
         * Aquí, hm->dcho->color == ROJO.
         */
        hm->son[1]->color = NEGRO;
        rotar_izda(n->padre);
    } else {
        /*
         * Aquí, hm->izdo->color == ROJO.
         */
        hm->son[0]->color = NEGRO;
        rotar_dcha(n->padre);
    }
}

#endif // RED_BLACK_H
