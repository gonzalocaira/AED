#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;

template <class T>
class nodo{
  public:
    T dato;
    nodo<T>* son[2];
    nodo<T>* padre;
    char color;
  public:
    nodo(T d){
      this->dato = d;
      this->son[0]=this->son[1]= NULL;
      this->color='r';
      this->padre=NULL;
    }
    nodo(){
      this->son[0]=this->son[1]=this->padre= NULL;
    }
};
#endif // NODO_H
