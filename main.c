#include <gtk/gtk.h>
#include <libintl.h>
#include <stdio.h>

#define DBG_PRINT_LINE printf("%d\n", __LINE__)

// Функция активации главного окна
static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);
    gtk_widget_show_all(window);
}

// Callbcak выхода из программы
static gboolean cb_delete(GtkWidget *window, gpointer data)
{
    gtk_main_quit();
    printf("Программа завершилась\n");
    return FALSE;
}

int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("iv.root.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
