#include "iostream"
#include "Cola.h"

using namespace std;

template <typename T>
bool Cola<T>::isEmpty(){
    if(!m_pFirst)return true;
    return false;
}
template <typename T>
void Cola<T>::Add_I(T d){
  Nodo<T> *nuevo=new Nodo<T>(d);
  if(isEmpty()){
    m_pFirst=nuevo;
    m_pLast=nuevo;
  }
  else{
    m_pLast->p_sig=nuevo;
    m_pLast=nuevo;
  }
}
template <typename T>
bool Cola<T>::find(T d,Nodo <T> **&p){
  p=&m_pFirst;
  while(*p){
    if((*p)->m_dato==d)return true;
    if((*p)->m_dato>d)return false;
    p=&((*p)->p_sig);
  }
  return false;
}
template <typename T>
bool Cola<T>::Add(T d){
  Nodo<T> *nuevo=new Nodo<T>(d);
  if(find(d))return false;
  else{
    if(isEmpty()){
      m_pFirst=nuevo;
      m_pLast=nuevo;
      return true;
    }else{
      m_pLast->p_sig=nuevo;
      m_pLast=nuevo;
      return true;
    }
  }
  return false;
}
template <typename T>
bool Cola<T>::Add_Esteroides(T d){
  Nodo<T> ** q;
  if(find(d,q))return false;
  Nodo<T> *tmp = *q;
  *q = new Nodo<T>(d);
  (*q)->p_sig=tmp;
  return true;
}

template <typename T>
void Cola<T>::imprimir(){
  Nodo<T> *tmp=m_pFirst;
  if(!tmp)return;
  while(tmp){
    cout<<tmp->m_dato<<"-";
    tmp=tmp->p_sig;
  }
  cout<<endl;
}
template <typename T>
T Cola<T>::extraer(){
    Nodo<T> *tmp=m_pFirst;
    T aux=tmp->m_dato;
    if(isEmpty()){cout<<"vacio";return 1;}
    else{
      if((tmp->p_sig)==NULL){
        delete tmp;
        return aux;}
      else{
      m_pFirst=m_pFirst->p_sig;
      delete tmp;
      return aux;}
    }
}

int main(int argc, char const *argv[]) {
  Cola<int> banco;
  banco.Add_Esteroides(14);
  banco.Add_Esteroides(15);
  banco.Add_Esteroides(12);
  banco.Add_Esteroides(17);
  //cout<<banco.isEmpty();
  banco.imprimir();
  banco.extraer();
  banco.imprimir();
  banco.extraer();
  banco.imprimir();
  banco.extraer();
  banco.imprimir();
  banco.extraer();
  banco.imprimir();
  banco.extraer();
  banco.imprimir();
  banco.extraer();
  banco.imprimir();
  return 0;
}
