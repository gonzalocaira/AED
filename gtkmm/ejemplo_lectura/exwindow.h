#ifndef GTKMM_Exwindow_H
#define GTKMM_Exwindow_H

#include "messageslist.h"
#include "messagetext.h"
#include <gtkmm.h>

class Exwindow : public Gtk::Window
{
public:
  Exwindow();
  virtual ~Exwindow();

protected:

  //Child widgets:
  Gtk::Paned m_VPaned;
  MessagesList m_MessagesList;
  MessageText m_MessageText;
};

#endif //GTKMM_Exwindow_H
