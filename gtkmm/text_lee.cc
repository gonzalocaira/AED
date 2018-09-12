#include <gtk/gtk.h>
#include <gtkmm.h>

int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  GtkWidget *view;
  GtkTextBuffer *buffer;

  view = gtk_text_view_new ();

  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (view));

  gtk_text_buffer_set_text (buffer, "Hello, this is some text", -1);


    //Shows the window and returns when it is closed.
    return app->run(view);

}
