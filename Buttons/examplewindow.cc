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


  m_refTextBuffer2 = Gtk::TextBuffer::create();
  m_refTextBuffer2->set_text("This is some alternative text, from TextBuffer #2.");

  m_refTextBuffer3 = Gtk::TextBuffer::create();
  m_refTextBuffer3->set_text("This is the text from TextBuffer #3.");

  m_refTextBuffer4 = Gtk::TextBuffer::create();
  m_refTextBuffer4->set_text("This is some alternative text, from TextBuffer #4.");

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
