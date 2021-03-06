#include <gtk/gtk.h>

typedef struct
{
     GtkWidget *entry, *textview;
} Widgets;

int delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
{
    return(FALSE);
}

void exit_cb(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

static void insert_text (GtkButton*, Widgets*);

int main (int argc,
          char *argv[])
{
     GtkWidget *window, *scrolled_win, *hbox, *vbox, *insert;
     Widgets *w = g_slice_new (Widgets);

     gtk_init (&argc, &argv);

     window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
     gtk_window_set_title (GTK_WINDOW (window), "phonebook");
     gtk_signal_connect(GTK_OBJECT (window), "delete_event",
                        GTK_SIGNAL_FUNC (delete_event), NULL);

     gtk_signal_connect(GTK_OBJECT (window), "destroy",
                        GTK_SIGNAL_FUNC (exit_cb), NULL);
  
     gtk_container_set_border_width (GTK_CONTAINER (window), 10);
     gtk_widget_set_size_request (window, 500, 500);

     w->textview = gtk_text_view_new ();
     w->entry = gtk_entry_new ();
     insert = gtk_button_new_with_label ("Add Person");

     g_signal_connect (G_OBJECT (insert), "clicked",
               G_CALLBACK (insert_text),
               (gpointer) w);

     scrolled_win = gtk_scrolled_window_new (NULL, NULL);
     gtk_container_add (GTK_CONTAINER (scrolled_win), w->textview);

     hbox = gtk_hbox_new (FALSE, 5);
     gtk_box_pack_start_defaults (GTK_BOX (hbox), w->entry);
     gtk_box_pack_start_defaults (GTK_BOX (hbox), insert);

     vbox = gtk_vbox_new (FALSE, 5);
     gtk_box_pack_start (GTK_BOX (vbox), scrolled_win, TRUE, TRUE, 0);
     gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, TRUE, 0);

     gtk_container_add (GTK_CONTAINER (window), vbox);
     gtk_widget_show_all (window);

     gtk_main();
     return 0;
}

/* Insert the text from the GtkEntry into the GtkTextView. */
static void insert_text (GtkButton *button,
             Widgets *w)
{
     GtkTextBuffer *buffer;
     GtkTextMark *mark;
     GtkTextIter iter;
     const gchar *text;

     buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (w->textview));
     text = gtk_entry_get_text (GTK_ENTRY (w->entry));

     mark = gtk_text_buffer_get_insert (buffer);
     gtk_text_buffer_get_iter_at_mark (buffer, &iter, mark);
     if (gtk_text_buffer_get_char_count(buffer))
     gtk_text_buffer_insert (buffer, &iter, "\n", 1);

     gtk_text_buffer_insert (buffer, &iter, text, -1);
}