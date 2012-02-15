#include <gtk/gtk.h>
#include <stdio.h>

void sair(GtkWidget *w, gpointer *p){
	g_print("Saindo...");
	gtk_exit(0);
}


int main(int argc, char **argv){
	

	GtkWidget *window, 
						*table, 
						*hbox, 
						*b_add, 
						*b_remove, 
						*b_ok, 
						*b_cancel;

	gtk_init(&argc,&argv);

	//criando a janela e definindo tamanho, titulo e evendo ao fechar.
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_usize(GTK_WIDGET(window),500,500);
	gtk_window_set_title(GTK_WINDOW(window),"Agenda Gtk");
	gtk_signal_connect(GTK_OBJECT(window),"destroy",GTK_SIGNAL_FUNC(sair),NULL);
	
	//criando os botões
	b_add = gtk_button_new_with_label("Adiciona");
	b_remove = gtk_button_new_with_label("Remove");
	b_ok = gtk_button_new_with_label("Confirmar");
	b_cancel = gtk_button_new_with_label("Cancelar");


	/**cria uma caixa horizontal.
		 true = determina que todas as subdivisões tem o mesmo tamanho
		 5 = qtd de pixels entre os componentes adicionados a caixa.
	*/
	hbox = gtk_hbox_new(TRUE,5);

	//adicionar botao na caixa.	
	gtk_box_pack_start(GTK_BOX(hbox),b_add,FALSE,TRUE,5);
	gtk_box_pack_start(GTK_BOX(hbox),b_remove,TRUE,FALSE,5);

	//adiciona a caixa hbox em window
	gtk_container_add(GTK_CONTAINER(window),hbox);
	
	//Exibe os widgets
	gtk_widget_show(b_add);
	gtk_widget_show(b_remove);
	gtk_widget_show(hbox);
	gtk_widget_show(window);

	gtk_main();

	return 0;
}
