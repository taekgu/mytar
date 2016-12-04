LPWD = /home/rok/mytar/incoding
HPWD = /home/rok/mytar
JPWD = /home/rok/mytar/untar/lib

mytar: main.c
	gcc main.c -o mytar -I$(HPWD) -L$(LPWD) -lincodingfuncs -L$(JPWD) -ldecodingfuncs

clean:
	rm mytar
