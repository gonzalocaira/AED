#include "iostream"

using namespace std;

template <typename T>
class Nodo{
public:
  T m_dato;
  Nodo<T> *m_pSig;
  Nodo<T> *m_pAnt;
public:
  Nodo(T d){
    p_sig=NULL;
    p_ant=NULL;
  }
};

template <typename T>
class Lista{
public:
  Nodo<T> *m_first;
  Nodo<T> *m_last;
public:
  Lista():m_first(0),m_last(0){};
  bool isEmpty(){
    if(!m_first)return true;
    return false;
  }
  bool find_R(T d,Nodo<T> *&p){
    if(!p){return false;}
    if(p->m_dato==d){return true;}
    return find_R(d,p->m_pSig)
  }
  bool find_I(T d){
    Nodo<T> *tmp=m_first;
    if(isEmpty()){
      return false;
    }
    else{
      while(!tmp){
        if(tmp->m_dato==d)return true;
        tmp=tmp->m_pSig;
      }
    }
  }
  bool Add_ordenado(T d)
};


int main(int argc, char const *argv[]) {

  return 0;
}
