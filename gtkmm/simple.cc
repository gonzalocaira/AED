#include <gtkmm.h>

int main(int argc, char *argv[])
{
  auto app =
    Gtk::Application::create(argc, argv,
      "org.gtkmm.examples.base");

  Gtk::Window window;
  window.set_default_size(200, 200);

  return app->run(window);
  /*Gtk::Main kit(argc,argv);
  Gtk::Window window;
  window.set_default_size(600,360);
  window.set_tittle("Agenda electronica");
  window.set_position(Gtk::WIN_POS_CENTER);

  Gtk::Main::wun(window);
  return 0;*/
}
