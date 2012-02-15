#include <gtk/gtk.h>
#include <stdio.h>

void sair(GtkWidget *w, gpointer *p){
	g_print("Saindo...");
}


int main(int argc, char **argv){
	

	GtkWidget *window;

	gtk_init(&argc,&argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_usize(GTK_WIDGET(window),500,500);
	gtk_window_set_title(GTK_WINDOW(window),"Agenda Gtk");
	
	gtk_signal_connect(GTK_OBJECT(window),"destroy",GTK_SIGNAL_FUNC(sair),NULL);
	

	gtk_widget_show(window);

	gtk_main();

	return 0;
}
