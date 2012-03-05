
#include <gtk/gtk.h>

#include "util.h"

static GtkWidget *janela;

GtkWidget *cria_janela(int x, int y, char *titulo)
{
	
	janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_usize(GTK_WIDGET(janela),x,y);
	gtk_window_set_title(GTK_WINDOW(janela),titulo);

	return janela;

}
