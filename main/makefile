LPWD = /home/sb/mytar/incoding
HPWD = /home/sb/mytar
JPWD = /home/sb/mytar/untar/lib

mytar: main.c
	gcc main.c -o mytar -I$(HPWD) -L$(LPWD) -lincodingfuncs -L$(JPWD) -ldecodingfuncs

clean:
	rm mytar
