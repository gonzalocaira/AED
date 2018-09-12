#include "exwindow.h"
#include "messageslist.h"
#include <sstream>
#include <gtkmm/application.h>
#include "messagetext.h"
#include <iostream>
#include <fstream>
#include <string>


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

MessagesList::MessagesList()
{
  /* Create a new scrolled window, with scrollbars only if needed */
  set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  add(m_TreeView);

  /* create list store */
  m_refListStore = Gtk::ListStore::create(m_Columns);

  m_TreeView.set_model(m_refListStore);

  /* Add some messages to the window */
  for(int i = 0; i < 10; ++i)
  {
    std::ostringstream text;
    text << "Sickness#" << i;

    Gtk::TreeModel::Row row = *(m_refListStore->append());
    row[m_Columns.m_col_text] = text.str();
  }

  //Add the Model's column to the View's columns:
  m_TreeView.append_column("Sickness", m_Columns.m_col_text);

  show_all_children();
}

MessagesList::~MessagesList()
{
}


Exwindow::Exwindow()
: m_VPaned(Gtk::ORIENTATION_VERTICAL)
{
  set_title ("Paned Windows");
  set_border_width(10);
  set_default_size(450, 400);

  /* Add a vpaned widget to our toplevel window */
  add(m_VPaned);

  /* Now add the contents of the two halves of the window */
  m_VPaned.add1(m_MessagesList);
  m_VPaned.add2(m_MessageText);

  show_all_children();
}

Exwindow::~Exwindow()
{
}
/*
int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  Exwindow window;

  //Shows the window and returns when it is closed.
  return app->run(window);
}*/
