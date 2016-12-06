HEAP = heap_Pop
HUFF = huffNode
TREE = tree_loadHuff
NOTREE = tree_loadHuff_n
WRT = writeData
NO = writeData_n

FUNCS = $(HUFF).o $(WRT).o $(NO).o $(NOTREE).o $(TREE).o
LIB = libdecodingfuncs.a
HPWD = /home/sb/mytar/untar/head
HEAD = $(HPWD)/head.h

$(LIB) : $(HEAD) $(FUNCS)
	ar rv $(LIB) $(FUNCS)

$(HUFF).o : $(HEAD) $(HUFF).c
	gcc -c $(HUFF).c -I$(HPWD)

$(WRT).o : $(HEAD) $(WRT).c
	gcc -c $(WRT).c -I$(HPWD)

$(NO).o : $(HEAD) $(NO).c
	gcc -c $(NO).c -I$(HPWD)

$(NOTREE).o : $(HEAD) $(NOTREE).c
	gcc -c $(NOTREE).c -I$(HPWD)

$(TREE).o : $(HEAD) $(TREE).c
	gcc -c $(TREE).c -I$(HPWD)

clean : 
	rm $(LIB) $(FUNCS)
