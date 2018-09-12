#include "iostream"
#include "fstream"

using namespace std;

template <typename T>
class Nodo{
public:
    T m_dato;
    Nodo<T> *m_pSig;
  public:
    Nodo(T d):m_dato(d),m_pSig(0){}
};

template <typename T>
class Lista{
private:
  Nodo<T> *m_pHead;
  Nodo<T> *m_pTail;
public:
  Lista():m_pHead(0),m_pTail(0){}
  bool isEmpty();
  bool find_R(T d,Nodo<T> *&p);
  void add_R(T d,Nodo<T> *&p);
  void add(T d);
  void print_R(Nodo<T> *p,ostream &os);
  void add_I(T d);
  //friend Lista<T>& operator<<(Lista<T> &L,T d);
  //friend ostream & operator<<(ostream & os,Lista<T> & L);
  bool find(T d,Nodo<T> **&p);
  bool add_E(T d);
};
template <typename T>
bool Lista<T>::isEmpty(){
  if(m_pHead==NULL)return true;
  return false;
}

template <typename T>
bool Lista<T>::find_R(T d,Nodo<T> *&p){
  if(!p){return false;}
  if(p->m_dato==d)return true;
  return find(d,p->m_pSig);
}

template<typename T>
void add_R(T d,Nodo<T> *&p){
  if(!p){p=new Nodo<T>(d),return;}
  return add_R(d,p->m_pSig);
}
template <typename T>
void add(T d){
  add_R(d,m_pHead);
}
template <typename T>
void print_R(Nodo<T> *p,ostream &os){
  if(!p)return;}
  os<<p->m_dato<<endl;
  return print_R(p->m_pSig,os);
}

int main(int argc, char const *argv[]) {

  return 0;
}
