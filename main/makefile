LPWD = /home/sb/mytar/incoding
HPWD = /home/sb/mytar
JPWD = /home/sb/mytar/untar/lib
JHWD = /home/sb/mytar/untar/head

mytar: main.c
	gcc main.c -o mytar -I$(HPWD) -I$(JHWD) -L$(LPWD) -lincodingfuncs -L$(JPWD) -ldecodingfuncs

clean:
	rm mytar
