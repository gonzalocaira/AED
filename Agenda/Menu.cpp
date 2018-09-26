#include "Menu.h"
using namespace sf;
Menu::Menu(float width,float height){
  txt_menu = new Texture();
  txt_menu -> loadFromFile("menu.png");
  spr_menu = new Sprite(*txt_menu);
  spr_menu -> setPosition(0,0);
  if(!font.loadFromFile("Echomotors Script Demo.ttf"))

  {
    //handle error
  }
  menu[0].setFont(font);
  menu[0].setFillColor(sf::Color::Cyan);
  menu[0].setString("Load text");
  menu[0].setCharacterSize(42);
  menu[0].setPosition(Vector2f(250,150));

  menu[1].setFont(font);
  menu[1].setFillColor(sf::Color::White);
  menu[1].setString("Delete stopwords");
  menu[1].setCharacterSize(42);
  menu[1].setPosition(Vector2f(250,190));

  menu[2].setFont(font);
  menu[2].setFillColor(sf::Color::White);
  menu[2].setString("Show frequency");
  menu[2].setCharacterSize(42);
  menu[2].setPosition(Vector2f(250,230));

  menu[3].setFont(font);
  menu[3].setFillColor(sf::Color::White);
  menu[3].setString("Exit");
  menu[3].setCharacterSize(42);
  menu[3].setPosition(Vector2f(250,270));



  selectedItemIndex=0;
}
Menu::~Menu(){
}

void Menu::draw(RenderWindow &window){
  for(int i=0;i<Max_NUMBER_OF_ITEMS;i++){
    window.draw(menu[i]);
  }

}
void Menu::MoveUp(){
  if(selectedItemIndex - 1 >= 0){
    menu[selectedItemIndex].setFillColor(Color::White);
    selectedItemIndex--;
    menu[selectedItemIndex].setFillColor(Color::Cyan);
  }
}
void Menu::MoveDown(){
  if(selectedItemIndex + 1 < Max_NUMBER_OF_ITEMS){
    menu[selectedItemIndex].setFillColor(Color::White);
    selectedItemIndex++;
    menu[selectedItemIndex].setFillColor(Color::Cyan);
  }
}
