#include <gtk/gtk.h>
#include <libintl.h>
#include <stdio.h>

#define DBG_PRINT_LINE printf("%d\n", __LINE__)

// Callbcak выхода из программы
static gboolean cb_delete(GtkWidget *window, gpointer data)
{
    gtk_main_quit();
    printf("Программа завершилась\n");
    return FALSE;
}

int main(int argc, char **argv)
{
    GtkWidget *window;
    // Инициализация GTK
    gtk_init(&argc, &argv);
    // Создание окна
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    // Создание обработчика
    // gtk_signal_connect(GTK_OBJECT(window), "delete_event", GTK_SIGNAL_FUNC(delete_event_cb), NULL);
    g_signal_connect(G_OBJECT(window), "delete-event", G_CALLBACK(cb_delete), NULL);

    // Показ всех виджетов
    gtk_widget_show_all(window);
    // Запуск приложения
    gtk_main();
    return 0;
}
