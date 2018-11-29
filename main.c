#include <gtk/gtk.h>
#include <libintl.h>
#include <stdio.h>

#define DBG_PRINT_LINE printf("%d\n", __LINE__)

// Callback на нажатие кнопки
static void button_click(GtkWidget *widget, gpointer data)
{
    g_print("Нажал на кнопку!\n");
}

// Функция активации главного окна
static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);
    //
    GtkWidget *button = gtk_button_new_with_label("Кнопка");
    gtk_container_add(GTK_CONTAINER(window), button);
    g_signal_connect(button, "clicked", G_CALLBACK(button_click), NULL);


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

    app = gtk_application_new("iv.application", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
