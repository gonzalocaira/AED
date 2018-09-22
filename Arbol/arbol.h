#include "iostream"
#include "stdlib.h"
#include "string.h"
#include <algorithm>
#include <fstream>
#include <stdio.h>



using namespace std;

template <typename T>
class Nodo{
public:
  Nodo<T> *m_pSon[2];
  //char caracteres[100];
  T m_dato;
public:
  Nodo(T d){
    m_dato=d;
    m_pSon[0]=m_pSon[1]=0;
  }
};

template <typename T>
class Tree{
private:
  Nodo<T> *m_pRoot;
public:
  Tree(){m_pRoot=0;}
  bool find_R(T d,Nodo<T> *p);
  bool add_R(T d,Nodo<T> *&p);
  void show_pre(Nodo<T> *p);
  void show_in(Nodo<T> *p);
  void show_pos(Nodo<T> *p);
  void show(int q);
  bool find(T d);
  bool find_E(T d,Nodo<T> **&p);
  bool find_I(T d,Nodo<T> *p);
  void add_I(T d);
  void add(T d);
  int altitude_R(Nodo<T> *p);
  void altitude();
  void print_R(Nodo<T> *p,ostream &os);
  void lectura();
  friend Tree<T> & operator<<(Tree<T> & L, T d)
  {
      L.add_I(d);
      return L;
  }
  friend ostream & operator<<(ostream & os, Tree<T> & L)
   {
       L.print_R(L.m_pRoot,os);
       return os;
   }
};
