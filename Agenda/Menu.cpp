#include "Menu.h"
using namespace sf;
Menu::Menu(float width,float height){
  if(!font.loadFromFile("Bafora Regular Demo.ttf")){
    //handle error
  }
  menu[0].setFont(font);
  menu[0].setFillColor(sf::Color::Cyan);
  menu[0].setString("Next");
  menu[0].setCharacterSize(56);
  menu[0].setPosition(Vector2f(390,150));

  menu[1].setFont(font);
  menu[1].setFillColor(sf::Color::White);
  menu[1].setString("Preview");
  menu[1].setCharacterSize(56);
  menu[1].setPosition(Vector2f(390,190));

  menu[2].setFont(font);
  menu[2].setFillColor(sf::Color::White);
  menu[2].setString("Begin");
  menu[2].setCharacterSize(56);
  menu[2].setPosition(Vector2f(390,230));

  menu[3].setFont(font);
  menu[3].setFillColor(sf::Color::White);
  menu[3].setString("Last");
  menu[3].setCharacterSize(56);
  menu[3].setPosition(Vector2f(390,270));

  menu[4].setFont(font);
  menu[4].setFillColor(sf::Color::White);
  menu[4].setString("Add");
  menu[4].setCharacterSize(56);
  menu[4].setPosition(Vector2f(390,310));

  menu[5].setFont(font);
  menu[5].setFillColor(sf::Color::White);
  menu[5].setString("Delete");
  menu[5].setCharacterSize(56);
  menu[5].setPosition(Vector2f(390,350));

  menu[6].setFont(font);
  menu[6].setFillColor(sf::Color::White);
  menu[6].setString("Exit");
  menu[6].setCharacterSize(56);
  menu[6].setPosition(Vector2f(390,390));

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
