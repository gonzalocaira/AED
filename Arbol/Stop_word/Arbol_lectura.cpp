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
  T m_pDato[2];
  Nodo <T>* m_pSon[2];
  int frecuencia;
public:
  Nodo (T english, T spanish){
    m_pSon[0]=m_pSon[1]=0;
    m_pDato[0]=english;
    m_pDato[1]=spanish;
    frecuencia=1;
  }
};

//Nodo stop word
template <class T>
class Nodo_S{
public:
  T m_pDato;
  Nodo_S <T>* m_pSon[2];
public:
  Nodo_S (T stop_word){
    m_pSon[0]=m_pSon[1]=0;
    m_pDato=stop_word;
  }
};

template <class T>
class Tree{
public:
      //Nodo<T> * m_pFrecuencia;
      Nodo<T> * m_pRoot_text;
      Nodo_S<T> * m_pRoot_stop_word;
      Nodo<T> *max_fre;
      vector<vector<string> > myvector;
      vector<string> myvector_stop;
    public:
      Tree(){
        m_pRoot_text=0;
        m_pRoot_stop_word=0;
        max_fre=0;
      }

      //leer palabras del diccionario
      void read_vector (/*vector<vector<string> > &myvector*/){
        string line;
        ifstream myfile ("SPANISH.TXT");
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
/*
      bool Find_stop (T d, Nodo_S <T> **&p){
        p=&m_pRoot_stop_word;
        while (*p){
          if ((*p)->m_pDato==d){
            //frecuencia+=1;
            return true;
          }
            //pp=(*p);
            p=&(*p)->m_pSon[(*p)->m_pDato<d];
        }
        return false;
      }
      bool Add_stop (T word){
        Nodo_S <T> **q;
        //pq=new Nodo<T>(0);
        if (Find_stop(word,q)) return false;
        *q=new Nodo_S<T>(word);
        //(*q)->parent=pq;
        return true;
      }*/
      void read_vector_word (/*vector<vector<string> > &myvector*/){
        string line;
        ifstream myfile ("SPANISH.TXT");
        if (myfile.is_open())
        {
          while ( getline (myfile,line) ){
            Nodo_S <T> **q;
            vector<string> vector_word;
            istringstream buf(line);
            //added
            int i=0;
            string word_second="";
            //..
            for (string word ;buf>>word; ){
                if (!Find_stop(word,q)){
                if (i==0) vector_word.push_back(word);
                word_second=word_second+word+" ";
                i++;}
            }
            vector_word.push_back(word_second);
            //cout<<word_second<<endl;
            myvector.push_back(vector_word);
          }
          myfile.close();
        }
        else cout << "No se puedo abrir el archivo"<<endl;
      }

      //Read stop words
      void read_stop_words (/*vector<vector<string> > &myvector*/){
        string line;
        ifstream myfile ("stopwords.txt");
        if (myfile.is_open())
        {
          while ( getline (myfile,line) ){
            myvector_stop.push_back(line);
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
        p=&m_pRoot_text;
        while (*p){
          if ((*p)->m_pDato[0]==d){
            (*p)->frecuencia+=1;
            return true;
          }
            //pp=(*p);
            p=&(*p)->m_pSon[(*p)->m_pDato[0]<d];
        }
        return false;
      }
      bool Find_translate (T d){
        Nodo <T> **p;
        p=&m_pRoot_text;
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

      bool Find_stop (T d, Nodo_S <T> **&p){
        p=&m_pRoot_stop_word;
        while (*p){
          if ((*p)->m_pDato==d){
            //frecuencia+=1;
            return true;
          }
            //pp=(*p);
            p=&(*p)->m_pSon[(*p)->m_pDato<d];
        }
        return false;
      }

      bool Add_stop (T word){
        Nodo_S <T> **q;
        //pq=new Nodo<T>(0);
        if (Find_stop(word,q)) return false;
        *q=new Nodo_S<T>(word);
        //(*q)->parent=pq;
        return true;
      }
      void Print_s (Nodo_S <T> **p){
        if (!(*p)) return;
        //cout<<"padre: "<<((*p)->parent)->m_pDato<<endl;
        cout<<(*p)->m_pDato<<endl;
        Print_s (&(*p)->m_pSon[0]);
        Print_s (&(*p)->m_pSon[1]);
      }

      bool Find_father (T d){
        Nodo <T> *padre_q;
        Nodo <T> *q;
        q=padre_q=m_pRoot_text;
        while (q){
          if (q->m_pDato[0]==d) break;
            padre_q=(q);
            q=(q)->m_pSon[(q)->m_pDato[0]<d];
        }
        if (!q)    return false;
        cout<<"padre "<<padre_q->m_pDato[0]<<endl;
        return true;
      }

      void Print (Nodo <T> **p){
        if (!(*p)) return;
        //cout<<"padre: "<<((*p)->parent)->m_pDato<<endl;
        cout<<(*p)->m_pDato[0]<<" "<<(*p)->m_pDato[1]<<endl;
        Print (&(*p)->m_pSon[0]);
        Print (&(*p)->m_pSon[1]);
      }
      /*void Print (){
        if (!(*p)) return;
        //cout<<"padre: "<<((*p)->parent)->m_pDato<<endl;
        while (*P){
        cout<<"Nodo: "<<(*p)->m_pDato[0]<<endl;
        Print (&(*p)->m_pSon[0]);
        Print (&(*p)->m_pSon[1]);
        }
      }*/
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
  Tree <string> Arbol;
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


  //string q="hola";
  Text text2;
  text2.setFont(font2);
  text2.setString("Stopwords");
  text2.setCharacterSize(100);
  text2.setPosition(100,20);
  text2.setFillColor(Color::Blue);

  string q;
  Text text3;
  text3.setFont(font2);


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
                      //añadir al arbol el texto,pero las palabras de stopword
                      /*Arbol_stopwords.read_vector_stopwords();
                      for (int i=0; i<Arbol_stopwords.myvector.size();i++){
                          Arbol_stopwords.Add(Arbol_stopwords.myvector[i][0]);
                      }
                      Arbol_txt.read_vector_text();
                      for (int i=0; i<Arbol_txt.myvector.size();i++){
                        //if(Arbol_txt.myvector[i][0])
                          Arbol_txt.Add(Arbol_txt.myvector[i][0]);
                      }*/
                      Arbol.read_vector();
                      for (int i=0; i<Arbol.myvector.size();i++){
                          Arbol.Add(Arbol.myvector[i][0],Arbol.myvector[i][1]);
                      }

                      Arbol.read_stop_words();
                      for (int i=0; i<Arbol.myvector_stop.size();i++){
                          Arbol.Add_stop(Arbol.myvector_stop[i]);
                      }

                      Arbol.read_vector_word();
                      Arbol.Print(&Arbol.m_pRoot_text);


                    break;
                  case 1:
                      //mostrar el de mayor frecuencia
                      //Arbol_txt.getMaxfrequency();
                      q="Tree = ";
                      text3.setString(q);
                      text3.setCharacterSize(50);
                      text3.setPosition(40,150);
                      text3.setFillColor(Color::Blue);
                      //window.clear();
                      window.draw(text3);
                      window.display();

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
    //window.draw(text3);
    menu.draw(window);
    window.display();
  }
  return 0;
}
