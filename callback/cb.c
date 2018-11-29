#include "cb.h"

// Функция активации главного окна
void activate(GtkApplication *app, gpointer user_data)
{
    // Создание главного окна
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 150, 300);

    // Создание горизонтального контейнера для хранения кнопок
    GtkWidget *buttonBox = gtk_button_box_new(GTK_ORIENTATION_VERTICAL);
    gtk_container_add(GTK_CONTAINER(window), buttonBox);

    // Кнопка 1
    GtkWidget *button1 = gtk_button_new_with_label("Кнопка 1");
    gtk_container_add(GTK_CONTAINER(buttonBox), button1);
    g_signal_connect(button1, "clicked", G_CALLBACK(button_click), "Сообщение в первый обработчик");

    // Кнопка 2
    GtkWidget *button2 = gtk_button_new_with_label("Кнопка 2");
    gtk_container_add(GTK_CONTAINER(buttonBox), button2);
    g_signal_connect(button2, "clicked", G_CALLBACK(button_click), "Сообщение во второй обработчик");

    // g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);
    gtk_widget_show_all(window);
}

// Callback на нажатие кнопки
void button_click(GtkWidget *widget, char* data)
{
    g_print("%s\n", data);
}
