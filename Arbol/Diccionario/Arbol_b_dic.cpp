#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

template <class T>
class Nodo{
public:
  T m_pDato[2];
  Nodo <T>* m_pSon[2];
  //Node <T> * right;
  //Node <T> * parent;
public:
  Nodo (T english, T spanish){
    //parent=0;
    m_pSon[0]=m_pSon[1]=0;
    m_pDato[0]=english;
    m_pDato[1]=spanish;
  }
};

template <class T>
class Tree{
  //typedef Node<T>  * pNodo;
  //typedef Node<T>  ** pdNodo;
  //  private:
public:
      Nodo<T> * m_pRoot;
      vector<vector<string> > myvector;
    public:
      Tree(){
        m_pRoot=0;
      }

      //leer palabras del diccionario
      void read_vector (/*vector<vector<string> > &myvector*/){
        string line;
        ifstream myfile ("English.txt");
        if (myfile.is_open())
        {
          while ( getline (myfile,line) ){
            vector<string> vector_word;
            istringstream buf(line);
            //added
            int i=0;
            string word_second="";
            //..
            for (string word ;buf>>word; i++){
                if (i==0) vector_word.push_back(word);
                word_second=word_second+word+" ";
            }
            vector_word.push_back(word_second);
            //cout<<word_second<<endl;
            myvector.push_back(vector_word);
          }
          myfile.close();
        }
        else cout << "No se puedo abrir el archivo"<<endl;
      }
        /*for (int i=0;i<myvector.size();i++){
          cout<<myvector[i][0]<<"  "<<myvector[i][1]<<endl;
        }
      }*/
      /*  vector<string> vector_word;
        istringstream buf(line);
        int i=0;
        string word_second=" ";
        for (string word;buf>>word; i++){
          if (i==0) vector_word.push_back(word);
          word_second=word_second+word+" ";
        }
        vector_word.push_back(word_second);
        myvector.push_back(vector_word);
      }*/

      bool Find (T d, Nodo <T> **&p){
        p=&m_pRoot;
        while (*p){
          if ((*p)->m_pDato[0]==d) return true;
            //pp=(*p);
            p=&(*p)->m_pSon[(*p)->m_pDato[0]<d];
        }
        return false;
      }
      bool Find_translate (T d){
        Nodo <T> **p;
        p=&m_pRoot;
        while (*p){
          if ((*p)->m_pDato[0]==d) {
            cout<<"Translte "<<(*p)->m_pDato[1]<<endl;
          //  delete p;
            return true;
          }
            //pp=(*p);
            p=&(*p)->m_pSon[(*p)->m_pDato[0]<d];
        }
        //delete p;
        return false;
      }
      bool Add (T eng, T spa){
        Nodo <T> **q;
        //pq=new Nodo<T>(0);
        if (Find(eng,q)) return false;
        *q=new Nodo<T>(eng,spa);
        //(*q)->parent=pq;
        return true;
      }

      bool Find_father (T d){
        Nodo <T> *padre_q;
        Nodo <T> *q;
        q=padre_q=m_pRoot;
        while (q){
          if (q->m_pDato[0]==d) break;
            padre_q=(q);
            q=(q)->m_pSon[(q)->m_pDato[0]<d];
        }
        if (!q)    return false;
        cout<<"padre "<<padre_q->m_pDato[0]<<endl;
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
        cout<<"Nodo: "<<(*p)->m_pDato[0]<<endl;

        Print (&(*p)->m_pSon[0]);

        Print (&(*p)->m_pSon[1]);
      }
      int Quantity (Nodo <T> *p){
        if (p) return 1+Quantity (p->m_pSon[1])+Quantity (p->m_pSon[0]);
        else return 0;
      }

      int Altura_Arbol(Nodo<T> *p){
          if (!p) return 0;
          return max(Altura_Arbol(p->m_pSon[0]),Altura_Arbol(p->m_pSon[1]))+1;
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
Tree <string> Arbol;
Arbol.read_vector();
/*Arbol.Add("ajoker");
Arbol.Add("aabigail");
Arbol.Add("akorea");
Arbol.Add("aniggas");
Arbol.Add("atrump");
Arbol.Add("agreat");
Arbol.Add("ayisas");
Arbol.Add("aburrito");
Arbol.Add("apepe asa");
Arbol.Add("aosfrog asa");
Arbol.Print(&Arbol.m_pRoot);
Arbol.Find_father("apepe asa");*/
for (int i=0; i<Arbol.myvector.size();i++){
    Arbol.Add(Arbol.myvector[i][0],Arbol.myvector[i][1]);
}

cout<<"altura"<<endl;
//cout<<Arbol.Altura_Arbol(Arbol.m_pRoot)<<endl;
cout<<"segunda_vector  "<<Arbol.myvector.size()<<endl;
string yellow="yourselves";
Arbol.Find_translate(yellow);
/*string palabra1, palabra2;
palabra1="filho";
palabra2="fila";
  if (palabra1<palabra2)
  cout<<"palabra1 "<<palabra1<<endl;
  if (palabra1>palabra2)
  cout<<"palabra2 "<<palabra2<<endl;
*/

//cout<<"Cantidad: "<<Arbol.Quantity(Arbol.get_root())<<endl;
//cout<<"Hello"<<endl;
return 0;
}
