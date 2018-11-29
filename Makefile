PKG_GTK = `pkg-config --cflags --libs gtk+-3.0`
APP_NAME = main

$(APP_NAME)	:	main.o
	gcc -std=c99 main.o $(PKG_GTK) -o $(APP_NAME)

main.o	:	main.c
	gcc -c main.c $(PKG_GTK)


clean	:
	rm *.o
	rm $(APP_NAME)
