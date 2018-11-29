#include <gtk/gtk.h>
#include <libintl.h>
#include <stdio.h>
#include "callback/cb.h"

#define FINISH(status) \
    printf("Приложение завершило свою работу с кодом: %d\n", status);\
    return status

int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);
    GtkBuilder *builder = gtk_builder_new_from_file("ui/window.ui");
    onCreate(builder);
    gtk_main();
    FINISH(0);
}
