
#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class Nodo
{   
	 public:
	 	 T      m_Dato;
	 	 Nodo<T> * m_pSig; 

	 public:
	 	Nodo(T d):m_Dato(d),m_pSig(0){};
};

template<class T>
class Lista
{  
    public:
        Nodo<T> *  m_pHead;
    public:
       Lista():m_pHead(0){};

       bool find_R(T  d, Nodo<T> * & p)
       {
       	   if(!p){return false;}
       	   if (p->m_Dato == d) {return true;}
       	   return find_R(d,p->m_pSig);  

       }


       void Add_R(T  d, Nodo<T> * &  p)
       {
       	   if(!p){p = new Nodo<T>(d); return; }
       	   return Add_R(d,p->m_pSig);  

       }
       void Add(T d)
       {
       	    Add_R(d,m_pHead);
       }
	   void print_R(Nodo<T> *  p, ostream & os)
       {
       	   if(!p){return ;}
       	   os<<p->m_Dato<<endl;
       	   return print_R(p->m_pSig,os);  

       }

       void Add_I(T d)
       {
       	 Nodo<T> * pNuevo = new Nodo<T>(d);
       	 if(!m_pHead)
         {
            m_pHead = pNuevo;
            return;	
         }
         Nodo<T> * tmp = m_pHead;
         for( ; tmp->m_pSig; tmp=tmp->m_pSig);
         tmp->m_pSig = pNuevo;	
         

       }

       friend Lista<T> & operator<<(Lista<T> & L, T d)
       {
       	   //L.Add_R(d,L.m_pHead);
       	   ////L.Add_I(d);
       	   L.AddE(d);
       	   return L;
       }

      friend ostream & operator<<(ostream & os, Lista<T> & L)
       {
       	   L.print_R(L.m_pHead,os);
       	   return os;
       }


       bool find(T d, Nodo<T>  ** & p)
       {
       	    p = &m_pHead;
       	    while(*p)
       	    {
       	    	if ((**p).m_Dato == d) return true;
       	    	if ((*p)->m_Dato > d) return false;
       	    	p = &((*p)->m_pSig);
       	    }
       	    return false;
       }

      bool AddE(T d)
      {
      	  Nodo<T>  ** q;
      	  if(find(d,q)) return false;
      	  Nodo<T> * tmp = *q;
      	  *q = new Nodo<T>(d);
      	  (*q)->m_pSig = tmp;
      	  return true;

      }







};
int main()
{

    ofstream F("file.txt");  
	Lista<int>  A;
	A<<3<<45<<65;
	cout<<A;
	F<<A;

	
}




