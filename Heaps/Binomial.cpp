
#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <fstream>
#include <stdlib.h>
#include <iterator>

using namespace std;


template <class T>
class Nodo
{
public:
	int m_Grado;
	T 	m_Dato;
	list<Nodo* > m_Hijos;
	Nodo<T>* 	 m_pPadre;

public:
	Nodo(T _Dato){
		this->m_Dato   = _Dato;
		this->m_Grado  = 0;
		this->m_pPadre = NULL; 
	}	
};

template<class T>
class BinomialHeap
{
public:
	Nodo<T >*  m_min; 
	list<Nodo<T>* > m_Roots;
public:
	BinomialHeap(){
		this->m_min = NULL;
	}
	void ADD(T _d)
	{
		Nodo<T>* _nuevoN  = new Nodo<T>(_d);
		this->m_Roots.insert(this->m_Roots.begin(),_nuevoN);
		if(this->m_Roots.size()>= 2)
		{
			Merge();
			Actualizar_min(m_min,_nuevoN);

		}else{
			m_min = _nuevoN;
		}
	}
	void  Actualizar_min(Nodo<T>* aux,Nodo<T>* aux2)
	{
        if(aux->m_Dato<aux2->m_Dato)
        {
            this->m_min=aux;
        }else{this->m_min=aux2;}		

	}
	Nodo<T> * Union_Bn(Nodo<T>*p,Nodo<T>*q)
	{
		if(p->m_Dato < q->m_Dato){
			p->m_Hijos.push_front(q);
			q->m_pPadre = p;
			p->m_Grado ++;
			this->m_Roots.remove(q);
			return p; 
		}
		else{
			if(p->m_Dato > q->m_Dato)
			{
				q->m_Hijos.push_front(p);
				p->m_pPadre = q;
				q->m_Grado ++; 
				this->m_Roots.remove(p);
				return q;
			}
		}
	}
	void Merge()
	{
		list<Nodo<T>*>::iterator it  = this->m_Roots.begin();
		vector<Nodo<T>* > Vector_Grados;
		for(int i = 0;i<=m_Roots.size()+1;i++){
			Vector_Grados.push_back(0);
		}
		while(it!=this->m_Roots.end())
		{
			int p = (*it)->m_Grado;
			if(Vector_Grados[p] == 0)
			{
				Vector_Grados[p] = *it;
				it ++; 
			}
			else{
				Nodo<T>* temp = *it;
				it++;
				Nodo<T>* m_menor = Union_Bn(temp,Vector_Grados[temp->m_Grado]);
				Vector_Grados[p] = 0;
				if(Vector_Grados[m_menor->m_Grado] == 0){
					Vector_Grados[m_menor->m_Grado] = m_menor;
				}else{
					int aux3 = m_menor->m_Grado;
					m_menor = Union_Bn(m_menor,Vector_Grados[m_menor->m_Grado]);
					Vector_Grados[aux3] = 0;
					Vector_Grados[m_menor->m_Grado] = m_menor ; 
				}
			}
		}
	}

 	void Graficar_roots()
 	{
 		string name = "Binomial";
 		ofstream file("Binomial.dot");
 		file<<"digraph {\n";
 		typename list<Nodo<T>* >:: iterator it = this->m_Roots.begin();
 		for(;it!=this->m_Roots.end();it++)
 		{
 			if((*it)->m_Hijos.empty())
 			{
 				file<<(*it)->m_Dato<<";\n";
 			}
 			else
 			{
 				Graficar_Hijos(*it,file);

 			}
 		}

 		file<<"}";
 		file.close();
 		string comando = "dot -Tpdf " + name + ".dot -o" + name + ".pdf";
		const char * c  =  comando.c_str();
		system(c);	

 	}
 	void Graficar_Hijos(Nodo<T> * aux, ofstream &file)
 	{

 		typename list<Nodo<T>* >:: iterator it = aux->m_Hijos.begin();
 		for(;it!=aux->m_Hijos.end();it++)

 		{
			 //os<<"structNodo"<<temp<<"[style=filled , label="<<p->dato<<"];"<<endl;
			//file<<"structNodo"<<aux->m_Dato<<"[style=filled , label="<<(*it)->m_Dato<<"];"<<endl;
 			file<<aux->m_Dato<<"->"<<(*it)->m_Dato<<";\n";
 			Graficar_Hijos(*it,file);
 		}
 	}


};

int main()
{
	BinomialHeap<int> A;
	A.ADD(3);
	A.ADD(5);
	A.ADD(6);
	A.ADD(7);
	A.ADD(1);
	A.ADD(9);
	A.ADD(10);
	A.ADD(11);
	A.ADD(15);
	A.ADD(16);
	A.ADD(18);
	A.ADD(21);
//	A.ADD(9);
//	A.ADD(2);
//	A.ADD(22);
//	A.ADD(17);
//	A.ADD(8);
//	A.ADD(4);
	
	A.Graficar_roots();
	return 0;
}

