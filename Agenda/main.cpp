#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "iostream"
#include "Menu.h"

using namespace sf;
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
       void print_Begin(){
         print_unit(m_pHead);
       }
       void print_Last(){
         print_unit(m_pLast);
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
            m_pLast = pNuevo;
            return;
         }
         Persona<T> * tmp = m_pHead;
         for( ; tmp->m_pSig; tmp=tmp->m_pSig);
         tmp->m_pSig = pNuevo;
         m_pLast = pNuevo;


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
          m_pLast=(*q);
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

int main(int argc, char const *argv[]) {
  Agenda<string> A;
  RenderWindow window(VideoMode(500,400),"Phonebook :D");
  Menu menu(window.getSize().x,window.getSize().y);
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
  /*text2.setStyle(Text::Style::Bold | Text::Style::Underlined);
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
      window.draw(playerText);
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
                  //  cout<<"Next"<<endl;
                    A.print();
                    break;
                  case 1:
                    //cout<<"Preview"<<endl;
                    A.print();
                    break;
                  case 2:
                    //cout<<"Begin"<<endl;
                    A.print_Begin();
                    break;
                  case 3:
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
  //  window.draw(text_input);
    window.draw(text2);
    menu.draw(window);
    window.display();
  }
  return 0;
}
