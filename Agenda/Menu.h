#include "SFML/Graphics.hpp"

//#include "Text.hpp"
using namespace sf;

#define Max_NUMBER_OF_ITEMS 4

class Menu{
public:
  Menu(float width,float height);
  ~Menu();
  void draw(RenderWindow &window);
  void MoveUp();
  void MoveDown();
  int GetPressedItem(){return selectedItemIndex;}
  Sprite get_sprite(){return *spr_menu;}
private:
  int selectedItemIndex;
  Font font;
  Text menu[Max_NUMBER_OF_ITEMS];
  Texture *txt_menu;
  Sprite *spr_menu;
};
