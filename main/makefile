LPWD = /home/rok/mytar/incoding
HPWD = /home/rok/mytar
JPWD = /home/rok/mytar/untar/lib
JHWD = /home/rok/mytar/untar/head

mytar: main.c
	gcc main.c -o mytar -I$(HPWD) -I$(JHWD) -L$(LPWD) -lincodingfuncs -L$(JPWD) -ldecodingfuncs

clean:
	rm mytar
