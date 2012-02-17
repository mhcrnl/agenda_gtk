#include <gtk/gtk.h>
#include <stdlib.h> //para uso da função malloc.

void sair(GtkWidget *w, gpointer *p){
	g_print("Saindo...");
	gtk_exit(0);
}

struct teste{
	GtkWidget *lista;
	GtkWidget *nome;
	GtkWidget *fone;
};

void adiciona(GtkWidget *w, gpointer *p){
	struct teste *novoContato;
	novoContato = (struct teste*) malloc(sizeof(struct teste*));
	novoContato = (struct teste*) p;

	gchar *dados[2];
	dados[0] = (char *) gtk_entry_get_text( GTK_ENTRY(novoContato->nome));
	dados[1] = (char *) gtk_entry_get_text( GTK_ENTRY(novoContato->fone));

	gtk_clist_append(GTK_CLIST(novoContato->lista),dados);
}

int main(int argc, char **argv){
	

	GtkWidget	*window, 
						*table, 
						*hbox_add_remove,
						*hbox_ok_cancel,
						*t_nome,
						*t_telefone,
						*b_add, 
						*b_remove, 
						*b_ok, 
						*b_cancel,
						*l_nome,
						*l_telefone,
						*clist;

	
	gchar *titulos[2]={"Nome","Telefone"};
	struct teste *novoContato;
	novoContato = (struct teste*) malloc(sizeof(struct teste*));


	gtk_init(&argc,&argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_usize(GTK_WIDGET(window),500,500);
	gtk_window_set_title(GTK_WINDOW(window),"Agenda Gtk");
	gtk_signal_connect(GTK_OBJECT(window),"destroy",GTK_SIGNAL_FUNC(sair),NULL);
	b_add = gtk_button_new_with_label("Adiciona");
	b_remove = gtk_button_new_with_label("Remove");
	b_ok = gtk_button_new_with_label("Confirmar");
	b_cancel = gtk_button_new_with_label("Sair");
	l_nome = gtk_label_new("Nome:");
	l_telefone = gtk_label_new("telefone:");
	t_nome = gtk_entry_new();
	t_telefone = gtk_entry_new();
	clist = gtk_clist_new_with_titles(2,titulos);
	gtk_clist_set_column_width(GTK_CLIST(clist),0,250);
	gtk_clist_set_column_width(GTK_CLIST(clist),1,250);
	hbox_add_remove = gtk_hbox_new(TRUE,5);
	hbox_ok_cancel = gtk_hbox_new(TRUE,5);
	table = gtk_table_new(5,3,FALSE);


	novoContato->lista = clist;
	novoContato->nome = t_nome;
	novoContato->fone = t_telefone;

	gtk_signal_connect(GTK_OBJECT(b_cancel),"clicked",GTK_SIGNAL_FUNC(sair),NULL);
	gtk_signal_connect(GTK_OBJECT(b_add),"clicked",GTK_SIGNAL_FUNC(adiciona),novoContato);

	gtk_box_pack_start(GTK_BOX(hbox_add_remove),b_add,FALSE,TRUE,5);
	gtk_box_pack_start(GTK_BOX(hbox_add_remove),b_remove,FALSE,TRUE,5);
	gtk_box_pack_start(GTK_BOX(hbox_ok_cancel),b_ok,FALSE,TRUE,5);
	gtk_box_pack_start(GTK_BOX(hbox_ok_cancel),b_cancel,FALSE,TRUE,5);
	
	gtk_table_attach(GTK_TABLE(table),clist,0,3,0,2,(GTK_FILL | GTK_EXPAND),(GTK_FILL|GTK_EXPAND),0,0);
	gtk_table_attach(GTK_TABLE(table),l_nome,0,1,2,3,GTK_FILL,GTK_SHRINK,0,0);
	gtk_table_attach(GTK_TABLE(table),l_telefone,0,1,3,4,GTK_SHRINK,GTK_SHRINK,0,0);
	gtk_table_attach(GTK_TABLE(table),t_nome,1,3,2,3,(GTK_FILL | GTK_SHRINK),GTK_SHRINK,0,0);
	gtk_table_attach(GTK_TABLE(table),t_telefone,1,3,3,4,(GTK_FILL | GTK_SHRINK),GTK_SHRINK,0,0);
	gtk_table_attach(GTK_TABLE(table),hbox_add_remove,0,1,4,5,GTK_FILL,GTK_SHRINK,0,0);	
	gtk_table_attach(GTK_TABLE(table),hbox_ok_cancel,2,3,4,5,GTK_FILL,GTK_SHRINK,0,0);

	gtk_container_add(GTK_CONTAINER(window),table);

	//Exibe os widgets
	gtk_widget_show(clist);
	gtk_widget_show(l_nome);
	gtk_widget_show(l_telefone);
	gtk_widget_show(t_nome);
	gtk_widget_show(t_telefone);
	gtk_widget_show(b_add);
	gtk_widget_show(b_remove);
	gtk_widget_show(hbox_add_remove);
	gtk_widget_show(b_ok);
	gtk_widget_show(b_cancel);
	gtk_widget_show(hbox_ok_cancel);
	gtk_widget_show(table);
	gtk_widget_show(window);

	gtk_main();

	return 0;
}
