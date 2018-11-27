#include <iostream>
using namespace std;

template<class T>
class Nodo
{
     public:
        Nodo<T>  * m_pSig;
             T     m_Dato;
     public:
       Nodo(T d){

          m_pSig=0;
          m_Dato=d;
       }
};

template<class T>
class List
{
    typedef Nodo<T>  * pNodo;
    public:
       pNodo m_pHead;
       pNodo m_pLast;
    public:
       List()
       {
         m_pHead = 0;
         m_pLast =0;
       }

      void push_front(T d)
      {
           pNodo pNuevo   =  new Nodo<T>(d);
           if ( !m_pHead )
				m_pHead = m_pLast = pNuevo;
           else
			{
                pNuevo->m_pSig = m_pHead;
				m_pHead = pNuevo;
            }
      }


	void push_back(T d){
		pNodo pNuevo   =  new Nodo<T>(d);
           if ( !m_pHead )
				m_pHead = m_pLast = pNuevo;
           else
			{
				m_pLast->m_pSig = pNuevo;
				m_pLast=pNuevo;
            }
	}

    void pop_front(){
	  if(!m_pHead) return;
      pNodo temp = m_pHead;
      m_pHead = m_pHead->m_pSig;
      delete temp;
    }
	void pop_back()
   {
		if(!m_pHead) return;
		if(m_pHead == m_pLast)
		{
		  delete m_pHead;
		  m_pHead = m_pLast =0;
		}
		pNodo tmp = m_pHead;
		for(  ; tmp->m_pSig!=m_pLast; tmp = tmp->m_pSig);
		delete m_pLast;
		m_pLast = tmp;
		//cout<<"se borro: "<<m_pLast->m_Dato;
   }

   void Print()
   {
       Nodo<T> *p = m_pHead;
       for(;p!=NULL;p=p->m_pSig){
        cout<<p->m_Dato<<" ";
       }
   }

    bool find(T d,Nodo<T> **&p){
      p=&m_pHead;
      while(*p){
        //cout<<(*p)->m_value<<" "<<d<<endl;
        if((*p)->m_Dato == d)
          return true;
        if((*p)->m_Dato > d){
          return false;
        }
        p=&(*p)->m_pSig;
      }
      return false;
    }

bool add(T d){
        Nodo<T> **q;
        if(!find(d,q)){
            Nodo<T> *Nuevo = new Nodo<T>(d);
            Nuevo->m_pSig=*q;
            *q=Nuevo;
            return true;
        }
        return false;
    }

    bool is_empty(){
        if(m_pHead==NULL){
            return true;
        }
        else{
            return false;
        }
    }

};