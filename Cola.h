#include "iostream"

using namespace std;

template <typename T>
class Nodo{
public:
  T m_dato;
  Nodo<T> *p_sig;
  //template <typename T> friend class Cola;
public:
  Nodo(T d){
    m_dato=d;
    p_sig=NULL;
  }
};
template<typename T>
class Cola{
private:
  Nodo<T> *m_pFirst;
  Nodo<T> *m_pLast;
public:
  Cola(){
    m_pFirst=NULL;
    m_pLast=NULL;
  }
  bool isEmpty();
  void Add_I(T d);
  bool Add(T d);
  //bool Add_last(T d);
  //bool Add_from(T d);
  bool find(T d,Nodo<T> **&p);
  void imprimir();
  bool Add_Esteroides(T d);
  T extraer();
};
