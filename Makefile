PKG_GTK = `pkg-config --cflags --libs gtk+-3.0`

main : main.o
	gcc  main.o $(PKG_GTK) -o main

main.o	:	main.c
	gcc -std=c99 -c  main.c $(PKG_GTK)

clean :
	rm *.o
	
