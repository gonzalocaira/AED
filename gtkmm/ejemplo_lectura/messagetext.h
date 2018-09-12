#ifndef GTKMM_EXAMPLE_MESSAGETEXT_H
#define GTKMM_EXAMPLE_MESSAGETEXT_H

#include <gtkmm.h>

class MessageText : public Gtk::ScrolledWindow
{
public:
  MessageText();
  virtual ~MessageText();

  void insert_sickness1();
  void insert_sickness2();
  void insert_sickness3();
  void insert_sickness4();
  void insert_sickness5();
  void insert_sickness6();

protected:
  Gtk::TextView m_TextView;
};

#endif //GTKMM_EXAMPLE_MESSAGETEXT_H
