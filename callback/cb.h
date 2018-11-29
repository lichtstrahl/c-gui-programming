#ifndef CB_H
#define CB_H

/*
    В этом файле объявлены заголовки всех функций, которые будут использоваться в приложении в качестве CALLBACK-ов
*/

#include <gtk/gtk.h>
#include <libintl.h>

// Активация. Первоначальные настройки приложения
void activate(GtkApplication *app, gpointer user_data);
// Объявление функции обработчика нажатия на кнопку
void button_click(GtkWidget *widget, char* data);


#endif
