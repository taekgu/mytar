LPWD = /home/sb/mytar/incoding

mytar: main.c
	gcc -o mytar main.c -I. -L$(LPWD) -lincodingfuncs

clean:
	rm mytar
