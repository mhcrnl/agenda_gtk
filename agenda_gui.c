#include <gtk/gtk.h>
#include <stdio.h>

void sair(GtkWidget *w, gpointer *p){
	g_print("Saindo...");
	gtk_exit(0);
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

	t_nome = gtk_entry_new();
	t_telefone = gtk_entry_new();

	/**cria uma caixa horizontal.
		 true = determina que todas as subdivisões tem o mesmo tamanho
		 5 = qtd de pixels entre os componentes adicionados a caixa.
	*/
	hbox_add_remove = gtk_hbox_new(TRUE,5);
	hbox_ok_cancel = gtk_hbox_new(TRUE,5);

	//criando uma tabela de 4 linhas, 3 colunas e as celulas não terao o mesmo tamanho(FALSE).
	table = gtk_table_new(4,3,TRUE);

	
	gtk_table_attach(GTK_TABLE(table),t_nome,1,3,0,1,(GTK_FILL | GTK_SHRINK),GTK_SHRINK,0,0);
	gtk_table_attach(GTK_TABLE(table),t_telefone,1,3,1,2,(GTK_FILL | GTK_SHRINK),GTK_SHRINK,0,0);

	//adicionar botao na caixa.	
	gtk_box_pack_start(GTK_BOX(hbox_add_remove),b_add,FALSE,TRUE,5);
	gtk_box_pack_start(GTK_BOX(hbox_add_remove),b_remove,FALSE,TRUE,5);

	gtk_box_pack_start(GTK_BOX(hbox_ok_cancel),b_ok,FALSE,TRUE,5);
	gtk_box_pack_start(GTK_BOX(hbox_ok_cancel),b_cancel,FALSE,TRUE,5);
	
	//adiciona as caixas na table
	gtk_table_attach(GTK_TABLE(table),hbox_add_remove,1,2,2,3,GTK_FILL,GTK_SHRINK,0,0);	
	gtk_table_attach(GTK_TABLE(table),hbox_ok_cancel,1,2,3,4,GTK_FILL,GTK_SHRINK,0,0);

	//adiciona a table em window
	gtk_container_add(GTK_CONTAINER(window),table);

	

	//Exibe os widgets
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
