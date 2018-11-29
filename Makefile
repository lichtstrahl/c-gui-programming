PKG_GTK = `pkg-config --cflags --libs gtk+-3.0`

main	:	main.o
	gcc -std=c99 main.o $(PKG_GTK) -o main

main.o	:	main.c
	gcc -c main.c $(PKG_GTK)
