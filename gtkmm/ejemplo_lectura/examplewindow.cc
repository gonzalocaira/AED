#include "examplewindow.h"
#include <gtkmm/application.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ExampleWindow::ExampleWindow()
: m_VBox(Gtk::ORIENTATION_VERTICAL),
  m_Button_Quit("_Quit", true),
  m_Button_Buffer1("First"),
  m_Button_Buffer2("Prev."),
  m_Button_Buffer3("Next"),
  m_Button_Buffer4("Last")

{
  set_title("List of injuries");
  set_border_width(5);
  set_default_size(800, 400);

  add(m_VBox);

  //Add the TreeView, inside a ScrolledWindow, with the button underneath:
  m_ScrolledWindow.add(m_TextView);

  //Only show the scrollbars when they are necessary:
  m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  m_VBox.pack_start(m_ScrolledWindow);

  //Add buttons:
  m_VBox.pack_start(m_ButtonBox, Gtk::PACK_SHRINK);

  m_ButtonBox.pack_start(m_Button_Buffer1, Gtk::PACK_SHRINK);
  m_ButtonBox.pack_start(m_Button_Buffer2, Gtk::PACK_SHRINK);
  m_ButtonBox.pack_start(m_Button_Buffer3, Gtk::PACK_SHRINK);
  m_ButtonBox.pack_start(m_Button_Buffer4, Gtk::PACK_SHRINK);
  m_ButtonBox.pack_start(m_Button_Quit, Gtk::PACK_SHRINK);
  m_ButtonBox.set_border_width(5);
  m_ButtonBox.set_spacing(5);
  m_ButtonBox.set_layout(Gtk::BUTTONBOX_END);

  //Connect signals:
  m_Button_Quit.signal_clicked().connect(sigc::mem_fun(*this,
              &ExampleWindow::on_button_quit) );
  m_Button_Buffer1.signal_clicked().connect(sigc::mem_fun(*this,
              &ExampleWindow::on_button_buffer1) );
  m_Button_Buffer2.signal_clicked().connect(sigc::mem_fun(*this,
              &ExampleWindow::on_button_buffer2) );
  m_Button_Buffer3.signal_clicked().connect(sigc::mem_fun(*this,
              &ExampleWindow::on_button_buffer3) );
  m_Button_Buffer4.signal_clicked().connect(sigc::mem_fun(*this,
              &ExampleWindow::on_button_buffer4) );

  fill_buffers();
  on_button_buffer1();

  show_all_children();
}

void ExampleWindow::fill_buffers()
{
  m_refTextBuffer1 = Gtk::TextBuffer::create();
  //for (int i=0;i<5;i++){
    //m_refTextBuffer1->set_text("gfffg");
  //}
  string line;
  ifstream myfile ("enfermedades.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      //cout << line << '\n';
      m_refTextBuffer1->set_text(line);
    }
    myfile.close();
  }

  else cout << "Unable to open file";

  m_refTextBuffer1 = Gtk::TextBuffer::create();
  //m_MessageText.insert_sickness1();
  m_refTextBuffer1->set_text("Depresion. ¿Qué es?\n\n"
  "La tristeza y la melancolía son dos sentimientos\n"
  "presentes en algún momento de la vida de todas las \n"
  "personas, al igual que la alegría y el placer. Los \n"
  "dos primeros no son en sí patológicos, pero en\n"
  "algunas ocasiones pueden llegar a serlo para \n"
   "ciertas personas. \n");

  m_refTextBuffer2 = Gtk::TextBuffer::create();
  //m_MessageText.insert_sickness1();
  m_refTextBuffer2->set_text("Acne. ¿Qué es?\n\n"

  "El acné es una enfermedad que se caracteriza\n"
  "por la aparición de lesiones en la piel como consecuencia\n"
  "de una foliculitis, una inflamación y posterior infección\n"
  "del poro folicular (orificio de salida del pelo).\n"
  "Estas lesiones suelen ser granos, espinillas \n"
  "negras y parches rojos e inflamados, como quistes.\n");

  m_refTextBuffer3 = Gtk::TextBuffer::create();
  m_refTextBuffer3->set_text("Cancer de Higado. ¿Qué es?\n\n"

  "El cáncer de hígado es una enfermedad por la\n"
  "cual se forman células malignas o cancerosas\n"
  "en los tejidos del hígado. El cáncer de hígado\n"
  "puede o bien originarse en el hígado (cáncer\n"
  "hepático primario) o comenzar en otro lugar y\n"
"posteriormente extenderse a este órgano (cáncer\n"
   "de hígado metastático).\n");

  m_refTextBuffer4 = Gtk::TextBuffer::create();
  m_refTextBuffer4->set_text("Bullying. ¿Qué es?\n\n"

   "Es la exposición que sufre un niño a daños físicos\n"
    "y psicológicos de forma intencionada y reiterada por \n"
    "parte de otro, o de un grupo de ellos, cuando acude \n"
    "al colegio. El acosador aprovecha un desequilibrio de \n"
    "poder que existe entre él y su víctima para conseguir un\n"
     "beneficio (material o no), mientras que el acosado se \n"
     "siente indefenso y puede desarrollar una serie de \n"
     "problemas psicológicos que afecten directamente a su\n"
      "salud o incluso, en situaciones extremas, propiciar \n"
      "que quiera acabar con su vida mediante el suicidio.\n");

}

ExampleWindow::~ExampleWindow()
{
}

void ExampleWindow::on_button_quit()
{
  hide();
}

void ExampleWindow::on_button_buffer1()
{
  m_TextView.set_buffer(m_refTextBuffer1);
}

void ExampleWindow::on_button_buffer2()
{
  ofstream myfile ("example.txt");
  if (myfile.is_open())
  {
    myfile << "This is a line.\n";
    myfile << "This is another line.\n";
    myfile.close();
  }
  else cout << "Unable to open file";
  m_TextView.set_buffer(m_refTextBuffer2);
}

void ExampleWindow::on_button_buffer3()
{
  m_TextView.set_buffer(m_refTextBuffer3);
}

void ExampleWindow::on_button_buffer4()
{
  m_TextView.set_buffer(m_refTextBuffer4);
}

int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  ExampleWindow window;
  //Shows the window and returns when it is closed.
  return app->run(window);
}
