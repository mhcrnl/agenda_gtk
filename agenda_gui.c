#include <gtk/gtk.h>
#include <stdio.h>


int main(int argc, char **argv){
	
	GtkWidget *window;

	gtk_init(&argc,&argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_usize(GTK_WIDGET(window),300,300);
	gtk_window_set_title(GTK_WINDOW(window),"Agenda Gtk");

	gtk_widget_show(window);

	gtk_main();

	return 0;
}
