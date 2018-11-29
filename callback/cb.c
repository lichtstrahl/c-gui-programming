#include "cb.h"

// Начальная конфигурация окна
void onCreate(GtkBuilder *builder)
{
    GtkWindow *window = (GtkWindow*)gtk_builder_get_object(builder, "window");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkButton *button1 = (GtkButton*)gtk_builder_get_object(builder, "button1");
    g_signal_connect(button1, "clicked", G_CALLBACK(button_click), "Нажата первая кнопка");

    GtkButton *button2 = (GtkButton*)gtk_builder_get_object(builder, "button2");
    g_signal_connect(button2, "clicked", G_CALLBACK(button_click), "Нажата вторая кнопка");

    GtkButton *buttonQuit = (GtkButton*)gtk_builder_get_object(builder, "button_quit");
    g_signal_connect(buttonQuit, "clicked", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(GTK_WIDGET(window));
}

// Callback на нажатие кнопки
void button_click(GtkWidget *widget, char* data)
{
    g_print("%s\n", data);
}
