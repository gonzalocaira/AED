
#include <iostream>
#include <fstream>
#include "string"

using namespace std;

template <typename T>
class Contacto{
public:
	T DNI;
	string nombre;
	string direccion;
	T telefono;
	T edad;
public:
	Contacto(){}
	/*Contacto(T _dni,string _nombre,string _direccion,T _telefono,T _edad){
		DNI=_dni;
		nombre=_nombre;
		direccion=_direccion;
		telefono=_telefono;
		edad=_edad;
	}*/
	/*Contacto(T _dni){
	DNI=_dni;
}*/
	void llenar(T _dni,T _telefono){
		DNI=_dni;
		telefono=_telefono;
	}
};

template<class T>
class Nodo
{
	 public:
		 Contacto<T> persona;
	 	 //T      m_Dato;
	 	 Nodo<T> * m_pSig;

	 public:
	 	Nodo(T d,T x){
			persona.llenar(d,x);
			m_pSig=0;
		};
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
       	   if (p->persona.DNI == d) {return true;}
       	   return find_R(d,p->m_pSig);

       }


       void Add_R(T  d,T x, Nodo<T> * &  p)
       {
       	   if(!p){p = new Nodo<T>(d,x); return; }
       	   return Add_R(d,p->m_pSig);

       }
       void Add(T d)
       {
       	    Add_R(d,m_pHead);
       }
	   	void print_R(Nodo<T> *  p, ostream & os)
       {
       	   if(!p){return ;}
       	   os<<p->persona.DNI<<endl;
       	   return print_R(p->m_pSig,os);

       }

       void Add_I(T d,T x)
       {
       	 Nodo<T> * pNuevo = new Nodo<T>(d,x);
       	 if(!m_pHead)
         {
            m_pHead = pNuevo;
            return;
         }
         Nodo<T> * tmp = m_pHead;
         for( ; tmp->m_pSig; tmp=tmp->m_pSig);
         tmp->m_pSig = pNuevo;


       }

       /*friend Lista<T> & operator<<(Lista<T> & L, T d)
       {
       	   //L.Add_R(d,L.m_pHead);
       	   ////L.Add_I(d);
       	   L.AddE(d,x);
       	   return L;
       }*/

      friend ostream & operator<<(ostream & os, Lista<T> & L)
       {
       	   L.print_R(L.m_pHead,os);
       	   return os;
       }


       bool find(T d)
       {
				 		Nodo<T> **p;
       	    p = &m_pHead;
       	    while(*p)
       	    {
       	    	if ((**p).persona.DNI == d) return true;
       	    	if ((*p)->persona.DNI > d) return false;
       	    	p = &((*p)->m_pSig);
       	    }
       	    return false;
       }

      bool Add_E(T d,T x)
      {
      	  Nodo<T>  ** q;
      	  if(find(d)) return false;
      	  Nodo<T> * tmp = *q;
      	  *q = new Nodo<T>(d,x);
      	  (*q)->m_pSig = tmp;
      	  return true;

      }

};
int main()
{
	//Contacto<int> X(4879,"l","r",78,78);
  ofstream F("file.txt");
	Lista<int>  A;
	Nodo<int> **q;
	//A<<3<<45<<65;
	A.Add_E(100,200);
	A.Add_E(99,201);
	A.Add_E(101,201);
	cout<<A;
//	cout<<A.find(100);
	F<<A;
	/*int op;
	int dni_,telefono_,edad_;
	string nombre_,direccion_;
	cout<<"\t\t Agenda "<<endl;
	cout<<"\n\t1)Buscar Amigo : "<<endl;
	cout<<"\t2)Insertar Amigo : "<<endl;
	cout<<"\t3)Eliminar Amigo : "<<endl;
	cout<<"\n\t4)mover al anterior : "<<endl;
	cout<<"\t5)mover al siguiente : "<<endl;
	cout<<"\t6)mover al primero : "<<endl;
	cout<<"\t7)mover al ultimo : "<<endl;
	cout<<"\t8)SALIR"<<endl;
	cout<<"Ingrese una opcion: "<<endl;
	cin>>op;

	switch (op) {
		case 1:
					break;
		case 2:
					cout<<"\nIngrese Dni :";
					cin>>dni_;
					cout<<"\nIngrese nombre :";
					cin>>nombre_;
					cout<<"\nIngrese direccion :";
					cin>>direccion_;
					cout<<"\nIngrese telefono :";
					cin>>telefono_;
					cout<<"\nIngrese edad:";
					cin>>edad_;
					Contacto<int> Y(dni_,nombre_,direccion_,telefono_,edad_);
					break;
		case 3:
					break;
		case 4:
					break;
		case 5:
					break;
		case 6:
					break;
		case 7:
					break;
		case 8:
					break;

	}*/
}
