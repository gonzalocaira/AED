#include "iostream"

using namespace std;

template <typename T>
class Nodo{
public:
  Nodo<T> *m_pSon[2];
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


};
