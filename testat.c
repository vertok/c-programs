 #include <cairo.h>
    #include <gtk/gtk.h>

    int x = 0;
    int x_old = 0;
    float value = 0;
    float value_old = 0;
    GtkWidget *button = NULL;
    GtkWidget *window = NULL;
    GtkWidget *area = NULL;
    GtkWidget *table = NULL;

    static gboolean load_interface(GtkWidget *widget)
    {
     cairo_t *cr;
     cr = gdk_cairo_create(area->window);
     cairo_set_source_rgb(cr, 1, 1, 1);
     cairo_rectangle(cr, 0, 0, 900, 400);
     cairo_fill(cr);
    }

    void draw(GtkWidget *widget)
    {
     cairo_t *cr;
     cr = gdk_cairo_create(widget->window);

     x_old = x;
     x = x + 15;
     value_old = value;
     value = value + 0.25;

     cairo_set_source_rgb(cr, 0, 0, 0);
     cairo_set_line_width (cr, 1);
     cairo_move_to(cr, x_old, 100 + (sin(value_old))*50);
     cairo_line_to(cr, x, 100 + (sin(value))*50);
     cairo_stroke(cr);
    }


     int main (int argc, char *argv[])
    {
      g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, (GLogFunc) gtk_false, NULL);
      gtk_init (&argc, &argv);
      g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, g_log_default_handler, NULL);

      window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
      gtk_container_set_border_width (GTK_CONTAINER (window), 3);
      gtk_window_set_title (GTK_WINDOW (window), "Draw");
      gtk_window_set_position (GTK_WINDOW (window), GTK_WIN_POS_CENTER);
      gtk_widget_realize (window);
      g_signal_connect (window, "destroy", gtk_main_quit, NULL);

      table = gtk_table_new (10, 10, TRUE);
      gtk_table_set_col_spacings(GTK_TABLE(table),10);
      gtk_table_set_row_spacings(GTK_TABLE(table),5);
      gtk_container_add (GTK_CONTAINER (window), table);

      area = gtk_drawing_area_new();
      gtk_signal_connect (GTK_OBJECT(area), "event", G_CALLBACK (load_interface),     (gpointer)area);
      gtk_table_attach_defaults (GTK_TABLE(table), area, 1, 10, 0, 10);

      button = gtk_button_new_from_stock ("START");
      g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (draw), (gpointer) window);
      gtk_table_attach_defaults (GTK_TABLE(table), button, 0, 1, 0, 1);

      gtk_widget_show_all (window);
      gtk_main ();

      return 0;
     }
