#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>
//#include "exwindow.h"

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


MessageText::MessageText()
{
  set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  add(m_TextView);
  insert_sickness1();
  insert_sickness2();

  show_all_children();
}

MessageText::~MessageText()
{
}

void MessageText::insert_sickness1()
{
  auto refTextBuffer = m_TextView.get_buffer();
  Gtk::TextBuffer::iterator iter = refTextBuffer->get_iter_at_offset(0);
    refTextBuffer->insert(iter,
    "Acne. ¿Qué es?\n\n"

    "El acné es una enfermedad que se caracteriza\n"
    "por la aparición de lesiones en la piel como consecuencia\n"
    "de una foliculitis, una inflamación y posterior infección\n"
    "del poro folicular (orificio de salida del pelo).\n"
    "Estas lesiones suelen ser granos, espinillas \n"
    "negras y parches rojos e inflamados, como quistes.\n"

  );
}
void MessageText::insert_sickness2(){
  auto refTextBuffer = m_TextView.get_buffer();
  Gtk::TextBuffer::iterator iter = refTextBuffer->get_iter_at_offset(0);
    refTextBuffer->insert(iter,
    "Cancer de Higado. ¿Qué es?\n\n"

    "El cáncer de hígado es una enfermedad por la\n"
    "cual se forman células malignas o cancerosas\n"
    "en los tejidos del hígado. El cáncer de hígado\n"
    "puede o bien originarse en el hígado (cáncer\n"
    "hepático primario) o comenzar en otro lugar y\n"
  "posteriormente extenderse a este órgano (cáncer\n"
     "de hígado metastático).\n"

  );
}



class ExampleWindow : public Gtk::Window
{
public:
  ExampleWindow();
  virtual ~ExampleWindow();

protected:

  void fill_buffers();

  //Signal handlers:
  void on_button_quit();
  void on_button_buffer1();
  void on_button_buffer2();
  void on_button_buffer3();
  void on_button_buffer4();

  //Child widgets:
  Gtk::Box m_VBox;

  Gtk::ScrolledWindow m_ScrolledWindow;
  Gtk::TextView m_TextView;
  MessageText m_MessageText;
  Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer1, m_refTextBuffer2, m_refTextBuffer3, m_refTextBuffer4;

  Gtk::ButtonBox m_ButtonBox;
  Gtk::Button m_Button_Quit, m_Button_Buffer1, m_Button_Buffer2, m_Button_Buffer3, m_Button_Buffer4;
};

#endif //GTKMM_EXAMPLEWINDOW_H
