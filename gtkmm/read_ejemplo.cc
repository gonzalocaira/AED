#include "examplewindow.h"
#include <gtkmm/application.h>
#include <iostream>
#include <fstream>
#include <string>

void modeselect(GtkWidget *widget, gpointer view)
{
char ch2;
char array2[8192];
gchar *buf2;
FILE *file2;
char ch1;
char array1[8192];
gchar *buf1;
FILE *file1;

GtkTextBuffer *buff;
array2[0] = ”;
array1[0] = ”;

buff = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));

gchar *text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(widget));

if(strcmp(text,”AODV MODE”) == 0 )
{
file1 = fopen(“enfermedades.txt”,”r”);

while((ch1 = fgetc(file1)) != EOF)
{
// g_print(“%c”,ch1);
strcat(array1 ,&ch1);
}
buf1 = g_strdup_printf((gchar *) array1);

fclose(file1);
// gtk_label_set_text(GTK_LABEL(label), buf1);
gtk_text_buffer_set_text(buff, buf1, -1);

}

if(strcmp(text,”OLSR MODE”) == 0 )
{
file1 = fopen(“sampleolsr.txt”,”r”);

while((ch1 = fgetc(file1)) != EOF)
{
// g_print(“%c”,ch1);
strcat(array1 ,&ch1);
}
buf1 = g_strdup_printf((gchar *) array1);

fclose(file1);
// gtk_label_set_text(GTK_LABEL(label), buf1);
gtk_text_buffer_set_text(buff,buf1, -1);
}

}

int main( int argc, char *argv[])
{

GtkWidget *window;
GtkWidget *view;
GtkWidget *frame;
GtkWidget *frame2;
GtkWidget *vbox;
GtkWidget *vbox1;
GtkWidget *hbox;
GtkWidget *label;
GtkWidget *label2;
GtkWidget *combo;

GtkTextBuffer *buffer;

gtk_init(&argc, &argv);

window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
// gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
gtk_window_set_default_size(GTK_WINDOW(window), 650, 600);
gtk_window_set_title(GTK_WINDOW(window), ” Protocol Information”);
gtk_container_set_border_width(GTK_CONTAINER(window), 5);
GTK_WINDOW(window)->allow_shrink = TRUE;

frame = gtk_fixed_new();
frame2 = gtk_fixed_new();
vbox = gtk_vbox_new(FALSE, 0);
vbox1 = gtk_vbox_new(FALSE, 0);
hbox = gtk_hbox_new(FALSE, 0);

// gtk_widget_set_size_request(frame, 100, 200);

combo = gtk_combo_box_new_text();
// gtk_widget_set_size_request(combo, 5, 30);
gtk_combo_box_append_text(GTK_COMBO_BOX(combo), “AODV MODE”);
gtk_combo_box_append_text(GTK_COMBO_BOX(combo), “OLSR MODE”);

// gtk_widget_set_size_request(vbox1, 50,50);

view = gtk_text_view_new();
gtk_widget_set_size_request(view, 0, 550);
gtk_text_view_set_editable(GTK_TEXT_VIEW (view), FALSE);
gtk_box_pack_start(GTK_BOX(vbox1), view, TRUE, TRUE, 0);
buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));

// gtk_text_buffer_set_text(buffer, “hi”, -1);

label = gtk_label_new( NULL);
gtk_widget_set_size_request(label, 650, 500);

label2 = gtk_label_new(“Select the mode”);

gtk_fixed_put(GTK_FIXED(frame), label, 10, 10);
// label2 = gtk_label_new(“Select the mode”);
gtk_fixed_put(GTK_FIXED(frame2), label2, 20, 25);
gtk_fixed_put(GTK_FIXED(frame2), combo, 200, 20);

gtk_box_pack_start(GTK_BOX(hbox), frame2, TRUE, TRUE, 0);
// gtk_box_pack_start(GTK_BOX(vbox), combo, FALSE, FALSE, 0);
gtk_box_pack_start(GTK_BOX(vbox), vbox1, TRUE, TRUE, 0);
gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);

gtk_container_add(GTK_CONTAINER(window), vbox);

g_signal_connect_swapped(G_OBJECT(window), “destroy”,
G_CALLBACK(gtk_main_quit), G_OBJECT(window));

g_signal_connect(G_OBJECT (combo),”changed”, G_CALLBACK(modeselect),(gpointer) view);

gtk_widget_show_all(window);

gtk_main();

return 0;
}
