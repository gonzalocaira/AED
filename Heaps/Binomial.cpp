//AED - 2018 CS UNSA
//Binomial_Heap
//Diego Antoni Gutierrez Gutierrez
//Vicente



#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <fstream>
#include <stdlib.h>


using namespace std;


template <class T>
class BinomialNode
{
public:
	int 				 m_Grado;
	T 					 m_Dato;
	list<BinomialNode* > m_Hijos;
	BinomialNode<T>* 	 m_pPadre;

public:
	BinomialNode(T _Dato){
		this->m_Dato   = _Dato;
		this->m_Grado  = 0;
		this->m_pPadre = NULL; 
	}	
};

template<class T>
class BinomialHeap
{
public:
	BinomialNode<T >*  		_vmin; 
	list<BinomialNode<T>* > m_Roots;
public:
	BinomialHeap(){
		this->_vmin = NULL;
	}
	void ADD(T _d)
	{
		BinomialNode<T>* _nuevoN  = new BinomialNode<T>(_d);
		this->m_Roots.insert(this->m_Roots.begin(),_nuevoN);
		if(this->m_Roots.size()>= 2)
		{
			Merge();
			Actualizar_min(_vmin,_nuevoN);

		}else{
			_vmin = _nuevoN;
		}
	}
	void  Actualizar_min(BinomialNode<T>* aux,BinomialNode<T>* aux2)
	{
        if(aux->dato<aux2->dato)
        {
            this->_vmin=aux;
        }else{this->_vmin=aux2;}		

	}
	BinomialNode<T> * Union_Bn(BinomialNode<T>*p,BinomialNode<T>*q)
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
		typename list<BinomialNode<T>*>::iterator it  = this->m_Roots.begin();
		vector<BinomialNode<T>* > Vector_Grados;
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
				BinomialNode<T>* temp = *it;
				it++;
				BinomialNode<T>* m_menor = Union_Bn(temp,Vector_Grados[temp->m_Grado]);
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
 		typename list<BinomialNode<T>* >:: iterator it = this->m_Roots.begin();
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
 	void Graficar_Hijos(BinomialNode<T> * aux, ofstream &file)
 	{

 		typename list<BinomialNode<T>* >:: iterator it = aux->m_Hijos.begin();
 		for(;it!=aux->m_Hijos.end();it++)
 		{
 			file<<aux->m_Dato<<"->"<<(*it)->m_Dato<<";\n";
 			Graficar_Hijos(*it,file);
 		}
 	}


};

int main()
{
	BinomialHeap<int> BH;
	BH.ADD(3);
	BH.ADD(5);
	BH.ADD(6);
	BH.ADD(7);
	BH.ADD(1);
	BH.ADD(9);
	BH.ADD(10);
	BH.ADD(11);
	BH.ADD(15);
	BH.ADD(16);
	BH.ADD(18);
	BH.ADD(21);
//	BH.ADD(9);
	BH.Graficar_roots();
	return 0;
}

