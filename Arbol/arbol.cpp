#include "arbol.h"

template <typename T>
bool Tree<T>::find_R(T d,Nodo<T> *p){
  if(!p)return false;
  if(p->m_dato== d)return true;
  return find_R(d,p->m_pSon[p->m_dato<d]);
}
template <typename T>
bool Tree<T>::find_I(T d,Nodo<T> *p){
  if(!*p)return false;
  else{
    if((*p)->m_dato== d)return true;
    if((*p)->m_dato > d)return find_R(d,p->m_pSon[0]);
    if((*p)->m_dato < d)return find_R(d,p->m_pSon[1]);
    return false;
  }
}

template <typename T>
bool Tree<T>::find(T d){
  Nodo<T> *tmp=m_pRoot;
  if(tmp->m_dato== d)return true;
  tmp=tmp->m_pSig;
  while(tmp){
    if(tmp->m_dato==d)return true;
    //Esto reemplaza a los dos if de abajo
    //tmp=tmp->m_pSon[tmp->m_dato<d];
    if(tmp->m_dato>d)tmp=tmp->m_pSon[0];
    if(tmp->m_dato<d)tmp=tmp->m_pSon[1];
  }
  return false;
}
template <typename T>
bool Tree<T>::add_R(T d,Nodo<T> *&p){
      if(!p){p=new Nodo<T>(d);return true;}
      if(p->m_dato==d) return false;
      return add_R(d,p->m_pSon[p->m_dato<d]);
}
/*
template <typename T>
void Tree<T>::add_I(T d){
  Nodo<T> *p,*q;
  p=q=m_pRoot;
  while(p){
    q=p;
    if(p->m_dato==d) return;
    p=p->m_pSon[p->m_dato<d];
  }
  q->m_pSon[p->m_dato<d]=new Nodo<T>(d);
  if(!q)m_pRoot=q;
  //else if(q-)
}*/

template <typename T>
bool Tree<T>::find_E(T d,Nodo<T> **&p){
  p=&m_pRoot;
  while(*p){
    if((*p)->m_dato==d) return true;
    p=&((*p)->m_pSon[(*p)->m_dato<d]);
  }
  return false;
}

template <typename T>
void Tree<T>::show_pre(Nodo<T> *p) {
  if(!p) return;
  cout<<p->m_dato<<" ";
  show_pre(p->m_pSon[0]);
  show_pre(p->m_pSon[1]);
}

template <typename T>
void Tree<T>::show_pos(Nodo<T> *p) {
  if(!p) return;
  show_pos(p->m_pSon[0]);
  show_pos(p->m_pSon[1]);
  cout<<p->m_dato<<" ";
}

template <typename T>
void Tree<T>::show_in(Nodo<T> *p) {
  if(!p) return;
  show_in(p->m_pSon[0]);
  cout<<p->m_dato<<" ";
  show_in(p->m_pSon[1]);
}

template <typename T>
void Tree<T>::show(int q){
  if(q=1)show_pre(m_pRoot);
  else if(q=2)show_pos(m_pRoot);
  else if(q=3)show_in(m_pRoot);
}

template <typename T>
void Tree<T>::add_I(T d){
  Nodo<T> **q;
  if(find_E(d,q))return;
  *q=new Nodo<T>(d);
}
/*
template <typename T>
bool Tree<T>::add(T d){
  Nodo <T> *nuevo=new Nodo<T>(d);
  Nodo <T> *tmp = m_pRoot;
  if(!tmp){m_pRoot = nuevo; return true;}
  else{
    while(tmp){
      if()
    }
  }
}*/
int main(int argc, char const *argv[]) {
  /* code */
  Tree<int> Binary;
  Binary.add_I(2);Binary.add_I(2);Binary.add_I(4);
  Binary.show(1);


  return 0;
}
