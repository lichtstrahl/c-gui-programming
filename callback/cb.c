#include "cb.h"

// Функция активации главного окна
void activate(GtkApplication *app, gpointer user_data)
{
    // Создание главного окна
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Кнопка 1
    GtkWidget *button1 = gtk_button_new_with_label("Кнопка 1");
    // gtk_container_add(GTK_CONTAINER(buttonBox), button1);
    gtk_grid_attach(GTK_GRID(grid), button1, 0,0,1,1);
    g_signal_connect(button1, "clicked", G_CALLBACK(button_click), "Сообщение в первый обработчик");

    // Кнопка 2
    GtkWidget *button2 = gtk_button_new_with_label("Кнопка 2");
    // gtk_container_add(GTK_CONTAINER(buttonBox), button2);
    gtk_grid_attach(GTK_GRID(grid), button2, 0, 1, 1, 1);
    g_signal_connect(button2, "clicked", G_CALLBACK(button_click), "Сообщение во второй обработчик");

    // Кнопка выхода
    GtkWidget *buttonQuit = gtk_button_new_with_label("Выход");
    // gtk_container_add(GTK_CONTAINER(buttonBox), buttonQuit);
    gtk_grid_attach(GTK_GRID(grid), buttonQuit, 1,0,1,2);
    g_signal_connect_swapped(buttonQuit, "clicked", G_CALLBACK(gtk_widget_destroy), window);

    // g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);
    gtk_widget_show_all(window);
}

// Callback на нажатие кнопки
void button_click(GtkWidget *widget, char* data)
{
    g_print("%s\n", data);
}
