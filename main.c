#include <gtk/gtk.h>
#include <libintl.h>
#include <stdio.h>
#include "callback/cb.h"

#define DBG_PRINT_LINE printf("%d\n", __LINE__)


int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("iv.application", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    printf("Приложение завершило свою работу с кодом: %d\n", status);
    return status;
}
