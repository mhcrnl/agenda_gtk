#include <gtk/gtk.h>
#include <stdlib.h> //para uso da função malloc.
#include "util.h"
#include <string.h>

#define	LINHAS	10
#define COLUNAS	2

static gint linha;

void sair(GtkWidget *w, gpointer *p){
	g_print("Saindo...");
	gtk_exit(0);
}

struct teste{
	GtkWidget *lista;
	GtkWidget *nome;
	GtkWidget *fone;
};


void atualiza_lista(GtkWidget *w, gpointer *p){
	char nome[51];
	char fone[30];
	gchar *dados[2];
	FILE *file;
	if((file=fopen("file.txt","r")) == NULL){
		g_printf("Falha ao abrir arquivos.\n");
		exit(1);
	}

	while(fscanf(file,"%s %s",nome,fone) != EOF){
		dados[0]=nome;
		dados[1]=fone;
		gtk_clist_append(GTK_CLIST(p),dados);
	}

}


/* grava os contados da clist em um arquivo em disco */
void get_dados(GtkWidget *w, gpointer *p){
	gchar *text;
	char *contatos[LINHAS][COLUNAS];
	char *aux;
	int i = 0;

	while(i < LINHAS){
		text = "";
		gtk_clist_get_text(GTK_CLIST(p),i,0,&text);
		contatos[i][0] = (char *) text;
		gtk_clist_get_text(GTK_CLIST(p),i,1,&text);
		contatos[i][1] = (char *) text;
		
		if (contatos[i][0] == "" && contatos[i][1]== "" )
			break;

		i++;
	}

	FILE *file;
	file = fopen("file.txt","w");
	if(file == NULL){
		g_printf("\nFalha ao abrir o arquivo\n");
		exit(1);
	}
	else{
		i =0;
		while(i < LINHAS){
			fprintf(file,"%s %s",contatos[i][0],contatos[i][1]);
			fputs("\n",file);
			++i;
			if(contatos[i][0]=="")
				break;
		}	
	}

	fclose(file);
}


/* remove a linha selecionada no clist */
void remove_dados(GtkWidget *w, gpointer *p){
	gtk_clist_remove(GTK_CLIST(p),linha);	
}

/* retorna as a linha e coluna do item selecionado na lista 
 * para ser utilizado na função que remove registro.	*/
void selection_made(GtkWidget				*clist,
										gint						row,
										gint						column,
										GdkEventButton	*event,
										gpointer				data){
	linha = row;
}

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

	window = cria_janela(500,500,"Agenda Gtk");

	gtk_signal_connect(GTK_OBJECT(window),"destroy",GTK_SIGNAL_FUNC(sair),NULL);

	b_add = gtk_button_new_with_label("Adiciona");
	b_remove = gtk_button_new_with_label("Remove");
	b_ok = gtk_button_new_with_label("Confirmar");
	b_cancel = gtk_button_new_with_label("Sair");
	l_nome = gtk_label_new("Nome:");
	l_telefone = gtk_label_new("telefone:");
	t_nome = gtk_entry_new();
	t_telefone = gtk_entry_new();

	clist = cria_clist(2,500,titulos);

	hbox_add_remove = gtk_hbox_new(TRUE,5);
	hbox_ok_cancel = gtk_hbox_new(TRUE,5);
	table = gtk_table_new(5,3,FALSE);

	novoContato->lista = clist;
	novoContato->nome = t_nome;
	novoContato->fone = t_telefone;

	gtk_signal_connect(GTK_OBJECT(window),"show",GTK_SIGNAL_FUNC(atualiza_lista),clist);
	gtk_signal_connect(GTK_OBJECT(clist),"select_row",GTK_SIGNAL_FUNC(selection_made),NULL);

	gtk_signal_connect(GTK_OBJECT(b_cancel),"clicked",GTK_SIGNAL_FUNC(sair),NULL);
	gtk_signal_connect(GTK_OBJECT(b_add),"clicked",GTK_SIGNAL_FUNC(adiciona),novoContato);
	gtk_signal_connect(GTK_OBJECT(b_remove),"clicked",GTK_SIGNAL_FUNC(remove_dados),clist);
	gtk_signal_connect(GTK_OBJECT(b_ok),"clicked",GTK_SIGNAL_FUNC(get_dados),clist);

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
