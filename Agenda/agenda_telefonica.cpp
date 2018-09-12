
#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class Persona
{
	 public:
		 T DNI;
	 	 T nombre;
	 	 T direccion;
	 	 T telefono;
	 	 T edad;
	 	 //T      m_Dato;
	 	 Persona<T> * m_pSig;

	 public:
	 	Persona(T dni,T nom_,T dir_,T tel_,T ed_):DNI(dni),nombre(nom_),direccion(dir_),telefono(tel_),edad(ed_),m_pSig(0){};

};

template<class T>
class Agenda
{
    public:
        Persona<T> *  m_pHead;
				Persona<T> *  m_pLast;
				Persona<T> *  m_pIndex;
    public:
       Agenda():m_pHead(0),m_pLast(0),m_pIndex(0){};

			 bool isEmpty(){
				 if(m_pHead==NULL)return true;
				 return false;
			 }

       bool find_R(T  d, Persona<T> * & p)
       {
       	   if(!p){return false;}
       	   if (p->DNI == d) {return true;}
       	   return find_R(d,p->m_pSig);

       }


       void Add_R(T  a,T b,T c,T d,T e, Persona<T> * &  p)
       {
       	   if(!p){p = new Persona<T>(a,b,c,d,e); return; }
       	   return Add_R(d,p->m_pSig);

       }
       void Add(T a,T b,T c,T d,T e)
       {
       	    Add_R(a,b,c,d,e,m_pHead);
       }

			 void print_unit(Persona<T> *p){
				 if(!p)return;
				 	cout<<p->DNI<<"-"<<p->nombre<<"-"<<p->direccion<<"-"<<p->telefono<<"-"<<p->edad<<"-"<<endl;
			 }
			 void print(){
				 Persona<T> *p=m_pHead;
				 if(isEmpty())return;
				 else{
					 while(p!=NULL){
						 cout<<p->DNI<<"-"<<p->nombre<<"-"<<p->direccion<<"-"<<p->telefono<<"-"<<p->edad<<"-"<<endl;
						 p=p->m_pSig;
					 }
				 }

			 }
	   void print_R(Persona<T> *  p, ostream & os)
       {
       	   if(!p){return ;}
       	   os<<p->DNI<<"-"<<p->nombre<<"-"<<p->direccion<<"-"<<p->telefono<<"-"<<p->edad<<"-"<<endl;
       	   return print_R(p->m_pSig,os);

       }

       void Add_I(T a,T b,T c,T d,T e)
       {
       	 Persona<T> * pNuevo = new Persona<T>(a,b,c,d,e);
       	 if(!m_pHead)
         {
            m_pHead = pNuevo;
            return;
         }
         Persona<T> * tmp = m_pHead;
         for( ; tmp->m_pSig; tmp=tmp->m_pSig);
         tmp->m_pSig = pNuevo;


       }

       /*friend Agenda<T> & operator<<(Agenda<T> & L, T d)
       {
       	   //L.Add_R(d,L.m_pHead);
       	   ////L.Add_I(d);
       	   //L.AddE(d);
       	   return 1;
       }

      friend ostream & operator<<(ostream & os, Agenda<T> & L)
       {
       	   L.print_R(L.m_pHead,os);
       	   return os;
       }*/


       bool find(T d, Persona<T>  ** & p)
       {
       	    p = &m_pHead;
       	    while(*p)
       	    {
       	    	if ((**p).DNI == d) return true;
       	    	if ((*p)->DNI > d) return false;
       	    	p = &((*p)->m_pSig);
       	    }
       	    return false;
       }

      bool AddE(T a,T b,T c,T d,T e)
      {
      	  Persona<T>  ** q;
      	  if(find(a,q)) return false;
      	  Persona<T> * tmp = *q;
      	  *q = new Persona<T>(a,b,c,d,e);
      	  (*q)->m_pSig = tmp;
      	  return true;

      }
		bool Remove(){
			Persona<T>  *tmp=m_pHead;
			if(isEmpty())return false;
			for( ; tmp->m_pSig!=m_pLast; tmp=tmp->m_pSig);

			delete m_pLast;
			m_pLast=tmp;
			return true;

		}






};
int main()
{

    //ofstream F("file.txt");
		Agenda<string>  A;
		string dni2,nom2,dir2,tel2,ed2;
		A.AddE("123","123","123","123","123");
		A.AddE("1233","1233","1233","1233","1233");
		A.AddE("1234","1234","1234","1234","1234");
		A.print();
		A.Remove();
		A.print();

}
