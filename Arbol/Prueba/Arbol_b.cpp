#include <iostream>
using namespace std;

template <class T>
class Nodo{
public:
  T m_pDato;
  Nodo <T>* m_pSon[2];
  //Node <T> * right;
  //Node <T> * parent;
public:
  Nodo (T d){
    //parent=0;
    m_pSon[0]=m_pSon[1]=0;
    m_pDato=d;
  }
};

template <class T>
class Tree{
  //typedef Node<T>  * pNodo;
  //typedef Node<T>  ** pdNodo;
  //  private:
public:
      Nodo<T> * m_pRoot;
    public:
      Tree(){
        m_pRoot=0;
      }
      bool Find (T d, Nodo <T> **&p){
        p=&m_pRoot;
        while (*p){
          if ((*p)->m_pDato==d) return true;
            //pp=(*p);
            p=&(*p)->m_pSon[(*p)->m_pDato<d];
        }
        return false;
      }
      bool Add (T d){
        Nodo <T> **q;
        //pq=new Nodo<T>(0);
        if (Find(d,q)) return false;
        *q=new Nodo<T>(d);
        //(*q)->parent=pq;
        return true;
      }

      bool Find_father (T d){
        Nodo <T> *padre_q;
        Nodo <T> *q;
        q=padre_q=m_pRoot;
        while (q){
          if (q->m_pDato==d) break;
            padre_q=(q);
            q=(q)->m_pSon[(q)->m_pDato<d];
        }
        if (!q)    return false;
        cout<<"padre "<<padre_q->m_pDato<<endl;
        return true;
      }


      /*bool sibling (T d){
        Node <T> **q;
        Node <T> *pq;
        if (Find(d,q,pq)) return false;
        *q=new Node<T>(d);
        (*q)->parent=pq;
        return true;
      }*/
      void Print (Nodo <T> **p){
        if (!(*p)) return;
        //cout<<"padre: "<<((*p)->parent)->m_pDato<<endl;
        cout<<"Nodo: "<<(*p)->m_pDato<<endl;

        Print (&(*p)->m_pSon[0]);

        Print (&(*p)->m_pSon[1]);
      }
      int Quantity (Nodo <T> *p){
        if (p) return 1+Quantity (p->m_pSon[1])+Quantity (p->m_pSon[0]);
        else return 0;
      }

      int Altura_Arbol(Nodo<T> *p){
          if (!p) return 0;
          return max(Altura_Arbol(p->m_pSon[0]),Altura_Arbol(p->m_pSon[0]))+1;
      }

      /*
      pNodo get_root(){
        return m_pRoot;
      }
      pdNodo get_rootP (){
        Node <T> **q;
        q=&m_pRoot;
        return q;
      }*/
};

int main (){
Tree <int> Arbol;
Arbol.Add(10);
Arbol.Add(15);
Arbol.Add(5);
Arbol.Add(3);
Arbol.Add(17);
Arbol.Add(7);
Arbol.Add(1);
Arbol.Add(13);
Arbol.Add(11);
Arbol.Add(4);
Arbol.Print(&Arbol.m_pRoot);
Arbol.Find_father(3);
cout<<"altura"<<endl;
cout<<Arbol.Altura_Arbol(Arbol.m_pRoot)<<endl;
//cout<<"Cantidad: "<<Arbol.Quantity(Arbol.get_root())<<endl;
//cout<<"Hello"<<endl;
return 0;
}
