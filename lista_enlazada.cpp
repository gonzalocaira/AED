#include "iostream"

using namespace std;

template <typename T>

class Nodo{
public:
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
  bool add(T d);
  bool find_recursivo(T d,Nodo<T> *p);
  bool isEmpty();
  bool delete_from();
  void mostrar();
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

template <typename T>
void List<T>::mostrar(){
  Nodo<T> *aux= p_head;
  if(isEmpty())
    cout<<"vacio"<<endl;
  else{
    while(aux!=NULL){
      cout<<aux->m_dato<<endl;
      aux=aux->p_sig;
    }
    cout<<endl;
  }

}

template <typename T>
bool List<T>::add(T d){
  Nodo<T> *nuevo = new Nodo<T>(d);
  if(isEmpty()){
    p_head= nuevo;
    p_last= nuevo;
    return true;
  }
  else{
    p_last->p_sig =nuevo;
    p_last= nuevo;
    return true;
  }
  return false;
}
//COdigo DE CC2
int main(){
  List<int> lista;
  lista.add(1);
  lista.add(2);
  lista.add(3);
  lista.mostrar();

  return 0;
}
