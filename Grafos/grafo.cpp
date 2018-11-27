#include "lista.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

template <class V,class E>
class Vertex;

template<class V,class E>
class Arista {
public:
  E m_distancia;
  Vertex<V,E> m_destino;
public:
  Arista();
  Arista (E d);
  E get_distancia(){return m_distancia;}
  bool operator==(const Arista<V,E> &a){
    return m_distancia==a.m_distancia;}
  bool operator>(const Arista<V,E> &a){
    return m_distancia>a.m_distancia;}
  bool operator<(const Arista<V,E> &a){
    return m_distancia<a.m_distancia;}
  friend std::ostream& operator<<(std::ostream &out,const Arista<V,E> &a){
    out<<a.m_distancia;
    return out;}
};
template<class V,class E>
Arista<V,E>::Arista(){
  this->m_distancia=0;
}
template<class V,class E>
Arista<V,E>::Arista(E d){
  this->m_distancia=d;
}

template<class V,class E>
class Vertex {
public:
  List<Arista<V,E>> m_Aristas;
  V m_dato;
public:
  Vertex (){};
  Vertex (V d);
  bool operator == (const Vertex<V,E> &v) const{
    return v.m_dato == m_dato;}
  bool operator > (const Vertex<V,E> &v) const{
    return v.m_dato > m_dato;}
  bool operator < (const Vertex<V,E> &v) const{
    return v.m_dato < m_dato;}
  friend std::ostream& operator<<(std::ostream &out,const Vertex<V,E> &v){
    out<<v.m_dato;
    return out;}
};

template<class V,class E>
Vertex<V,E>::Vertex(V d){
  m_dato=d;
  m_Aristas;
}



template<class V,class E>
class Graph
{
private:
    const int INF = numeric_limits<int>::max();
    int cantidad_nodos;
    vector< vector<int> > ady; 
    List<Vertex<V,E>> m_lista_grafo;
public:
    Graph(){};
    Graph(int nodes){
        cantidad_nodos = nodes;
        ady = vector< vector<int> > (cn);

        for(int i = 0; i < cn; i++)
            ady[i] = vector<int> (cn, INF);
    }
    void add_Vertex(V v1){
        m_lista_grafo.add(Vertex<V,E>(v1));
    }
    bool add_Arista(V v1,V v2,E A){
        Nodo<Vertex<V,E>> **p;
        Nodo<Vertex<V,E>> **q;
        bool o1=m_lista_grafo.find(Vertex<V,E>(v1),p);
        bool o2=m_lista_grafo.find(Vertex<V,E>(v2),q);
        if(o1==true && o2==true){
            Arista<V,E> aux=Arista<V,E>(A);
            aux.m_destino=(*q)->m_Dato;
            ((*p)->m_Dato.m_Aristas).add(aux);
            return true;
        }
        return false;
    }
    
    void GraphViz(){
        string title = "Grafo";
 		ofstream archivo("Grafo.dot");
        
        archivo<<"digraph Grafo {"<<endl;
        if(!m_lista_grafo.is_empty()){
            Nodo<Vertex<V,E>> *temp;
            temp=m_lista_grafo.m_pHead;
            while(temp!=NULL){
                archivo<<(temp->m_Dato).m_dato<<"[label="<<"\""<<(temp->m_Dato).m_dato<<"\""<<"]"<<endl;
                temp=temp->m_pSig;
            }
            temp=m_lista_grafo.m_pHead;
            while(temp!=NULL){
                Nodo<Vertex<V,E>> **p;
                bool o1=m_lista_grafo.find(Vertex<V,E>((temp->m_Dato).m_dato),p);
                    if(o1){
                            List<Arista<V,E>> temp2;
                            Nodo<Arista<V,E>> *temp3;
                            temp2=((*p)->m_Dato.m_Aristas);
                            temp3=temp2.m_pHead;
                            while(temp3!=temp2.m_pLast){
                                archivo<<" "<<(temp->m_Dato).m_dato<<" -> "<<((temp3->m_Dato).m_destino).m_dato<<"[label="<<"\""
                                <<(temp3->m_Dato).m_distancia<<"\""<<",weight="<<"\""<<(temp3->m_Dato).m_distancia<<"\""<<" color=\"green\""<<"]"<<endl;
                                temp3=temp3->m_pSig;
                            }
                    }
                temp=temp->m_pSig;
            }
        }
        archivo<<"}"<<endl;
        
        string comando = "dot -Tpng " + title + ".dot -o" + title + ".png";
		const char * c  =  comando.c_str();
		system(c);
    }

    
};


int main(){
    Graph<string,int> A;
    A.add_Vertex("Peru");
    A.add_Vertex("Bolivia");
    A.add_Vertex("Argentina");
    A.add_Vertex("Brasil");
    A.add_Vertex("Colombia");
    A.add_Vertex("Alemania");
    A.add_Vertex("Francia");
    A.add_Vertex("Paraguay");
    A.add_Vertex("Canada");
    A.add_Vertex("Ecuador");
    A.add_Vertex("Portugal");
    A.add_Arista("Francia","Peru",55000);
    A.add_Arista("Alemania","Colombia",54000);
    A.add_Arista("Argentina","Francia",50000);
    A.add_Arista("Peru","Argentina",4000);
    A.add_Arista("Argentina","Colombia",3000);
    A.add_Arista("Colombia","Alemania",60000);
    A.add_Arista("Francia","Brasil",70000);
    A.add_Arista("Brasil","Colombia",45000);
    A.add_Arista("Bolivia","Brasil",15000);
    A.add_Arista("Peru","Brasil",20000);
    A.add_Arista("Alemania","Francia",15000);
    A.add_Arista("Paraguay","Ecuador",42000);
    A.add_Arista("Paraguay","Colombia",47000);
    A.add_Arista("Bolivia","Canada",18000);
    A.add_Arista("Ecuador","Brasil",28000);
    A.add_Arista("Alemania","Portugal",17000);
    A.GraphViz();
    return 0;
}