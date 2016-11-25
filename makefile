mytar: main.c mainhead.h
	gcc -o mytar main.c -I.

clean:
	rm mytar
