
//#include <gtk/gtk.h>

#include "util.h"

static GtkWidget *janela;
static GtkWidget *clist;

GtkWidget *cria_janela(int x, int y, char *titulo){
	
	janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_usize(GTK_WIDGET(janela),x,y);
	gtk_window_set_title(GTK_WINDOW(janela),titulo);

	return janela;
}

GtkWidget *cria_clist(int num_cols, int largura, char **titulo){
	int i = 0;
	clist = gtk_clist_new_with_titles(num_cols,titulo);
	while(i < num_cols){
		gtk_clist_set_column_width(GTK_CLIST(clist),i,(largura / num_cols));
		i++;
	}
	return clist;
}



