#include "iostream"
#include "stdlib.h"
#include "string.h"
#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <iomanip>



using namespace std;

template <typename T>
class Nodo{
public:
  Nodo<T> *m_pSon[2];
  int factor_e;
  T m_dato;
public:
  Nodo(T d){
    m_dato=d;
    m_pSon[0]=m_pSon[1]=0;
    factor_e=0;
  }
};

template <typename T>
 class Tree_AVL{
 private:
   Nodo<T> *m_pRoot;
 public:
   Tree_AVL(){m_pRoot=0;}
   void RII(Nodo<T> *&p){
     Nodo<T> *q=p->m_pSon[0];
     Nodo<T> *r=q->m_pSon[0];
     p->m_pSon[0]=r->m_pSon[1];
     q->m_pSon[1]=p;
     p->factor_e=q->factor_e=0;

     p=q;
   }
   void RDD(Nodo<T> *&p){
     Nodo<T> *q=p->m_pSon[1];
     Nodo<T> *r=q->m_pSon[1];
     p->m_pSon[1]=r->m_pSon[0];
     q->m_pSon[0]=p;
     p->factor_e=q->factor_e=0;
     p=q;
   }
   void RID(Nodo<T> *&p){
    Nodo<T> *q=p->m_pSon[0];
    Nodo<T> *r=q->m_pSon[1];
    p->m_pSon[0]= r->m_pSon[1];
    q->m_pSon[1]= r->m_pSon[0];
    r->m_pSon[0]=p;
    r->m_pSon[1]=q;
    if(r->factor_e==0)p->factor_e=q->factor_e=0;
    if(r->factor_e==1){
      p->factor_e=-1;
      q->factor_e=0;
    }
    if(r->factor_e==-1){
      p->factor_e=0;
      q->factor_e=1;
    }
      p=r;
   }
   void RDI(Nodo<T> *&p){
    Nodo<T> *q=p->m_pSon[1];
    Nodo<T> *r=q->m_pSon[0];
    p->m_pSon[1]= r->m_pSon[0];
    q->m_pSon[0]= r->m_pSon[1];
    r->m_pSon[1]=p;
    r->m_pSon[0]=q;
    if(r->factor_e==0)p->factor_e=q->factor_e=0;
    if(r->factor_e==1){
      p->factor_e=-1;
      q->factor_e=0;
    }
    if(r->factor_e==-1){
      p->factor_e=0;
      q->factor_e=1;
    }
    p=r;
   }
   void add_R(T d,Nodo<T> *&p){
     if(!p){p=new Nodo<T>(d);return;}
     if(p->m_dato==d)return;
     add_R(d,p->m_pSon[p->m_dato<d]);
     /*if(p->m_dato<d)
     {
       p->factor_e=p->factor_e+1;
       cout<<p->factor_e;}
     else
     {
       p->factor_e=p->factor_e-1;
       cout<<p->factor_e;
     }*/

     p->factor_e+=(p->m_dato<d)?1:-1;
     //p->factor_e=(p->m_dato<d)?p->factor_e++:p->factor_e--;
     switch (p->factor_e) {
       case 0:return ;
       case -2:if(p->m_pSon[0]->factor_e==-1){RII(p);}
                else {RID(p);}break;
       case 2:if(p->m_pSon[1]->factor_e==1)RDD(p);
                else RDI(p);break;
     }
   }
   void add0(T d){
     add_R(d,m_pRoot);
   }
   void show_pre(Nodo<T> *p) {
     if(!p) return;

     show_pre(p->m_pSon[0]);
     cout<<p->m_dato<<" ";
     show_pre(p->m_pSon[1]);
   }
   void print(){
     show_pre(m_pRoot);
   }
   void print_root(){
     cout<<m_pRoot->factor_e<<endl;
   }
   void mostrar_arbol(Nodo<T> *p,int tab){
     if(p!=NULL){
       if(p->m_pSon[1]){
         mostrar_arbol(p->m_pSon[1],tab+4);
       }
       if(p->m_pSon[0]){
         mostrar_arbol(p->m_pSon[0],tab+4);
       }
       if(tab){
         cout<<setw(tab)<<" ";
       }
       cout<<p->m_dato<<"\n";
     }
   }
   void mostrar_arbol_completo(){
     mostrar_arbol(m_pRoot,0);
   }
 };
int main(int argc, char const *argv[]) {
  Tree_AVL<double> arbol;
  arbol.add0(1);
  arbol.add0(7);
  arbol.add0(3);
  arbol.add0(9);
  arbol.add0(4);
  arbol.add0(2);

  //arbol.print_root();
  arbol.mostrar_arbol_completo();
  return 0;
}
