#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "iostream"
#include "Menu.h"

using namespace sf;
using namespace std;

using namespace std;

template <class T>
class Nodo{
public:
  T m_pDato[1];
  int frequency;
  Nodo <T>* m_pSon[2];
  //Node <T> * right;
  //Node <T> * parent;
public:
  Nodo (T word){
    //parent=0;
    m_pSon[0]=m_pSon[1]=0;
    m_pDato[0]=word;
    frequency=0;
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
      T max;
    public:
      Tree(){
        m_pRoot=0;
      }

      //leer palabras del texto
      void read_vector_stopwords (){
        string line;
        ifstream myfile ("stopwords.txt");
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
      //leer palabras del texto
      void read_vector_text (){
        string line;
        //ifstream myfile ("FabulasDeSamaniego.txt");
        //ifstream myfile ("Bishop - Pattern Recognition And Machine Learning - Springer  2006.txt");
        ifstream myfile ("Bishop - Pattern Recognition And Machine Learning - Springer  2006.txt");
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

      bool Find (T d, Nodo <T> **&p){
        p=&m_pRoot;
        while (*p){
          if ((*p)->m_pDato[0]==d) {

            //añade frequencia a la palabra
            (*p)->frequency++;
            return true;
          }
            //pp=(*p);
            p=&(*p)->m_pSon[(*p)->m_pDato[0]<d];
        }
        return false;
      }



      /*
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
      }*/
      bool Add (T word){
        Nodo <T> **q;
        //pq=new Nodo<T>(0);
        if (Find(word,q)) return false;
        *q=new Nodo<T>(word);
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
      void MaxFrequency(){
        Nodo<T> *tmp=m_pRoot;
        int max=-1;
        if(tmp)max=tmp->frequency;
        /*while(tmp){

        }*/
        cout<<tmp->m_pDato[0];
        cout<<tmp->frequency<<endl;
      }
      void Print (Nodo <T> **p){
        if (!(*p)) return;
        //cout<<"padre: "<<((*p)->parent)->m_pDato<<endl;
        cout<<"Nodo: "<<(*p)->m_pDato[0]<<" "<<(*p)->frequency<<endl;

        Print (&(*p)->m_pSon[0]);

        Print (&(*p)->m_pSon[1]);
      }
      void show(){
        Nodo<T> **tmp=&m_pRoot;
        Print(tmp);
      }
      int Quantity (Nodo <T> *p){
        if (p) return 1+Quantity (p->m_pSon[1])+Quantity (p->m_pSon[0]);
        else return 0;
      }

      int Altura_Arbol(Nodo<T> *p){
          if (!p) return 0;
          return max(Altura_Arbol(p->m_pSon[0]),Altura_Arbol(p->m_pSon[1]))+1;
      }
};


int main(int argc, char const *argv[]) {
  Tree <string> Arbol_stopwords;
  Tree <string> Arbol_txt;
//  Agenda<string> A;
  RenderWindow window(VideoMode(500,400),"Stopwords :D");
  window.setVerticalSyncEnabled(true);
  Menu menu(window.getSize().x,window.getSize().y);

  sf::Texture textura;

	// Cargamos la textura desde un archivo
	if(!textura.loadFromFile("menu.png"))
	{
		// Si hay un error salimos
		return EXIT_FAILURE;
	}

	// Creamos un sprite
	sf::Sprite sprite;
	// Asignamos la textura al sprite
	sprite.setTexture(textura);
	// Seleccionamos solo un rectangulo de la textura
  Font font2;
  if(!font2.loadFromFile("Bafora Regular Demo.ttf")){
    cout<<"Error loading file"<<endl;
  }

  String playerInput;
  Text playerText;
  playerText.setPosition(60,300);
  playerText.setFillColor(Color::Red);



  Text text2;
  text2.setFont(font2);
  text2.setString("Stopwords!");
  text2.setCharacterSize(100);
  text2.setPosition(100,20);
  text2.setFillColor(Color::Blue);

  /*Text text_max;
  text_max.setFont(font2);
  text_max.setString("frequency");
  text_max.setCharacterSize(50);
  text_max.setPosition(300,20);
  text_max.setFillColor(Color::Blue);
  text2.setStyle(Text::Style::Bold | Text::Style::Underlined);
  text2.setOutlineColor(Color::Cyan);
  text2.setOutlineThickness(-10);*/
  while(window.isOpen()){
    Event event;
		//window.draw(menu.get_sprite());
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::TextEntered){
          if(event.text.unicode < 128){
             playerInput +=event.text.unicode;
             playerText.setString(playerInput);
          }
        }


      switch (event.type) {
        case Event::KeyReleased:
           switch (event.key.code) {
             case Keyboard::Up:
                menu.MoveUp();
                break;
             case Keyboard::Down:
                menu.MoveDown();
                break;
             case Keyboard::Return:
                switch (menu.GetPressedItem()) {
                  case 0:
                      Arbol_stopwords.read_vector_stopwords();
                      for (int i=0; i<Arbol_stopwords.myvector.size();i++){
                          Arbol_stopwords.Add(Arbol_stopwords.myvector[i][0]);
                      }
                      Arbol_txt.read_vector_text();
                      for (int i=0; i<Arbol_txt.myvector.size();i++){
                        //if(Arbol_txt.myvector[i][0])
                          Arbol_txt.Add(Arbol_txt.myvector[i][0]);
                      }
                    break;
                  case 1:

                      //text_max.setString(Arbol_txt.m_pRoot->m_pDato[0]);
                      //text2.setString(Arbol_txt.m_pRoot->m_pDato[0]);
                      //Arbol_txt.MaxFrequency();
                    break;
                  case 2:
                    window.close();
                    break;
                }
           }
           break;
        case Event::Closed:
          window.close();
          break;
      }
    }

    window.clear();
    window.draw(playerText);
    window.draw(sprite);
    window.draw(text2);
    menu.draw(window);
    window.display();
  }
  return 0;
}
