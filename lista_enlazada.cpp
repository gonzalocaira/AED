#include "iostream"

using namespace std;

template <typename T>

class Nodo{
private:
  T m_dato;
  Nodo<T> *p_sig;
public:
  Nodo() {}
  Nodo(T d){
    m_dato=d;
    p_sig=NULL;
  }
};

template <typename T>

class List{
private:
  Nodo<T> *p_head;
  Nodo<T> *p_last;
public:
  List(){
    p_head = p_last = NULL;
  }
  bool find(T d);
  bool find_recursivo(T d);
  bool Add(T d);
  bool find_recursivo(T d,Nodo<T> *p);
  bool isEmpty();
  bool delete_from();
};

template <typename T>
bool List<T>::isEmpty(){
  if(p_head==NULL)
    return true;
  return false;
}

template <typename T>
bool List<T>::find(T d){
  Nodo<T> *aux=p_head;
  if(isEmpty())return false;
  else{
    while(aux!=NULL){
      if(aux->m_dato==d){
        return true;
      }
      aux=aux->sig;
    }
    return false;
  }
}

template <typename T>
bool List<T>::find_recursivo(T d,Nodo<T> *p){
  if(!p)return false;
  if(p->m_dato == d) return true;
  return find_recursivo(d,p->p_sig);
}

template <typename T>
bool List<T>::delete_from(){
  Nodo<T> *aux;
  aux=p_head;
  if(isEmpty())
    return false;
  p_head=p_head->p_sig;
  delete aux;
  return true;
}


int main(){
  List<int> lista();
  return 0;
}
